// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2016/12/17 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Mat3.h"

// Core namespace
namespace Core {

	const Mat3 Mat3::zero(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	const Mat3 Mat3::identity(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);

	Mat3::Mat3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33) :
		mMatrix{ m11, m12, m13, m21, m22, m23, m31, m32, m33 } {
	}

	Mat3::Mat3(float(&array)[9]) :
		mMatrix{ array[0], array[1], array[2], array[3], array[4], array[5], array[6], array[7], array[8] } {
	}

	Mat3::Mat3(const Mat3 &other) :
		mMatrix{ other.mMatrix[0], other.mMatrix[1], other.mMatrix[2], other.mMatrix[3], other.mMatrix[4], other.mMatrix[5],
			other.mMatrix[6], other.mMatrix[7], other.mMatrix[8] } {
	}

	Mat3 &Mat3::operator=(const Mat3 &other) {
		for (int i = 0; i < 9; ++i) {
			this->mMatrix[i] = other.mMatrix[i];
		}
		return *this;
	}

	Mat3 Mat3::add(const Mat3 &matrixA, const Mat3 &matrixB) {
		float tempArray[9] = { 0.0f };
		for (int i = 0; i <= 6; i += 3) {
			RF_ALIGN16 float vectorA[4] = { matrixA.mMatrix[i], matrixA.mMatrix[i + 1], matrixA.mMatrix[i + 2], 0.0f };
			RF_ALIGN16 float vectorB[4] = { matrixB.mMatrix[i], matrixB.mMatrix[i + 1], matrixB.mMatrix[i + 2], 0.0f };
			RF_ALIGN16 float vectorResult[4] = { 0.0f };
			__m128 sseA, sseB, sseResult;
			sseA = _mm_load_ps(vectorA);
			sseB = _mm_load_ps(vectorB);
			sseResult = _mm_add_ps(sseA, sseB);
			_mm_store_ps(vectorResult, sseResult);
			tempArray[i] = vectorResult[0];
			tempArray[i + 1] = vectorResult[1];
			tempArray[i + 2] = vectorResult[2];
		}
		return Mat3(tempArray);
	}

	Mat3 Mat3::sub(const Mat3 &matrixA, const Mat3 &matrixB) {
		float tempArray[9] = { 0.0f };
		for (int i = 0; i <= 6; i += 3) {
			RF_ALIGN16 float vectorA[4] = { matrixA.mMatrix[i], matrixA.mMatrix[i + 1], matrixA.mMatrix[i + 2], 0.0f };
			RF_ALIGN16 float vectorB[4] = { matrixB.mMatrix[i], matrixB.mMatrix[i + 1], matrixB.mMatrix[i + 2], 0.0f };
			RF_ALIGN16 float vectorResult[4] = { 0.0f };
			__m128 sseA, sseB, sseResult;
			sseA = _mm_load_ps(vectorA);
			sseB = _mm_load_ps(vectorB);
			sseResult = _mm_sub_ps(sseA, sseB);
			_mm_store_ps(vectorResult, sseResult);
			tempArray[i] = vectorResult[0];
			tempArray[i + 1] = vectorResult[1];
			tempArray[i + 2] = vectorResult[2];
		}
		return Mat3(tempArray);
	}

	Mat3 Mat3::mul(const Mat3 &matrix, float scalar) {
		float tempArray[9] = { 0.0f };
		for (int i = 0; i <= 6; i += 3) {
			RF_ALIGN16 float vectorA[4] = { matrix.mMatrix[i], matrix.mMatrix[i + 1], matrix.mMatrix[i + 2], 0.0f };
			RF_ALIGN16 float vectorB[4] = { scalar, scalar, scalar, 0.0f };
			RF_ALIGN16 float vectorResult[4] = { 0.0f };
			__m128 sseA, sseB, sseResult;
			sseA = _mm_load_ps(vectorA);
			sseB = _mm_load_ps(vectorB);
			sseResult = _mm_mul_ps(sseA, sseB);
			_mm_store_ps(vectorResult, sseResult);
			tempArray[i] = vectorResult[0];
			tempArray[i + 1] = vectorResult[1];
			tempArray[i + 2] = vectorResult[2];
		}
		return Mat3(tempArray);
	}

