// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2019/6/24 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "../../Core/Math/Mat4.h"
#include "../../Core/Math/Scalar.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(Core_Math_Mat4);

BOOST_AUTO_TEST_CASE(Core_Math_Mat4_Mul_5) {
	Core::Mat4 matA = { 39.960573f,   -2194.44363f, 0.505245911f, 8.10687704f, -32047.2288f, 68.2740270f,
						-551.562246f, -17.8175706f, 428822.846f,  2.48021670f, -60.4490367f, 0.0111602932f,
						67276926.2f,  -89976438.9,  3.30548558f,  2.03580777f };
	Core::Mat4 matB = { -1005848.58f, 8.01575588f,  0.698062847f, 84.3916908f,  -0.415146824f, -516.633953f,
						9748.40374f,  -20.7782684f, 5.15812180f,  0.034995064f, -2263.16989f,  491080.144f,
						-2604555.10f, 95.2951006f,  866.353247f,  0.0738167588f };
	Core::Mat4 matRes = { -61308179.9252f,		 1134816.9647f,		-21386414.6330f,	 297085.9122f,
						  32281063552.4219f,	 -293872.6722f,		1876034.5578f,		 -273567206.9458f,
						  -431330880101.0903f,   3436056.8332f,		460339.5589f,		 6503711.8465f,
						  -67670368633958.4117f, 47024158916.6641f, -877079695679.1476f, 7548791409.4701f };
	matA.mul(matB);
	for (Core::uint8 i = 1; i < 5; ++i) {
		for (Core::uint8 j = 1; j < 5; ++j) {
			BOOST_CHECK_CLOSE_FRACTION(matA.get(i, j), matRes.get(i, j), 0.0001f);
		}
	}
}

BOOST_AUTO_TEST_SUITE_END();