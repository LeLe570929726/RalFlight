# ----------------------------------------------------------------------------------------------------
# Copyright © 2016-2017 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Craete: 2016/12/3 by LeLe570929726
# ----------------------------------------------------------------------------------------------------
include("Cmake/MinBuildVersion.cmake")

cmake_minimum_required(VERSION ${MIN_VERSION_CMAKE})

project(RalFlight)
set(RalFlight_VERSION_MAJOR 0)
set(RalFlight_VERSION_MINOR 1)
set(RALFLIGHT_VERSION_RELEASE "\"0.1 Alpha1\"")

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/Bin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/Bin")

# Check system and set system token
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set(RALFLIGHT_SYSTEM "RALFLIGHT_SYSTEM_WINDOWS")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(RALFLIGHT_SYSTEM "RALFLIGHT_SYSTEM_LINUX")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    set(RALFLIGHT_SYSTEM "RALFLIGHT_SYSTEM_MAC")
endif()

# Build token
option(RALFLIGHT_BUILD "Build token" ON)

# Src
add_subdirectory("${PROJECT_SOURCE_DIR}/Src")