# ----------------------------------------------------------------------------------------------------
# Copyright © 2016-2017 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Craete: 2016/12/31 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Include macro
include("CMake/Macro.cmake")

# Check the local system
if((${CMAKE_SYSTEM_NAME} STREQUAL "Windows") AND (${CMAKE_SYSTEM_VERSION} MATCHES "10\.[0-9]+\.[0-9]+"))
	# Get all subdir in include directory
	string(REPLACE "\\" "/" DIRECTX_12_ROOT_DIR "$ENV{ProgramFiles\(x86\)}")
	list_subdir(DIRECTX_12_SUBDIR_LIST	"${DIRECTX_12_ROOT_DIR}/Windows Kits/10/Include")
	set(DIRECTX_12_AVAILABLE_PATH "")
	foreach(DIRECTX_12_SUBDIR_LIST_ITEM ${DIRECTX_12_SUBDIR_LIST})
		find_path(DIRECTX_12_IS_PATH_INCLUDE "um/d3d12.h" PATHS 
			"${DIRECTX_12_ROOT_DIR}/Windows Kits/10/Include/${DIRECTX_12_SUBDIR_LIST_ITEM}")
		find_path(DIRECTX_12_IS_PATH_LIB_X86 "um/x86/d3d12.lib" PATHS 
			"${DIRECTX_12_ROOT_DIR}/Windows Kits/10/Lib/${DIRECTX_12_SUBDIR_LIST_ITEM}")
		find_path(DIRECTX_12_IS_PATH_LIB_X64 "um/x64/d3d12.lib" PATHS 
			"${DIRECTX_12_ROOT_DIR}/Windows Kits/10/Lib/${DIRECTX_12_SUBDIR_LIST_ITEM}")
		if(${DIRECTX_12_IS_PATH_INCLUDE} MATCHES "DIRECTX_12_IS_PATH_INCLUDE-NOTFOUND")
			set(DIRECTX_12_FAILD 1)
		elseif(${DIRECTX_12_IS_PATH_LIB_X86} MATCHES "DIRECTX_12_IS_PATH_LIB_X86-NOTFOUND")
			set(DIRECTX_12_FAILD 2)
		elseif(${DIRECTX_12_IS_PATH_LIB_X64} MATCHES "DIRECTX_12_IS_PATH_LIB_X64-NOTFOUND")
			set(DIRECTX_12_FAILD 3)
		else()
			set(DIRECTX_12_PATH_INCLUDE "${DIRECTX_12_ROOT_DIR}/Windows Kits/10/Include/${DIRECTX_12_SUBDIR_LIST_ITEM}/um")
			set(DIRECTX_12_PATH_LIB_X86 "${DIRECTX_12_ROOT_DIR}/Windows Kits/10/Include/${DIRECTX_12_SUBDIR_LIST_ITEM}/um/x86")
			set(DIRECTX_12_PATH_LIB_X64 "${DIRECTX_12_ROOT_DIR}/Windows Kits/10/Include/${DIRECTX_12_SUBDIR_LIST_ITEM}/um/x64")
			set(DIRECTX_12_FAILD 0)
		endif()
	endforeach()
else()
    set(DIRECTX_12_FAILD 4)
endif()