# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
# 
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Create: 2018/6/29 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Include config
include("${PROJECT_SOURCE_DIR}/3rdParty/Boost/BoostConfig.cmake")

# Find Boost
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS 
  locale
  filesystem
)