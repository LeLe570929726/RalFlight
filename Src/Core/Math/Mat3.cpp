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
	RF_ALIGN16 real32 vecA[4] = { this->mMatrix[0], this->mMatrix[3], this->mMatrix[6], 0.0f };
	RF_ALIGN16 real32 vecB[4] = { this->mMatrix[1], this->mMatrix[4], this->mMatrix[7], 0.0f };
	RF_ALIGN16 real32 vecC[4] = { this->mMatrix[2], this->mMatrix[5], this->mMatrix[8], 0.0f };
	RF_ALIGN16 real32 vecRes[4] = { 0.0f };
	__m128 sseA, sseB, sseC, sseD, sseE, sseF, sseRes;
	sseA = _mm_load_ps(vecA);
	sseB = _mm_load_ps(vecB);
	sseC = _mm_load_ps(vecC);
	sseD = _mm_broadcast_ss(&vector.mX);
	sseE = _mm_broadcast_ss(&vector.mY);
	sseF = _mm_broadcast_ss(&vector.mZ);
	sseD = _mm_mul_ss(sseA, sseD);
	sseE = _mm_mul_ss(sseB, sseE);
	sseF = _mm_mul_ss(sseC, sseF);
	sseRes = _mm_add_ss(_mm_add_ss(sseD, sseE), sseF);
	_mm_store_ps(vecRes, sseRes);
	return Vec3(vecRes[0], vecRes[1], vecRes[2]);
}

Mat3 &Mat3::mul(const Mat3 &matrix) {
	RF_ALIGN32 real32 vecA[8] = { this->mMatrix[0], this->mMatrix[0], this->mMatrix[0], this->mMatrix[1],
								  this->mMatrix[1], this->mMatrix[1], this->mMatrix[2], this->mMatrix[2] };
	RF_ALIGN32 real32 vecB[8] = { this->mMatrix[3], this->mMatrix[3], this->mMatrix[3], this->mMatrix[4],
								  this->mMatrix[4], this->mMatrix[4], this->mMatrix[5], this->mMatrix[5] };
	RF_ALIGN32 real32 vecC[8] = { this->mMatrix[6], this->mMatrix[6], this->mMatrix[6], this->mMatrix[7],
								  this->mMatrix[7], this->mMatrix[7], this->mMatrix[8], this->mMatrix[8] };
	RF_ALIGN16 real32 vecD[4] = { this->mMatrix[2], this->mMatrix[5], this->mMatrix[8], 0.0f };
	RF_ALIGN16 real32 vecRes[4] = { 0.0f };
	__m256 avxA, avxB, avxC, avxD, avxRes;
	__m128 sseA, sseB, sseRes;
	avxA = _mm256_load_ps(vecA);
	avxB = _mm256_load_ps(vecB);
	avxC = _mm256_load_ps(vecC);
	avxD = _mm256_load_ps(matrix.mMatrix);
	sseA = _mm_load_ps(vecD);
	sseB = _mm_broadcast_ss(&matrix.mMatrix[8]);
	avxA = _mm256_mul_ps(avxA, avxD);
	avxB = _mm256_mul_ps(avxB, avxD);
	avxC = _mm256_mul_ps(avxC, avxD);
	sseRes = _mm_mul_ps(sseA, sseB);
	avxRes = _mm256_add_ps(_mm256_add_ps(avxA, avxB), avxC);
	_mm256_store_ps(this->mMatrix, avxRes);
	_mm_store_ps(vecRes, sseRes);
	this->mMatrix[8] = vecRes[0] + vecRes[1] + vecRes[2];
	return *this;
}

Mat3 &Mat3::div(real32 scalar) {
	assert(scalar);
	__m256 avxA, avxB, avxRes;
	avxA = _mm256_load_ps(this->mMatrix);
	avxB = _mm256_broadcast_ss(&scalar);
	avxRes = _mm256_div_ps(avxA, avxB);
	_mm256_store_ps(this->mMatrix, avxRes);
	this->mMatrix[8] /= scalar;
	return *this;
}

Mat3 &Mat3::transpose() {
	real32 tempScalar;
	tempScalar = this->mMatrix[1];
	this->mMatrix[1] = this->mMatrix[3];
	this->mMatrix[3] = tempScalar;
	tempScalar = this->mMatrix[2];
	this->mMatrix[2] = this->mMatrix[6];
	this->mMatrix[6] = tempScalar;
	tempScalar = this->mMatrix[5];
	this->mMatrix[5] = this->mMatrix[7];
	this->mMatrix[7] = tempScalar;
	return *this;
}

