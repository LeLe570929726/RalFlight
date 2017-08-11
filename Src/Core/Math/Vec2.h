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
#include <assert.h>

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
		inline Vec2 operator+(const Vec2 &vector) const {
			return Vec2::add(*this, vector);
		}
		inline Vec2 &operator+=(const Vec2 &vector) {
			*this = Vec2::add(*this, vector);
			return *this;
		}
		inline Vec2 operator-(const Vec2 &vector) const {
			return Vec2::sub(*this, vector);
		}
		inline Vec2 &operator-=(const Vec2 &vector) {
			*this = Vec2::sub(*this, vector);
			return *this;
		}
		inline Vec2 operator*(float scalar) const {
			return Vec2::mul(*this, scalar);
		}
		inline Vec2 &operator*=(float scalar) {
			*this = Vec2::mul(*this, scalar);
			return *this;
		}
		inline Vec2 operator/(float scalar) const {
			return Vec2::div(*this, scalar);
		}
		inline Vec2 &operator/=(float scalar) {
			*this = Vec2::div(*this, scalar);
			return *this;
		}

	public:
		inline Vec2 &add(const Vec2 &vector) {
			*this = Vec2::add(*this, vector);
			return *this;
		}
		inline Vec2 &sub(const Vec2 &vector) {
			*this = Vec2::sub(*this, vector);
			return *this;
		}
		inline Vec2 &mul(float scalar) {
			*this = Vec2::mul(*this, scalar);
			return *this;
		}
		inline Vec2 &div(float scalar) {
			*this = Vec2::div(*this, scalar);
			return *this;
		}
		inline float module() const {
			return Vec2::module(*this);
		}
		// Module's reciprocal
		inline float rmodule() const {
			return Vec2::rmodule(*this);
		}
		inline Vec2 &normalize() {
			*this = Vec2::normalize(*this);
			return *this;
		}
		inline float dot(const Vec2 &vector) const {
			return Vec2::dot(*this, vector);
		}
		inline float cross(const Vec2 &vector) const {
			return Vec2::cross(*this, vector);
		}
		inline float angle(const Vec2 &vector) const {
			return Vec2::angle(*this, vector);
		}
		inline Vec2 project(const Vec2 &vector) const {
			return Vec2::project(*this, vector);
		}

	public:
		inline float getX() const {
			return this->mX;
		}
		inline float getY() const {
			return this->mY;
		}
		inline void set(float(&array)[2]) {
			Vec2::set(*this, array);
		}
		inline void setX(float x) {
			Vec2::setX(*this, x);
		}
		inline void setY(float y) {
			Vec2::setY(*this, y);
		}

	public:
		inline bool isZero() const {
			return Vec2::isZero(*this);
		}
		inline bool isOne() const {
			return Vec2::isOne(*this);
		}

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

	public:
		static float getX(const Vec2 &vector);
		static float getY(const Vec2 &vector);
		static void set(Vec2 &vector, float(&array)[2]);
		static void setX(Vec2 &vector, float x);
		static void setY(Vec2 &vector, float y);

	public:
		static bool isZero(const Vec2 &vector);
		static bool isOne(const Vec2 &vector);

	private:
		float mX;
		float mY;
	};

}

#endif // RALFLIGHT_SRC_CORE_MATH_VEC2_H