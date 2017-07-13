// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/16 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Mat2.h"

// Core namespace
namespace Core {

	Mat2::Mat2(float m11, float m12, float m21, float m22) :
		mMatrix{ m11, m12, m21, m22 } {
	}

	Mat2::Mat2(float(&array)[4]) :
		mMatrix{ array[0], array[1], array[2], array[3] } {
	}

	Mat2::Mat2(const Mat2 &other) :
		mMatrix{ other.mMatrix[0], other.mMatrix[1], other.mMatrix[2], other.mMatrix[3] } {
	}

	Mat2 &Mat2::operator=(const Mat2 &other) {
		this->mMatrix[0] = other.mMatrix[0];
		this->mMatrix[1] = other.mMatrix[1];
		this->mMatrix[2] = other.mMatrix[2];
		this->mMatrix[3] = other.mMatrix[3];
		return *this;
	}

	Mat2 Mat2::operator+(const Mat2 &matrix) const {
		return Mat2::add(*this, matrix);
	}

	Mat2 &Mat2::operator+=(const Mat2 &matrix) {
		*this = Mat2::add(*this, matrix);
		return *this;
	}

	Mat2 Mat2::operator-(const Mat2 &matrix) const {
		return Mat2::sub(*this, matrix);
	}

	Mat2 &Mat2::operator-=(const Mat2 &matrix) {
		*this = Mat2::sub(*this, matrix);
		return *this;
	}

	Mat2 Mat2::operator*(float scalar) const {
		return Mat2::mul(*this, scalar);
	}

	Mat2 &Mat2::operator*=(float scalar) {
		*this = Mat2::mul(*this, scalar);
		return *this;
	}

	Vec2 Mat2::operator*(const Vec2 &vector) const {
		return Mat2::mul(*this, vector);
	}

	Mat2 Mat2::operator*(const Mat2 &matrix) const {
		return Mat2::mul(*this, matrix);
	}

	Mat2 &Mat2::operator*=(const Mat2 &matrix) {
		*this = Mat2::mul(*this, matrix);
		return *this;
	}

	Mat2 Mat2::operator/(float scalar) const {
		return Mat2::div(*this, scalar);
	}

	Mat2 &Mat2::operator/=(float scalar) {
		*this = Mat2::div(*this, scalar);
		return *this;
	}

	Mat2 &Mat2::add(const Mat2 matrix) {
		*this = Mat2::add(*this, matrix);
		return *this;
	}

	Mat2 &Mat2::sub(const Mat2 matrix) {
		*this = Mat2::sub(*this, matrix);
		return *this;
	}

	Mat2 &Mat2::mul(float scalar) {
		*this = Mat2::mul(*this, scalar);
		return *this;
	}

	Vec2 Mat2::mul(const Vec2 &vector) {
		return Mat2::mul(*this, vector);
	}

	Mat2 &Mat2::mul(const Mat2 matrix) {
		*this = Mat2::mul(*this, matrix);
		return *this;
	}

	Mat2 Mat2::div(float scalar) {
		*this = Mat2::div(*this, scalar);
		return *this;
	}

	Mat2 &Mat2::transpose() {
		*this = Mat2::transpose(*this);
		return *this;
	}

	inline float Mat2::get(int col, int row) const {
		if (col > 0 && col < 3 && row > 0 && row < 3) {
			return this->mMatrix[(col - 1) + (2 * (row - 1))];
		} else {
			return 0.0f;
		}
	}

	inline Vec2 Mat2::row(int row) const {
		if (row > 0 && row < 3) {
			return Vec2(this->mMatrix[(row - 1) << 1], this->mMatrix[((row - 1) << 1) + 1]);
		} else {
			return Vec2(0.0f, 0.0f);
		}
	}

	inline Vec2 Mat2::col(int col) const {
		if (col > 0 && col < 3) {
			return Vec2(this->mMatrix[col - 1], this->mMatrix[col - 1 + 2]);
		} else {
			return Vec2(0.0f, 0.0f);
		}
	}

	inline bool Mat2::set(int col, int row, float scalar) {
		if (col > 0 && col < 3 && row > 0 && row < 3) {
			this->mMatrix[(col - 1) + (2 * (row - 1))] = scalar;
			return true;
		} else {
			return false;
		}
	}

	inline void Mat2::set(float(&array)[4]) {
		this->mMatrix[0] = array[0];
		this->mMatrix[1] = array[1];
		this->mMatrix[2] = array[2];
		this->mMatrix[3] = array[3];
	}

	inline bool Mat2::setRow(int row, const Vec2 &vector) {
		if (row > 0 && row < 3) {
			this->mMatrix[(row - 1) << 1] = vector.x();
			this->mMatrix[((row - 1) << 1) + 1] = vector.y();
			return true;
		} else {
			return false;
		}
	}

	inline bool Mat2::setCol(int col, const Vec2 &vector) {
		if (col > 0 && col < 3) {
			this->mMatrix[col - 1] = vector.x();
			this->mMatrix[col - 1 + 2] = vector.y();
			return true;
		} else {
			return false;
		}
	}

