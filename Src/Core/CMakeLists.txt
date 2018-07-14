# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Create: 2018/3/25 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Token
add_definitions(-DRF_CORE_BUILD)

# Public depends
# Boost
set(RF_SRC_CORE_INCLUDE ${RF_SRC_CORE_INCLUDE} ${Boost_INCLUDE_DIRS})
set(RF_SRC_CORE_LIBS ${RF_SRC_CORE_LIBS} ${Boost_LIBRARIES})

# Global
configure_file("${PROJECT_SOURCE_DIR}/Src/Core/Global/Global.in.h" "${PROJECT_SOURCE_DIR}/Src/Core/Global/Global.h")
configure_file("${PROJECT_SOURCE_DIR}/Src/Core/Global/VersionInfo.in.h" "${PROJECT_SOURCE_DIR}/Src/Core/Global/VersionInfo.h")

# Math
# Sources
set(RF_SRC_CORE_SOURCES ${RF_SRC_CORE_SOURCES}
    "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec2.cpp"
    "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec3.cpp"
    "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec4.cpp"
    "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat2.cpp"
    "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat3.cpp"
    "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat4.cpp"
    "${PROJECT_SOURCE_DIR}/Src/Core/Math/MatrixHelper.cpp"
)
# Headers
set(RF_SRC_CORE_HEADERS ${RF_SRC_CORE_HEADERS}
    "${PROJECT_SOURCE_DIR}/Src/Core/Math/Scalar.h"
    "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec2.h"
    "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec3.h"
    "${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec4.h"
    "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat2.h"
    "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat3.h"
    "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat4.h"
    "${PROJECT_SOURCE_DIR}/Src/Core/Math/MatrixHelper.h"
)
# Depends
if(${RF_OS} STREQUAL "RF_OS_LINUX")
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -msse)
endif()

# String
# Sources
set(RF_SRC_CORE_SOURCES ${RF_SRC_CORE_SOURCES}
    "${PROJECT_SOURCE_DIR}/Src/Core/String/Convertor.cpp"
    "${PROJECT_SOURCE_DIR}/Src/Core/String/Char.cpp"
    "${PROJECT_SOURCE_DIR}/Src/Core/String/String.cpp"
)
# Headers
set(RF_SRC_CORE_HEADERS ${RF_SRC_CORE_HEADERS}
    "${PROJECT_SOURCE_DIR}/Src/Core/String/Convertor.h"
    "${PROJECT_SOURCE_DIR}/Src/Core/String/Char.h"
    "${PROJECT_SOURCE_DIR}/Src/Core/String/String.h"
)

# FileSystem
# Sources
set(RF_SRC_CORE_SOURCES ${RF_SRC_CORE_SOURCES}
    "${PROJECT_SOURCE_DIR}/Src/Core/FileSystem/Path.cpp"
    "${PROJECT_SOURCE_DIR}/Src/Core/FileSystem/File.cpp"
)
# Headers
set(RF_SRC_CORE_HEADERS ${RF_SRC_CORE_HEADERS}
    "${PROJECT_SOURCE_DIR}/Src/Core/FileSystem/Path.h"
    "${PROJECT_SOURCE_DIR}/Src/Core/FileSystem/File.h"
)

# Log
# Sources
set(RF_SRC_CORE_SOURCES ${RF_SRC_CORE_SOURCES}
    "${PROJECT_SOURCE_DIR}/Src/Core/Log/Log.cpp"
)
# Headers
set(RF_SRC_CORE_HEADERS ${RF_SRC_CORE_HEADERS}
    "${PROJECT_SOURCE_DIR}/Src/Core/Log/Log.h"
)

# Library
include_directories(${RF_SRC_CORE_INCLUDE})
add_library(RalFlightCore SHARED ${RF_SRC_CORE_SOURCES})
target_link_libraries(RalFlightCore ${RF_SRC_CORE_LIBS})