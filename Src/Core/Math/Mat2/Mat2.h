// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/13 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_MATH_MAT2_H
#define RALFLIGHT_SRC_CORE_MATH_MAT2_H
 
class Mat2 {
public:
	Mat2(float m11, float m12, float m21, float m22);
	Mat2(const Mat2 &other);
	Mat2 &operator=(const Mat2 &other);
	~Mat2() = default;
 
public:
	Vec4 operator+(const Mat4 &matrix);
	Vec4 &operator+=(const Mat4 &matrix);
	Vec4 operator-(const Mat4 &matrix);
	Vec4 &operator-=(const Mat4 &matrix);
 
private:
	float matrix[4];
}
 
#endif		// RALFLIGHT_SRC_CORE_MATH_MAT2_H