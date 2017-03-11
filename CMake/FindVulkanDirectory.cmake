# ----------------------------------------------------------------------------------------------------
# Copyright © 2016-2017 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Craete: 2017/1/15 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Check the local system
if((${CMAKE_SYSTEM_NAME} STREQUAL "Linux") OR (${CMAKE_SYSTEM_NAME} STREQUAL "Windows"))
    # Check the environment variable
    if(DEFINED ENV{VULKAN_SDK})
        # Check the include path
        find_path(VULKAN_PATH_INCLUDE_ROOT "vulkan.h" PATHS "$ENV{VULKAN_SDK}/Include/vulkan")
        if(${VULKAN_PATH_INCLUDE_ROOT} MATCHES "VULKAN_PATH_INCLUDE_ROOT-NOTFOUND")
            set(VULKAN_FAILD 3)
        else()
            set(VULKAN_PATH_INCLUDE "$ENV{VULKAN_SDK}/Include/vulkan")
            # Check the lib(x86) path
            find_path(VULKAN_PATH_LIB_X86_ROOT "vulkan-1.lib" PATHS "$ENV{VULKAN_SDK}/Bin32")
            if(${VULKAN_PATH_LIB_X86_ROOT} MATCHES "VULKAN_PATH_LIB_X86_ROOT-NOTFOUND")
                set(VULKAN_FAILD 4)
            else()
                set(VULKAN_PATH_LIB_X86 "$ENV{VULKAN_SDK}/Bin32")
                # Check the lib(x64) path
                find_path(VULKAN_PATH_LIB_X64_ROOT "vulkan-1.lib" PATHS "$ENV{VULKAN_SDK}/Bin")
                if(VULKAN_PATH_LIB_X64_ROOT MATCHES "VULKAN_PATH_LIB_X64_ROOT-NOTFOUND")
                    set(VULKAN_FAILD 5)
                else()
                    set(VULKAN_PATH_LIB_X64 "$ENV{VULKAN_SDK}/Bin")
                    set(VULKAN_FAILD 0)
                endif()
            endif()
        endif()
    else()
        set(VULKAN_FAILD 2)
    endif()
else()
    set(VULKAN_FAILD 1)
endif()