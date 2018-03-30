# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Create: 2018/3/25 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Headers
set(DIRECTX_INCLUDE "${PROJECT_SOURCE_DIR}/3rdParty/DirectX/Include")

# Version
set(DIRECTX_VERSION "10.0.16299.0")

# Libraries
if(${RF_ARCH} STREQUAL "x86")
    set(DIRECTX_LIBS ${DIRECTX_LIBS}
        "${PROJECT_SOURCE_DIR}/3rdParty/DirectX/Libs/x86/d3d12.lib"
        "${PROJECT_SOURCE_DIR}/3rdParty/DirectX/Libs/x86/d3dcompiler.lib"
        "${PROJECT_SOURCE_DIR}/3rdParty/DirectX/Libs/x86/dxgi.lib"
    )
elseif(${RF_ARCH} STREQUAL "x64")
    set(DIRECTX_LIBS ${DIRECTX_LIBS}
        "${PROJECT_SOURCE_DIR}/3rdParty/DirectX/Libs/x64/d3d12.lib"
        "${PROJECT_SOURCE_DIR}/3rdParty/DirectX/Libs/x64/d3dcompiler.lib"
        "${PROJECT_SOURCE_DIR}/3rdParty/DirectX/Libs/x64/dxgi.lib"
    )
endif()