#
# Copyright (c) 2018-present, PureDarwin Project.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. 
#

file(GLOB_RECURSE xcyaml_HEADERS Headers/xcyaml/**/*.h)

add_library(xcyaml STATIC
    Sources/Project.cpp
    ${xcyaml_HEADERS})
set_target_properties(xcyaml PROPERTIES FOLDER "Libraries")
target_link_libraries(xcyaml PUBLIC libutil pbxproj yaml-cpp)
target_include_directories(xcyaml PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Headers")