	Vec3 Mat3::mul(const Mat3 &matrix, const Vec3 &vector) {
		float tempArray[3] = { 0.0f };
		RF_ALIGN16 float vectorA[4] = { vector.getX(), vector.getY(), vector.getZ(), 0.0f };
		__m128 sseA;
		sseA = _mm_load_ps(vectorA);
		for (int i = 0; i <= 6; i += 3) {
			RF_ALIGN16 float vectorB[4] = { matrix.mMatrix[i], matrix.mMatrix[i + 1], matrix.mMatrix[i + 2], 0.0f };
			RF_ALIGN16 float vectorResult[4] = { 0.0f };
			__m128 sseB, sseResult;
			sseB = _mm_load_ps(vectorB);
			sseResult = _mm_mul_ps(sseA, sseB);
			_mm_store_ps(vectorResult, sseResult);
			tempArray[static_cast<int>(i / 3)] = vectorResult[0] + vectorResult[1] + vectorResult[2];
		}
		return Vec3(tempArray);
	}

	Mat3 Mat3::mul(const Mat3 &matrixA, const Mat3 &matrixB) {
		float tempArray[9] = { 0.0f };
		for (int i = 0; i < 9; ++i) {
			RF_ALIGN16 float vectorA[4] = { matrixA.mMatrix[static_cast<int>(i / 3)], matrixA.mMatrix[static_cast<int>(i / 3) + 1],
				matrixA.mMatrix[static_cast<int>(i / 3) + 2], 0.0f };
			RF_ALIGN16 float vectorB[4] = { matrixB.mMatrix[(i % 3)], matrixB.mMatrix[(i % 3) + 3],
				matrixB.mMatrix[(i % 3) + 6], 0.0f };
			RF_ALIGN16 float vectorResult[4] = { 0.0f };
			__m128 sseA, sseB, sseResult;
			sseA = _mm_load_ps(vectorA);
			sseB = _mm_load_ps(vectorB);
			sseResult = _mm_mul_ps(sseA, sseB);
			_mm_store_ps(vectorResult, sseResult);
			tempArray[i] = vectorResult[0] + vectorResult[1] + vectorResult[2];
		}
		return Mat3(tempArray);
	}

	Mat3 Mat3::div(const Mat3 &matrix, float scalar) {
		assert(scalar);
		float tempArray[9] = { 0.0f };
		for (int i = 0; i <= 6; i += 3) {
			RF_ALIGN16 float vectorA[4] = { matrix.mMatrix[i], matrix.mMatrix[i + 1], matrix.mMatrix[i + 2], 0.0f };
			RF_ALIGN16 float vectorB[4] = { scalar, scalar, scalar, 0.0f };
			RF_ALIGN16 float vectorResult[4] = { 0.0f };
			__m128 sseA, sseB, sseResult;
			sseA = _mm_load_ps(vectorA);
			sseB = _mm_load_ps(vectorB);
			sseResult = _mm_div_ps(sseA, sseB);
			_mm_store_ps(vectorResult, sseResult);
			tempArray[i] = vectorResult[0];
			tempArray[i + 1] = vectorResult[1];
			tempArray[i + 2] = vectorResult[2];
		}
		return Mat3(tempArray);
	}

	Mat3 Mat3::transpose(const Mat3 &matrix) {
		Mat3 tempMatrix = matrix;
		float tempScalar;
		tempScalar = tempMatrix.mMatrix[1];
		tempMatrix.mMatrix[1] = tempMatrix.mMatrix[3];
		tempMatrix.mMatrix[3] = tempScalar;
		tempScalar = tempMatrix.mMatrix[2];
		tempMatrix.mMatrix[2] = tempMatrix.mMatrix[6];
		tempMatrix.mMatrix[6] = tempScalar;
		tempScalar = tempMatrix.mMatrix[5];
		tempMatrix.mMatrix[5] = tempMatrix.mMatrix[7];
		tempMatrix.mMatrix[7] = tempScalar;
		return tempMatrix;
	}

