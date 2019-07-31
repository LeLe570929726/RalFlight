# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
#
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Create: 2018/3/25 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Token
add_definitions(-DRF_CORE_BUILD)

# Compile options
set(RF_SRC_CORE_COMPILE_OPTIONS ${RF_SRC_CORE_COMPILE_OPTIONS})

# Public dependences
# Dependence's directory
set(RF_SRC_CORE_DEPENDENCES_INCLUDE ${RF_SRC_CORE_DEPENDENCES_INCLUDE})
# Boost
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.65 REQUIRED COMPONENTS
    locale
    filesystem
)
set(RF_SRC_CORE_DEPENDENCES_INCLUDE ${RF_SRC_CORE_DEPENDENCES_INCLUDE} ${Boost_INCLUDE_DIR})

# Global
configure_file("Global/Global.in.h" "Global/Global.h")
configure_file("Global/VersionInfo.in.h" "Global/VersionInfo.h")

# Container
# Sources
set(RF_SRC_CORE_SOURCES ${RF_SRC_CORE_SOURCES}
)
# Headers
set(RF_SRC_CORE_HEADERS ${RF_SRC_CORE_HEADERS}
    "Container/List.h"
    "Container/Vector.h"
    "Container/LockFreeQueue.h"
)

# Memory
# Sources
set(RF_SRC_CORE_SOURCES ${RF_SRC_CORE_SOURCES}
)
# Headers
set(RF_SRC_CORE_HEADERS ${RF_SRC_CORE_HEADERS}
    "Memory/UniquePointer.h"
)

# Math
# Sources
set(RF_SRC_CORE_SOURCES ${RF_SRC_CORE_SOURCES}
	"Math/Scalar.cpp"
    "Math/Vec2.cpp"
    "Math/Vec3.cpp"
    "Math/Vec4.cpp"
    "Math/Mat2.cpp"
    "Math/Mat3.cpp"
    "Math/Mat4.cpp"
    "Math/MatrixHelper.cpp"
)
# Headers
set(RF_SRC_CORE_HEADERS ${RF_SRC_CORE_HEADERS}
    "Math/Scalar.h"
    "Math/Vec2.h"
    "Math/Vec3.h"
    "Math/Vec4.h"
    "Math/Mat2.h"
    "Math/Mat3.h"
    "Math/Mat4.h"
    "Math/MatrixHelper.h"
)
# Dependences
if(${RF_OS} STREQUAL "RF_OS_WIN")
    set(RF_SRC_CORE_COMPILE_OPTIONS ${RF_SRC_CORE_COMPILE_OPTIONS} /arch:AVX /arch:AVX2)
elseif(${RF_OS} STREQUAL "RF_OS_LINUX")
    set(RF_SRC_CORE_COMPILE_OPTIONS ${RF_SRC_CORE_COMPILE_OPTIONS} -msse)
endif()

# String
# Sources
set(RF_SRC_CORE_SOURCES ${RF_SRC_CORE_SOURCES}
    "String/Convertor.cpp"
    "String/Char.cpp"
    "String/CharReference.cpp"
    "String/String.cpp"
    "String/StringIterator.cpp"
    "String/ConstStringIterator.cpp"
)
# Headers
set(RF_SRC_CORE_HEADERS ${RF_SRC_CORE_HEADERS}
    "String/Convertor.h"
    "String/Char.h"
    "String/CharReference.h"
    "String/String.h"
    "String/StringIterator.h"
    "String/ConstStringIterator.h"
)

# FileSystem
# Sources
set(RF_SRC_CORE_SOURCES ${RF_SRC_CORE_SOURCES}
    "FileSystem/Path.cpp"
    "FileSystem/File.cpp"
    "FileSystem/PathStatus.cpp"
    "FileSystem/Directory.cpp"
)
# Headers
set(RF_SRC_CORE_HEADERS ${RF_SRC_CORE_HEADERS}
    "FileSystem/Path.h"
    "FileSystem/File.h"
    "FileSystem/PathStatus.h"
    "FileSystem/Directory.h"
)

# Log
# Sources
set(RF_SRC_CORE_SOURCES ${RF_SRC_CORE_SOURCES}
    #"Log/Log.cpp"
    #"Log/StackTracer.cpp"
)
# Headers
set(RF_SRC_CORE_HEADERS ${RF_SRC_CORE_HEADERS}
    #"Log/Log.h"
    #"Log/StackTracer.h"
)

# Library
add_library(RalFlightCore SHARED ${RF_SRC_CORE_SOURCES})
target_link_libraries(RalFlightCore
    Boost::boost Boost::locale Boost::filesystem
)
set_target_properties(RalFlightCore PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES ${RF_SRC_CORE_DEPENDENCES_INCLUDE}
)
target_compile_options(RalFlightCore PRIVATE ${RF_SRC_CORE_COMPILE_OPTIONS})