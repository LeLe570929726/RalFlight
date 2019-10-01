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
#include "Vec4.h"

namespace Core {

class RF_API Mat4 {
public:
	Mat4(real32 m11, real32 m12, real32 m13, real32 m14, real32 m21, real32 m22, real32 m23, real32 m24, real32 m31, real32 m32,
		 real32 m33, real32 m34, real32 m41, real32 m42, real32 m43, real32 m44);
	explicit Mat4(real32 (&array)[16]);
	Mat4(const Mat4 &other);
	Mat4 &operator=(const Mat4 &other);
	~Mat4() = default;

public:
	inline Mat4 operator+(const Mat4 &matrix) const { return Mat4::add(*this, matrix); }
	inline Mat4 &operator+=(const Mat4 &matrix) {
		*this = Mat4::add(*this, matrix);
		return *this;
	}
	inline Mat4 operator-(const Mat4 &matrix) const { return Mat4::sub(*this, matrix); }
	inline Mat4 &operator-=(const Mat4 &matrix) {
		*this = Mat4::sub(*this, matrix);
		return *this;
	}
	inline Mat4 operator*(real32 scalar) const { return Mat4::mul(*this, scalar); }
	inline Mat4 &operator*=(real32 scalar) {
		*this = Mat4::mul(*this, scalar);
		return *this;
	}
	inline Vec4 operator*(const Vec4 &vector) const { return Mat4::mul(*this, vector); }
	inline Mat4 operator*(const Mat4 &matrix) const { return Mat4::mul(*this, matrix); }
	inline Mat4 &operator*=(const Mat4 &matrix) {
		*this = Mat4::mul(*this, matrix);
		return *this;
	}
	inline Mat4 operator/(real32 scalar) const { return Mat4::div(*this, scalar); }
	inline Mat4 &operator/=(real32 scalar) {
		*this = Mat4::div(*this, scalar);
		return *this;
	}

public:
	Mat4 &add(const Mat4 &matrix);
	Mat4 &sub(const Mat4 &matrix);
	Mat4 &mul(real32 scalar);
	Vec4 mul(const Vec4 &vector) const;
	Mat4 &mul(const Mat4 &matrix);
	Mat4 &div(real32 scalar);
	Mat4 &transpose();
	real32 det() const;

public:
	real32 get(uint8 col, uint8 row) const;
	Vec4 row(uint8 row) const;
	Vec4 col(uint8 col) const;
	void set(uint8 col, uint8 row, real32 scalar);
	void set(real32 (&array)[16]);
	void setRow(uint8 row, const Vec4 &vector);
	void setCol(uint8 col, const Vec4 &vector);

public:
	static Mat4 add(const Mat4 &matrixA, const Mat4 &matrixB);
	static Mat4 sub(const Mat4 &matrixA, const Mat4 &matrixB);
	static Mat4 mul(const Mat4 &matrix, real32 scalar);
	static Vec4 mul(const Mat4 &matrix, const Vec4 &vector);
	static Mat4 mul(const Mat4 &matrixA, const Mat4 &matrixB);
	static Mat4 div(const Mat4 &matrix, real32 scalar);
	static Mat4 transpose(const Mat4 &matrix);
	static real32 det(const Mat4 &matrix);

public:
	static real32 get(const Mat4 &matrix, int col, int row);
	static Vec4 row(const Mat4 &matrix, int row);
	static Vec4 col(const Mat4 &matrix, int col);
	static void set(Mat4 &matrix, int col, int row, real32 scalar);
	static void set(Mat4 &matrix, real32 (&array)[16]);
	static void setRow(Mat4 &matrix, int row, const Vec4 &vector);
	static void setCol(Mat4 &matrix, int col, const Vec4 &vector);

public:
	static const Mat4 zero;
	static const Mat4 identity;

private:
	RF_ALIGN32 real32 mMatrix[16];
};

} // namespace Core
