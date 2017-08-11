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
#include <assert.h>

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
		inline Vec3 operator+(const Vec3 &vector) const {
			return Vec3::add(*this, vector);
		}
		inline Vec3 &operator+=(const Vec3 &vector) {
			*this = Vec3::add(*this, vector);
			return *this;
		}
		inline Vec3 operator-(const Vec3 &vector) const {
			return Vec3::sub(*this, vector);
		}
		inline Vec3 &operator-=(const Vec3 &vector) {
			*this = Vec3::sub(*this, vector);
			return *this;
		}
		inline Vec3 operator*(float scalar) const {
			return Vec3::mul(*this, scalar);
		}
		inline Vec3 &operator*=(float scalar) {
			*this = Vec3::mul(*this, scalar);
			return *this;
		}
		inline Vec3 operator/(float scalar) const {
			return Vec3::mul(*this, scalar);
		}
		inline Vec3 &operator/=(float scalar) {
			*this = Vec3::div(*this, scalar);
			return *this;
		}

	public:
		inline Vec3 &add(const Vec3 &vector) {
			*this = Vec3::add(*this, vector);
			return *this;
		}
		inline Vec3 &sub(const Vec3 &vector) {
			*this = Vec3::sub(*this, vector);
			return *this;
		}
		inline Vec3 &mul(float scalar) {
			*this = Vec3::mul(*this, scalar);
			return *this;
		}
		inline Vec3 &div(float scalar) {
			*this = Vec3::div(*this, scalar);
			return *this;
		}
		inline float module() const {
			return Vec3::module(*this);
		}
		// Module's reciprocal
		inline float rmodule() const {
			return Vec3::rmodule(*this);
		}
		inline Vec3 &normalize() {
			*this = Vec3::add(*this);
			return *this;
		}
		inline float dot(const Vec3 &vector) const {
			return Vec3::dot(*this, vector);
		}
		inline Vec3 cross(const Vec3 &vector) const {
			return Vec3::cross(*this, vector);
		}
		inline float angle(const Vec3 &vector) const {
			return Vec3::angle(*this, vector);
		}
		inline Vec3 project(const Vec3 &vector) const {
			return Vec3::project(*this, vector);
		}

	public:
		inline float getX() const {
			return Vec3::getX(*this);
		}
		inline float getY() const {
			return Vec3::getY(*this);
		}
		inline float getZ() const {
			return Vec3::getZ(*this);
		}
		inline void set(float(&array)[3]) {
			Vec3::set(*this, array);
		}
		inline void setX(float x) {
			Vec3::setX(*this, x);
		}
		inline void setY(float y) {
			Vec3::setY(*this, y);
		}
		inline void setZ(float z) {
			Vec3::setZ(*this, z);
		}

	public:
		inline bool isZero() const {
			return Vec3::isZero(*this);
		}
		inline bool isOne() const {
			return Vec3::isOne(*this);
		}

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

	public:
		static float getX(const Vec3 &vector);
		static float getY(const Vec3 &vector);
		static float getZ(const Vec3 &vector);
		static void set(Vec3 &vector, float(&array)[3]);
		static void setX(Vec3 &vector, float x);
		static void setY(Vec3 &vector, float y);
		static void setZ(Vec3 &vector, float z);

	public:
		static bool isZero(const Vec3 &vector);
		static bool isOne(const Vec3 &vector);

	private:
		float mX;
		float mY;
		float mZ;
	};

}

#endif // RALFLIGHT_SRC_CORE_MATH_VEC3_H