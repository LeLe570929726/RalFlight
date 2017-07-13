// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/13 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_MATH_MAT2_H
#define RALFLIGHT_SRC_CORE_MATH_MAT2_H

#include "../Global/Macro.h"
#include "Vec2.h"
#include <intrin.h>

// Core namespace
namespace Core {

	class RALFLIGHT_API Mat2 {
	public:
		Mat2(float m11, float m12, float m21, float m22);
		Mat2(float(&array)[4]);
		Mat2(const Mat2 &other);
		Mat2 &operator=(const Mat2 &other);
		~Mat2() = default;

	public:
		Mat2 operator+(const Mat2 &matrix) const;
		Mat2 &operator+=(const Mat2 &matrix);
		Mat2 operator-(const Mat2 &matrix) const;
		Mat2 &operator-=(const Mat2 &matrix);
		Mat2 operator*(float scalar) const;
		Mat2 &operator*=(float scalar);
		Vec2 operator*(const Vec2 &vector) const;
		Mat2 operator*(const Mat2 &matrix) const;
		Mat2 &operator*=(const Mat2 &matrix);
		Mat2 operator/(float scalar) const;
		Mat2 &operator/=(float scalar);

	public:
		Mat2 &add(const Mat2 matrix);
		Mat2 &sub(const Mat2 matrix);
		Mat2 &mul(float scalar);
		Vec2 mul(const Vec2 &vector);
		Mat2 &mul(const Mat2 matrix);
		Mat2 div(float scalar);
		Mat2 &transpose();

	public:
		inline float get(int col, int row) const;
		inline Vec2 row(int row) const;
		inline Vec2 col(int col) const;

	public:
		inline bool set(int col, int row, float scalar);
		inline void set(float(&array)[4]);
		inline bool setRow(int row, const Vec2 &vector);
		inline bool setCol(int col, const Vec2 &vector);

	public:
		static Mat2 add(const Mat2 &matrixA, const Mat2 &matrixB);
		static Mat2 sub(const Mat2 &matrixA, const Mat2 &matrixB);
		static Mat2 mul(const Mat2 &matrix, float scalar);
		static Vec2 mul(const Mat2 &matrix, const Vec2 &vector);
		static Mat2 mul(const Mat2 &matrixA, const Mat2 &matrixB);
		static Mat2 div(const Mat2 &matrix, float scalar);
		static Mat2 transpose(const Mat2 &matrix);

	private:
		float mMatrix[4];
	};

}

#endif		// RALFLIGHT_SRC_CORE_MATH_MAT2_H
