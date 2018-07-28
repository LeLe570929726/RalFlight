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
configure_file("Global/Global.in.h" "Global/Global.h")
configure_file("Global/VersionInfo.in.h" "Global/VersionInfo.h")

# Memory
# Sources
set(RF_SRC_CORE_SOURCES ${RF_SRC_CORE_SOURCES}
)
# Headers
set(RF_SRC_CORE_HEADERS ${RF_SRC_CORE_HEADERS}
    "Memory/UniquePointer.h"
)

# Math
# Sources
set(RF_SRC_CORE_SOURCES ${RF_SRC_CORE_SOURCES}
    "Math/Vec2.cpp"
    "Math/Vec3.cpp"
    "Math/Vec4.cpp"
    "Math/Mat2.cpp"
    "Math/Mat3.cpp"
    "Math/Mat4.cpp"
    "Math/MatrixHelper.cpp"
)
# Headers
set(RF_SRC_CORE_HEADERS ${RF_SRC_CORE_HEADERS}
    "Math/Scalar.h"
    "Math/Vec2.h"
    "Math/Vec3.h"
    "Math/Vec4.h"
    "Math/Mat2.h"
    "Math/Mat3.h"
    "Math/Mat4.h"
    "Math/MatrixHelper.h"
)
# Depends
if(${RF_OS} STREQUAL "RF_OS_LINUX")
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -msse)
endif()

# String
# Sources
set(RF_SRC_CORE_SOURCES ${RF_SRC_CORE_SOURCES}
    "String/Convertor.cpp"
    "String/Char.cpp"
    "String/CharReference.cpp"
    "String/String.cpp"
    "String/StringIterator.cpp"
)
# Headers
set(RF_SRC_CORE_HEADERS ${RF_SRC_CORE_HEADERS}
    "String/Convertor.h"
    "String/Char.h"
    "String/CharReference.h"
    "String/String.h"
    "String/StringIterator.h"
)

# FileSystem
# Sources
set(RF_SRC_CORE_SOURCES ${RF_SRC_CORE_SOURCES}
    "FileSystem/Path.cpp"
    "FileSystem/File.cpp"
)
# Headers
set(RF_SRC_CORE_HEADERS ${RF_SRC_CORE_HEADERS}
    "FileSystem/Path.h"
    "FileSystem/File.h"
)

# Log
# Sources
set(RF_SRC_CORE_SOURCES ${RF_SRC_CORE_SOURCES}
    "Log/Log.cpp"
)
# Headers
set(RF_SRC_CORE_HEADERS ${RF_SRC_CORE_HEADERS}
    "Log/Log.h"
)

# Library
include_directories(${RF_SRC_CORE_INCLUDE})
add_library(RalFlightCore SHARED ${RF_SRC_CORE_SOURCES})
target_link_libraries(RalFlightCore ${RF_SRC_CORE_LIBS})