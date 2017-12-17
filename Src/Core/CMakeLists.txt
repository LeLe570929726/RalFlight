# ----------------------------------------------------------------------------------------------------
# Copyright © 2016-2017 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Craete: 2016/12/10 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Global
add_subdirectory("${PROJECT_SOURCE_DIR}/Src/Core/Global")

# STL
add_subdirectory("${PROJECT_SOURCE_DIR}/Src/Core/STL")

# Math
add_subdirectory("${PROJECT_SOURCE_DIR}/Src/Core/Math")

# Thread
add_subdirectory("${PROJECT_SOURCE_DIR}/Src/Core/Thread")

# Plugin
# set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Plugin/LibraryLoader/LibraryLoader.h")
# set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Plugin/LibraryLoader/LibraryLoader.cpp")
# set(RALFILGHT_SRC_CORE_HEAD ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Plugin/PluginLoader/PluginLoader.h")
# set(RALFILGHT_SRC_CORE_SOURCE ${RALFILGHT_SRC_CORE_SOURCE} "${PROJECT_SOURCE_DIR}/Src/Core/Plugin/PluginLoader/PluginLoader.cpp")