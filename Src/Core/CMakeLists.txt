# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Craete: 2016/12/10 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Global
include("${PROJECT_SOURCE_DIR}/Src/Core/Global/CMakeLists.txt")

# STL
include("${PROJECT_SOURCE_DIR}/Src/Core/STL/CMakeLists.txt")

# Math
include("${PROJECT_SOURCE_DIR}/Src/Core/Math/CMakeLists.txt")

# Thread
include("${PROJECT_SOURCE_DIR}/Src/Core/Thread/CMakeLists.txt")

# Library
add_library(RalFlightCore SHARED ${RALFILGHT_SRC_CORE_STL_SOURCE}
								 ${RALFILGHT_SRC_CORE_MATH_SOURCE}
								 ${RALFILGHT_SRC_CORE_THREAD_SOURCE})