# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Create: 2018/3/30 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Header
if(${RF_OS} STREQUAL "RF_OS_WIN")
    set(VULKAN_INCLUDE "${PROJECT_SOURCE_DIR}/3rdParty/Vulkan/Windows/Include")
elseif(${RF_OS} STREQUAL "RF_OS_LINUX")
    # Todo
endif()

# Version
if(${RF_OS} STREQUAL "RF_OS_WIN")
    set(VULKAN_VERSION "1.1.70.1")
elseif(${RF_OS} STREQUAL "RF_OS_LINUX")
    # Todo
endif()

# Libraries
if(${RF_OS} STREQUAL "RF_OS_WIN")
    if(${RF_ARCH} STREQUAL "x86")
        set(DIRECTX_LIBS ${DIRECTX_LIBS}
            "${PROJECT_SOURCE_DIR}/3rdParty/Vulkan/Windows/Libs/x86/vulkan-1.lib"
        )
    elseif(${RF_ARCH} STREQUAL "x64")
        set(DIRECTX_LIBS ${DIRECTX_LIBS}
            "${PROJECT_SOURCE_DIR}/3rdParty/Vulkan/Windows/Libs/x64/vulkan-1.lib"
        )
    endif()
elseif(${RF_OS} STREQUAL "RF_OS_LINUX")
    # Todo
endif()