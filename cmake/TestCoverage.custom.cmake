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

if (CMAKE_BUILD_TYPE STREQUAL "TestCoverage")
    # Include TestCoverage module
    include(TestCoverage)

    # lcovrc configuration file generation
    configure_file(coverage/lcovrc.in ${CMAKE_CURRENT_BINARY_DIR}/coverage/lcovrc @ONLY)

    # LCOV configuration
    set(LCOV_EXCLUDE_PATTERNS "'/usr/*';'test/*'")
    set(LCOV_OUTPUT_FILE coverage/coverage.info)
    set(LCOV_OPTIONS "--config-file;${CMAKE_CURRENT_BINARY_DIR}/coverage/lcovrc")

    # GenHTML configuration
    set(GENHTML_OUTPUT_DIR "coverage/html")
    set(GENHTML_OPTIONS "--demangle-cpp;--config-file;${CMAKE_CURRENT_BINARY_DIR}/coverage/lcovrc")

    # Force tests compilation
    set(BUILD_TESTS true)
endif ()
