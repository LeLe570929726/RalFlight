# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Craete: 2017/12/1 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Source files
set(RALFILGHT_SRC_CORE_THREAD_SOURCE ${RALFILGHT_SRC_CORE_THREAD_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Thread/Runnable.cpp")
set(RALFILGHT_SRC_CORE_THREAD_SOURCE ${RALFILGHT_SRC_CORE_THREAD_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Thread/RunnableBase.cpp")
set(RALFILGHT_SRC_CORE_THREAD_SOURCE ${RALFILGHT_SRC_CORE_THREAD_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Thread/Thread.cpp")
set(RALFILGHT_SRC_CORE_THREAD_SOURCE ${RALFILGHT_SRC_CORE_THREAD_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Thread/ThreadPool.cpp")
set(RALFILGHT_SRC_CORE_THREAD_SOURCE ${RALFILGHT_SRC_CORE_THREAD_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Thread/Mutex.cpp")
set(RALFILGHT_SRC_CORE_THREAD_SOURCE ${RALFILGHT_SRC_CORE_THREAD_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Thread/ReadWriteLock.cpp")

# Header files
set(RALFILGHT_SRC_CORE_THREAD_HEAD ${RALFILGHT_SRC_CORE_THREAD_HEAD} "${PROJECT_SOURCE_DIR}/Src/Core/Thread/Runnable.h")
set(RALFILGHT_SRC_CORE_THREAD_HEAD ${RALFILGHT_SRC_CORE_THREAD_HEAD} "${PROJECT_SOURCE_DIR}/Src/Core/Thread/RunnableBase.h")
set(RALFILGHT_SRC_CORE_THREAD_HEAD ${RALFILGHT_SRC_CORE_THREAD_HEAD} "${PROJECT_SOURCE_DIR}/Src/Core/Thread/Thread.h")
set(RALFILGHT_SRC_CORE_THREAD_HEAD ${RALFILGHT_SRC_CORE_THREAD_HEAD} "${PROJECT_SOURCE_DIR}/Src/Core/Thread/ThreadPool.h")
set(RALFILGHT_SRC_CORE_THREAD_HEAD ${RALFILGHT_SRC_CORE_THREAD_HEAD} "${PROJECT_SOURCE_DIR}/Src/Core/Thread/Mutex.h")
set(RALFILGHT_SRC_CORE_THREAD_HEAD ${RALFILGHT_SRC_CORE_THREAD_HEAD} "${PROJECT_SOURCE_DIR}/Src/Core/Thread/ReadWriteLock.h")

# Find pthread
if(${RALFLIGHT_SYSTEM} STREQUAL "RALFLIGHT_SYSTEM_LINUX" OR ${RALFLIGHT_SYSTEM} STREQUAL "RALFLIGHT_SYSTEM_MAC")
	set(THREADS_PREFER_PTHREAD_FLAG ON)
	find_package(Threads REQUIRED)
	target_link_libraries(RalFlightCore Threads::Threads)
endif()