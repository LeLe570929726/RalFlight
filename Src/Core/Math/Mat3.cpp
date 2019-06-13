// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2016/12/17 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Mat3.h"
#include <assert.h>
#include <cstring>
#include <utility>
#if defined(RF_OS_WIN)
#include <intrin.h>
#elif defined(RF_OS_LINUX)
#include <xmmintrin.h>
#endif

namespace Core {

const Mat3 Mat3::zero(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
const Mat3 Mat3::identity(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);

Mat3::Mat3(real32 m11, real32 m12, real32 m13, real32 m21, real32 m22, real32 m23, real32 m31, real32 m32, real32 m33)
	: mMatrix{ m11, m12, m13, m21, m22, m23, m31, m32, m33 } {}

Mat3::Mat3(real32 (&array)[9])
	: mMatrix{ array[0], array[1], array[2], array[3], array[4], array[5], array[6], array[7], array[8] } {}

Mat3::Mat3(const Mat3 &other)
	: mMatrix{ other.mMatrix[0], other.mMatrix[1], other.mMatrix[2], other.mMatrix[3], other.mMatrix[4],
			   other.mMatrix[5], other.mMatrix[6], other.mMatrix[7], other.mMatrix[8] } {}

Mat3 &Mat3::operator=(const Mat3 &other) {
	std::memcpy(this->mMatrix, other.mMatrix, sizeof(this->mMatrix));
	return *this;
}

Mat3 &Mat3::add(const Mat3 &matrix) {
	__m256 avxA, avxB, avxRes;
	avxA = _mm256_load_ps(this->mMatrix);
	avxB = _mm256_load_ps(matrix.mMatrix);
	avxRes = _mm256_add_ps(avxA, avxB);
	_mm256_store_ps(this->mMatrix, avxRes);
	this->mMatrix[8] += matrix.mMatrix[8];
	return *this;
}

Mat3 &Mat3::sub(const Mat3 &matrix) {
	__m256 avxA, avxB, avxRes;
	avxA = _mm256_load_ps(this->mMatrix);
	avxB = _mm256_load_ps(matrix.mMatrix);
	avxRes = _mm256_sub_ps(avxA, avxB);
	_mm256_store_ps(this->mMatrix, avxRes);
	this->mMatrix[8] -= matrix.mMatrix[8];
	return *this;
}

Mat3 &Mat3::mul(real32 scalar) {
	__m256 avxA, avxB, avxRes;
	avxA = _mm256_load_ps(this->mMatrix);
	avxB = _mm256_broadcast_ss(&scalar);
	avxRes = _mm256_mul_ps(avxA, avxB);
	_mm256_store_ps(this->mMatrix, avxRes);
	this->mMatrix[8] *= scalar;
	return *this;
}

Vec3 Mat3::mul(const Vec3 &vector) {
	real32 x = vector.x();
	real32 y = vector.y();
	real32 z = vector.z();
	RF_ALIGN16 real32 vecA[4] = { this->mMatrix[0], this->mMatrix[3], this->mMatrix[6], 0.0f };
	RF_ALIGN16 real32 vecB[4] = { this->mMatrix[1], this->mMatrix[4], this->mMatrix[7], 0.0f };
	RF_ALIGN16 real32 vecC[4] = { this->mMatrix[2], this->mMatrix[5], this->mMatrix[8], 0.0f };
	RF_ALIGN16 real32 vecRes[4] = { 0.0f };
	__m128 sseA, sseB, sseC, sseD, sseE, sseF, sseRes;
	sseA = _mm_load_ps(vecA);
	sseB = _mm_load_ps(vecB);
	sseC = _mm_load_ps(vecC);
	sseD = _mm_broadcast_ss(&x);
	sseE = _mm_broadcast_ss(&y);
	sseF = _mm_broadcast_ss(&z);
	sseD = _mm_mul_ss(sseA, sseD);
	sseE = _mm_mul_ss(sseB, sseE);
	sseF = _mm_mul_ss(sseC, sseF);
	sseRes = _mm_add_ss(_mm_add_ss(sseD, sseE), sseF);
	_mm_store_ps(vecRes, sseRes);
	return Vec3(vecRes[0], vecRes[1], vecRes[2]);
}

Mat3 Mat3::add(const Mat3 &matrixA, const Mat3 &matrixB) {
	auto tmpMat = matrixA;
	return tmpMat.add(matrixB);
}

Mat3 Mat3::sub(const Mat3 &matrixA, const Mat3 &matrixB) {
	auto tmpMat = matrixA;
	return tmpMat.sub(matrixB);
}

Mat3 Mat3::mul(const Mat3 &matrix, real32 scalar) {
	auto tmpMat = matrix;
	return tmpMat.mul(scalar);
}

Vec3 Mat3::mul(const Mat3 &matrix, const Vec3 &vector) {
	auto tmpMat = matrix;
	return tmpMat.mul(vector);
}

Mat3 Mat3::mul(const Mat3 &matrixA, const Mat3 &matrixB) {
	real32 tempArray[9] = { 0.0f };
	for (int i = 0; i < 9; ++i) {
		RF_ALIGN16 real32 vectorA[4] = { matrixA.mMatrix[static_cast<int>(i / 3)], matrixA.mMatrix[static_cast<int>(i / 3) + 1],
										 matrixA.mMatrix[static_cast<int>(i / 3) + 2], 0.0f };
		RF_ALIGN16 real32 vectorB[4] = { matrixB.mMatrix[(i % 3)], matrixB.mMatrix[(i % 3) + 3], matrixB.mMatrix[(i % 3) + 6],
										 0.0f };
		RF_ALIGN16 real32 vectorResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorA);
		sseB = _mm_load_ps(vectorB);
		sseResult = _mm_mul_ps(sseA, sseB);
		_mm_store_ps(vectorResult, sseResult);
		tempArray[i] = vectorResult[0] + vectorResult[1] + vectorResult[2];
	}
	return Mat3(tempArray);
}

Mat3 Mat3::div(const Mat3 &matrix, real32 scalar) {
	assert(scalar);
	real32 tempArray[9] = { 0.0f };
	for (int i = 0; i <= 6; i += 3) {
		RF_ALIGN16 real32 vectorA[4] = { matrix.mMatrix[i], matrix.mMatrix[i + 1], matrix.mMatrix[i + 2], 0.0f };
		RF_ALIGN16 real32 vectorB[4] = { scalar, scalar, scalar, 0.0f };
		RF_ALIGN16 real32 vectorResult[4] = { 0.0f };
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
	real32 tempScalar;
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

real32 Mat3::determinant(const Mat3 &matrix) {
	RF_ALIGN16 real32 vectorA[4] = { matrix.mMatrix[0], matrix.mMatrix[1], matrix.mMatrix[2], 0.0f };
	RF_ALIGN16 real32 vectorB[4] = { matrix.mMatrix[4], matrix.mMatrix[5], matrix.mMatrix[3], 0.0f };
	RF_ALIGN16 real32 vectorC[4] = { matrix.mMatrix[8], matrix.mMatrix[6], matrix.mMatrix[7], 0.0f };
	RF_ALIGN16 real32 vectorD[4] = { matrix.mMatrix[2], matrix.mMatrix[0], matrix.mMatrix[1], 0.0f };
	RF_ALIGN16 real32 vectorE[4] = { matrix.mMatrix[4], matrix.mMatrix[5], matrix.mMatrix[3], 0.0f };
	RF_ALIGN16 real32 vectorF[4] = { matrix.mMatrix[6], matrix.mMatrix[7], matrix.mMatrix[8], 0.0f };
	RF_ALIGN16 real32 vectorResultA[4] = { 0.0f };
	RF_ALIGN16 real32 vectorResultB[4] = { 0.0f };
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

real32 Mat3::get(const Mat3 &matrix, int col, int row) {
	assert(col > 0 && col < 4);
	assert(row > 0 && row < 4);
	return matrix.mMatrix[(col - 1) + ((row - 1) * 3)];
}

Vec3 Mat3::row(const Mat3 &matrix, int row) {
	assert(row > 0 && row < 4);
	return Vec3(matrix.mMatrix[(row - 1) * 3], matrix.mMatrix[((row - 1) * 3) + 1], matrix.mMatrix[((row - 1) * 3) + 2]);
}

Vec3 Mat3::col(const Mat3 &matrix, int col) {
	assert(col > 0 && col < 4);
	return Vec3(matrix.mMatrix[col - 1], matrix.mMatrix[col - 1 + 3], matrix.mMatrix[col - 1 + 6]);
}

void Mat3::set(Mat3 &matrix, int col, int row, real32 scalar) {
	assert(col > 0 && col < 4);
	assert(row > 0 && row < 4);
	matrix.mMatrix[(col - 1) + ((row - 1) * 3)] = scalar;
}

void Mat3::set(Mat3 &matrix, real32 (&array)[9]) {
	for (int i = 0; i < 9; ++i) {
		matrix.mMatrix[i] = array[i];
	}
}

void Mat3::setRow(Mat3 &matrix, int row, const Vec3 &vector) {
	assert(row > 0 && row < 4);
	matrix.mMatrix[(row - 1) * 3] = vector.x();
	matrix.mMatrix[((row - 1) * 3) + 1] = vector.y();
	matrix.mMatrix[((row - 1) * 3) + 2] = vector.x();
}

void Mat3::setCol(Mat3 &matrix, int col, const Vec3 &vector) {
	assert(col > 0 && col < 4);
	matrix.mMatrix[col - 1] = vector.x();
	matrix.mMatrix[col - 1 + 3] = vector.y();
	matrix.mMatrix[col - 1 + 6] = vector.x();
}

} // namespace Core