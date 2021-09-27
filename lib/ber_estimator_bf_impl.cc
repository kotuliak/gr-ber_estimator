/* -*- c++ -*- */
/*
 * Copyright 2021 gr-ber_estimator author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <gnuradio/io_signature.h>
#include "ber_estimator_bf_impl.h"

namespace gr {
  namespace ber_estimator {

    #pragma message("set the following appropriately and remove this warning")
    using input_type = uint8_t;
    #pragma message("set the following appropriately and remove this warning")
    using output_type = float;
    ber_estimator_bf::sptr
    ber_estimator_bf::make(gr_vector_int &symbol_)
    {
      return gnuradio::make_block_sptr<ber_estimator_bf_impl>(symbol_);
    }

    boost::dynamic_bitset<> concatenate(const boost::dynamic_bitset<>& first, const boost::dynamic_bitset<>& second)
    {
      boost::dynamic_bitset<> value(first);
      //Increase the size of the bit buffer to fit the data being placed in it
      value.resize(first.size() + second.size());
      value <<= second.size();
      for (size_t i = 0; i < second.size(); i++)
      {
        value[i] = second[i];
      }
      return value;
    }


    /*
     * The private constructor
     */
    ber_estimator_bf_impl::ber_estimator_bf_impl(gr_vector_int &symbol_)
      : gr::block("ber_estimator_bf",
              gr::io_signature::make(1 /* min inputs */, 1 /* max inputs */, sizeof(input_type)),
              gr::io_signature::make(1 /* min outputs */, 1 /*max outputs */, sizeof(output_type)))
    {
      for (size_t i = 0; i < symbol_.size(); i++)
      {
        boost::dynamic_bitset<> byte(8, symbol_[i]);
        
        symbol = concatenate(symbol, byte);
      }
      // std::cout << std::endl;
      std::cout << symbol << std::endl;
    }

    /*
     * Our virtual destructor.
     */
    ber_estimator_bf_impl::~ber_estimator_bf_impl()
    {
      std::cout << symbol << std::endl;
    }

    void
    ber_estimator_bf_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    { 
      ninput_items_required[0] = noutput_items * symbol.size();
    }

    int
    ber_estimator_bf_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const input_type *in = reinterpret_cast<const input_type*>(input_items[0]);
      output_type *out = reinterpret_cast<output_type*>(output_items[0]);

      int min_ind = 0;

      for (size_t j = 0; j < noutput_items; j++) {

        boost::dynamic_bitset<> received_symbol;

        

        for (size_t i = 0; i < symbol.size(); i++)
        {
          boost::dynamic_bitset<> byte(1, in[j * (symbol.size()) + i + min_ind]);
          received_symbol = concatenate(received_symbol, byte);
        }

        if (counter % 1000 == 0) {
          std::cout << received_symbol << std::endl;  
        }
        counter++;

        if (delay_zero_count < 10) {

          float min = symbol.size();
          int min_ind_can = 0;

          for (size_t k = 0; k < symbol.size(); k++) {
            float min_cand = (float) (symbol ^ received_symbol).count();
            if (min_cand < min) {
              min_ind_can = k;
              min = min_cand;
            }
            bool left = received_symbol[symbol.size() - 1];
            received_symbol = received_symbol << 1;
            received_symbol[0] = left;
          }

          min_ind += min_ind_can;
          out[j] = min / (float) symbol.size();

          if (min_ind_can != 0) {
            
            std::cout << min_ind << " " << delay_zero_count << std::endl;
            delay_zero_count = 0;
          } else {
            delay_zero_count++;
          }

        } else {
          
          min_ind += 0;
          float min_cand = (float) (symbol ^ received_symbol).count();
          out[j] = min_cand / (float) symbol.size();
          std::cout << "went through initial period! " << out[j] << std::endl;
        } 

        // std::cout << out[j] << std::endl;
        // std::cout << (received_symbol) << " " << noutput_items << "\n";
      }

      consume_each (noutput_items * (symbol.size()) + min_ind);

      // Tell runtime system how many output items we produced.

      
      return noutput_items;
    }

  } /* namespace ber_estimator */
} /* namespace gr */

