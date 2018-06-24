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
# Qt
set(RF_SRC_CORE_INCLUDE ${RF_SRC_CORE_INCLUDE} ${QT_INCLUDE})
# QtCore
set(RF_SRC_CORE_INCLUDE ${RF_SRC_CORE_INCLUDE} ${QT_INCLUDE_CORE})
set(RF_SRC_CORE_LIBS ${RF_SRC_CORE_LIBS} ${QT_LIBS_CORE})

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

# Thread
# Headers
set(RF_SRC_CORE_HEADERS ${RF_SRC_CORE_HEADERS}
    "${PROJECT_SOURCE_DIR}/Src/Core/Thread/SafeQueue.h"
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

# Memory
# Sources
#set(RF_SRC_CORE_SOURCES ${RF_SRC_CORE_SOURCES}
#    "${PROJECT_SOURCE_DIR}/Src/Core/Memory/MemoryPool.cpp"
#)
# Headers
#set(RF_SRC_CORE_HEADERS ${RF_SRC_CORE_HEADERS}
#    "${PROJECT_SOURCE_DIR}/Src/Core/Memory/MemoryPool.h"
#)

# Library
include_directories(${RF_SRC_CORE_INCLUDE})
add_library(RalFlightCore SHARED ${RF_SRC_CORE_SOURCES})
target_link_libraries(RalFlightCore ${RF_SRC_CORE_LIBS})