// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2016/12/16 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Mat2.h"
#include <assert.h>
#include <cstring>
#if defined(RF_OS_WIN)
#include <intrin.h>
#elif defined(RF_OS_LINUX)
#include <xmmintrin.h>
#endif

namespace Core {

const Mat2 Mat2::zero(0.0f, 0.0f, 0.0f, 0.0f);
const Mat2 Mat2::identity(1.0f, 0.0f, 0.0f, 1.0f);

Mat2::Mat2() : mMatrix{ 0.0f, 0.0f, 0.0f, 0.0f } {}

Mat2::Mat2(real32 m11, real32 m12, real32 m21, real32 m22) : mMatrix{ m11, m12, m21, m22 } {}

Mat2::Mat2(real32 (&array)[4]) : mMatrix{ array[0], array[1], array[2], array[3] } {}

Mat2::Mat2(const Mat2 &other) : mMatrix{ other.mMatrix[0], other.mMatrix[1], other.mMatrix[2], other.mMatrix[3] } {}

Mat2 &Mat2::operator=(const Mat2 &other) {
	std::memcpy(this->mMatrix, other.mMatrix, sizeof(this->mMatrix));
	return *this;
}

Mat2 &Mat2::add(const Mat2 &matrix) {
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mMatrix);
	sseB = _mm_load_ps(matrix.mMatrix);
	sseRes = _mm_add_ps(sseA, sseB);
	_mm_store_ps(this->mMatrix, sseRes);
	return *this;
}

Mat2 &Mat2::sub(const Mat2 &matrix) {
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mMatrix);
	sseB = _mm_load_ps(matrix.mMatrix);
	sseRes = _mm_sub_ps(sseA, sseB);
	_mm_store_ps(this->mMatrix, sseRes);
	return *this;
}

Mat2 &Mat2::mul(real32 scalar) {
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mMatrix);
	sseB = _mm_set_ps1(scalar);
	sseRes = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(this->mMatrix, sseRes);
	return *this;
}

Vec2 Mat2::mul(const Vec2 &vector) const {
	RF_ALIGN16 real32 vecA[4] = { vector.x(), vector.y(), vector.x(), vector.y() };
	RF_ALIGN16 real32 vecRes[4] = { 0.0f };
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mMatrix);
	sseB = _mm_load_ps(vecA);
	sseRes = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(vecRes, sseRes);
	return Vec2(vecRes[0] + vecRes[1], vecRes[2] + vecRes[3]);
}

Mat2 &Mat2::mul(const Mat2 &matrix) {
	RF_ALIGN32 real32 vecA[8] = { this->mMatrix[0], this->mMatrix[0], this->mMatrix[1], this->mMatrix[1],
								  this->mMatrix[2], this->mMatrix[2], this->mMatrix[3], this->mMatrix[3] };
	RF_ALIGN32 real32 vecB[8] = { matrix.mMatrix[0], matrix.mMatrix[1], matrix.mMatrix[2], matrix.mMatrix[3],
								  matrix.mMatrix[0], matrix.mMatrix[1], matrix.mMatrix[2], matrix.mMatrix[3] };
	RF_ALIGN32 real32 vecRes[8] = { 0.0f };
	__m256 avxA, avxB, avxC;
	avxA = _mm256_load_ps(vecA);
	avxB = _mm256_load_ps(vecB);
	avxC = _mm256_mul_ps(avxA, avxB);
	avxA = _mm256_unpacklo_ps(avxC, avxC);
	avxB = _mm256_unpackhi_ps(avxC, avxC);
	avxC = _mm256_add_ps(avxA, avxB);
	_mm256_store_ps(vecRes, avxC);
	this->mMatrix[0] = vecRes[0];
	this->mMatrix[1] = vecRes[2];
	this->mMatrix[2] = vecRes[4];
	this->mMatrix[3] = vecRes[6];
	return *this;
}

