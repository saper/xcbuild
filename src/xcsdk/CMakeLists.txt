#
# Copyright (c) 2015-present, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. An additional grant
# of patent rights can be found in the PATENTS file in the same directory.
#

file(GLOB_RECURSE xcsdk_HEADERS Headers/xcsdk/**/*.h)
add_library(xcsdk STATIC
            Sources/Configuration.cpp
            Sources/Environment.cpp
            Sources/SDK/Manager.cpp
            Sources/SDK/Platform.cpp
            Sources/SDK/PlatformVersion.cpp
            Sources/SDK/Product.cpp
            Sources/SDK/Target.cpp
            Sources/SDK/Toolchain.cpp
            ${xcsdk_HEADERS})

set_target_properties(xcsdk PROPERTIES FOLDER "Libraries")
target_link_libraries(xcsdk PUBLIC pbxsetting process util plist)
target_include_directories(xcsdk PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Headers")

add_executable(xcrun Tools/xcrun.cpp)
set_target_properties(xcrun PROPERTIES FOLDER "Tools")
target_link_libraries(xcrun xcsdk util)
install(TARGETS xcrun DESTINATION usr/bin)

add_executable(xcode-select Tools/xcode-select.cpp)
set_target_properties(xcode-select PROPERTIES FOLDER "Tools")
target_link_libraries(xcode-select xcsdk util)
install(TARGETS xcode-select DESTINATION usr/bin)

if (BUILD_TESTING)
  ADD_UNIT_GTEST(xcsdk PlatformVersion Tests/test_PlatformVersion.cpp)
  ADD_UNIT_GTEST(xcsdk Toolchain Tests/test_Toolchain.cpp)
  ADD_UNIT_GTEST(xcsdk Configuration Tests/test_Configuration.cpp)
  ADD_UNIT_GTEST(xcsdk Manager Tests/test_Manager.cpp)
endif ()
