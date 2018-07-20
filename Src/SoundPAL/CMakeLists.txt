# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Create: 2018/5/5 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Token
add_definitions(-DRF_SOUNDPAL_BUILD)

# Public depends
# Qt
set(RF_SRC_SOUNDPAL_INCLUDE ${RF_SRC_SOUNDPAL_INCLUDE} ${QT_INCLUDE})
# QtCore
set(RF_SRC_SOUNDPAL_INCLUDE ${RF_SRC_SOUNDPAL_INCLUDE} ${QT_INCLUDE_CORE})
set(RF_SRC_SOUNDPAL_LIBS ${RF_SRC_SOUNDPAL_LIBS} ${QT_LIBS_CORE})

# Format
# Sources
set(RF_SRC_SOUNDPAL_SOURCES ${RF_SRC_SOUNDPAL_SOURCES}
    "${PROJECT_SOURCE_DIR}/Src/SoundPAL/Format/Format.h"
)
# Headers
SET(RF_SRC_SOUNDPAL_HEADERS ${RF_SRC_SOUNDPAL_HEADERS}
    #"${PROJECT_SOURCE_DIR}/Src/SoundPAL/Format/Format.h"
    #"${PROJECT_SOURCE_DIR}/Src/SoundPAL/Format/FormatWav.h"
)

# Library
include_directories(${RF_SRC_SOUNDPAL_INCLUDE})
add_library(RalFlightSoundPAL SHARED ${RF_SRC_SOUNDPAL_SOURCES})
target_link_libraries(RalFlightSoundPAL ${RF_SRC_SOUNDPAL_LIBS})