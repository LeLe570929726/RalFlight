// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2016/12/11 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"
#include "Scalar.h"
#include "Vec3.h"

namespace Core {

class Mat4;

class RF_API Vec4 {
public:
	Vec4(real32 x, real32 y, real32 z, real32 w);
	explicit Vec4(real32 (&array)[4]);
	Vec4(const Vec4 &other);
	Vec4 &operator=(const Vec4 &other);
	~Vec4() = default;

public:
	inline Vec4 operator+(const Vec4 &vector) const { return Vec4::add(*this, vector); }
	inline Vec4 &operator+=(const Vec4 &vector) {
		*this = Vec4::add(*this, vector);
		return *this;
	}
	inline Vec4 operator-(const Vec4 &vector) const { return Vec4::sub(*this, vector); }
	inline Vec4 &operator-=(const Vec4 &vector) {
		*this = Vec4::sub(*this, vector);
		return *this;
	}
	inline Vec4 operator*(real32 scalar) const { return Vec4::mul(*this, scalar); }
	inline Vec4 &operator*=(real32 scalar) {
		*this = Vec4::mul(*this, scalar);
		return *this;
	}
	inline Vec4 operator/(real32 scalar) const { return Vec4::div(*this, scalar); }
	inline Vec4 &operator/=(real32 scalar) {
		*this = Vec4::div(*this, scalar);
		return *this;
	}

public:
	Vec4 &add(const Vec4 &vector);
	Vec4 &sub(const Vec4 &vector);
	Vec4 &mul(real32 scalar);
	Vec4 &div(real32 scalar);
	real32 module() const;
	real32 rmodule() const;
	Vec4 &normalize();
	real32 dot(const Vec4 &vector) const;
	real32 angle(const Vec4 &vector) const;
	Vec4 project(const Vec4 &vector) const;

public:
	real32 x() const;
	real32 y() const;
	real32 z() const;
	real32 w() const;
	void set(real32 (&array)[4]);
	void setX(real32 x);
	void setY(real32 y);
	void setZ(real32 z);
	void setW(real32 w);

public:
	bool isZero() const;
	bool isOne() const;

public:
	static Vec4 add(const Vec4 &vectorA, const Vec4 &vectorB);
	static Vec4 sub(const Vec4 &vectorA, const Vec4 &vectorB);
	static Vec4 mul(const Vec4 &vector, real32 scalar);
	static Vec4 div(const Vec4 &vector, real32 scalar);
	static real32 module(const Vec4 &vector);
	static real32 rmodule(const Vec4 &vector);
	static Vec4 normalize(const Vec4 &vector);
	static real32 dot(const Vec4 &vectorA, const Vec4 &vectorB);
	static real32 angle(const Vec4 &vectorA, const Vec4 &vectorB);
	static Vec4 project(const Vec4 &vectorA, const Vec4 &vectorB);

public:
	static real32 x(const Vec4 &vector);
	static real32 y(const Vec4 &vector);
	static real32 z(const Vec4 &vector);
	static real32 w(const Vec4 &vector);
	static void set(Vec4 &vector, real32 (&array)[4]);
	static void setX(Vec4 &vector, real32 x);
	static void setY(Vec4 &vector, real32 y);
	static void setZ(Vec4 &vector, real32 z);
	static void setW(Vec4 &vector, real32 w);

public:
	static bool isZero(const Vec4 &vector);
	static bool isOne(const Vec4 &vector);

public:
	static const Vec4 zero;

private:
	friend Mat4;

private:
	RF_ALIGN16 real32 mVector[4];
};

} // namespace Core