real32 Mat3::det() const {
	RF_ALIGN32 real32 vecA[8] = {
		this->mMatrix[0], this->mMatrix[1], this->mMatrix[2], this->mMatrix[2], this->mMatrix[0], this->mMatrix[1], 0.0f, 0.0f
	};
	RF_ALIGN32 real32 vecB[8] = {
		this->mMatrix[4], this->mMatrix[5], this->mMatrix[3], this->mMatrix[4], this->mMatrix[5], this->mMatrix[3], 0.0f, 0.0f
	};
	RF_ALIGN32 real32 vecC[8] = {
		this->mMatrix[8], this->mMatrix[6], this->mMatrix[7], this->mMatrix[6], this->mMatrix[7], this->mMatrix[8], 0.0f, 0.0f
	};
	RF_ALIGN32 real32 vecRes[8] = { 0.0f };
	__m256 avxA, avxB, avxC, avxRes;
	avxA = _mm256_load_ps(vecA);
	avxB = _mm256_load_ps(vecB);
	avxC = _mm256_load_ps(vecC);
	avxRes = _mm256_mul_ps(_mm256_mul_ps(avxA, avxB), avxC);
	_mm256_store_ps(vecRes, avxRes);
	return vecRes[0] + vecRes[1] + vecRes[2] - vecRes[3] - vecRes[4] - vecRes[5];
}

real32 Mat3::get(uint8 col, uint8 row) const {
	assert(col > 0 && col < 4);
	assert(row > 0 && row < 4);
	return this->mMatrix[(col - 1) + ((row - 1) * 3)];
}

Vec3 Mat3::row(uint8 row) const {
	assert(row > 0 && row < 4);
	return Vec3(this->mMatrix[(row - 1) * 3], this->mMatrix[((row - 1) * 3) + 1], this->mMatrix[((row - 1) * 3) + 2]);
}

Vec3 Mat3::col(uint8 col) const {
	assert(col > 0 && col < 4);
	return Vec3(this->mMatrix[col - 1], this->mMatrix[col - 1 + 3], this->mMatrix[col - 1 + 6]);
}

void Mat3::set(uint8 col, uint8 row, real32 scalar) {
	assert(col > 0 && col < 4);
	assert(row > 0 && row < 4);
	this->mMatrix[(col - 1) + ((row - 1) * 3)] = scalar;
}

void Mat3::set(real32 (&array)[9]) { std::memcpy(this->mMatrix, array, sizeof(this->mMatrix)); }

void Mat3::setRow(uint8 row, const Vec3 &vector) {
	assert(row > 0 && row < 4);
	this->mMatrix[(row - 1) * 3] = vector.mX;
	this->mMatrix[((row - 1) * 3) + 1] = vector.mY;
	this->mMatrix[((row - 1) * 3) + 2] = vector.mZ;
}

void Mat3::setCol(uint8 col, const Vec3 &vector) {
	assert(col > 0 && col < 4);
	this->mMatrix[col - 1] = vector.mX;
	this->mMatrix[col - 1 + 3] = vector.mY;
	this->mMatrix[col - 1 + 6] = vector.mZ;
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
	auto tmpMat = matrixA;
	return tmpMat.mul(matrixB);
}

Mat3 Mat3::div(const Mat3 &matrix, real32 scalar) {
	assert(scalar);
	auto tmpMat = matrix;
	return tmpMat.div(scalar);
}

Mat3 Mat3::transpose(const Mat3 &matrix) {
	auto tmpMat = matrix;
	return tmpMat.transpose();
}

real32 Mat3::det(const Mat3 &matrix) { return matrix.det(); }

real32 Mat3::get(const Mat3 &matrix, uint8 col, uint8 row) {
	assert(col > 0 && col < 4);
	assert(row > 0 && row < 4);
	return matrix.get(col, row);
}

Vec3 Mat3::row(const Mat3 &matrix, uint8 row) {
	assert(row > 0 && row < 4);
	return matrix.row(row);
}

Vec3 Mat3::col(const Mat3 &matrix, uint8 col) {
	assert(col > 0 && col < 4);
	return Vec3(matrix.mMatrix[col - 1], matrix.mMatrix[col - 1 + 3], matrix.mMatrix[col - 1 + 6]);
}

void Mat3::set(Mat3 &matrix, uint8 col, uint8 row, real32 scalar) {
	assert(col > 0 && col < 4);
	assert(row > 0 && row < 4);
	matrix.set(col, row, scalar);
}

void Mat3::set(Mat3 &matrix, real32 (&array)[9]) { matrix.set(array); }

void Mat3::setRow(Mat3 &matrix, uint8 row, const Vec3 &vector) {
	assert(row > 0 && row < 4);
	matrix.setRow(row, vector);
}

void Mat3::setCol(Mat3 &matrix, uint8 col, const Vec3 &vector) {
	assert(col > 0 && col < 4);
	matrix.setCol(col, vector);
}

} // namespace Core