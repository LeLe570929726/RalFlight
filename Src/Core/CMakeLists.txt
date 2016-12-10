# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Craete: 2016/12/10 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Math
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Scalar/Scalar.h")
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec2/Vec2.h")
set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec2/Vec2.cpp")
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec3/Vec3.h")
set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec3/Vec3.cpp")

add_library(RalFlightCore SHARED ${RALFILGHT_SRC_CORE_SOURCE})