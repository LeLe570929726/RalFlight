# ----------------------------------------------------------------------------------------------------
# Copyright © 2016-2017 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Craete: 2017/12/1 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Source files
set(RALFILGHT_SRC_CORE_THREAD_SOURCE ${RALFILGHT_SRC_CORE_THREAD_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Thread/ThreadBase.cpp")

# Header files
set(RALFILGHT_SRC_CORE_THREAD_HEAD ${RALFILGHT_SRC_CORE_THREAD_HEAD} "${PROJECT_SOURCE_DIR}/Src/Core/Thread/ThreadBase.h")

# Shared library
add_library(RalFlightCoreThread SHARED ${RALFILGHT_SRC_CORE_THREAD_SOURCE})