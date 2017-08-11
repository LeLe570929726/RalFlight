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
#include <assert.h>

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
		inline Mat2 operator+(const Mat2 &matrix) const {
			return Mat2::add(*this, matrix);
		}
		inline Mat2 &operator+=(const Mat2 &matrix) {
			*this = Mat2::add(*this, matrix);
			return *this;
		}
		inline Mat2 operator-(const Mat2 &matrix) const {
			return Mat2::sub(*this, matrix);
		}
		inline Mat2 &operator-=(const Mat2 &matrix) {
			*this = Mat2::sub(*this, matrix);
			return *this;
		}
		inline Mat2 operator*(float scalar) const {
			return Mat2::mul(*this, scalar);
		}
		inline Mat2 &operator*=(float scalar) {
			*this = Mat2::mul(*this, scalar);
			return *this;
		}
		inline Vec2 operator*(const Vec2 &vector) const {
			return Mat2::mul(*this, vector);
		}
		inline Mat2 operator*(const Mat2 &matrix) const {
			return Mat2::mul(*this, matrix);
		}
		inline Mat2 &operator*=(const Mat2 &matrix) {
			*this = Mat2::mul(*this, matrix);
			return *this;
		}
		inline Mat2 operator/(float scalar) const {
			return Mat2::div(*this, scalar);
		}
		inline Mat2 &operator/=(float scalar) {
			*this = Mat2::div(*this, scalar);
			return *this;
		}

	public:
		inline Mat2 &add(const Mat2 matrix) {
			*this = Mat2::add(*this, matrix);
			return *this;
		}
		inline Mat2 &sub(const Mat2 matrix) {
			*this = Mat2::sub(*this, matrix);
			return *this;
		}
		inline Mat2 &mul(float scalar) {
			*this = Mat2::mul(*this, scalar);
			return *this;
		}
		inline Vec2 mul(const Vec2 &vector) {
			return Mat2::mul(*this, vector);
		}
		inline Mat2 &mul(const Mat2 matrix) {
			*this = Mat2::mul(*this, matrix);
			return *this;
		}
		inline Mat2 div(float scalar) {
			*this = Mat2::div(*this, scalar);
			return *this;
		}
		inline Mat2 &transpose() {
			*this = Mat2::transpose(*this);
			return *this;
		}

	public:
		inline float get(int col, int row) const {
			return Mat2::get(*this, col, row);
		}
		inline Vec2 getRow(int row) const {
			return Mat2::getRow(*this, row);
		}
		inline Vec2 getCol(int col) const {
			return Mat2::getCol(*this, col);
		}

	public:
		inline void set(int col, int row, float scalar) {
			Mat2::set(*this, col, row, scalar);
		}
		inline void set(float(&array)[4]) {
			Mat2::set(*this, array);
		}
		inline void setRow(int row, const Vec2 &vector) {
			Mat2::setRow(*this, row, vector);
		}
		inline void setCol(int col, const Vec2 &vector) {
			Mat2::setCol(*this, col, vector);
		}

	public:
		static Mat2 add(const Mat2 &matrixA, const Mat2 &matrixB);
		static Mat2 sub(const Mat2 &matrixA, const Mat2 &matrixB);
		static Mat2 mul(const Mat2 &matrix, float scalar);
		static Vec2 mul(const Mat2 &matrix, const Vec2 &vector);
		static Mat2 mul(const Mat2 &matrixA, const Mat2 &matrixB);
		static Mat2 div(const Mat2 &matrix, float scalar);
		static Mat2 transpose(const Mat2 &matrix);

	public:
		static float get(const Mat2 &matrix, int col, int row);
		static Vec2 getRow(const Mat2 &matrix, int row);
		static Vec2 getCol(const Mat2 &matrix, int col);
		static void set(Mat2 &matrix, int col, int row, float scalar);
		static void set(Mat2 &matrix, float(&array)[4]);
		static void setRow(Mat2 &matrix, int row, const Vec2 &vector);
		static void setCol(Mat2 &matrix, int col, const Vec2 &vector);

	public:
		static const Mat2 zero;
		static const Mat2 identity;

	private:
		float mMatrix[4];
	};

}

#endif		// RALFLIGHT_SRC_CORE_MATH_MAT2_H
