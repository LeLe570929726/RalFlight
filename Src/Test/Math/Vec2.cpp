// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2019/7/30 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "../../Core/Math/Vec2.h"
#include "../../Core/Math/Scalar.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(Core_Math_Vec2);

BOOST_AUTO_TEST_CASE(Core_Math_Vec2_Cross_1) {
	Core::Vec2 vecA = { 58.197063f, -3.4893147f };
	Core::Vec2 vecB = { 69.913880f, -0.67728958f };
	Core::real32 scaRes = 204.535264861f;
	BOOST_CHECK_CLOSE_FRACTION(vecA.cross(vecB), scaRes, 0.0001f);
}

BOOST_AUTO_TEST_CASE(Core_Math_Vec2_Angle_1) {
	Core::Vec2 vecA = { -480.198072f, 33.1824120f };
	Core::Vec2 vecB = { 0.661884238f, -1.64497582f };
	Core::real32 scaRes = 2.02233;
	auto tmp = vecA.angle(vecB);
	BOOST_CHECK_CLOSE_FRACTION(vecA.angle(vecB), scaRes, 0.0001f);
}

BOOST_AUTO_TEST_CASE(Core_Math_Vec2_Project_1) {
	Core::Vec2 vecA = { -480.198072f, 33.1824120f };
	Core::Vec2 vecB = { 0.661884238f, -1.64497582f };
	Core::real32 scaRes = 2.02233;
	auto tmp = vecA.angle(vecB);
	BOOST_CHECK_CLOSE_FRACTION(vecA.angle(vecB), scaRes, 0.0001f);
}

BOOST_AUTO_TEST_SUITE_END();