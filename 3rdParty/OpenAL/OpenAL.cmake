# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Create: 2018/5/5 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Config
include("${PROJECT_SOURCE_DIR}/3rdParty/OpenAL/OpenALConfig.cmake")

# Check config
if("${OPENAL_INCLUDES_PRIVATE}" STREQUAL "")
    message(FATAL_ERROR "OpenAL config missing. Please check OpenAL config in 3rdParty/OpenAL/OpenALConfig.cmake.")
endif()
if("${OPENAL_INCLUDES_PRIVATE}" STREQUAL "" OR "${OPENAL_VERSION_PRIVATE}" STREQUAL "")
    message(FATAL_ERROR "OpenAL config missing. Please check OpenAL config in 3rdParty/OpenAL/OpenALConfig.cmake.")
endif()
if(${RF_ARCH} STREQUAL "x86")
    if("${OPENAL_LIBS_PRIVATE_X86}" STREQUAL "")
        message(FATAL_ERROR "OpenAL config missing. Please check OpenAL config in 3rdParty/OpenAL/OpenALConfig.cmake.")
    endif()
    set(OPENAL_LIBS_PRIVATE_ROOT ${OPENAL_LIBS_PRIVATE_X86})
else()
    if("${OPENAL_LIBS_PRIVATE_X64}" STREQUAL "")
        message(FATAL_ERROR "OpenAL config missing. Please check OpenAL config in 3rdParty/OpenAL/OpenALConfig.cmake.")
    endif()
    set(OPENAL_LIBS_PRIVATE_ROOT ${OPENAL_LIBS_PRIVATE_X64})
endif()

# Version
set(OPENAL_VERSION ${OPENAL_VERSION_PRIVATE})

# Include directories
set(OPENAL_INCLUDE ${OPENAL_INCLUDES_PRIVATE})

# Libraries
if(${RF_OS} STREQUAL "RF_OS_WIN")
    set(OPENAL_LIBS "${OPENAL_LIBS_PRIVATE_ROOT}/OpenAL32.lib")
elseif(${RF_OS} STREQUAL "RF_OS_LINUX")
    # TODO
    # set(QT_LIBS_CORE "${QT_LIBS_PRIVATE_ROOT}/libQt5Core.so")
endif()