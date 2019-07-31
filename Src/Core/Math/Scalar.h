// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2016/12/6 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"
#include <cmath>
#include <cstdint>
#include <cassert>
#include <type_traits>
#if defined(RF_OS_WIN)
#include <intrin.h>
#elif defined(RF_OS_LINUX)
#include <xmmintrin.h>
#endif

namespace Core {

using int8 = std::int8_t;
using int16 = std::int16_t;
using int32 = std::int32_t;
using int64 = std::int64_t;

using uint8 = std::uint8_t;
using uint16 = std::uint16_t;
using uint32 = std::uint32_t;
using uint64 = std::uint64_t;

using real32 = float;
using real64 = double;

class RF_API_TEMPLATE Scalar {
public:
	Scalar() = delete;
	Scalar(const Scalar &other) = delete;
	Scalar &operator=(const Scalar &other) = delete;
	~Scalar() = delete;

public:
	template <class T, typename std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, int> = 0>
	static T abs(T scalar) {
		return static_cast<T>(std::abs(static_cast<double>(scalar)));
	}
	template <class T, typename std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, int> = 0>
	static T cos(T scalar) {
		return static_cast<T>(std::cos(static_cast<double>(scalar)));
	}
	template <class T, typename std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, int> = 0>
	static T sin(T scalar) {
		return static_cast<T>(std::cos(static_cast<double>(scalar)));
	}
	template <class T, typename std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, int> = 0>
	static T tan(T scalar) {
		return static_cast<T>(std::tan(static_cast<double>(scalar)));
	}
	template <class T, typename std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, int> = 0>
	static T acos(T scalar) {
		assert(scalar >= -1 && scalar <= 1);
		return static_cast<T>(std::acos(static_cast<double>(scalar)));
	}
	template <class T, typename std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, int> = 0>
	static T asin(T scalar) {
		assert(scalar >= -1 && scalar <= 1);
		return static_cast<T>(std::asin(static_cast<double>(scalar)));
	}
	template <class T, typename std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, int> = 0>
	static T atan(T scalar) {
		return static_cast<T>(std::atan(static_cast<double>(scalar)));
	}
	template <class T, typename std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, int> = 0>
	static T atan2(T scalarX, T scalarY) {
		assert(scalarY);
		return static_cast<T>(std::atan2(static_cast<double>(scalarX), static_cast<double>(scalarY)));
	}
	template <class T, typename std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, int> = 0>
	static T pow(T scalarBase, T scalarExp) {
		return static_cast<T>(std::pow(static_cast<double>(scalarBase), static_cast<double>(scalarExp)));
	}
	template <class T, typename std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, int> = 0>
	static T sqrt(T scalar) {
		assert(scalar >= 0);
		return static_cast<T>(std::sqrt(static_cast<double>(scalar)));
	}
	template <class T, typename std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, int> = 0>
	static T rsqrt(T scalar) {
		assert(scalar >= 0);
		auto tmpSca = static_cast<real32>(scalar);
		__m128 sseA, sseRes;
		sseA = _mm_broadcast_ss(&tmpSca);
		sseRes = _mm_rsqrt_ss(sseA);
		_mm_store_ss(&tmpSca, sseRes);
		return static_cast<T>(tmpSca);
	}
	template <class T, typename std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, int> = 0>
	static T ln(T scalar) {
		assert(scalar > 0);
		return static_cast<T>(std::log(static_cast<double>(scalar)));
	}
	template <class T, typename std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, int> = 0>
	static T log10(T scalar) {
		assert(scalar > 0);
		return static_cast<T>(std::log10(static_cast<double>(scalar)));
	}
	template <class T, typename std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, int> = 0>
	static T log2(T scalar) {
		assert(scalar > 0);
		return static_cast<T>(std::log2(static_cast<double>(scalar)));
	}
	template <class T, typename std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, int> = 0>
	static T log(T scalarBase, T scalarAnti) {
		assert(scalarBase > 0);
		assert(scalarAnti > 0);
		return static_cast<T>(Scalar::ln(static_cast<double>(scalarAnti)) / Scalar::ln(static_cast<double>(scalarBase)));
	}
	template <class T, typename std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, int> = 0>
	static T degreeToRadian(T scalar) {
		return static_cast<T>(Scalar::DegreeToRadian * static_cast<double>(scalar));
	}
	template <class T, typename std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, int> = 0>
	static T radianToDegree(T scalar) {
		return static_cast<T>(Scalar::RadianToDegree * static_cast<double>(scalar));
	}

public:
	static const real64 Pi;
	static const real64 E;

private:
	static const real64 DegreeToRadian;	  // Pi / 180
	static const real64 RadianToDegree;   // 180 / P
};

} // namespace Core
