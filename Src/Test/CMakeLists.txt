# ----------------------------------------------------------------------------------------------------
# Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
#
# @Project: RalFlight
# @License: Licensed under GNU General Public License v3.
# @Description: A free and open-source flight simulator.
#
# @Create: 2019/4/13 by LeLe570929726
# ----------------------------------------------------------------------------------------------------

# Token
add_definitions(-DRF_TEST_BUILD)

# Public dependences
# Dependence's directory
set(RF_SRC_TEST_DEPENDENCES_INCLUDE ${RF_SRC_TEST_DEPENDENCES_INCLUDE})
# Boost
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.65 REQUIRED COMPONENTS
    unit_test_framework
)
set(RF_SRC_TEST_DEPENDENCES_INCLUDE ${RF_SRC_TEST_DEPENDENCES_INCLUDE} ${Boost_INCLUDE_DIR})

# Math
# Sources
set(RF_SRC_CORE_TEST_MATH_SOURCES ${RF_SRC_CORE_TEST_MATH_SOURCES}
	"Math/Module.cpp"
	"Math/Vec2.cpp"
    "Math/Mat2.cpp"
	"Math/Mat3.cpp"
	"Math/Mat4.cpp"
)

# Executable
add_executable(RalFlightTestMath ${RF_SRC_CORE_TEST_MATH_SOURCES})
target_link_libraries(RalFlightTestMath
    RalFlightCore Boost::boost Boost::unit_test_framework
)
set_target_properties(RalFlightTestMath PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES ${RF_SRC_TEST_DEPENDENCES_INCLUDE}
)