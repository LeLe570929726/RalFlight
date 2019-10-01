// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2016/12/17 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"
#include "Scalar.h"
#include "Vec3.h"

namespace Core {

class RF_API Mat3 {
public:
	Mat3(real32 m11, real32 m12, real32 m13, real32 m21, real32 m22, real32 m23, real32 m31, real32 m32, real32 m33);
	explicit Mat3(real32 (&array)[9]);
	Mat3(const Mat3 &other);
	Mat3 &operator=(const Mat3 &other);
	~Mat3() = default;

public:
	inline Mat3 operator+(const Mat3 &matrix) const { return Mat3::add(*this, matrix); }
	inline Mat3 &operator+=(const Mat3 &matrix) {
		*this = Mat3::add(*this, matrix);
		return *this;
	}
	inline Mat3 operator-(const Mat3 &matrix) const { return Mat3::sub(*this, matrix); }
	inline Mat3 &operator-=(const Mat3 &matrix) {
		*this = Mat3::sub(*this, matrix);
		return *this;
	}
	inline Mat3 operator*(real32 scalar) const { return Mat3::mul(*this, scalar); }
	inline Mat3 &operator*=(real32 scalar) {
		*this = Mat3::mul(*this, scalar);
		return *this;
	}
	inline Vec3 operator*(const Vec3 &vector) const { return Mat3::mul(*this, vector); }
	inline Mat3 operator*(const Mat3 &matrix) const { return Mat3::mul(*this, matrix); }
	inline Mat3 &operator*=(const Mat3 &matrix) {
		*this = Mat3::mul(*this, matrix);
		return *this;
	}
	inline Mat3 operator/(real32 scalar) const { return Mat3::div(*this, scalar); }
	inline Mat3 &operator/=(real32 scalar) {
		*this = Mat3::div(*this, scalar);
		return *this;
	}

public:
	Mat3 &add(const Mat3 &matrix);
	Mat3 &sub(const Mat3 &matrix);
	Mat3 &mul(real32 scalar);
	Vec3 mul(const Vec3 &vector) const;
	Mat3 &mul(const Mat3 &matrix);
	Mat3 &div(real32 scalar);
	Mat3 &transpose();
	real32 det() const;

public:
	real32 get(uint8 col, uint8 row) const;
	Vec3 row(uint8 row) const;
	Vec3 col(uint8 col) const;
	void set(uint8 col, uint8 row, real32 scalar);
	void set(real32 (&array)[9]);
	void setRow(uint8 row, const Vec3 &vector);
	void setCol(uint8 col, const Vec3 &vector);

public:
	static Mat3 add(const Mat3 &matrixA, const Mat3 &matrixB);
	static Mat3 sub(const Mat3 &matrixA, const Mat3 &matrixB);
	static Mat3 mul(const Mat3 &matrix, real32 scalar);
	static Vec3 mul(const Mat3 &matrix, const Vec3 &vector);
	static Mat3 mul(const Mat3 &matrixA, const Mat3 &matrixB);
	static Mat3 div(const Mat3 &matrix, real32 scalar);
	static Mat3 transpose(const Mat3 &matrix);
	static real32 det(const Mat3 &matrix);

public:
	static real32 get(const Mat3 &matrix, uint8 col, uint8 row);
	static Vec3 row(const Mat3 &matrix, uint8 row);
	static Vec3 col(const Mat3 &matrix, uint8 col);
	static void set(Mat3 &matrix, uint8 col, uint8 row, real32 scalar);
	static void set(Mat3 &matrix, real32 (&array)[9]);
	static void setRow(Mat3 &matrix, uint8 row, const Vec3 &vector);
	static void setCol(Mat3 &matrix, uint8 col, const Vec3 &vector);

public:
	static const Mat3 zero;
	static const Mat3 identity;

private:
	RF_ALIGN32 real32 mMatrix[9];
};

} // namespace Core
