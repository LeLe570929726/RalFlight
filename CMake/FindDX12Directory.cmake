# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Craete: 2016/12/31 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Check the local system
if((${CMAKE_SYSTEM_NAME} STREQUAL "Windows") AND (${CMAKE_SYSTEM_VERSION} MATCHES "10\.[0-9]+\.[0-9]+"))
	# Find include path
	find_path(DIRECTX_12_PATH_INCLUDE_ROOT "um/d3d12.h" PATHS "$ENV{ProgramFiles}/Windows Kits/10/Include/10.0.10150.0"
		"$ENV{ProgramFiles}/Windows Kits/10/Include/10.0.10240.0" "$ENV{ProgramFiles}/Windows Kits/10/Include/10.0.10586.0")
	if(${DIRECTX_12_PATH_INCLUDE_ROOT} MATCHES "DIRECTX_12_PATH_INCLUDE-NOTFOUND")
		set(DIRECTX_12_FAILD 2)
	else()
		set(DIRECTX_12_PATH_INCLUDE "${DIRECTX_12_PATH_INCLUDE_ROOT}/um" "${DIRECTX_12_PATH_INCLUDE_ROOT}/shared")
		# Find lib(x86) path
		find_path(DIRECTX_12_PATH_LIB_X86_ROOT "um/x86/d3d12.lib" PATHS "$ENV{ProgramFiles}/Windows Kits/10/Lib/10.0.10150.0"
			"$ENV{ProgramFiles}/Windows Kits/10/Lib/10.0.10240.0" "$ENV{ProgramFiles}/Windows Kits/10/Lib/10.0.10586.0")
		if(${DIRECTX_12_PATH_LIB_X86_ROOT} MATCHES "DIRECTX_12_PATH_LIB_X86_ROOT-NOTFOUND")
			set(DIRECTX_12_FAILD 3)
		else()
			set(DIRECTX_12_PATH_LIB_X86 "${DIRECTX_12_PATH_LIB_X86_ROOT}/um/x86")
			# Find lib(x64) path
			find_path(DIRECTX_12_PATH_LIB_X64_ROOT "um/x64/d3d12.lib" PATHS "$ENV{ProgramFiles}/Windows Kits/10/Lib/10.0.10150.0"
				"$ENV{ProgramFiles}/Windows Kits/10/Lib/10.0.10240.0" "$ENV{ProgramFiles}/Windows Kits/10/Lib/10.0.10586.0")
			if(${DIRECTX_12_PATH_LIB_X64_ROOT} MATCHES "DIRECTX_12_PATH_LIB_X64_ROOT-NOTFOUND")
				set(DIRECTX_12_FAILD 4)
			else()
				set(DIRECTX_12_PATH_LIB_X64 "${DIRECTX_12_PATH_LIB_X64_ROOT}/um/x64")
				set(DIRECTX_12_FAILD 0)
			endif()
		endif()
	endif()
else()
    set(DIRECTX_12_FAILD 1)
endif()