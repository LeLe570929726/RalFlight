// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/5 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_MATH_VEC3_H
#define RALFLIGHT_SRC_CORE_MATH_VEC3_H
 
#include "../Global/Macro.h"
#include "Scalar.h"
#include <intrin.h>

// Core namespace
namespace Core {

	class RALFLIGHT_API Vec3 {
	public:
		Vec3(float x, float y, float z);
		Vec3(float(&array)[3]);
		Vec3(const Vec3 &other);
		Vec3 &operator=(const Vec3 &other);
		~Vec3() = default;

	public:
		Vec3 operator+(const Vec3 &vector) const;
		Vec3 &operator+=(const Vec3 &vector);
		Vec3 operator-(const Vec3 &vector) const;
		Vec3 &operator-=(const Vec3 &vector);
		Vec3 operator*(float scalar) const;
		Vec3 &operator*=(float scalar);
		Vec3 operator/(float scalar) const;
		Vec3 &operator/=(float scalar);

	public:
		Vec3 &add(const Vec3 &vector);
		Vec3 &sub(const Vec3 &vector);
		Vec3 &mul(float scalar);
		Vec3 &div(float scalar);
		float module() const;
		float rmodule() const;     // Module's reciprocal
		Vec3 &normalize();
		float dot(const Vec3 &vector) const;
		Vec3 cross(const Vec3 &vector) const;
		float angle(const Vec3 &vector) const;
		Vec3 project(const Vec3 &vector) const;

	public:
		inline void set(float(&array)[3]);
		inline void setX(float x);
		inline void setY(float y);
		inline void setZ(float z);

	public:
		inline bool isZero() const;
		inline bool isOne() const;

	public:
		inline float x() const;
		inline float y() const;
		inline float z() const;

	public:
		static Vec3 add(const Vec3 &vectorA, const Vec3 &vectorB);
		static Vec3 sub(const Vec3 &vectorA, const Vec3 &vectorB);
		static Vec3 mul(const Vec3 &vector, float scalar);
		static Vec3 div(const Vec3 &vector, float scalar);
		static float module(const Vec3 &vector);
		static float rmodule(const Vec3 &vector);
		static Vec3 normalize(const Vec3 &vector);
		static float dot(const Vec3 &vectorA, const Vec3 &vectorB);
		static Vec3 cross(const Vec3 &vectorA, const Vec3 &vectorB);
		static float angle(const Vec3 &vectorA, const Vec3 &vectorB);
		static Vec3 project(const Vec3 &vectorA, const Vec3 &vectorB);

	private:
		float mX;
		float mY;
		float mZ;
	};

}

#endif // RALFLIGHT_SRC_CORE_MATH_VEC3_H