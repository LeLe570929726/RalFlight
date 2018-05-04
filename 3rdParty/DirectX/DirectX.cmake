# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Create: 2018/3/25 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Config
include("${PROJECT_SOURCE_DIR}/3rdParty/DirectX/DirectXConfig.cmake")

# Check config
if(NOT DIRECTX_INCLUDES_PRIVATE)
    message(FATAL_ERROR "DirectX config missing. Please check DirectX config in 3rdParty/DirectX/DirectXConfig.cmake.")
endif()
if(${DIRECTX_INCLUDES_PRIVATE} STREQUAL "" OR ${DIRECTX_VERSION_PRIVATE} STREQUAL "")
    message(FATAL_ERROR "DirectX config missing. Please check DirectX config in 3rdParty/DirectX/DirectXConfig.cmake.")
endif()
if(${RF_ARCH} STREQUAL "x86")
    if(${DIRECTX_LIBS_PRIVATE_X86} STREQUAL "")
        message(FATAL_ERROR "DirectX config missing. Please check DirectX config in 3rdParty/DirectX/DirectXConfig.cmake.")
    endif()
    set(QT_LIBS_PRIVATE_ROOT ${DIRECTX_LIBS_PRIVATE_X86})
else()
    if(${DIRECTX_LIBS_PRIVATE_X64} STREQUAL "")
        message(FATAL_ERROR "DirectX config missing. Please check DirectX config in 3rdParty/DirectX/DirectXConfig.cmake.")
    endif()
    set(QT_LIBS_PRIVATE_ROOT ${DIRECTX_LIBS_PRIVATE_X64})
endif()

# Version
set(DIRECTX_VERSION ${DIRECTX_VERSION_PRIVATE})

# Include directories
set(DIRECTX_INCLUDE "${DIRECTX_INCLUDES_PRIVATE}/um"
    "${DIRECTX_INCLUDES_PRIVATE}/shared")
set(DIRECTX_INCLUDE_D3D12 "${DIRECTX_INCLUDES_PRIVATE}/um")
set(DIRECTX_INCLUDE_DXGI "${DIRECTX_INCLUDES_PRIVATE}/shared")
set(DIRECTX_INCLUDE_XAUDIO2 "${DIRECTX_INCLUDES_PRIVATE}/um")

# Libraries
set(DIRECTX_LIBS_D3D12 "${QT_LIBS_PRIVATE_ROOT}/d3d12.lib"
    "${QT_LIBS_PRIVATE_ROOT}/d3dcompiler.lib")
set(DIRECTX_LIBS_DXGI "${QT_LIBS_PRIVATE_ROOT}/dxgi.lib")
set(DIRECTX_LIBS_XAUDIO2 "${QT_LIBS_PRIVATE_ROOT}/xaudio2.lib"
    "${QT_LIBS_PRIVATE_ROOT}/xaudio2_8.lib")