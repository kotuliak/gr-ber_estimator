/* -*- c++ -*- */
/*
 * Copyright 2021 gr-ber_estimator author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_BER_ESTIMATOR_BER_ESTIMATOR_BF_IMPL_H
#define INCLUDED_BER_ESTIMATOR_BER_ESTIMATOR_BF_IMPL_H

#include <boost/dynamic_bitset.hpp>
#include <ber_estimator/ber_estimator_bf.h>

namespace gr {
  namespace ber_estimator {

    class ber_estimator_bf_impl : public ber_estimator_bf
    {
     private:
     boost::dynamic_bitset<> symbol;
     int counter = 0;
     int delay_zero_count = 0;
     float smoothed_ber = 0;
     int report_period;

     public:
      ber_estimator_bf_impl(gr_vector_int &symbol_, int report_period_);
      ~ber_estimator_bf_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);

    };

  } // namespace ber_estimator
} // namespace gr

#endif /* INCLUDED_BER_ESTIMATOR_BER_ESTIMATOR_BF_IMPL_H */

