# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT ber_estimator_sources)
    MESSAGE(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT ber_estimator_sources)

########################################################################
# Check for pygccxml
########################################################################
GR_PYTHON_CHECK_MODULE_RAW(
    "pygccxml"
    "import pygccxml"
    PYGCCXML_FOUND
    )

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

list(APPEND ber_estimator_python_files
    ber_estimator_bf_python.cc python_bindings.cc)

GR_PYBIND_MAKE_OOT(ber_estimator 
   ../..
   gr::ber_estimator
   "${ber_estimator_python_files}")

install(TARGETS ber_estimator_python DESTINATION ${GR_PYTHON_DIR}/ber_estimator COMPONENT pythonapi)
