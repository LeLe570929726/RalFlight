# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Create: 2018/3/30 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Config
include("${PROJECT_SOURCE_DIR}/3rdParty/Vulkan/VulkanConfig.cmake")

# Check config
if("${VULKAN_INCLUDES_PRIVATE}" STREQUAL "")
    message(FATAL_ERROR "Vulkan config missing. Please check Vulkan config in 3rdParty/Vulkan/VulkanConfig.cmake.")
endif()
if("${VULKAN_INCLUDES_PRIVATE}" STREQUAL "" OR "${VULKAN_VERSION_PRIVATE}" STREQUAL "")
    message(FATAL_ERROR "Vulkan config missing. Please check Vulkan config in 3rdParty/Vulkan/VulkanConfig.cmake.")
endif()
if(${RF_ARCH} STREQUAL "x86")
    if("${VULKAN_LIBS_PRIVATE_X86}" STREQUAL "")
        message(FATAL_ERROR "Vulkan config missing. Please check Vulkan config in 3rdParty/Vulkan/VulkanConfig.cmake.")
    endif()
    set(VULKAN_LIBS_PRIVATE_ROOT ${VULKAN_LIBS_PRIVATE_X86})
else()
    if("${VULKAN_LIBS_PRIVATE_X64}" STREQUAL "")
        message(FATAL_ERROR "Vulkan config missing. Please check Vulkan config in 3rdParty/Vulkan/VulkanConfig.cmake.")
    endif()
    set(VULKAN_LIBS_PRIVATE_ROOT ${VULKAN_LIBS_PRIVATE_X64})
endif()

# Version
set(VULKAN_VERSION ${VULKAN_VERSION_PRIVATE})

# Include directories
set(VULKAN_INCLUDE ${VULKAN_INCLUDES_PRIVATE})

# Libraries
if(${RF_OS} STREQUAL "RF_OS_WIN")
    set(VULKAN_LIBS "${VULKAN_LIBS_PRIVATE_ROOT}/vulkan-1.lib")
elseif(${RF_OS} STREQUAL "RF_OS_LINUX")
    # TODO
    # set(QT_LIBS_CORE "${QT_LIBS_PRIVATE_ROOT}/libQt5Core.so")
endif()