// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/11 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_MATH_VEC4_H
#define RALFLIGHT_SRC_CORE_MATH_VEC4_H

#include "../Global/Macro.h"
#include "Scalar.h"
#include "Vec3.h"
#include <intrin.h>

// Core namespace
namespace Core {

	class RALFLIGHT_API Vec4 {
	public:
		Vec4(float x, float y, float z, float w);
		Vec4(float(&array)[4]);
		Vec4(const Vec4 &other);
		Vec4 &operator=(const Vec4 &other);
		~Vec4() = default;

	public:
		Vec4 operator+(const Vec4 &vector) const;
		Vec4 &operator+=(const Vec4 &vector);
		Vec4 operator-(const Vec4 &vector) const;
		Vec4 &operator-=(const Vec4 &vector);
		Vec4 operator*(float scalar) const;
		Vec4 &operator*=(float scalar);
		Vec4 operator/(float scalar) const;
		Vec4 &operator/=(float scalar);

	public:
		Vec4 &add(const Vec4 &vector);
		Vec4 &sub(const Vec4 &vector);
		Vec4 &mul(float scalar);
		Vec4 &div(float scalar);
		float module() const;
		float rmodule() const;     // Module's reciprocal
		Vec4 &normalize();
		float dot(const Vec4 &vector) const;
		float angle(const Vec4 &vector) const;
		Vec4 project(const Vec4 &vector) const;

	public:
		inline void set(float(&array)[4]);
		inline void setX(float x);
		inline void setY(float y);
		inline void setZ(float z);
		inline void setW(float w);

	public:
		inline bool isZero() const;
		inline bool isOne() const;

	public:
		inline float x() const;
		inline float y() const;
		inline float z() const;
		inline float w() const;

	public:
		static Vec4 add(const Vec4 &vectorA, const Vec4 &vectorB);
		static Vec4 sub(const Vec4 &vectorA, const Vec4 &vectorB);
		static Vec4 mul(const Vec4 &vector, float scalar);
		static Vec4 div(const Vec4 &vector, float scalar);
		static float module(const Vec4 &vector);
		static float rmodule(const Vec4 &vector);
		static Vec4 normalize(const Vec4 &vector);
		static float dot(const Vec4 &vectorA, const Vec4 &vectorB);
		static float angle(const Vec4 &vectorA, const Vec4 &vectorB);
		static Vec4 project(const Vec4 &vectorA, const Vec4 &vectorB);


	private:
		float mX;
		float mY;
		float mZ;
		float mW;
	};

}
 
#endif      // RALFLIGHT_SRC_CORE_MATH_VEC4_H