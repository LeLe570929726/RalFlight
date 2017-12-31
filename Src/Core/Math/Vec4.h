// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
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
#include <assert.h>
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	#include <intrin.h>
#elif defined(RALFLIGHT_SYSTEM_LINUX)
	#include <xmmintrin.h>
#endif

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
		inline Vec4 operator+(const Vec4 &vector) const {
			return Vec4::add(*this, vector);
		}
		inline Vec4 &operator+=(const Vec4 &vector) {
			*this = Vec4::add(*this, vector);
			return *this;
		}
		inline Vec4 operator-(const Vec4 &vector) const {
			return Vec4::sub(*this, vector);
		}
		inline Vec4 &operator-=(const Vec4 &vector) {
			*this = Vec4::sub(*this, vector);
			return *this;
		}
		inline Vec4 operator*(float scalar) const {
			return Vec4::mul(*this, scalar);
		}
		inline Vec4 &operator*=(float scalar) {
			*this = Vec4::mul(*this, scalar);
			return *this;
		}
		inline Vec4 operator/(float scalar) const {
			return Vec4::div(*this, scalar);
		}
		inline Vec4 &operator/=(float scalar) {
			*this = Vec4::div(*this, scalar);
			return *this;
		}

	public:
		inline Vec4 &add(const Vec4 &vector) {
			*this = Vec4::add(*this, vector);
			return *this;
		}
		inline Vec4 &sub(const Vec4 &vector) {
			*this = Vec4::sub(*this, vector);
			return *this;
		}
		inline Vec4 &mul(float scalar) {
			*this = Vec4::mul(*this, scalar);
			return *this;
		}
		inline Vec4 &div(float scalar) {
			*this = Vec4::div(*this, scalar);
			return *this;
		}
		inline float module() const {
			return Vec4::module(*this);
		}
		// Module's reciprocal
		inline float rmodule() const {
			return Vec4::rmodule(*this);
		}
		inline Vec4 &normalize() {
			*this = Vec4::normalize(*this);
			return *this;
		}
		inline float dot(const Vec4 &vector) const {
			return Vec4::dot(*this, vector);
		}
		inline float angle(const Vec4 &vector) const {
			return Vec4::angle(*this, vector);
		}
		inline Vec4 project(const Vec4 &vector) const {
			return Vec4::project(*this, vector);
		}

	public:
		inline float getX() const {
			return Vec4::getX(*this);
		}
		inline float getY() const {
			return Vec4::getY(*this);
		}
		inline float getZ() const {
			return Vec4::getZ(*this);
		}
		inline float getW() const {
			return Vec4::getW(*this);
		}
		inline void set(float(&array)[4]) {
			Vec4::set(*this, array);
		}
		inline void setX(float x) {
			Vec4::setX(*this, x);
		}
		inline void setY(float y) {
			Vec4::setY(*this, y);
		}
		inline void setZ(float z) {
			Vec4::setZ(*this, z);
		}
		inline void setW(float w) {
			Vec4::setW(*this, w);
		}

	public:
		inline bool isZero() const {
			return Vec4::isZero(*this);
		}
		inline bool isOne() const {
			return Vec4::isOne(*this);
		}

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

	public:
		static float getX(const Vec4 &vector);
		static float getY(const Vec4 &vector);
		static float getZ(const Vec4 &vector);
		static float getW(const Vec4 &vector);
		static void set(Vec4 &vector, float(&array)[4]);
		static void setX(Vec4 &vector, float x);
		static void setY(Vec4 &vector, float y);
		static void setZ(Vec4 &vector, float z);
		static void setW(Vec4 &vector, float w);

	public:
		static bool isZero(const Vec4 &vector);
		static bool isOne(const Vec4 &vector);


	private:
		float mX;
		float mY;
		float mZ;
		float mW;
	};

}
 
#endif      // RALFLIGHT_SRC_CORE_MATH_VEC4_H