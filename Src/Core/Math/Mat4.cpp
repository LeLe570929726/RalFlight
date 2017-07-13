// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/17 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Mat4.h"

// Core namespace
namespace Core {

	Mat4::Mat4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24,
		float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44) :
		mMatrix{ m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44 } {
	}

	Mat4::Mat4(float(&array)[16]) :
		mMatrix{ array[0], array[1], array[2], array[3], array[4], array[5], array[6], array[7], array[8], array[9],
			array[10], array[11], array[12], array[13], array[14], array[15] } {
	}

	Mat4::Mat4(const Mat4 &other) :
		mMatrix{ other.mMatrix[0], other.mMatrix[1], other.mMatrix[2], other.mMatrix[3], other.mMatrix[4], other.mMatrix[5],
			other.mMatrix[6], other.mMatrix[7], other.mMatrix[8], other.mMatrix[9], other.mMatrix[10], other.mMatrix[11],
			other.mMatrix[12], other.mMatrix[13], other.mMatrix[14], other.mMatrix[15] } {
	}

	Mat4 &Mat4::operator=(const Mat4 &other) {
		for (int i = 0; i < 15; ++i) {
			this->mMatrix[i] = other.mMatrix[i];
		}
		return *this;
	}

	Mat4 Mat4::operator+(const Mat4 &matrix) const {
		return Mat4::add(*this, matrix);
	}

	Mat4 &Mat4::operator+=(const Mat4 &matrix) {
		*this = Mat4::add(*this, matrix);
		return *this;
	}

	Mat4 Mat4::operator-(const Mat4 &matrix) const {
		return Mat4::sub(*this, matrix);
	}

	Mat4 &Mat4::operator-=(const Mat4 &matrix) {
		*this = Mat4::sub(*this, matrix);
		return *this;
	}

	Mat4 Mat4::operator*(float scalar) const {
		return Mat4::mul(*this, scalar);
	}

	Mat4 &Mat4::operator*=(float scalar) {
		*this = Mat4::mul(*this, scalar);
		return *this;
	}

	Vec4 Mat4::operator*(const Vec4 &vector) const {
		return Mat4::mul(*this, vector);
	}

	Mat4 Mat4::operator*(const Mat4 &matrix) const {
		return Mat4::mul(*this, matrix);
	}

	Mat4 &Mat4::operator*=(const Mat4 &matrix) {
		*this = Mat4::mul(*this, matrix);
		return *this;
	}

	Mat4 Mat4::operator/(float scalar) const {
		return Mat4::div(*this, scalar);
	}

	Mat4 &Mat4::operator/=(float scalar) {
		*this = Mat4::div(*this, scalar);
		return *this;
	}

	Mat4 &Mat4::add(const Mat4 &matrix) {
		*this = Mat4::add(*this, matrix);
		return *this;
	}

	Mat4 &Mat4::sub(const Mat4 &matrix) {
		*this = Mat4::sub(*this, matrix);
		return *this;
	}

	Mat4 &Mat4::mul(float scalar) {
		*this = Mat4::mul(*this, scalar);
		return *this;
	}

	Vec4 Mat4::mul(const Vec4 &vector) {
		return Mat4::mul(*this, vector);
	}

	Mat4 &Mat4::mul(const Mat4 &matrix) {
		*this = Mat4::mul(*this, matrix);
		return *this;
	}

	Mat4 &Mat4::div(float scalar) {
		*this = Mat4::div(*this, scalar);
		return *this;
	}

	Mat4 &Mat4::transpose() {
		*this = Mat4::transpose(*this);
		return *this;
	}

	inline float Mat4::get(int col, int row) const {
		if (col > 0 && col < 5 && row > 0 && row < 5) {
			return this->mMatrix[(col - 1) + ((row - 1) << 4)];
		} else {
			return 0.0f;
		}
	}

	inline Vec4 Mat4::row(int row) const {
		if (row > 0 && row < 5) {
			return Vec4(this->mMatrix[(row - 1) << 2], this->mMatrix[((row - 1) << 2) + 1], this->mMatrix[((row - 1) << 2) + 2], this->mMatrix[((row - 1) << 2) + 3]);
		} else {
			return Vec4(0.0f, 0.0f, 0.0f, 0.0f);
		}
	}

	inline Vec4 Mat4::col(int col) const {
		if (col > 0 && col < 5) {
			return Vec4(this->mMatrix[col - 1], this->mMatrix[col - 1 + 4], this->mMatrix[col - 1 + 8], this->mMatrix[col - 1 + 12]);
		} else {
			return Vec4(0.0f, 0.0f, 0.0f, 0.0f);
		}
	}

	inline bool Mat4::set(int col, int row, float scalar) {
		if (col > 0 && col < 5 && row > 0 && row < 5) {
			this->mMatrix[(col - 1) + ((row - 1) << 4)] = scalar;
			return true;
		} else {
			return false;
		}
	}

	inline void Mat4::set(float(&array)[16]) {
		for (int i = 0; i < 16; ++i) {
			this->mMatrix[i] = array[i];
		}
	}

	inline bool Mat4::setRow(int row, const Vec4 &vector) {
		if (row > 0 && row < 5) {
			this->mMatrix[(row - 1) << 2] = vector.x();
			this->mMatrix[((row - 1) << 2) + 1] = vector.y();
			this->mMatrix[((row - 1) << 2) + 2] = vector.z();
			this->mMatrix[((row - 1) << 2) + 3] = vector.w();
			return true;
		} else {
			return false;
		}
	}

	inline bool Mat4::setCol(int col, const Vec4 &vector) {
		if (col > 0 && col < 5) {
			this->mMatrix[col - 1] = vector.x();
			this->mMatrix[col - 1 + 4] = vector.y();
			this->mMatrix[col - 1 + 8] = vector.z();
			this->mMatrix[col - 1 + 12] = vector.w();
			return false;
		} else {
			return false;
		}
	}

	Mat4 Mat4::add(const Mat4 &matrixA, const Mat4 &matrixB) {
		float tempArray[16] = { 0.0f };
		for (int i = 0; i <= 12; i += 4) {
			__declspec(align(16)) float vectorA[4] = { matrixA.mMatrix[i], matrixA.mMatrix[i + 1],
													   matrixA.mMatrix[i + 2], matrixA.mMatrix[i + 3] };
			__declspec(align(16)) float vectorB[4] = { matrixB.mMatrix[i], matrixB.mMatrix[i + 1], 
													   matrixB.mMatrix[i + 2], matrixB.mMatrix[i + 3] };
			__declspec(align(16)) float vectorResult[4] = { 0.0f };
			__m128 sseA, sseB, sseResult;
			sseA = _mm_load_ps(vectorA);
			sseB = _mm_load_ps(vectorB);
			sseResult = _mm_add_ps(sseA, sseB);
			_mm_store_ps(vectorResult, sseResult);
			tempArray[i] = vectorResult[0];
			tempArray[i + 1] = vectorResult[1];
			tempArray[i + 2] = vectorResult[2];
			tempArray[i + 3] = vectorResult[3];
		}
		return Mat4(tempArray);
	}

	Mat4 Mat4::sub(const Mat4 &matrixA, const Mat4 &matrixB) {
		float tempArray[16] = { 0.0f };
		for (int i = 0; i <= 12; i += 4) {
			__declspec(align(16)) float vectorA[4] = { matrixA.mMatrix[i], matrixA.mMatrix[i + 1], 
													   matrixA.mMatrix[i + 2], matrixA.mMatrix[i + 3] };
			__declspec(align(16)) float vectorB[4] = { matrixB.mMatrix[i], matrixB.mMatrix[i + 1], 
													   matrixB.mMatrix[i + 2], matrixB.mMatrix[i + 3] };
			__declspec(align(16)) float vectorResult[4] = { 0.0f };
			__m128 sseA, sseB, sseResult;
			sseA = _mm_load_ps(vectorA);
			sseB = _mm_load_ps(vectorB);
			sseResult = _mm_sub_ps(sseA, sseB);
			_mm_store_ps(vectorResult, sseResult);
			tempArray[i] = vectorResult[0];
			tempArray[i + 1] = vectorResult[1];
			tempArray[i + 2] = vectorResult[2];
			tempArray[i + 3] = vectorResult[3];
		}
		return Mat4(tempArray);
	}

	Mat4 Mat4::mul(const Mat4 &matrix, float scalar) {
		float tempArray[16] = { 0.0f };
		for (int i = 0; i <= 12; i += 4) {
			__declspec(align(16)) float vectorA[4] = { matrix.mMatrix[i], matrix.mMatrix[i + 1], 
													   matrix.mMatrix[i + 2], matrix.mMatrix[i + 3] };
			__declspec(align(16)) float vectorB[4] = { scalar, scalar, scalar, scalar };
			__declspec(align(16)) float vectorResult[4] = { 0.0f };
			__m128 sseA, sseB, sseResult;
			sseA = _mm_load_ps(vectorA);
			sseB = _mm_load_ps(vectorB);
			sseResult = _mm_mul_ps(sseA, sseB);
			_mm_store_ps(vectorResult, sseResult);
			tempArray[i] = vectorResult[0];
			tempArray[i + 1] = vectorResult[1];
			tempArray[i + 2] = vectorResult[2];
			tempArray[i + 3] = vectorResult[3];
		}
		return Mat4(tempArray);
	}

	Vec4 Mat4::mul(const Mat4 &matrix, const Vec4 &vector) {
		float tempArray[4] = { 0.0f };
		__declspec(align(16)) float vectorA[4] = { vector.x(), vector.y(), vector.z(), vector.w() };
		__m128 sseA;
		sseA = _mm_load_ps(vectorA);
		for (int i = 0; i <= 12; i += 12) {
			__declspec(align(16)) float vectorB[4] = { matrix.mMatrix[i], matrix.mMatrix[i + 1], 
													   matrix.mMatrix[i + 2], matrix.mMatrix[i + 3] };
			__declspec(align(16)) float vectorResult[4] = { 0.0f };
			__m128 sseB, sseResult;
			sseB = _mm_load_ps(vectorB);
			sseResult = _mm_mul_ps(sseA, sseB);
			_mm_store_ps(vectorResult, sseResult);
			tempArray[static_cast<int>(i >> 2)] = vectorResult[0] + vectorResult[1] + vectorResult[2] + vectorResult[3];
		}
		return Vec4(tempArray);
	}

	Mat4 Mat4::mul(const Mat4 &matrixA, const Mat4 &matrixB) {
		float tempArray[16] = { 0.0f };
		for (int i = 0; i < 16; ++i) {
			__declspec(align(16)) float vectorA[4] = { matrixA.mMatrix[static_cast<int>(i >> 2)], matrixA.mMatrix[static_cast<int>(i >> 2) + 1],
													   matrixA.mMatrix[static_cast<int>(i >> 2) + 2], matrixA.mMatrix[static_cast<int>(i >> 2) + 3] };
			__declspec(align(16)) float vectorB[4] = { matrixB.mMatrix[(i % 4)], matrixB.mMatrix[(i % 4) + 4],
													   matrixB.mMatrix[(i % 4) + 8], matrixB.mMatrix[(i % 4) + 12] };
			__declspec(align(16)) float vectorResult[4] = { 0.0f };
			__m128 sseA, sseB, sseResult;
			sseA = _mm_load_ps(vectorA);
			sseB = _mm_load_ps(vectorB);
			sseResult = _mm_mul_ps(sseA, sseB);
			_mm_store_ps(vectorResult, sseResult);
			tempArray[i] = vectorResult[0] + vectorResult[1] + vectorResult[2] + vectorResult[3];
		}
		return Mat4(tempArray);
	}

	Mat4 Mat4::div(const Mat4 &matrix, float scalar) {
		float tempArray[16] = { 0.0f };
		for (int i = 0; i <= 12; i += 4) {
			__declspec(align(16)) float vectorA[4] = { matrix.mMatrix[i], matrix.mMatrix[i + 1], 
													   matrix.mMatrix[i + 2], matrix.mMatrix[i + 3] };
			__declspec(align(16)) float vectorB[4] = { scalar, scalar, scalar, scalar };
			__declspec(align(16)) float vectorResult[4] = { 0.0f };
			__m128 sseA, sseB, sseResult;
			sseA = _mm_load_ps(vectorA);
			sseB = _mm_load_ps(vectorB);
			sseResult = _mm_div_ps(sseA, sseB);
			_mm_store_ps(vectorResult, sseResult);
			tempArray[i] = vectorResult[0];
			tempArray[i + 1] = vectorResult[1];
			tempArray[i + 2] = vectorResult[2];
			tempArray[i + 3] = vectorResult[3];
		}
		return Mat4(tempArray);
	}

	Mat4 Mat4::transpose(const Mat4 &matrix) {
		Mat4 tempMatrix = matrix;
		float tempScalar;
		tempScalar = tempMatrix.mMatrix[1];
		tempMatrix.mMatrix[1] = tempMatrix.mMatrix[4];
		tempMatrix.mMatrix[4] = tempScalar;
		tempScalar = tempMatrix.mMatrix[2];
		tempMatrix.mMatrix[2] = tempMatrix.mMatrix[8];
		tempMatrix.mMatrix[8] = tempScalar;
		tempScalar = tempMatrix.mMatrix[3];
		tempMatrix.mMatrix[3] = tempMatrix.mMatrix[12];
		tempMatrix.mMatrix[12] = tempScalar;
		tempScalar = tempMatrix.mMatrix[7];
		tempMatrix.mMatrix[7] = tempMatrix.mMatrix[13];
		tempMatrix.mMatrix[13] = tempScalar;
		tempScalar = tempMatrix.mMatrix[11];
		tempMatrix.mMatrix[11] = tempMatrix.mMatrix[14];
		tempMatrix.mMatrix[14] = tempScalar;
		tempScalar = tempMatrix.mMatrix[6];
		tempMatrix.mMatrix[6] = tempMatrix.mMatrix[9];
		tempMatrix.mMatrix[9] = tempScalar;
		return tempMatrix;
	}

}