// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2016/12/7 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"
#include "Scalar.h"

namespace Core {

class RF_API Vec2 {
public:
	Vec2(real32 x, real32 y);
	explicit Vec2(real32 (&array)[2]);
	Vec2(const Vec2 &other);
	Vec2 &operator=(const Vec2 &other);
	~Vec2() = default;

public:
	inline Vec2 operator+(const Vec2 &vector) const { return Vec2::add(*this, vector); }
	inline Vec2 &operator+=(const Vec2 &vector) {
		*this = Vec2::add(*this, vector);
		return *this;
	}
	inline Vec2 operator-(const Vec2 &vector) const { return Vec2::sub(*this, vector); }
	inline Vec2 &operator-=(const Vec2 &vector) {
		*this = Vec2::sub(*this, vector);
		return *this;
	}
	inline Vec2 operator*(real32 scalar) const { return Vec2::mul(*this, scalar); }
	inline Vec2 &operator*=(real32 scalar) {
		*this = Vec2::mul(*this, scalar);
		return *this;
	}
	inline Vec2 operator/(real32 scalar) const { return Vec2::div(*this, scalar); }
	inline Vec2 &operator/=(real32 scalar) {
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
	inline Vec2 &mul(real32 scalar) {
		*this = Vec2::mul(*this, scalar);
		return *this;
	}
	inline Vec2 &div(real32 scalar) {
		*this = Vec2::div(*this, scalar);
		return *this;
	}
	inline real32 module() const { return Vec2::module(*this); }
	// Module's reciprocal
	inline real32 rmodule() const { return Vec2::rmodule(*this); }
	inline Vec2 &normalize() {
		*this = Vec2::normalize(*this);
		return *this;
	}
	inline real32 dot(const Vec2 &vector) const { return Vec2::dot(*this, vector); }
	inline real32 cross(const Vec2 &vector) const { return Vec2::cross(*this, vector); }
	inline real32 angle(const Vec2 &vector) const { return Vec2::angle(*this, vector); }
	inline Vec2 project(const Vec2 &vector) const { return Vec2::project(*this, vector); }

public:
	inline real32 x() const { return this->mX; }
	inline real32 y() const { return this->mY; }
	inline void set(real32 (&array)[2]) { Vec2::set(*this, array); }
	inline void setX(real32 x) { Vec2::setX(*this, x); }
	inline void setY(real32 y) { Vec2::setY(*this, y); }

public:
	inline bool isZero() const { return Vec2::isZero(*this); }
	inline bool isOne() const { return Vec2::isOne(*this); }

public:
	static Vec2 add(const Vec2 &vectorA, const Vec2 &vectorB);
	static Vec2 sub(const Vec2 &vectorA, const Vec2 &vectorB);
	static Vec2 mul(const Vec2 &vector, real32 scalar);
	static Vec2 div(const Vec2 &vector, real32 scalar);
	static real32 module(const Vec2 &vector);
	static real32 rmodule(const Vec2 &vector);
	static Vec2 normalize(const Vec2 &vector);
	static real32 dot(const Vec2 &vectorA, const Vec2 &vectorB);
	static real32 cross(const Vec2 &vectorA, const Vec2 &vectorB);
	static real32 angle(const Vec2 &vectorA, const Vec2 &vectorB);
	static Vec2 project(const Vec2 &vectorA, const Vec2 &vectorB);

public:
	static real32 x(const Vec2 &vector);
	static real32 y(const Vec2 &vector);
	static void set(Vec2 &vector, real32 (&array)[2]);
	static void setX(Vec2 &vector, real32 x);
	static void setY(Vec2 &vector, real32 y);

public:
	static bool isZero(const Vec2 &vector);
	static bool isOne(const Vec2 &vector);

private:
	real32 mX;
	real32 mY;
};

} // namespace Core