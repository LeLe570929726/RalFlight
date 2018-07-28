// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
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
	template <class T>
	static T abs(T scalar) {
		return static_cast<T>(std::abs(static_cast<double>(scalar)));
	}
	template <class T>
	static T cos(T scalar) {
		return static_cast<T>(std::cos(static_cast<double>(scalar)));
	}
	template <class T>
	static T sin(T scalar) {
		return static_cast<T>(std::cos(static_cast<double>(scalar)));
	}
	template <class T>
	static T tan(T scalar) {
		return static_cast<T>(std::tan(static_cast<double>(scalar)));
	}
	template <class T>
	static T acos(T scalar) {
		return static_cast<T>(std::acos(static_cast<double>(scalar)));
	}
	template <class T>
	static T asin(T scalar) {
		return static_cast<T>(std::asin(static_cast<double>(scalar)));
	}
	template <class T>
	static T atan(T scalar) {
		return static_cast<T>(std::atan(static_cast<double>(scalar)));
	}
	template <class T>
	static T atan2(T scalarX, T scalarY) {
		return static_cast<T>(std::atan2(static_cast<double>(scalarX), static_cast<double>(scalarY)));
	}
	template <class T>
	static T pow(T scalarBase, T scalarExp) {
		return static_cast<T>(std::pow(static_cast<double>(scalarBase), static_cast<double>(scalarExp)));
	}
	template <class T>
	static T sqrt(T scalar) {
		return static_cast<T>(std::sqrt(static_cast<double>(scalar)));
	}
	template <class T>
	static T ln(T scalar) {
		return static_cast<T>(std::log(static_cast<double>(scalar)));
	}
	template <class T>
	static T log(T scalarBase, T scalarAnti) {
		return static_cast<T>(Scalar::ln(static_cast<double>(scalarAnti)) / Scalar::ln(static_cast<double>(scalarBase)));
	}
	template <class T>
	static T degreeToRadian(T scalar) {
		return static_cast<T>(Scalar::DegreeToRadian * static_cast<double>(scalar));
	}
	template <class T>
	static T radianToDegree(T scalar) {
		return static_cast<T>(Scalar::RadianToDegree * static_cast<double>(scalar));
	}

public:
	static inline const real64 Pi = 3.141592653589793;
	static inline const real64 E = 2.718281828459045;

private:
	static inline const real64 DegreeToRadian = 0.01745329251994329; // Pi / 180
	static inline const real64 RadianToDegree = 57.29577951308232;   // 180 / P
};

} // namespace Core
