# ----------------------------------------------------------------------------------------------------
# Copyright © 2016-2017 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Craete: 2017/07/15 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Source files
set(RALFILGHT_SRC_CORE_STL_SOURCE ${RALFILGHT_SRC_CORE_STL_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/STL/String.cpp")

# Header files
set(RALFILGHT_SRC_CORE_STL_HEAD ${RALFILGHT_SRC_CORE_STL_HEAD} "${PROJECT_SOURCE_DIR}/Src/Core/STL/Iterator.h")
set(RALFILGHT_SRC_CORE_STL_HEAD ${RALFILGHT_SRC_CORE_STL_HEAD} "${PROJECT_SOURCE_DIR}/Src/Core/STL/String.h")

# Shared library
add_library(RalFlightCoreSTL SHARED ${RALFILGHT_SRC_CORE_STL_SOURCE})