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

class Mat2;

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
	Vec2 &add(const Vec2 &vector);
	Vec2 &sub(const Vec2 &vector);
	Vec2 &mul(real32 scalar);
	Vec2 &div(real32 scalar);
	real32 module() const;
	real32 rmodule() const;
	Vec2 &normalize();
	real32 dot(const Vec2 &vector) const;
	real32 cross(const Vec2 &vector) const;
	real32 angle(const Vec2 &vector) const;
	Vec2 project(const Vec2 &vector) const;

public:
	real32 x() const;
	real32 y() const;
	void set(real32 (&array)[2]);
	void setX(real32 x);
	void setY(real32 y);

public:
	bool isZero() const;
	bool isOne() const;

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

public:
	static const Vec2 zero;

private:
	friend Mat2;

private:
	RF_ALIGN16 real32 mVector[4];
};

} // namespace Core