#
# Copyright (c) 2015-present, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. An additional grant
# of patent rights can be found in the PATENTS file in the same directory.
#

file(GLOB_RECURSE xcformatter_HEADERS Headers/xcformatter/**/*.h)
add_library(xcformatter STATIC
            Sources/Formatter.cpp
            Sources/DefaultFormatter.cpp
            Sources/NullFormatter.cpp
            ${xcformatter_HEADERS})

target_link_libraries(xcformatter PUBLIC pbxbuild pbxproj pbxsetting)
target_include_directories(xcformatter PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Headers")
