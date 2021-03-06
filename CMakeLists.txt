cmake_minimum_required(VERSION 3.0)
set(CMP0048 NEW)

#Disable in source compilation
if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
    message( FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt." )
endif()

if(NOT DEFINED CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type")
endif()

project(myLib VERSION 1.0.0 LANGUAGES C CXX)

enable_testing()

#Set default install path
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_LIST_DIR}/../install_dir/" CACHE PATH "Where to install myLib")

#Set path to Dependencies 
set(GTEST_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}/../install_dir/" CACHE PATH "Root folder of the google test framework installation")

include(cmake/CompilerFlags.cmake)

add_subdirectory(src)
add_subdirectory(tests)
