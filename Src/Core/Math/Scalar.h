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

#include "../Global/Global.h"
#include <QtGlobal>
#include <QtMath>

// Core namespace
namespace Core {

	using int8 = qint8;
	using int16 = qint16;
	using int32 = qint32;
	using int64 = qint64;

	using uint8 = quint8;
	using uint16 = quint16;
	using uint32 = quint32;
	using uint64 = quint64;

    using real32 = float;
    using real64 = double;

	class RF_API_TEMPLATE Scalar {
	public:
		Scalar() = delete;
		Scalar(const Scalar &other) = delete;
		~Scalar() = delete;
		Scalar &operator=(const Scalar &other) = delete;

	public:
		template <class T>
		static T abs(T scalar) {
			return qAbs(scalar);
		}
		template <class T>
		static T cos(T scalar) {
			return static_cast<T>(qCos(static_cast<qreal>(scalar)));
		}
		template <class T>
		static T sin(T scalar) {
			return static_cast<T>(qSin(static_cast<qreal>(scalar)));
		}
		template <class T>
		static T tan(T scalar) {
			return static_cast<T>(qTan(static_cast<qreal>(scalar)));
		}
		template <class T>
		static T acos(T scalar) {
			return static_cast<T>(qAcos(static_cast<qreal>(scalar)));
		}
		template <class T>
		static T asin(T scalar) {
			return static_cast<T>(qAsin(static_cast<qreal>(scalar)));
		}
		template <class T>
		static T atan(T scalar) {
			return static_cast<T>(qAtan(static_cast<qreal>(scalar)));
		}
		template <class T>
		static T atan2(T scalarX, T scalarY) {
			return static_cast<T>(qAtan2(static_cast<qreal>(scalarX), static_cast<qreal>(scalarY)));
		}
		template <class T>
		static T pow(T scalarBase, T scalarExp) {
			return static_cast<T>(qPow(static_cast<qreal>(scalarBase), static_cast<qreal>(scalarExp)));
		}
		template <class T>
		static T sqrt(T scalar) {
			return static_cast<T>(qSqrt(static_cast<qreal>(scalar)));
		}
		template <class T>
		static T ln(T scalar) {
			return static_cast<T>(qLn(static_cast<qreal>(scalar)));
		}
		template <class T>
		static T log(T scalarBase, T scalarAnti) {
			return static_cast<T>(Scalar::ln(scalarAnti) / Scalar::ln(scalarBase));
		}
		template <class T>
		static T degreeToRadian(T scalar) {
			return static_cast<T>(qDegreesToRadians(static_cast<double>(scalar)));
		}
		template <class T>
		static T radianToDegree(T scalar) {
			return static_cast<T>(qRadiansToDegrees(static_cast<double>(scalar)));
		}
	};

}
