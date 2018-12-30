# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Create: 2018/3/25 by LeLe570929726
# ----------------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.8.2 FATAL_ERROR)

# Project information
project(RalFlight)
set(RalFlight_VERSION_MAJOR 0)
set(RalFlight_VERSION_MINOR 1)
set(RF_VERSION_RELEASE "\"0.1 Alpha1\"")

# Target token
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set(RF_OS "RF_OS_WIN")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(RF_OS "RF_OS_LINUX")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    set(RF_OS "RF_OS_MACOS")
endif()

# Platform token
set(RF_ARCH ${CMAKE_GENERATOR_PLATFORM})

# Set c++ standard version
set(CMAKE_CXX_STANDARD 17)

# Set executable path
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/Bin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/Bin")

# Add subdirectories
# Config
include("CMake/Config.cmake")
# Src
add_subdirectory("Src")