	float Mat3::determinant(const Mat3 &matrix) {
		RF_ALIGN16 float vectorA[4] = { matrix.mMatrix[0], matrix.mMatrix[1], matrix.mMatrix[2], 0.0f };
		RF_ALIGN16 float vectorB[4] = { matrix.mMatrix[4], matrix.mMatrix[5], matrix.mMatrix[3], 0.0f };
		RF_ALIGN16 float vectorC[4] = { matrix.mMatrix[8], matrix.mMatrix[6], matrix.mMatrix[7], 0.0f };
		RF_ALIGN16 float vectorD[4] = { matrix.mMatrix[2], matrix.mMatrix[0], matrix.mMatrix[1], 0.0f };
		RF_ALIGN16 float vectorE[4] = { matrix.mMatrix[4], matrix.mMatrix[5], matrix.mMatrix[3], 0.0f };
		RF_ALIGN16 float vectorF[4] = { matrix.mMatrix[6], matrix.mMatrix[7], matrix.mMatrix[8], 0.0f };
		RF_ALIGN16 float vectorResultA[4] = { 0.0f };
		RF_ALIGN16 float vectorResultB[4] = { 0.0f };
		__m128 sseA, sseB, sseC, sseD, sseE, sseF, sseResultA, sseResultB;
		sseA = _mm_load_ps(vectorA);
		sseB = _mm_load_ps(vectorB);
		sseC = _mm_load_ps(vectorC);
		sseD = _mm_load_ps(vectorD);
		sseE = _mm_load_ps(vectorE);
		sseF = _mm_load_ps(vectorF);
		sseB = _mm_mul_ps(sseA, sseB);
		sseResultA = _mm_mul_ps(sseB, sseC);
		sseE = _mm_mul_ps(sseD, sseE);
		sseResultB = _mm_mul_ps(sseE, sseF);
		_mm_store_ps(vectorResultA, sseResultA);
		_mm_store_ps(vectorResultB, sseResultB);
		return vectorResultA[0] + vectorResultA[1] + vectorResultA[2] - vectorResultB[0] - vectorResultB[1] - vectorResultB[2];
	}

	float Mat3::get(const Mat3 &matrix, int col, int row) {
		assert(col > 0 && col < 4);
		assert(row > 0 && row < 4);
		return matrix.mMatrix[(col - 1) + ((row - 1) * 3)];
	}

	Vec3 Mat3::getRow(const Mat3 &matrix, int row) {
		assert(row > 0 && row < 4);
		return Vec3(matrix.mMatrix[(row - 1) * 3], matrix.mMatrix[((row - 1) * 3) + 1], matrix.mMatrix[((row - 1) * 3) + 2]);
	}

	Vec3 Mat3::getCol(const Mat3 &matrix, int col) {
		assert(col > 0 && col < 4);
		return Vec3(matrix.mMatrix[col - 1], matrix.mMatrix[col - 1 + 3], matrix.mMatrix[col - 1 + 6]);
	}

	void Mat3::set(Mat3 &matrix, int col, int row, float scalar) {
		assert(col > 0 && col < 4);
		assert(row > 0 && row < 4);
		matrix.mMatrix[(col - 1) + ((row - 1) * 3)] = scalar;
	}

	void Mat3::set(Mat3 &matrix, float(&array)[9]) {
		for (int i = 0; i < 9; ++i) {
			matrix.mMatrix[i] = array[i];
		}
	}

	void Mat3::setRow(Mat3 &matrix, int row, const Vec3 &vector) {
		assert(row > 0 && row < 4);
		matrix.mMatrix[(row - 1) * 3] = vector.getX();
		matrix.mMatrix[((row - 1) * 3) + 1] = vector.getY();
		matrix.mMatrix[((row - 1) * 3) + 2] = vector.getZ();
	}

	void Mat3::setCol(Mat3 &matrix, int col, const Vec3 &vector) {
		assert(col > 0 && col < 4);
		matrix.mMatrix[col - 1] = vector.getX();
		matrix.mMatrix[col - 1 + 3] = vector.getY();
		matrix.mMatrix[col - 1 + 6] = vector.getZ();
	}

}