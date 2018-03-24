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
		Mat3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33);
		Mat3(float(&array)[9]);
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
		inline Mat3 operator*(float scalar) const {
			return Mat3::mul(*this, scalar);
		}
		inline Mat3 &operator*=(float scalar) {
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
		inline Mat3 operator/(float scalar) const {
			return Mat3::div(*this, scalar);
		}
		inline Mat3 &operator/=(float scalar) {
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
		inline Mat3 &mul(float scalar) {
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
		inline Mat3 &div(float scalar) {
			*this = Mat3::div(*this, scalar);
			return *this;
		}
		inline Mat3 &transpose() {
			*this = Mat3::transpose(*this);
			return *this;
		}
		inline float determinant() {
			return Mat3::determinant(*this);
		}

	public:
		inline float get(int col, int row) const {
			return Mat3::get(*this, col, row);
		}
		inline Vec3 getRow(int row) const {
			return Mat3::getRow(*this, row);
		}
		inline Vec3 getCol(int col) const {
			return Mat3::getCol(*this, col);
		}
		inline void set(int col, int row, float scalar) {
			Mat3::set(*this, col, row, scalar);
		}
		inline void set(float(&array)[9]) {
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
		static Mat3 mul(const Mat3 &matrix, float scalar);
		static Vec3 mul(const Mat3 &matrix, const Vec3 &vector);
		static Mat3 mul(const Mat3 &matrixA, const Mat3 &matrixB);
		static Mat3 div(const Mat3 &matrix, float scalar);
		static Mat3 transpose(const Mat3 &matrix);
		static float determinant(const Mat3 &matrix);

	public:
		static float get(const Mat3 &matrix, int col, int row);
		static Vec3 getRow(const Mat3 &matrix, int row);
		static Vec3 getCol(const Mat3 &matrix, int col);
		static void set(Mat3 &matrix, int col, int row, float scalar);
		static void set(Mat3 &matrix, float(&array)[9]);
		static void setRow(Mat3 &matrix, int row, const Vec3 &vector);
		static void setCol(Mat3 &matrix, int col, const Vec3 &vector);

	public:
		static const Mat3 zero;
		static const Mat3 identity;

	private:
		float mMatrix[9];
	};

}