Mat2 &Mat2::div(real32 scalar) {
	assert(scalar);
	RF_ALIGN16 real32 vecB[4] = { scalar, scalar, scalar, scalar };
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mMatrix);
	sseB = _mm_load_ps(vecB);
	sseRes = _mm_div_ps(sseA, sseB);
	_mm_store_ps(this->mMatrix, sseRes);
	return *this;
}

Mat2 &Mat2::transpose() {
	real32 tempScalar = this->mMatrix[1];
	this->mMatrix[1] = this->mMatrix[2];
	this->mMatrix[2] = tempScalar;
	return *this;
}

real32 Mat2::determinant() const {
	RF_ALIGN16 real32 vecA[4] = { this->mMatrix[0], this->mMatrix[1], 0, 0 };
	RF_ALIGN16 real32 vecB[4] = { this->mMatrix[3], this->mMatrix[2], 0, 0 };
	RF_ALIGN16 real32 vecRes[4] = { 0.0f };
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(vecA);
	sseB = _mm_load_ps(vecB);
	sseRes = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(vecRes, sseRes);
	return vecRes[0] - vecRes[1];
}

real32 Mat2::get(int row, int col) const {
	assert(col > 0 && col < 3);
	assert(row > 0 && row < 3);
	return this->mMatrix[(col - 1) + (2 * (row - 1))];
}

// More function here

Mat2 Mat2::add(const Mat2 &matrixA, const Mat2 &matrixB) {
	auto tmpMat = matrixA;
	return tmpMat.add(matrixB);
}

Mat2 Mat2::sub(const Mat2 &matrixA, const Mat2 &matrixB) {
	auto tmpMat = matrixA;
	return tmpMat.sub(matrixB);
}

Mat2 Mat2::mul(const Mat2 &matrix, real32 scalar) {
	auto tmpMat = matrix;
	return tmpMat.mul(scalar);
}

Vec2 Mat2::mul(const Mat2 &matrix, const Vec2 &vector) { return matrix.mul(vector); }

Mat2 Mat2::mul(const Mat2 &matrixA, const Mat2 &matrixB) {
	auto tmpMat = matrixA;
	return tmpMat.mul(matrixB);
}

Mat2 Mat2::div(const Mat2 &matrix, real32 scalar) {
	auto tmpMat = matrix;
	return tmpMat.div(scalar);
}

Mat2 Mat2::transpose(const Mat2 &matrix) {
	auto tmpMat = matrix;
	tmpMat.transpose();
	return tmpMat;
}

real32 Mat2::determinant(const Mat2 &matrix) { return matrix.determinant(); }

real32 Mat2::get(const Mat2 &matrix, int row, int col) {
	assert(col > 0 && col < 3);
	assert(row > 0 && row < 3);
	return matrix.get(row, col);
}

Vec2 Mat2::row(const Mat2 &matrix, int row) {
	assert(row > 0 && row < 3);
	return Vec2(matrix.mMatrix[(row - 1) << 1], matrix.mMatrix[((row - 1) << 1) + 1]);
}

Vec2 Mat2::col(const Mat2 &matrix, int col) {
	assert(col > 0 && col < 3);
	return Vec2(matrix.mMatrix[col - 1], matrix.mMatrix[col - 1 + 2]);
}

void Mat2::set(Mat2 &matrix, int col, int row, real32 scalar) {
	assert(col > 0 && col < 3);
	assert(row > 0 && row < 3);
	matrix.mMatrix[(col - 1) + (2 * (row - 1))] = scalar;
}

void Mat2::set(Mat2 &matrix, real32 (&array)[4]) { matrix = Mat2(array); }

void Mat2::setRow(Mat2 &matrix, int row, const Vec2 &vector) {
	assert(row > 0 && row < 3);
	matrix.mMatrix[(row - 1) << 1] = vector.x();
	matrix.mMatrix[((row - 1) << 1) + 1] = vector.y();
}

void Mat2::setCol(Mat2 &matrix, int col, const Vec2 &vector) {
	assert(col > 0 && col < 3);
	matrix.mMatrix[col - 1] = vector.x();
	matrix.mMatrix[col - 1 + 2] = vector.y();
}

} // namespace Core