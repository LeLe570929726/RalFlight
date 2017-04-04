# ----------------------------------------------------------------------------------------------------
# Copyright © 2016-2017 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Craete: 2016/12/10 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Global
configure_file("${PROJECT_SOURCE_DIR}/Src/Core/Global/Macro/Macro.h.in" "${PROJECT_SOURCE_DIR}/Src/Core/Global/Macro/Macro.h")
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Global/Macro/Macro.h")
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Global/FunctionPointer/FunctionPointer.h")

# STD
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/STD/Iterator/Iterator.h")
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/STD/String/String.h")
set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/STD/String/String.cpp")

# Math
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Scalar/Scalar.h")
set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Scalar/Scalar.cpp")
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec2/Vec2.h")
set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec2/Vec2.cpp")
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec3/Vec3.h")
set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec3/Vec3.cpp")
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec4/Vec4.h")
set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec4/Vec4.cpp")
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat2/Mat2.h")
set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat2/Mat2.cpp")
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat3/Mat3.h")
set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat3/Mat3.cpp")
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat4/Mat4.h")
set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat4/Mat4.cpp")

# Plugin
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Plugin/LibraryLoader/LibraryLoader.h")
set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Plugin/LibraryLoader/LibraryLoader.cpp")
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Plugin/PluginLoader/PluginLoader.h")
set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Plugin/PluginLoader/PluginLoader.cpp")

# FileSystem
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/FileSystem/FileSystem/FileSystem.h")
set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/FileSystem/FileSystem/FileSystem.cpp")
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/FileSystem/Path/Path.h")
set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/FileSystem/Path/Path.cpp")

add_library(RalFlightCore SHARED ${RALFILGHT_SRC_CORE_SOURCE})