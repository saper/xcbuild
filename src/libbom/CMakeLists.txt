#
# Copyright (c) 2015-present, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. An additional grant
# of patent rights can be found in the PATENTS file in the same directory.
#

file(GLOB_RECURSE bom_HEADERS Headers/bom/**/*.h)
add_library(bom STATIC
            Sources/bom.c
            Sources/bom_memory.c
            Sources/bom_tree.c
            ${bom_HEADERS})

set_target_properties(bom PROPERTIES FOLDER "Libraries")
target_link_libraries(bom PUBLIC util)
if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
  if ("${CMAKE_CXX_PLATFORM_ID}" STREQUAL "MinGW")
    target_link_libraries(bom PRIVATE wsock32 ws2_32)
  else ()
    target_link_libraries(bom PRIVATE WSock32 WS2_32)
  endif ()
endif ()
target_include_directories(bom PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Headers")

add_executable(lsbom Tools/lsbom.cpp)
set_target_properties(lsbom PROPERTIES FOLDER "Tools")
target_link_libraries(lsbom PRIVATE util bom)
if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
  if ("${CMAKE_CXX_PLATFORM_ID}" STREQUAL "MinGW")
    target_link_libraries(lsbom PRIVATE wsock32 ws2_32)
  else ()
    target_link_libraries(lsbom PRIVATE WSock32 WS2_32)
  endif ()
endif ()
install(TARGETS lsbom DESTINATION bin)

add_executable(dump_bom Tools/dump_bom.c)
set_target_properties(dump_bom PROPERTIES FOLDER "Tools")
target_link_libraries(dump_bom PRIVATE bom util)
if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
  if ("${CMAKE_CXX_PLATFORM_ID}" STREQUAL "MinGW")
    target_link_libraries(dump_bom PRIVATE wsock32 ws2_32)
  else ()
    target_link_libraries(dump_bom PRIVATE WSock32 WS2_32)
  endif ()
endif ()
install(TARGETS dump_bom DESTINATION bin)
