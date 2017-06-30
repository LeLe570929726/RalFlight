// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/7 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_MATH_VEC2_H
#define RALFLIGHT_SRC_CORE_MATH_VEC2_H
 
#include "../Global/Macro.h"
#include "Scalar.h"
#include <intrin.h>

// Core namespace
namespace Core {

	class RALFLIGHT_API Vec2 {
	public:
		Vec2(float x, float y);
		Vec2(float(&array)[2]);
		Vec2(const Vec2 &other);
		Vec2 &operator=(const Vec2 &other);
		~Vec2() = default;

	public:
		Vec2 operator+(const Vec2 &vector) const;
		Vec2 &operator+=(const Vec2 &vector);
		Vec2 operator-(const Vec2 &vector) const;
		Vec2 &operator-=(const Vec2 &vector);
		Vec2 operator*(float scalar) const;
		Vec2 &operator*=(float scalar);
		Vec2 operator/(float scalar) const;
		Vec2 &operator/=(float scalar);

	public:
		Vec2 &add(const Vec2 &vector);
		Vec2 &sub(const Vec2 &vector);
		Vec2 &mul(float scalar);
		Vec2 &div(float scalar);
		float module() const;
		float rmodule() const;     // Module's reciprocal
		Vec2 &normalize();
		float dot(const Vec2 &vector) const;
		float cross(const Vec2 &vector) const;
		float angle(const Vec2 &vector) const;
		Vec2 project(const Vec2 &vector) const;

	public:
		inline void set(float(&array)[2]);
		inline void setX(float x);
		inline void setY(float y);

	public:
		inline bool isZero() const;
		inline bool isOne() const;

	public:
		inline float x() const;
		inline float y() const;

	public:
		static Vec2 add(const Vec2 &vectorA, const Vec2 &vectorB);
		static Vec2 sub(const Vec2 &vectorA, const Vec2 &vectorB);
		static Vec2 mul(const Vec2 &vector, float scalar);
		static Vec2 div(const Vec2 &vector, float scalar);
		static float module(const Vec2 &vector);
		static float rmodule(const Vec2 &vector);
		static Vec2 normalize(const Vec2 &vector);
		static float dot(const Vec2 &vectorA, const Vec2 &vectorB);
		static float cross(const Vec2 &vectorA, const Vec2 &vectorB);
		static float angle(const Vec2 &vectorA, const Vec2 &vectorB);
		static Vec2 project(const Vec2 &vectorA, const Vec2 &vectorB);

	private:
		float mX;
		float mY;
	};

}

#endif // RALFLIGHT_SRC_CORE_MATH_VEC2_H