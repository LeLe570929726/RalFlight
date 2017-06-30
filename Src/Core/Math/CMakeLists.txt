# ----------------------------------------------------------------------------------------------------
# Copyright © 2016-2017 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Craete: 2017/06/24 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Source files
set(RALFILGHT_SRC_CORE_MATH_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Scalar.cpp")
set(RALFILGHT_SRC_CORE_MATH_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec2.cpp")
set(RALFILGHT_SRC_CORE_MATH_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec3.cpp")
set(RALFILGHT_SRC_CORE_MATH_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec4.cpp")
set(RALFILGHT_SRC_CORE_MATH_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat2.cpp")
set(RALFILGHT_SRC_CORE_MATH_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat3.cpp")
set(RALFILGHT_SRC_CORE_MATH_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat4.cpp")

# Header files
set(RALFILGHT_SRC_CORE_MATH_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Scalar.h")
set(RALFILGHT_SRC_CORE_MATH_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec2.h")
set(RALFILGHT_SRC_CORE_MATH_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec3.h")
set(RALFILGHT_SRC_CORE_MATH_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec4.h")
set(RALFILGHT_SRC_CORE_MATH_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat2.h")
set(RALFILGHT_SRC_CORE_MATH_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat3.h")
set(RALFILGHT_SRC_CORE_MATH_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat4.h")

# Shared library
add_library(RalFlightCoreMath SHARED ${RALFILGHT_SRC_CORE_MATH_SOURCE})