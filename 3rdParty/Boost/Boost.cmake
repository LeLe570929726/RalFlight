# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Create: 2018/6/29 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Config
include("${PROJECT_SOURCE_DIR}/3rdParty/Boost/BoostConfig.cmake")

# Check config
if("${BOOST_INCLUDES_PRIVATE}" STREQUAL "")
    message(FATAL_ERROR "Boost config missing. Please check Boost config in 3rdParty/Boost/BoostConfig.cmake.")
endif()
if("${BOOST_INCLUDES_PRIVATE}" STREQUAL "" OR "${BOOST_VERSION_PRIVATE}" STREQUAL "")
    message(FATAL_ERROR "Boost config missing. Please check Boost config in 3rdParty/Boost/BoostConfig.cmake.")
endif()

# Version
set(BOOST_VERSION ${BOOST_VERSION_PRIVATE})

# Include directories
set(BOOST_INCLUDE ${BOOST_INCLUDES_PRIVATE})
set(BOOST_INCLUDE_POOL "${BOOST_INCLUDES_PRIVATE}/pool")