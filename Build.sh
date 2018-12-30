#!/bin/bash
# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
#
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Create: 2018/4/6 by LeLe570929726
# ----------------------------------------------------------------------------------------------------


# Set variable
rootPath=$(dirname $(readlink -f $0))
buildToken=$1
buildTarget=$2

# Check variable
# Check build token
if [ ! -n "$buildToken" ]
then
    echo -e "\033[35mError - Parameter one must be 'release' or 'debug'.\033[0m"
    exit
fi
if [[ $buildToken != "release" && $buildToken != "debug" ]]
then
    echo -e "\033[35mError - Parameter one must be 'release' or 'debug'.\033[0m"
    exit
fi

# Check build target
if [ ! -n "$buildTarget" ]
then
    echo -e "\033[35mError - Parameter two must be 'x86' or 'x64'.\033[0m"
    exit
fi
if [[ $buildTarget != "x86" && $buildTarget != "x64" ]]
then
    echo -e "\033[35mError - Parameter two must be 'x86' or 'x64'.\033[0m"
    exit
fi

# Check directories
if [ -d "$rootPath/Build" ]
then
    rm -r "$rootPath/Build"
fi
if [ -d "$rootPath/Bin" ]
then
    rm -r "$rootPath/Bin"
fi

# Create directories
mkdir "$rootPath/Build"
mkdir "$rootPath/Bin"

# Check cmake support
if [ `cmake --version | grep -c "cmake version"` == 0 ]
then
    echo -e "\033[35mError - Can't find CMake. Please confirm that you had installed CMake and add the directory into Path environment variable.\033[0m"
    exit
fi

# Build
cd "$rootPath/Build"
cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=$buildToken -DEXECUTABLE_OUTPUT_PATH="$rootPath/Bin" -DCMAKE_GENERATOR_PLATFORM=$buildTarget ../
# Check makefile
if [ ! -f "Makefile" ];
then
    echo -e "\033[35mError - CMake config failed, please check log of CMake.\033[0m"
    exit
fi
make

# Exit
echo -e "\033[32mBuild successfully.\033[0m"
exit