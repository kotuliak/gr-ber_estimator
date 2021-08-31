if(NOT PKG_CONFIG_FOUND)
    INCLUDE(FindPkgConfig)
endif()
PKG_CHECK_MODULES(PC_BER_ESTIMATOR ber_estimator)

FIND_PATH(
    BER_ESTIMATOR_INCLUDE_DIRS
    NAMES ber_estimator/api.h
    HINTS $ENV{BER_ESTIMATOR_DIR}/include
        ${PC_BER_ESTIMATOR_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    BER_ESTIMATOR_LIBRARIES
    NAMES gnuradio-ber_estimator
    HINTS $ENV{BER_ESTIMATOR_DIR}/lib
        ${PC_BER_ESTIMATOR_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/ber_estimatorTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(BER_ESTIMATOR DEFAULT_MSG BER_ESTIMATOR_LIBRARIES BER_ESTIMATOR_INCLUDE_DIRS)
MARK_AS_ADVANCED(BER_ESTIMATOR_LIBRARIES BER_ESTIMATOR_INCLUDE_DIRS)