	Mat2 Mat2::add(const Mat2 &matrixA, const Mat2 &matrixB) {
		__declspec(align(16)) float vectorAA[4] = { matrixA.mMatrix[0], matrixA.mMatrix[1], matrixA.mMatrix[2], matrixA.mMatrix[3] };
		__declspec(align(16)) float vectorAB[4] = { matrixB.mMatrix[0], matrixB.mMatrix[1], matrixB.mMatrix[2], matrixB.mMatrix[3] };
		__declspec(align(16)) float vectorAResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorAA);
		sseB = _mm_load_ps(vectorAB);
		sseResult = _mm_add_ps(sseA, sseB);
		_mm_store_ps(vectorAResult, sseResult);
		return Mat2(vectorAResult[0], vectorAResult[1], vectorAResult[2], vectorAResult[3]);
	}

	Mat2 Mat2::sub(const Mat2 &matrixA, const Mat2 &matrixB) {
		__declspec(align(16)) float vectorAA[4] = { matrixA.mMatrix[0], matrixA.mMatrix[1], matrixA.mMatrix[2], matrixA.mMatrix[3] };
		__declspec(align(16)) float vectorAB[4] = { matrixB.mMatrix[0], matrixB.mMatrix[1], matrixB.mMatrix[2], matrixB.mMatrix[3] };
		__declspec(align(16)) float vectorAResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorAA);
		sseB = _mm_load_ps(vectorAB);
		sseResult = _mm_sub_ps(sseA, sseB);
		_mm_store_ps(vectorAResult, sseResult);
		return Mat2(vectorAResult[0], vectorAResult[1], vectorAResult[2], vectorAResult[3]);
	}

	Mat2 Mat2::mul(const Mat2 &matrix, float scalar) {
		__declspec(align(16)) float vectorA[4] = { matrix.mMatrix[0], matrix.mMatrix[1], matrix.mMatrix[2], matrix.mMatrix[3] };
		__declspec(align(16)) float vectorB[4] = { scalar, scalar, scalar, scalar };
		__declspec(align(16)) float vectorResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorA);
		sseB = _mm_load_ps(vectorB);
		sseResult = _mm_mul_ps(sseA, sseB);
		_mm_store_ps(vectorResult, sseResult);
		return Mat2(vectorResult[0], vectorResult[1], vectorResult[2], vectorResult[3]);
	}

	Vec2 Mat2::mul(const Mat2 &matrix, const Vec2 &vector) {
		__declspec(align(16)) float vectorA[4] = { matrix.mMatrix[0], matrix.mMatrix[1], matrix.mMatrix[2], matrix.mMatrix[3] };
		__declspec(align(16)) float vectorB[4] = { vector.x(), vector.y(), vector.x(), vector.y() };
		__declspec(align(16)) float vectorResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorA);
		sseB = _mm_load_ps(vectorB);
		sseResult = _mm_mul_ps(sseA, sseB);
		_mm_store_ps(vectorResult, sseResult);
		return Vec2(vectorResult[0] + vectorResult[1], vectorResult[2] + vectorResult[3]);
	}

	Mat2 Mat2::mul(const Mat2 &matrixA, const Mat2 &matrixB) {
		__declspec(align(16)) float vectorAA[4] = { matrixA.mMatrix[0], matrixA.mMatrix[1], matrixA.mMatrix[0], matrixA.mMatrix[1] };
		__declspec(align(16)) float vectorAB[4] = { matrixB.mMatrix[0], matrixB.mMatrix[2], matrixB.mMatrix[1], matrixB.mMatrix[3] };
		__declspec(align(16)) float vectorAC[4] = { matrixA.mMatrix[2], matrixA.mMatrix[3], matrixA.mMatrix[2], matrixA.mMatrix[3] };
		__declspec(align(16)) float vectorAD[4] = { matrixB.mMatrix[0], matrixB.mMatrix[2], matrixB.mMatrix[1], matrixB.mMatrix[3] };
		__declspec(align(16)) float vectorAResultA[4] = { 0.0f };
		__declspec(align(16)) float vectorAResultB[4] = { 0.0f };
		__m128 sseA, sseB, sseC, sseD, sseResultA, sseResultB;
		sseA = _mm_load_ps(vectorAA);
		sseB = _mm_load_ps(vectorAB);
		sseC = _mm_load_ps(vectorAC);
		sseD = _mm_load_ps(vectorAD);
		sseResultA = _mm_mul_ps(sseA, sseB);
		sseResultB = _mm_mul_ps(sseC, sseD);
		_mm_store_ps(vectorAResultA, sseResultA);
		_mm_store_ps(vectorAResultB, sseResultB);

		return Mat2(vectorAResultA[0] + vectorAResultA[1], vectorAResultA[2] + vectorAResultA[3], 
					vectorAResultB[0] + vectorAResultB[1], vectorAResultB[2] + vectorAResultB[3]);
	}

	Mat2 Mat2::div(const Mat2 &matrix, float scalar) {
		__declspec(align(16)) float vectorA[4] = { matrix.mMatrix[0], matrix.mMatrix[1], matrix.mMatrix[2], matrix.mMatrix[3] };
		__declspec(align(16)) float vectorB[4] = { scalar, scalar, scalar, scalar };
		__declspec(align(16)) float vectorResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorA);
		sseB = _mm_load_ps(vectorB);
		sseResult = _mm_div_ps(sseA, sseB);
		_mm_store_ps(vectorResult, sseResult);
		return Mat2(vectorResult[0], vectorResult[1], vectorResult[2], vectorResult[3]);
	}

	Mat2 Mat2::transpose(const Mat2 &matrix) {
		Mat2 tempMatrix = matrix;
		float tempScalar = tempMatrix.mMatrix[1];
		tempMatrix.mMatrix[1] = tempMatrix.mMatrix[2];
		tempMatrix.mMatrix[2] = tempScalar;
		return tempMatrix;
	}

}