#
# Copyright (c) 2015-present, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.
#

file(GLOB_RECURSE xcexecution_HEADERS Headers/xcexecution/**/*.h)
add_library(xcexecution STATIC
            Sources/Parameters.cpp
            Sources/Executor.cpp
            Sources/SimpleExecutor.cpp
            Sources/NinjaExecutor.cpp
            ${xcexecution_HEADERS})

set_target_properties(xcexecution PROPERTIES FOLDER "Libraries")
target_link_libraries(xcexecution PUBLIC xcformatter pbxbuild xcscheme xcworkspace pbxproj pbxsetting process util dependency ninja builtin)
target_include_directories(xcexecution PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Headers")

if (BUILD_TESTING)
  ADD_UNIT_GTEST(xcexecution SimpleExecutor Tests/test_SimpleExecutor.cpp)
endif ()
