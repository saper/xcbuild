#
# Copyright (c) 2015-present, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree. An additional grant
# of patent rights can be found in the PATENTS file in the same directory.
#

file(GLOB_RECURSE pbxproj_HEADERS Headers/pbxproj/**/*.h)
add_library(pbxproj STATIC
            Sources/Context.cpp
            Sources/ISA.cpp
            Sources/PlistHelpers.cpp
            Sources/PBX/AggregateTarget.cpp
            Sources/PBX/AppleScriptBuildPhase.cpp
            Sources/PBX/BaseGroup.cpp
            Sources/PBX/BuildFile.cpp
            Sources/PBX/BuildPhase.cpp
            Sources/PBX/BuildRule.cpp
            Sources/PBX/CopyFilesBuildPhase.cpp
            Sources/PBX/FileReference.cpp
            Sources/PBX/FrameworksBuildPhase.cpp
            Sources/PBX/Group.cpp
            Sources/PBX/GroupItem.cpp
            Sources/PBX/HeadersBuildPhase.cpp
            Sources/PBX/LegacyTarget.cpp
            Sources/PBX/NativeTarget.cpp
            Sources/PBX/Object.cpp
            Sources/PBX/Project.cpp
            Sources/PBX/ReferenceProxy.cpp
            Sources/PBX/ResourcesBuildPhase.cpp
            Sources/PBX/RezBuildPhase.cpp
            Sources/PBX/ShellScriptBuildPhase.cpp
            Sources/PBX/SourcesBuildPhase.cpp
            Sources/PBX/Target.cpp
            Sources/PBX/VariantGroup.cpp
            Sources/PBX/ContainerItemProxy.cpp
            Sources/PBX/TargetDependency.cpp
            Sources/XC/BuildConfiguration.cpp
            Sources/XC/ConfigurationList.cpp
            Sources/XC/VersionGroup.cpp
            ${pbxproj_HEADERS})

target_link_libraries(pbxproj PUBLIC pbxsetting util plist)
set_target_properties(pbxproj PROPERTIES FOLDER "Libraries")
target_include_directories(pbxproj PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Headers")
target_include_directories(pbxproj PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/PrivateHeaders")

add_executable(dump_xcodeproj Tools/dump_xcodeproj.cpp)
set_target_properties(dump_xcodeproj PROPERTIES FOLDER "Tools")
target_link_libraries(dump_xcodeproj pbxproj xcscheme pbxsetting util plist)

