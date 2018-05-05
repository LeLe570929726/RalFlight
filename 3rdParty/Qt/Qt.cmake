# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Create: 2018/4/6 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Config
include("${PROJECT_SOURCE_DIR}/3rdParty/Qt/QtConfig.cmake")

# Check config
if("${QT_INCLUDES_PRIVATE}" STREQUAL "")
    message(FATAL_ERROR "Qt config missing. Please check Qt config in 3rdParty/Qt/QtConfig.cmake.")
endif()
if("${QT_INCLUDES_PRIVATE}" STREQUAL "" OR "${QT_VERSION_PRIVATE}" STREQUAL "")
    message(FATAL_ERROR "Qt config missing. Please check Qt config in 3rdParty/Qt/QtConfig.cmake.")
endif()
if(${RF_ARCH} STREQUAL "x86")
    if("${QT_LIBS_PRIVATE_X86}" STREQUAL "")
        message(${RF_ARCH})
        message(FATAL_ERROR "Qt config missing. Please check Qt config in 3rdParty/Qt/QtConfig.cmake.")
    endif()
    set(QT_LIBS_PRIVATE_ROOT ${QT_LIBS_PRIVATE_X86})
else()
    if("${QT_LIBS_PRIVATE_X64}" STREQUAL "")
        message(FATAL_ERROR "Qt config missing. Please check Qt config in 3rdParty/Qt/QtConfig.cmake.")
    endif()
    set(QT_LIBS_PRIVATE_ROOT ${QT_LIBS_PRIVATE_X64})
endif()

# Version
set(QT_VERSION ${QT_VERSION_PRIVATE})

# Include directories
set(QT_INCLUDE ${QT_INCLUDES_PRIVATE})
set(QT_INCLUDE_CORE "${QT_INCLUDES_PRIVATE}/QtCore")
set(QT_INCLUDE_GUI "${QT_INCLUDES_PRIVATE}/QtGui")

# Libraries
if(${RF_OS} STREQUAL "RF_OS_WIN")
    set(QT_LIBS_CORE "${QT_LIBS_PRIVATE_ROOT}/Qt5Core.lib")
    set(QT_LIBS_GUI "${QT_LIBS_PRIVATE_ROOT}/Qt5Gui.lib")
elseif(${RF_OS} STREQUAL "RF_OS_LINUX")
    set(QT_LIBS_CORE "${QT_LIBS_PRIVATE_ROOT}/libQt5Core.so")
    set(QT_LIBS_GUI "${QT_LIBS_PRIVATE_ROOT}/libQt5Gui.so")
endif()