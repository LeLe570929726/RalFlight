// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2016/12/17 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once
 
#include "../Global/Global.h"
#include "Vec4.h"
#include <assert.h>
#if defined(RF_OS_WIN)
	#include <intrin.h>
#elif defined(RF_OS_LINUX)
	#include <xmmintrin.h>
#endif

// Core namespace
namespace Core {

	class RF_API Mat4 {
	public:
		Mat4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);
		Mat4(float(&array)[16]);
		Mat4(const Mat4 &other);
		Mat4 &operator=(const Mat4 &other);
		~Mat4() = default;

	public:
		inline Mat4 operator+(const Mat4 &matrix) const {
			return Mat4::add(*this, matrix);
		}
		inline Mat4 &operator+=(const Mat4 &matrix) {
			*this = Mat4::add(*this, matrix);
			return *this;
		}
		inline Mat4 operator-(const Mat4 &matrix) const {
			return Mat4::sub(*this, matrix);
		}
		inline Mat4 &operator-=(const Mat4 &matrix) {
			*this = Mat4::sub(*this, matrix);
			return *this;
		}
		inline Mat4 operator*(float scalar) const {
			return Mat4::mul(*this, scalar);
		}
		inline Mat4 &operator*=(float scalar) {
			*this = Mat4::mul(*this, scalar);
			return *this;
		}
		inline Vec4 operator*(const Vec4 &vector) const {
			return Mat4::mul(*this, vector);
		}
		inline Mat4 operator*(const Mat4 &matrix) const {
			return Mat4::mul(*this, matrix);
		}
		inline Mat4 &operator*=(const Mat4 &matrix) {
			*this = Mat4::mul(*this, matrix);
			return *this;
		}
		inline Mat4 operator/(float scalar) const {
			return Mat4::div(*this, scalar);
		}
		inline Mat4 &operator/=(float scalar) {
			*this = Mat4::div(*this, scalar);
			return *this;
		}

	public:
		inline Mat4 &add(const Mat4 &matrix) {
			*this = Mat4::add(*this, matrix);
			return *this;
		}
		inline Mat4 &sub(const Mat4 &matrix) {
			*this = Mat4::sub(*this, matrix);
			return *this;
		}
		inline Mat4 &mul(float scalar) {
			*this = Mat4::mul(*this, scalar);
			return *this;
		}
		inline Vec4 mul(const Vec4 &vector) {
			return Mat4::mul(*this, vector);
		}
		inline Mat4 &mul(const Mat4 &matrix) {
			*this = Mat4::mul(*this, matrix);
			return *this;
		}
		inline Mat4 &div(float scalar) {
			*this = Mat4::div(*this, scalar);
			return *this;
		}
		inline Mat4 &transpose() {
			*this = Mat4::transpose(*this);
			return *this;
		}

	public:
		inline float get(int col, int row) const {
			return Mat4::get(*this, col, row);
		}
		inline Vec4 getRow(int row) const {
			return Mat4::getRow(*this, row);
		}
		inline Vec4 getCol(int col) const {
			return Mat4::getCol(*this, col);
		}
		inline void set(int col, int row, float scalar) {
			Mat4::set(*this, col, row, scalar);
		}
		inline void set(float(&array)[16]) {
			Mat4::set(*this, array);
		}
		inline void setRow(int row, const Vec4 &vector) {
			Mat4::setRow(*this, row, vector);
		}
		inline void setCol(int col, const Vec4 &vector) {
			Mat4::setCol(*this, col, vector);
		}

	public:
		static Mat4 add(const Mat4 &matrixA, const Mat4 &matrixB);
		static Mat4 sub(const Mat4 &matrixA, const Mat4 &matrixB);
		static Mat4 mul(const Mat4 &matrix, float scalar);
		static Vec4 mul(const Mat4 &matrix, const Vec4 &vector);
		static Mat4 mul(const Mat4 &matrixA, const Mat4 &matrixB);
		static Mat4 div(const Mat4 &matrix, float scalar);
		static Mat4 transpose(const Mat4 &matrix);
		static float determinant(const Mat4 &matrix);

	public:
		static float get(const Mat4 &matrix, int col, int row);
		static Vec4 getRow(const Mat4 &matrix, int row);
		static Vec4 getCol(const Mat4 &matrix, int col);
		static void set(Mat4 &matrix, int col, int row, float scalar);
		static void set(Mat4 &matrix, float(&array)[16]);
		static void setRow(Mat4 &matrix, int row, const Vec4 &vector);
		static void setCol(Mat4 &matrix, int col, const Vec4 &vector);

	public:
		static const Mat4 zero;
		static const Mat4 identity;

	private:
		float mMatrix[16];
	};

}