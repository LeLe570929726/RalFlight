// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
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
	Mat2();
	Mat2(real32 m11, real32 m12, real32 m21, real32 m22);
	explicit Mat2(real32 (&array)[4]);
	Mat2(const Mat2 &other);
	Mat2 &operator=(const Mat2 &other);
	~Mat2() = default;

public:
	inline Mat2 operator+(const Mat2 &matrix) const { return Mat2::add(*this, matrix); }
	inline Mat2 &operator+=(const Mat2 &matrix) {
		this->add(matrix);
		return *this;
	}
	inline Mat2 operator-(const Mat2 &matrix) const { return Mat2::sub(*this, matrix); }
	inline Mat2 &operator-=(const Mat2 &matrix) {
		this->sub(matrix);
		return *this;
	}
	inline Mat2 operator*(real32 scalar) const { return Mat2::mul(*this, scalar); }
	inline Mat2 &operator*=(real32 scalar) {
		this->mul(scalar);
		return *this;
	}
	inline Vec2 operator*(const Vec2 &vector) const { return Mat2::mul(*this, vector); }
	inline Mat2 operator*(const Mat2 &matrix) const { return Mat2::mul(*this, matrix); }
	inline Mat2 &operator*=(const Mat2 &matrix) {
		this->mul(matrix);
		return *this;
	}
	inline Mat2 operator/(real32 scalar) const { return Mat2::div(*this, scalar); }
	inline Mat2 &operator/=(real32 scalar) {
		this->div(scalar);
		return *this;
	}

public:
	Mat2 &add(const Mat2 &matrix);
	Mat2 &sub(const Mat2 &matrix);
	Mat2 &mul(real32 scalar);
	Vec2 mul(const Vec2 &vector) const;
	Mat2 &mul(const Mat2 &matrix);
	Mat2 &div(real32 scalar);
	Mat2 &transpose();
	real32 det() const;

public:
	real32 get(uint8 row, uint8 col) const;
	Vec2 row(uint8 row) const;
	Vec2 col(uint8 col) const;

public:
	void set(uint8 col, uint8 row, real32 scalar);
	void set(real32 (&array)[4]);
	void setRow(uint8 row, const Vec2 &vector);
	void setCol(uint8 col, const Vec2 &vector);

public:
	static Mat2 add(const Mat2 &matrixA, const Mat2 &matrixB);
	static Mat2 sub(const Mat2 &matrixA, const Mat2 &matrixB);
	static Mat2 mul(const Mat2 &matrix, real32 scalar);
	static Vec2 mul(const Mat2 &matrix, const Vec2 &vector);
	static Mat2 mul(const Mat2 &matrixA, const Mat2 &matrixB);
	static Mat2 div(const Mat2 &matrix, real32 scalar);
	static Mat2 transpose(const Mat2 &matrix);
	static real32 det(const Mat2 &matrix);

public:
	static real32 get(const Mat2 &matrix, uint8 row, uint8 col);
	static Vec2 row(const Mat2 &matrix, uint8 row);
	static Vec2 col(const Mat2 &matrix, uint8 col);
	static void set(Mat2 &matrix, uint8 col, uint8 row, real32 scalar);
	static void set(Mat2 &matrix, real32 (&array)[4]);
	static void setRow(Mat2 &matrix, uint8 row, const Vec2 &vector);
	static void setCol(Mat2 &matrix, uint8 col, const Vec2 &vector);

public:
	static const Mat2 zero;
	static const Mat2 identity;

private:
	RF_ALIGN32 real32 mMatrix[4];
};

} // namespace Core