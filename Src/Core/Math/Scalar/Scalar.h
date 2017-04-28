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

#include "../../Global/Macro/Macro.h"
#include <stdint.h>
namespace std {
#include <math.h>
}

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

	template <typename T>
	class RALFLIGHT_API Scalar {
	public:
		Scalar() = delete;
		~Scalar() = delete;

	public:
		static T cos(T scalar) {
			return static_cast<T>(cos(static_cast<double>(scalar)));
		}
		static T sin(T scalar) {
			return static_cast<T>(sin(static_cast<double>(scalar)));
		}
		static T tan(T scalar) {
			return static_cast<T>(tan(static_cast<double>(scalar)));
		}
		static T acos(T scalar) {
			return static_cast<T>(acos(static_cast<double>(scalar)));
		}
		static T asin(T scalar) {
			return static_cast<T>(asin(static_cast<double>(scalar)));
		}
		static T atan(T scalar) {
			return static_cast<T>(atan(static_cast<double>(scalar)));
		}
		static T pow(T scalarBase, T scalarExp) {
			return static_cast<T>(pow(static_cast<double>(scalarBase), static_cast<double>(scalarExp)));
		}
		static T sqrt(T scalar) {
			return static_cast<T>(sqrt(static_cast<double>(scalar)));
		}
		static T log(T scalar) {
			return static_cast<T>(log(static_cast<double>(scalar)));
		}
	};

}

#endif        // RALFLIGHT_SRC_CORE_MATH_SCALAR_H
