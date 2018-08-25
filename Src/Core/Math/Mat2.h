// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2016/12/13 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"
#include "Scalar.h"
#include "Vec2.h"

namespace Core {

class RF_API Mat2 {
public:
	Mat2(real32 m11, real32 m12, real32 m21, real32 m22);
	explicit Mat2(real32 (&array)[4]);
	Mat2(const Mat2 &other);
	Mat2 &operator=(const Mat2 &other);
	~Mat2() = default;

public:
	inline Mat2 operator+(const Mat2 &matrix) const { return Mat2::add(*this, matrix); }
	inline Mat2 &operator+=(const Mat2 &matrix) {
		*this = Mat2::add(*this, matrix);
		return *this;
	}
	inline Mat2 operator-(const Mat2 &matrix) const { return Mat2::sub(*this, matrix); }
	inline Mat2 &operator-=(const Mat2 &matrix) {
		*this = Mat2::sub(*this, matrix);
		return *this;
	}
	inline Mat2 operator*(real32 scalar) const { return Mat2::mul(*this, scalar); }
	inline Mat2 &operator*=(real32 scalar) {
		*this = Mat2::mul(*this, scalar);
		return *this;
	}
	inline Vec2 operator*(const Vec2 &vector) const { return Mat2::mul(*this, vector); }
	inline Mat2 operator*(const Mat2 &matrix) const { return Mat2::mul(*this, matrix); }
	inline Mat2 &operator*=(const Mat2 &matrix) {
		*this = Mat2::mul(*this, matrix);
		return *this;
	}
	inline Mat2 operator/(real32 scalar) const { return Mat2::div(*this, scalar); }
	inline Mat2 &operator/=(real32 scalar) {
		*this = Mat2::div(*this, scalar);
		return *this;
	}

public:
	inline Mat2 &add(const Mat2 &matrix) {
		*this = Mat2::add(*this, matrix);
		return *this;
	}
	inline Mat2 &sub(const Mat2 &matrix) {
		*this = Mat2::sub(*this, matrix);
		return *this;
	}
	inline Mat2 &mul(real32 scalar) {
		*this = Mat2::mul(*this, scalar);
		return *this;
	}
	inline Vec2 mul(const Vec2 &vector) { return Mat2::mul(*this, vector); }
	inline Mat2 &mul(const Mat2 &matrix) {
		*this = Mat2::mul(*this, matrix);
		return *this;
	}
	inline Mat2 div(real32 scalar) {
		*this = Mat2::div(*this, scalar);
		return *this;
	}
	inline Mat2 &transpose() {
		*this = Mat2::transpose(*this);
		return *this;
	}
	inline real32 determinant() { return Mat2::determinant(*this); }

public:
	inline real32 get(int col, int row) const { return Mat2::get(*this, col, row); }
	inline Vec2 row(int row) const { return Mat2::row(*this, row); }
	inline Vec2 col(int col) const { return Mat2::col(*this, col); }

public:
	inline void set(int col, int row, real32 scalar) { Mat2::set(*this, col, row, scalar); }
	inline void set(real32 (&array)[4]) { Mat2::set(*this, array); }
	inline void setRow(int row, const Vec2 &vector) { Mat2::setRow(*this, row, vector); }
	inline void setCol(int col, const Vec2 &vector) { Mat2::setCol(*this, col, vector); }

public:
	static Mat2 add(const Mat2 &matrixA, const Mat2 &matrixB);
	static Mat2 sub(const Mat2 &matrixA, const Mat2 &matrixB);
	static Mat2 mul(const Mat2 &matrix, real32 scalar);
	static Vec2 mul(const Mat2 &matrix, const Vec2 &vector);
	static Mat2 mul(const Mat2 &matrixA, const Mat2 &matrixB);
	static Mat2 div(const Mat2 &matrix, real32 scalar);
	static Mat2 transpose(const Mat2 &matrix);
	static real32 determinant(const Mat2 &matrix);

public:
	static real32 get(const Mat2 &matrix, int col, int row);
	static Vec2 row(const Mat2 &matrix, int row);
	static Vec2 col(const Mat2 &matrix, int col);
	static void set(Mat2 &matrix, int col, int row, real32 scalar);
	static void set(Mat2 &matrix, real32 (&array)[4]);
	static void setRow(Mat2 &matrix, int row, const Vec2 &vector);
	static void setCol(Mat2 &matrix, int col, const Vec2 &vector);

public:
	static const Mat2 zero;
	static const Mat2 identity;

private:
	real32 mMatrix[4];
};

} // namespace Core