// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/17 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_MATH_MAT4_H
#define RALFLIGHT_SRC_CORE_MATH_MAT4_H
 
#include "../Global/Macro.h"
#include "Vec4.h"
#include <intrin.h>

// Core namespace
namespace Core {

	class RALFLIGHT_API Mat4 {
	public:
		Mat4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);
		Mat4(float(&array)[16]);
		Mat4(const Mat4 &other);
		Mat4 &operator=(const Mat4 &other);
		~Mat4() = default;

	public:
		Mat4 operator+(const Mat4 &matrix) const;
		Mat4 &operator+=(const Mat4 &matrix);
		Mat4 operator-(const Mat4 &matrix) const;
		Mat4 &operator-=(const Mat4 &matrix);
		Mat4 operator*(float scalar) const;
		Mat4 &operator*=(float scalar);
		Vec4 operator*(const Vec4 &vector) const;
		Mat4 operator*(const Mat4 &matrix) const;
		Mat4 &operator*=(const Mat4 &matrix);
		Mat4 operator/(float scalar) const;
		Mat4 &operator/=(float scalar);

	public:
		Mat4 &add(const Mat4 &matrix);
		Mat4 &sub(const Mat4 &matrix);
		Mat4 &mul(float scalar);
		Vec4 mul(const Vec4 &vector);
		Mat4 &mul(const Mat4 &matrix);
		Mat4 &div(float scalar);
		Mat4 &transpose();

	public:
		inline float get(int col, int row) const;
		inline Vec4 row(int row) const;
		inline Vec4 col(int col) const;

	public:
		inline bool set(int col, int row, float scalar);
		inline void set(float(&array)[16]);
		inline bool setRow(int row, const Vec4 &vector);
		inline bool setCol(int col, const Vec4 &vector);

	public:
		static Mat4 add(const Mat4 &matrixA, const Mat4 &matrixB);
		static Mat4 sub(const Mat4 &matrixA, const Mat4 &matrixB);
		static Mat4 mul(const Mat4 &matrix, float scalar);
		static Vec4 mul(const Mat4 &matrix, const Vec4 &vector);
		static Mat4 mul(const Mat4 &matrixA, const Mat4 &matrixB);
		static Mat4 div(const Mat4 &matrix, float scalar);
		static Mat4 transpose(const Mat4 &matrix);

	private:
		float mMatrix[16];
	};

}

#endif          // RALFLIGHT_SRC_CORE_MATH_MAT4_H
