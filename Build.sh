#!/bin/bash
# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Craete: 2016/12/3 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Var
EXCU_DIR=`pwd`

# Create directory
mkdir -p $EXCU_DIR/Build/x86/
mkdir -p $EXCU_DIR/Build/x64/

# Config Build32
cd $EXCU_DIR/Build/x86
cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DRALFLIGHT_BUILD=ON -DCXXFLAGS=-m32 -DEXECUTABLE_OUTPUT_PATH="$EXCU_DIR/Bin/x86" -DLIBRARY_OUTPUT_PATH="$EXCU_DIR/Bin/x86" ../../

# Build32
make

# Config Build64
cd $EXCU_DIR/Build/x64
cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DRALFLIGHT_BUILD=ON -DCXXFLAGS=-m64 -DEXECUTABLE_OUTPUT_PATH="$EXCU_DIR/Bin/x64" -DLIBRARY_OUTPUT_PATH="$EXCU_DIR/Bin/x64" ../../

# Build64
make