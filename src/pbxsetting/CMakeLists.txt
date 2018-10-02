#
# Copyright (c) 2015-present, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. An additional grant
# of patent rights can be found in the PATENTS file in the same directory.
#

file(GLOB_RECURSE pbxsetting_HEADERS Headers/pbxsetting/**/*.h)
add_library(pbxsetting STATIC
            Sources/Condition.cpp
            Sources/DefaultSettings.cpp
            Sources/Environment.cpp
            Sources/Level.cpp
            Sources/Setting.cpp
            Sources/Type.cpp
            Sources/Value.cpp
            Sources/XC/Config.cpp
            ${pbxsetting_HEADERS})

target_link_libraries(pbxsetting PUBLIC process util plist)
set_target_properties(pbxsetting PROPERTIES FOLDER "Libraries")
target_include_directories(pbxsetting PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Headers")
target_include_directories(pbxsetting PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/PrivateHeaders")

add_executable(dump_xcconfig Tools/dump_xcconfig.cpp)
set_target_properties(dump_xcconfig PROPERTIES FOLDER "Tools")
target_link_libraries(dump_xcconfig pbxsetting util)

if (BUILD_TESTING)
  ADD_UNIT_GTEST(pbxsetting Condition Tests/test_Condition.cpp)
  ADD_UNIT_GTEST(pbxsetting Environment Tests/test_Environment.cpp)
  ADD_UNIT_GTEST(pbxsetting Setting Tests/test_Setting.cpp)
  ADD_UNIT_GTEST(pbxsetting Type Tests/test_Type.cpp)
  ADD_UNIT_GTEST(pbxsetting Value Tests/test_Value.cpp)
  ADD_UNIT_GTEST(pbxsetting Config Tests/test_Config.cpp)
endif ()

