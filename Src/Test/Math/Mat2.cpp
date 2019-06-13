// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2019/4/13 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#define BOOST_TEST_MODULE Core_Math_Mat2
#include "../../Core/Math/Mat2.h"
#include "../../Core/Math/Scalar.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(add_1) {
	Core::Mat2 matA = { 185.472f, 26.2021f, 5.0264f, 2313.03f };
	Core::Mat2 matB = { 15.3822f, 1.02791f, -411.15f, 22.7172f };
	Core::Mat2 matRes = { 200.8542f, 27.23001f, -406.1236f, 2335.7472f };
	matA.add(matB);
	for (Core::uint8 i = 1; i < 3; ++i) {
		for (Core::uint8 j = 1; j < 3; ++j) {
			BOOST_CHECK_CLOSE_FRACTION(matA.get(i, j), matRes.get(i, j), 0.0001f);
		}
	}
}

BOOST_AUTO_TEST_CASE(add_2) {
	Core::Mat2 matA = { 708.54133f, -2.1164375f, 95.56369f, 5975.7826f };
	Core::Mat2 matB = { -0.93448995f, 702.29087f, 0.0f, 0.0000001986f };
	Core::Mat2 matRes = { 707.60684005f, 700.1744325f, 95.56369f, 5975.7826001986f };
	matA.add(matB);
	for (Core::uint8 i = 1; i < 3; ++i) {
		for (Core::uint8 j = 1; j < 3; ++j) {
			BOOST_CHECK_CLOSE_FRACTION(matA.get(i, j), matRes.get(i, j), 0.0001f);
		}
	}
}

BOOST_AUTO_TEST_CASE(sub_1) {
	Core::Mat2 matA = { 87.0158f, 5.9636f, -544.745f, 250.835f };
	Core::Mat2 matB = { -83.4974f, 3913.88f, 42.7572f, 2.05796f };
	Core::Mat2 matRes = { 170.5132f, -3907.9164f, -587.5022f, 248.77704f };
	matA.sub(matB);
	for (Core::uint8 i = 1; i < 3; ++i) {
		for (Core::uint8 j = 1; j < 3; ++j) {
			BOOST_CHECK_CLOSE_FRACTION(matA.get(i, j), matRes.get(i, j), 0.0001f);
		}
	}
}

BOOST_AUTO_TEST_CASE(sub_2) {
	Core::Mat2 matA = { 87.0158f, 5.9636f, -544.745f, 250.835f };
	Core::Mat2 matB = { -83.4974f, 3913.88f, 42.7572f, 2.05796f };
	Core::Mat2 matRes = { 170.5132f, -3907.9164f, -587.5022f, 248.77704f };
	matA.sub(matB);
	for (Core::uint8 i = 1; i < 3; ++i) {
		for (Core::uint8 j = 1; j < 3; ++j) {
			BOOST_CHECK_CLOSE_FRACTION(matA.get(i, j), matRes.get(i, j), 0.0001f);
		}
	}
}

BOOST_AUTO_TEST_CASE(mul_1) {
	Core::Mat2 matA = { 1.80848f, 93.7121f, -3.8096f, 654.432f };
	Core::real32 scalar = 88.9078f;
	Core::Mat2 matRes = { 160.787978144f, 8331.7277536f, -338.704043958f, 58184.1093696f };
	matA.mul(scalar);
	for (Core::uint8 i = 1; i < 3; ++i) {
		for (Core::uint8 j = 1; j < 3; ++j) {
			BOOST_CHECK_CLOSE_FRACTION(matA.get(i, j), matRes.get(i, j), 0.0001f);
		}
	}
}

// TODO: mul 2

BOOST_AUTO_TEST_CASE(mul_3) {
	Core::Mat2 matA = { 0.74969375f, -3988.0421f, 98.233047f, -6.286618f };
	Core::Vec2 vecA = { 0.086706445f, -4858.0868f };
	Core::Vec2 vecRes = { 19374254.7488f, 30549.4533607f };
	matA.mul(vecA);
	BOOST_CHECK_CLOSE_FRACTION(vecRes.x(), vecRes.x(), 0.0001f);
	BOOST_CHECK_CLOSE_FRACTION(vecRes.y(), vecRes.y(), 0.0001f);
}

// TODO: mul 4()

BOOST_AUTO_TEST_CASE(mul_5) {
	Core::Mat2 matA = { 0.13851f, 11.8271f, 1.54060f, 267.4f };
	Core::Mat2 matB = { 4.913f, 2.18543f, 128.62f, 1.39161f };
	Core::Mat2 matRes = { 1521.88210163f, 16.7614145403f, 34400.5569678f, 375.483387458f };
	matA.mul(matB);
	for (Core::uint8 i = 1; i < 3; ++i) {
		for (Core::uint8 j = 1; j < 3; ++j) {
			BOOST_CHECK_CLOSE_FRACTION(matA.get(i, j), matRes.get(i, j), 0.0001f);
		}
	}
}

BOOST_AUTO_TEST_CASE(div_1) {
	Core::Mat2 matA = { -67.95097f, 382.7131f, 5.040021f, 0.9791835f };
	Core::real32 scalar = 8.565392f;
	Core::Mat2 matRes = { -7.93320025f, 44.6813292f, 0.588416852f, 0.114318585f };
	matA.div(scalar);
	for (Core::uint8 i = 1; i < 3; ++i) {
		for (Core::uint8 j = 1; j < 3; ++j) {
			BOOST_CHECK_CLOSE_FRACTION(matA.get(i, j), matRes.get(i, j), 0.0001f);
		}
	}
}

BOOST_AUTO_TEST_CASE(div_2) {
	Core::Mat2 matA = { 0.3146189f, 9.674551f, -27.56971f, 45.56928f };
	Core::real32 scalar = -97.40945f;
	Core::Mat2 matRes = { -0.00322986014f, -0.0993184028f, 0.283029110f, -0.467811695f };
	matA.div(scalar);
	for (Core::uint8 i = 1; i < 3; ++i) {
		for (Core::uint8 j = 1; j < 3; ++j) {
			BOOST_CHECK_CLOSE_FRACTION(matA.get(i, j), matRes.get(i, j), 0.0001f);
		}
	}
}