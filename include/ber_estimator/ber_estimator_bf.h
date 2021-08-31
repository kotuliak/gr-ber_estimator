/* -*- c++ -*- */
/*
 * Copyright 2021 gr-ber_estimator author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_BER_ESTIMATOR_BER_ESTIMATOR_BF_H
#define INCLUDED_BER_ESTIMATOR_BER_ESTIMATOR_BF_H

#include <ber_estimator/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace ber_estimator {

    /*!
     * \brief <+description of block+>
     * \ingroup ber_estimator
     *
     */
    class BER_ESTIMATOR_API ber_estimator_bf : virtual public gr::block
    {
     public:
      typedef std::shared_ptr<ber_estimator_bf> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of ber_estimator::ber_estimator_bf.
       *
       * To avoid accidental use of raw pointers, ber_estimator::ber_estimator_bf's
       * constructor is in a private implementation
       * class. ber_estimator::ber_estimator_bf::make is the public interface for
       * creating new instances.
       */
      static sptr make(gr_vector_int &symbol_);
    };

  } // namespace ber_estimator
} // namespace gr

#endif /* INCLUDED_BER_ESTIMATOR_BER_ESTIMATOR_BF_H */

