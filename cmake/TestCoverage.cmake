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

if (NOT (CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "TestCoverage"))
    message(WARNING "Code coverage results with an optimized build may be misleading")
endif ()

# Set-up test coverage compilation flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 --coverage -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 --coverage -fprofile-arcs -ftest-coverage")

# Test coverage options
set(LCOV_EXCLUDE_PATTERNS "" CACHE STRING "lcov exclude patterns.")
set(LCOV_OUTPUT_FILE "coverage.info" CACHE STRING "lcov output file.")

# GenHTML options
set(WITH_GENHTML true CACHE BOOLEAN "Enable genhtml report generation.")
set(GENHTML_OUTPUT_DIR "coverage" CACHE STRING "genhtml output directory.")

# Coveralls option
set(WITH_COVERALLS true CACHE BOOLEAN "Enable coveralls report generation.")
set(COVERALLS_TOKEN "" CACHE STRING "Coveralls token")

function(test_coverage_report target test-target)

    find_program(GCOV_PATH gcov)
    if (NOT GCOV_PATH)
        message(FATAL_ERROR "gcov not found")
    endif ()

    find_program(LCOV_PATH lcov)
    if (NOT LCOV_PATH)
        message(FATAL_ERROR "lcov not found")
    endif ()

    # Add a clean-up target dependency to the test target
    add_custom_target(pre-${target}
        COMMAND ${LCOV_PATH} --directory ${CMAKE_BINARY_DIR} --zerocounters)
    add_dependencies(${test-target} pre-${target})

    # Report generation
    add_custom_target(${target}
        COMMAND ${LCOV_PATH} --directory ${CMAKE_BINARY_DIR} --capture --output-file ${LCOV_OUTPUT_FILE}
        COMMAND ${LCOV_PATH} --remove ${LCOV_OUTPUT_FILE} ${LCOV_EXCLUDE_PATTERNS} --output-file ${LCOV_OUTPUT_FILE}
        DEPENDS ${test-target})

endfunction()

function(test_coverage_genhtml target test-target)

    find_program(GENHTML_PATH genhtml)
    if (NOT GENHTML_PATH)
        message(FATAL_ERROR "genhtml not found")
    endif ()

    if (NOT TARGET ${target})
        test_coverage_report(${target} ${test-target})
    endif ()

    add_custom_target(${target}-genhtml
        COMMAND ${GENHTML_PATH} -o ${GENHTML_OUTPUT_DIR} ${LCOV_OUTPUT_FILE}
        DEPENDS ${target})

endfunction()

function(test_coverage_coveralls target test-target)

    find_program(COVERALLS_LCOV_PATH coveralls-lcov)
    if (NOT COVERALLS_LCOV_PATH)
        message(FATAL_ERROR "coveralls-lcov not found")
    endif ()

    if (NOT TARGET ${target})
        test_coverage_report(${target} ${test-target})
    endif ()

    add_custom_target(${target}-coveralls
        COMMAND ${COVERALLS_LCOV_PATH} --repo-token ${COVERALLS_TOKEN} ${LCOV_OUTPUT_FILE}
        DEPENDS ${target})

endfunction()

function(test_coverage target test-target)

    if (WITH_GENHTML)
        test_coverage_genhtml(${target} ${test-target})
    endif ()

    if (WITH_COVERALLS)
        test_coverage_coveralls(${target} ${test-target})
    endif ()

endfunction()
