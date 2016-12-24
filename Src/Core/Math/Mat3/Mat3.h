// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/17 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_MATH_MAT3_H
#define RALFLIGHT_SRC_CORE_MATH_MAT3_H
 
#include "../Vec3/Vec3.h"
#include <intrin.h>
 
class Mat3 {
public:
	Mat3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33);
	Mat3(float (&array)[9]);
	Mat3(const Mat3 &other);
	Mat3 &operator=(const Mat3 &other);
	~Mat3() = default;
 
public:
	Mat3 operator+(const Mat3 &matrix) const;
	Mat3 &operator+=(const Mat3 &matrix);
	Mat3 operator-(const Mat3 &matrix) const;
	Mat3 &operator-=(const Mat3 &matrix);
	Mat3 operator*(float scalar) const;
	Mat3 &operator*=(float scalar);
	Vec3 operator*(const Vec3 &vector) const;
	Mat3 operator*(const Mat3 &matrix) const;
	Mat3 &operator*=(const Mat3 &matrix);
	Mat3 operator/(float scalar) const;
	Mat3 &operator/=(float scalar);
 
public:
	Mat3 &tra();		// Transpose

public:
	float get(int col, int row) const;
	Vec3 row(int row) const;
	Vec3 col(int col) const;

public:
	bool set(int col, int row, float scalar);
	void set(float (&array)[9]);
	bool setRow(int row, const Vec3 &vector);
	bool setCol(int col, const Vec3 &vector);
 
private:
	float mMatrix[9];
};
 
#endif          // RALFLIGHT_SRC_CORE_MATH_MAT3_H
