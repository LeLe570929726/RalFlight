# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Create: 2018/3/23 by LeLe570929726
# ----------------------------------------------------------------------------------------------------
TARGET = RalFlightCore

TEMPLATE = lib
QT += core

# Global Utility
HEADERS += \
    Global/Global.h
DEFINES += RF_BUILD

# Math Utility
SOURCES += \
    Math/Vec2.cpp \
    Math/Vec3.cpp \
    Math/Vec4.cpp \
    Math/Mat2.cpp \
    Math/Mat3.cpp \
    Math/Mat4.cpp \
    Math/MatrixHelper.cpp
HEADERS += \
    Math/Scalar.h \
    Math/Vec2.h \
    Math/Vec3.h \
    Math/Vec4.h \
    Math/Mat2.h \
    Math/Mat3.h \
    Math/Mat4.h \
    Math/MatrixHelper.h