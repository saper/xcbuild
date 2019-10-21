#
# Copyright (c) 2015-present, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.
#

file(GLOB_RECURSE xcworkspace_HEADERS Headers/xcworkspace/**/*.h)
add_library(xcworkspace STATIC
            Sources/XC/Workspace.cpp
            Sources/XC/FileRef.cpp
            Sources/XC/Group.cpp
            Sources/XC/GroupItem.cpp
            ${xcworkspace_HEADERS})

set_target_properties(xcworkspace PROPERTIES FOLDER "Libraries")
target_link_libraries(xcworkspace PUBLIC pbxsetting process util plist)
target_include_directories(xcworkspace PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Headers")

add_executable(dump_xcworkspace Tools/dump_xcworkspace.cpp)
set_target_properties(dump_xcworkspace PROPERTIES FOLDER "Tools")
target_link_libraries(dump_xcworkspace xcworkspace xcscheme pbxproj util plist)

