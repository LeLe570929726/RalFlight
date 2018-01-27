# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Craete: 2016/12/3 by LeLe570929726
# ----------------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.8.2)

# Project information
project(RalFlight)
set(RalFlight_VERSION_MAJOR 0)
set(RalFlight_VERSION_MINOR 1)
set(RALFLIGHT_VERSION_RELEASE "\"0.1 Alpha1\"")

# Check system and set system token
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set(RALFLIGHT_SYSTEM "RALFLIGHT_SYSTEM_WINDOWS")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(RALFLIGHT_SYSTEM "RALFLIGHT_SYSTEM_LINUX")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    set(RALFLIGHT_SYSTEM "RALFLIGHT_SYSTEM_MAC")
endif()

# C++ standard
set(CMAKE_CXX_STANDARD 17)

# Build token
option(RALFLIGHT_BUILD "Build token" ON)

# Src
if(${RALFLIGHT_BUILD} STREQUAL ON)
	add_subdirectory("${PROJECT_SOURCE_DIR}/Src")
else()
    configure_file("${PROJECT_SOURCE_DIR}/Src/Core/Global/Macro.h.in" "${PROJECT_SOURCE_DIR}/Src/Core/Global/Macro.h")
endif()