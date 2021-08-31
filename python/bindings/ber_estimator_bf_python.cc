/*
 * Copyright 2021 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(ber_estimator_bf.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(c6535dde56b21af6da1e155700d210e4)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <ber_estimator/ber_estimator_bf.h>
// pydoc.h is automatically generated in the build directory
#include <ber_estimator_bf_pydoc.h>

void bind_ber_estimator_bf(py::module& m)
{

    using ber_estimator_bf    = ::gr::ber_estimator::ber_estimator_bf;


    py::class_<ber_estimator_bf, gr::block, gr::basic_block,
        std::shared_ptr<ber_estimator_bf>>(m, "ber_estimator_bf", D(ber_estimator_bf))

        .def(py::init(&ber_estimator_bf::make),
           py::arg("symbol_"),
           D(ber_estimator_bf,make)
        )
        



        ;




}








