# Copyright (c) 2016 ZZBGames
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

cmake_minimum_required(VERSION 2.8)
project(zzb-core)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(PROJECT_VERSION_MAJOR "0")
set(PROJECT_VERSION_MINOR "0")
set(PROJECT_VERSION_PATCH "1")
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}")

set(BUILD_SHARED_LIBS TRUE CACHE BOOL "Build shared libraries.")
set(BUILD_STATIC_LIBS TRUE CACHE BOOL "Build static libraries.")
set(BUILD_DOC TRUE CACHE BOOL "Generate documentation.")
set(BUILD_TESTS TRUE CACHE BOOL "Build tests.")

find_package(SFML 2 REQUIRED graphics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -std=c++11")
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build: Debug Release RelWithDebInfo MinSizeRel" FORCE)
endif()

if (CMAKE_BUILD_TYPE STREQUAL "TestCoverage")
    include(TestCoverage)
    set(BUILD_TESTS true)
    set(LCOV_EXCLUDE_PATTERNS "'/usr/*';'test/*'")
endif()

set(BIN_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/bin" CACHE PATH "The directory the executables are installed in.")
set(INCLUDE_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/include" CACHE PATH "The directory the headers are installed in.")
set(LIB_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/lib" CACHE PATH "The directory the libraries are installed in.")
set(DOC_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/doc" CACHE PATH "The directory the documentation is installed in.")

include_directories(${SFML_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(src)
if (BUILD_TESTS)
    add_subdirectory(test)
    if (CMAKE_BUILD_TYPE STREQUAL "TestCoverage")
        test_coverage_coveralls(test-coverage tests)
    endif()
endif()
if (BUILD_DOC)
    add_subdirectory(doc)
endif()
