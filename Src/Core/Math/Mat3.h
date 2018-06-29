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
 
#include "../Global/Token.h"
#include "Scalar.h"
#include "Vec3.h"
#include <assert.h>
#if defined(RF_OS_WIN)
	#include <intrin.h>
#elif defined(RF_OS_LINUX)
	#include <xmmintrin.h>
#endif

// Core namespace
namespace Core {

	class RF_API Mat3 {
	public:
		Mat3(real32 m11, real32 m12, real32 m13, real32 m21, real32 m22, real32 m23, real32 m31, real32 m32, real32 m33);
		Mat3(real32(&array)[9]);
		Mat3(const Mat3 &other);
		Mat3 &operator=(const Mat3 &other);
		~Mat3() = default;

	public:
		inline Mat3 operator+(const Mat3 &matrix) const {
			return Mat3::add(*this, matrix);
		}
		inline Mat3 &operator+=(const Mat3 &matrix) {
			*this = Mat3::add(*this, matrix);
			return *this;
		}
		inline Mat3 operator-(const Mat3 &matrix) const {
			return Mat3::sub(*this, matrix);
		}
		inline Mat3 &operator-=(const Mat3 &matrix) {
			*this = Mat3::sub(*this, matrix);
			return *this;
		}
		inline Mat3 operator*(real32 scalar) const {
			return Mat3::mul(*this, scalar);
		}
		inline Mat3 &operator*=(real32 scalar) {
			*this = Mat3::mul(*this, scalar);
			return *this;
		}
		inline Vec3 operator*(const Vec3 &vector) const {
			return Mat3::mul(*this, vector);
		}
		inline Mat3 operator*(const Mat3 &matrix) const {
			return Mat3::mul(*this, matrix);
		}
		inline Mat3 &operator*=(const Mat3 &matrix) {
			*this = Mat3::mul(*this, matrix);
			return *this;
		}
		inline Mat3 operator/(real32 scalar) const {
			return Mat3::div(*this, scalar);
		}
		inline Mat3 &operator/=(real32 scalar) {
			*this = Mat3::div(*this, scalar);
			return *this;
		}

	public:
		inline Mat3 &add(const Mat3 &matrix) {
			*this = Mat3::add(*this, matrix);
			return *this;
		}
		inline Mat3 &sub(const Mat3 &matrix) {
			*this = Mat3::sub(*this, matrix);
			return *this;
		}
		inline Mat3 &mul(real32 scalar) {
			*this = Mat3::mul(*this, scalar);
			return *this;
		}
		inline Vec3 mul(const Vec3 &vector) {
			return Mat3::mul(*this, vector);
		}
		inline Mat3 &mul(const Mat3 &matrix) {
			*this = Mat3::mul(*this, matrix);
			return *this;
		}
		inline Mat3 &div(real32 scalar) {
			*this = Mat3::div(*this, scalar);
			return *this;
		}
		inline Mat3 &transpose() {
			*this = Mat3::transpose(*this);
			return *this;
		}
		inline real32 determinant() {
			return Mat3::determinant(*this);
		}

	public:
		inline real32 get(int col, int row) const {
			return Mat3::get(*this, col, row);
		}
		inline Vec3 getRow(int row) const {
			return Mat3::getRow(*this, row);
		}
		inline Vec3 getCol(int col) const {
			return Mat3::getCol(*this, col);
		}
		inline void set(int col, int row, real32 scalar) {
			Mat3::set(*this, col, row, scalar);
		}
		inline void set(real32(&array)[9]) {
			Mat3::set(*this, array);
		}
		inline void setRow(int row, const Vec3 &vector) {
			Mat3::setRow(*this, row, vector);
		}
		inline void setCol(int col, const Vec3 &vector) {
			Mat3::setCol(*this, col, vector);
		}

	public:
		static Mat3 add(const Mat3 &matrixA, const Mat3 &matrixB);
		static Mat3 sub(const Mat3 &matrixA, const Mat3 &matrixB);
		static Mat3 mul(const Mat3 &matrix, real32 scalar);
		static Vec3 mul(const Mat3 &matrix, const Vec3 &vector);
		static Mat3 mul(const Mat3 &matrixA, const Mat3 &matrixB);
		static Mat3 div(const Mat3 &matrix, real32 scalar);
		static Mat3 transpose(const Mat3 &matrix);
		static real32 determinant(const Mat3 &matrix);

	public:
		static real32 get(const Mat3 &matrix, int col, int row);
		static Vec3 getRow(const Mat3 &matrix, int row);
		static Vec3 getCol(const Mat3 &matrix, int col);
		static void set(Mat3 &matrix, int col, int row, real32 scalar);
		static void set(Mat3 &matrix, real32(&array)[9]);
		static void setRow(Mat3 &matrix, int row, const Vec3 &vector);
		static void setCol(Mat3 &matrix, int col, const Vec3 &vector);

	public:
		static const Mat3 zero;
		static const Mat3 identity;

	private:
		real32 mMatrix[9];
	};

}