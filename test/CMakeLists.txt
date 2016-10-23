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

set(MODULE_NAME unittest)

set(MODULE_SOURCES
    util/DimensionTest.cpp
    util/InsetsTest.cpp
    tiles/TilesetTest.cpp
)

find_package(GTest REQUIRED)
if (NOT GTEST_FOUND)
    message(FATAL_ERROR "Google Test is needed to build the tests.")
endif ()

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(${MODULE_NAME} ${MODULE_SOURCES})
target_link_libraries(${MODULE_NAME} ${SFML_LIBRARIES} ${GTEST_BOTH_LIBRARIES} zzb-util zzb-tiles)

add_custom_target(tests ${MODULE_NAME} DEPENDS ${MODULE_NAME} COMMENT "Running unit tests...")

file(COPY res DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
