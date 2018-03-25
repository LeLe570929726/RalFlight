# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Create: 2018/3/25 by LeLe570929726
# ----------------------------------------------------------------------------------------------------
TEMPLATE = aux

TARGET = DirectX

INCLUDEPATH += Include

contains(QMAKE_HOST.arch, x86_64) {
    LIBS += \
        Libs/x64/d3d12.lib \
        Libs/x64/d3dcompiler.lib \
        Libs/x64/dxgi.lib
}
contains(QMAKE_HOST.arch, x86_64) {
    LIBS += \
        Libs/x86/d3d12.lib \
        Libs/x86/d3dcompiler.lib \
        Libs/x86/dxgi.lib
}