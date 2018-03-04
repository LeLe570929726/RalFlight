# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Create: 2016/12/10 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Global
configure_file("${PROJECT_SOURCE_DIR}/Src/Core/Global/Macro.h.in" "${PROJECT_SOURCE_DIR}/Src/Core/Global/Macro.h")

# STL
# Source files
set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE}
)
# Header files
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_HEAD}
		"${PROJECT_SOURCE_DIR}/Src/Core/STL/IteratorBase.h"
		"${PROJECT_SOURCE_DIR}/Src/Core/STL/UniquePointer.h"
		"${PROJECT_SOURCE_DIR}/Src/Core/STL/Map.h"
		"${PROJECT_SOURCE_DIR}/Src/Core/STL/Queue.h"
)

# String
# Source files
set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE}
		"${PROJECT_SOURCE_DIR}/Src/Core/String/Char.cpp"
		"${PROJECT_SOURCE_DIR}/Src/Core/String/String.cpp"
		"${PROJECT_SOURCE_DIR}/Src/Core/String/StringEncode.cpp"
		"${PROJECT_SOURCE_DIR}/Src/Core/String/RegEx.cpp"
)
# Header files
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_HEAD}
		"${PROJECT_SOURCE_DIR}/Src/Core/String/Char.h"
		"${PROJECT_SOURCE_DIR}/Src/Core/String/String.h"
		"${PROJECT_SOURCE_DIR}/Src/Core/String/StringEncode.h"
		"${PROJECT_SOURCE_DIR}/Src/Core/String/RegEx.h"
)

# FileSystem
# Source files
set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE}
		"${PROJECT_SOURCE_DIR}/Src/Core/FileSystem/Path.cpp"
)
# Header files
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_HEAD}
		"${PROJECT_SOURCE_DIR}/Src/Core/FileSystem/Path.h"
)

# Math
# Source files
set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE}
		"${PROJECT_SOURCE_DIR}/Src/Core/Math/Scalar.cpp"
		"${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec2.cpp"
		"${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec3.cpp"
		"${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec4.cpp"
		"${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat2.cpp"
		"${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat3.cpp"
		"${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat4.cpp"
		"${PROJECT_SOURCE_DIR}/Src/Core/Math/MatrixHelper.cpp"
)
# Header files
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_HEAD}
		"${PROJECT_SOURCE_DIR}/Src/Core/Math/Scalar.h"
		"${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec2.h"
		"${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec3.h"
		"${PROJECT_SOURCE_DIR}/Src/Core/Math/Vec4.h"
        "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat2.h"
        "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat3.h"
        "${PROJECT_SOURCE_DIR}/Src/Core/Math/Mat4.h"
        "${PROJECT_SOURCE_DIR}/Src/Core/Math/MatrixHelper.h"
)
# Support
if(${RALFLIGHT_SYSTEM} STREQUAL "RALFLIGHT_SYSTEM_LINUX")
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -msse)
endif()

# Thread
# Source files
set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE}
        "${PROJECT_SOURCE_DIR}/Src/Core/Thread/RunnableBase.cpp"
        "${PROJECT_SOURCE_DIR}/Src/Core/Thread/Thread.cpp"
        "${PROJECT_SOURCE_DIR}/Src/Core/Thread/ThreadPool.cpp"
        "${PROJECT_SOURCE_DIR}/Src/Core/Thread/ReadWriteLock.cpp"
)
# Header files
set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_HEAD}
        "${PROJECT_SOURCE_DIR}/Src/Core/Thread/Runnable.h"
        "${PROJECT_SOURCE_DIR}/Src/Core/Thread/RunnableBase.h"
        "${PROJECT_SOURCE_DIR}/Src/Core/Thread/Thread.h"
        "${PROJECT_SOURCE_DIR}/Src/Core/Thread/ThreadPool.h"
        "${PROJECT_SOURCE_DIR}/Src/Core/Thread/Mutex.h"
        "${PROJECT_SOURCE_DIR}/Src/Core/Thread/ReadWriteLock.h"
)
# Support
if(${RALFLIGHT_SYSTEM} STREQUAL "RALFLIGHT_SYSTEM_LINUX" OR ${RALFLIGHT_SYSTEM} STREQUAL "RALFLIGHT_SYSTEM_MAC")
    set(THREADS_PREFER_PTHREAD_FLAG ON)
    find_package(Threads REQUIRED)
    set(RALFILGHT_SRC_CORE_LINK ${RALFILGHT_SRC_CORE_LINK} Threads::Threads)
endif()

# Library
add_library(RalFlightCore SHARED ${RALFILGHT_SRC_CORE_SOURCE})
target_link_libraries(RalFlightCore ${RALFILGHT_SRC_CORE_LINK})