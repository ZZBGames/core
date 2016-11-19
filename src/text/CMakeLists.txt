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

set(MODULE_NAME zzb-text)

set(MODULE_SOURCES
    Font.cpp
    Text.cpp
)

if (BUILD_SHARED_LIBS)
    add_library(${MODULE_NAME} SHARED ${MODULE_SOURCES})
    set_target_properties(${MODULE_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})
    set_target_properties(${MODULE_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

    target_link_libraries(${MODULE_NAME} ${SFML_LIBRARIES} zzb-util zzb-tiles)

    install(TARGETS ${MODULE_NAME} LIBRARY DESTINATION ${LIB_INSTALL_DIR} COMPONENT library)
endif()

if (BUILD_STATIC_LIBS)
    add_library(${MODULE_NAME}-static STATIC ${MODULE_SOURCES})
    set_target_properties(${MODULE_NAME}-static PROPERTIES OUTPUT_NAME ${MODULE_NAME})

    target_link_libraries(${MODULE_NAME}-static ${SFML_LIBRARIES} zzb-util zzb-tiles)

    install(TARGETS ${MODULE_NAME}-static ARCHIVE DESTINATION ${LIB_INSTALL_DIR} COMPONENT library)
endif()
