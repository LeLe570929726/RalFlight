// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/6 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_MATH_SCALAR_H
#define RALFLIGHT_SRC_CORE_MATH_SCALAR_H

#include "../Global/Macro.h"
#include <stdint.h>
#include <cmath>

// Core namespace
namespace Core {

	using int8 = int8_t;
	using int16 = int16_t;
	using int32 = int32_t;
	using int64 = int64_t;

	using uint8 = uint8_t;
	using uint16 = uint16_t;
	using uint32 = uint32_t;
	using uint64 = uint64_t;

	template <class T>
	class RALFLIGHT_API Scalar {
	public:
		Scalar() = delete;
		Scalar(const Scalar &other) = delete;
		~Scalar() = delete;
		Scalar &operator=(const Scalar &other) = delete;

	public:
		static T abs(T scalar) {
			return static_cast<T>(std::abs(static_cast<double>(scalar)));
		}
		static T cos(T scalar) {
			return static_cast<T>(std::cos(static_cast<double>(scalar)));
		}
		static T sin(T scalar) {
			return static_cast<T>(std::sin(static_cast<double>(scalar)));
		}
		static T tan(T scalar) {
			return static_cast<T>(std::tan(static_cast<double>(scalar)));
		}
		static T acos(T scalar) {
			return static_cast<T>(std::acos(static_cast<double>(scalar)));
		}
		static T asin(T scalar) {
			return static_cast<T>(std::asin(static_cast<double>(scalar)));
		}
		static T atan(T scalar) {
			return static_cast<T>(std::atan(static_cast<double>(scalar)));
		}
		static T pow(T scalarBase, T scalarExp) {
			return static_cast<T>(std::pow(static_cast<double>(scalarBase), static_cast<double>(scalarExp)));
		}
		static T sqrt(T scalar) {
			return static_cast<T>(std::sqrt(static_cast<double>(scalar)));
		}
		static T log(T scalar) {
			return static_cast<T>(std::log(static_cast<double>(scalar)));
		}
	};

}

#endif        // RALFLIGHT_SRC_CORE_MATH_SCALAR_H
