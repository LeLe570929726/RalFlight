// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2016/12/17 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Mat4.h"
#include <cassert>
#include <cstring>
#if defined(RF_OS_WIN)
#include <intrin.h>
#elif defined(RF_OS_LINUX)
#include <xmmintrin.h>
#endif

namespace Core {

const Mat4 Mat4::zero(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
const Mat4 Mat4::identity(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);

Mat4::Mat4(real32 m11, real32 m12, real32 m13, real32 m14, real32 m21, real32 m22, real32 m23, real32 m24, real32 m31,
		   real32 m32, real32 m33, real32 m34, real32 m41, real32 m42, real32 m43, real32 m44)
	: mMatrix{ m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44 } {}

Mat4::Mat4(real32 (&array)[16])
	: mMatrix{ array[0], array[1], array[2],  array[3],	 array[4],	array[5],  array[6],  array[7],
			   array[8], array[9], array[10], array[11], array[12], array[13], array[14], array[15] } {}

Mat4::Mat4(const Mat4 &other)
	: mMatrix{ other.mMatrix[0],  other.mMatrix[1],	 other.mMatrix[2],	other.mMatrix[3], other.mMatrix[4],	 other.mMatrix[5],
			   other.mMatrix[6],  other.mMatrix[7],	 other.mMatrix[8],	other.mMatrix[9], other.mMatrix[10], other.mMatrix[11],
			   other.mMatrix[12], other.mMatrix[13], other.mMatrix[14], other.mMatrix[15] } {}

Mat4 &Mat4::operator=(const Mat4 &other) {
	std::memcpy(this->mMatrix, other.mMatrix, sizeof(this->mMatrix));
	return *this;
}

Mat4 &Mat4::add(const Mat4 &matrix) {
	__m256 avxA, avxB, avxC, avxD, avxRes;
	avxA = _mm256_load_ps(this->mMatrix);
	avxB = _mm256_load_ps(&this->mMatrix[8]);
	avxC = _mm256_load_ps(matrix.mMatrix);
	avxD = _mm256_load_ps(&matrix.mMatrix[8]);
	avxRes = _mm256_add_ps(avxA, avxB);
	_mm256_store_ps(this->mMatrix, avxRes);
	avxRes = _mm256_add_ps(avxC, avxD);
	_mm256_store_ps(&this->mMatrix[8], avxRes);
	return *this;
}

Mat4 &Mat4::sub(const Mat4 &matrix) {
	__m256 avxA, avxB, avxC, avxD, avxRes;
	avxA = _mm256_load_ps(this->mMatrix);
	avxB = _mm256_load_ps(&this->mMatrix[8]);
	avxC = _mm256_load_ps(matrix.mMatrix);
	avxD = _mm256_load_ps(&matrix.mMatrix[8]);
	avxRes = _mm256_sub_ps(avxA, avxB);
	_mm256_store_ps(this->mMatrix, avxRes);
	avxRes = _mm256_sub_ps(avxC, avxD);
	_mm256_store_ps(&this->mMatrix[8], avxRes);
	return *this;
}

Mat4 &Mat4::mul(real32 scalar) {
	__m256 avxA, avxB, avxC, avxRes;
	avxA = _mm256_load_ps(this->mMatrix);
	avxB = _mm256_load_ps(&this->mMatrix[8]);
	avxC = _mm256_broadcast_ss(&scalar);
	avxRes = _mm256_mul_ps(avxA, avxC);
	_mm256_store_ps(this->mMatrix, avxRes);
	avxRes = _mm256_mul_ps(avxB, avxC);
	_mm256_store_ps(&this->mMatrix[8], avxRes);
	return *this;
}

Vec4 Mat4::mul(const Vec4 &vector) const {
	Vec4 tmpVec = Vec4::zero;
	__m128 sseA, sseB, sseC, sseD, sseE, sseRes;
	sseA = _mm_load_ps(this->mMatrix);
	sseB = _mm_load_ps(&this->mMatrix[4]);
	sseC = _mm_load_ps(&this->mMatrix[8]);
	sseD = _mm_load_ps(&this->mMatrix[12]);
	_MM_TRANSPOSE4_PS(sseA, sseB, sseC, sseD);
	sseE = _mm_broadcast_ss(&vector.mVector[0]);
	sseA = _mm_mul_ps(sseA, sseE);
	sseE = _mm_broadcast_ss(&vector.mVector[1]);
	sseB = _mm_mul_ps(sseB, sseE);
	sseE = _mm_broadcast_ss(&vector.mVector[2]);
	sseC = _mm_mul_ps(sseC, sseE);
	sseE = _mm_broadcast_ss(&vector.mVector[3]);
	sseD = _mm_mul_ps(sseD, sseE);
	sseB = _mm_add_ps(sseA, sseB);
	sseC = _mm_add_ps(sseB, sseC);
	sseRes = _mm_add_ps(sseC, sseD);
	_mm_store_ps(tmpVec.mVector, sseRes);
	return tmpVec;
}

Mat4 &Mat4::mul(const Mat4 &matrix) {
	__m256 avxA, avxB, avxC, avxD, avxE, avxF, avxG, avxH, avxI, avxJ, avxK, avxL, avxM, avxN, avxO;
	avxA = _mm256_load_ps(this->mMatrix);
	avxB = _mm256_load_ps(&this->mMatrix[8]);
	avxC = _mm256_load_ps(matrix.mMatrix);
	avxD = _mm256_load_ps(&matrix.mMatrix[8]);
	avxE = _mm256_shuffle_ps(avxA, avxA, _MM_SHUFFLE(0, 0, 0, 0));
	avxF = _mm256_shuffle_ps(avxB, avxB, _MM_SHUFFLE(0, 0, 0, 0));
	avxG = _mm256_permute2f128_ps(avxC, avxC, 0x00);
	avxH = _mm256_mul_ps(avxE, avxG);
	avxI = _mm256_mul_ps(avxF, avxG);
	avxE = _mm256_shuffle_ps(avxA, avxA, _MM_SHUFFLE(1, 1, 1, 1));
	avxF = _mm256_shuffle_ps(avxB, avxB, _MM_SHUFFLE(1, 1, 1, 1));
	avxG = _mm256_permute2f128_ps(avxC, avxC, 0x11);
	avxJ = _mm256_mul_ps(avxE, avxG);
	avxK = _mm256_mul_ps(avxF, avxG);
	avxE = _mm256_shuffle_ps(avxA, avxA, _MM_SHUFFLE(2, 2, 2, 2));
	avxF = _mm256_shuffle_ps(avxB, avxB, _MM_SHUFFLE(2, 2, 2, 2));
	avxG = _mm256_permute2f128_ps(avxD, avxD, 0x00);
	avxL = _mm256_mul_ps(avxE, avxG);
	avxM = _mm256_mul_ps(avxF, avxG);
	avxE = _mm256_shuffle_ps(avxA, avxA, _MM_SHUFFLE(3, 3, 3, 3));
	avxF = _mm256_shuffle_ps(avxB, avxB, _MM_SHUFFLE(3, 3, 3, 3));
	avxG = _mm256_permute2f128_ps(avxD, avxD, 0x11);
	avxN = _mm256_mul_ps(avxE, avxG);
	avxO = _mm256_mul_ps(avxF, avxG);
	avxH = _mm256_add_ps(avxH, avxJ);
	avxL = _mm256_add_ps(avxL, avxN);
	avxI = _mm256_add_ps(avxI, avxK);
	avxM = _mm256_add_ps(avxM, avxO);
	avxH = _mm256_add_ps(avxH, avxL);
	avxI = _mm256_add_ps(avxI, avxM);
	_mm256_store_ps(this->mMatrix, avxH);
	_mm256_store_ps(&this->mMatrix[8], avxI);
	return *this;
}

Mat4 &Mat4::div(real32 scalar) {
	assert(scalar);
	__m256 avxA, avxB, avxC, avxRes;
	avxA = _mm256_load_ps(this->mMatrix);
	avxB = _mm256_load_ps(&this->mMatrix[8]);
	avxC = _mm256_broadcast_ss(&scalar);
	avxRes = _mm256_div_ps(avxA, avxC);
	_mm256_store_ps(this->mMatrix, avxRes);
	avxRes = _mm256_div_ps(avxB, avxC);
	_mm256_store_ps(&this->mMatrix[8], avxRes);
	return *this;
}

Mat4 &Mat4::transpose() {
	__m128 sseA, sseB, sseC, sseD;
	sseA = _mm_load_ps(this->mMatrix);
	sseB = _mm_load_ps(&this->mMatrix[4]);
	sseC = _mm_load_ps(&this->mMatrix[8]);
	sseD = _mm_load_ps(&this->mMatrix[12]);
	_MM_TRANSPOSE4_PS(sseA, sseB, sseC, sseD);
	_mm_store_ps(this->mMatrix, sseA);
	_mm_store_ps(&this->mMatrix[4], sseB);
	_mm_store_ps(&this->mMatrix[8], sseC);
	_mm_store_ps(&this->mMatrix[12], sseD);
	return *this;
}

real32 Mat4::det() const {
	RF_ALIGN32 real32 vecRes[8] = { 0.0f };
	__m128 sseA, sseB, sseC, sseD;
	__m256 avxA, avxB, avxC, avxD, avxE, avxF, avxG, avxH, avxI, avxJ, avxK, avxL, avxM, avxN, avxRes;
	sseA = _mm_load_ps(this->mMatrix);
	sseB = _mm_load_ps(&this->mMatrix[4]);
	sseC = _mm_load_ps(&this->mMatrix[8]);
	sseD = _mm_load_ps(&this->mMatrix[12]);
	avxA = _mm256_set_m128(sseA, sseA);
	avxB = _mm256_set_m128(sseB, sseB);
	avxC = _mm256_set_m128(sseC, sseC);
	avxD = _mm256_set_m128(sseD, sseD);
	avxE = _mm256_permute_ps(avxA, 0x40);
	avxF = _mm256_permute_ps(avxA, 0x09);
	avxG = _mm256_blend_ps(avxE, avxF, 0xF0);
	avxE = _mm256_permute_ps(avxB, 0xB9);
	avxF = _mm256_permute_ps(avxB, 0x0F);
	avxH = _mm256_blend_ps(avxE, avxF, 0xF0);
	avxE = _mm256_permute_ps(avxA, 0xB9);
	avxF = _mm256_permute_ps(avxA, 0x0F);
	avxI = _mm256_blend_ps(avxE, avxF, 0xF0);
	avxE = _mm256_permute_ps(avxB, 0x40);
	avxF = _mm256_permute_ps(avxA, 0x09);
	avxJ = _mm256_blend_ps(avxE, avxF, 0xF0);
	avxE = _mm256_permute_ps(avxC, 0x16);
	avxF = _mm256_permute_ps(avxC, 0x00);
	avxK = _mm256_blend_ps(avxE, avxF, 0xF0);
	avxE = _mm256_permute_ps(avxD, 0xEF);
	avxF = _mm256_permute_ps(avxD, 0x06);
	avxL = _mm256_blend_ps(avxE, avxF, 0xF0);
	avxE = _mm256_permute_ps(avxC, 0xEF);
	avxF = _mm256_permute_ps(avxC, 0x06);
	avxM = _mm256_blend_ps(avxE, avxF, 0xF0);
	avxE = _mm256_permute_ps(avxD, 0x16);
	avxF = _mm256_permute_ps(avxD, 0x00);
	avxN = _mm256_blend_ps(avxE, avxF, 0xF0);
	avxH = _mm256_mul_ps(avxG, avxH);
	avxJ = _mm256_mul_ps(avxI, avxJ);
	avxL = _mm256_mul_ps(avxK, avxL);
	avxN = _mm256_mul_ps(avxM, avxN);
	avxJ = _mm256_sub_ps(avxH, avxJ);
	avxN = _mm256_sub_ps(avxL, avxN);
	avxRes = _mm256_mul_ps(avxJ, avxN);
	_mm256_store_ps(vecRes, avxRes);
	return vecRes[0] - vecRes[1] + vecRes[2] + vecRes[3] - vecRes[4] + vecRes[5];
}

real32 Mat4::get(uint8 col, uint8 row) const {
	assert(col > 0 && col < 5);
	assert(row > 0 && row < 5);
	return this->mMatrix[(col - 1) + ((row - 1) << 2)];
}

Vec4 Mat4::row(uint8 row) const {
	assert(row > 0 && row < 5);
	return Vec4(this->mMatrix[(row - 1) << 2], this->mMatrix[((row - 1) << 2) + 1], this->mMatrix[((row - 1) << 2) + 2],
				this->mMatrix[((row - 1) << 2) + 3]);
}

Vec4 Mat4::col(uint8 col) const {
	assert(col > 0 && col < 5);
	return Vec4(this->mMatrix[col - 1], this->mMatrix[col - 1 + 4], this->mMatrix[col - 1 + 8], this->mMatrix[col - 1 + 12]);
}

void Mat4::set(uint8 col, uint8 row, real32 scalar) {
	assert(col > 0 && col < 5);
	assert(row > 0 && row < 5);
	this->mMatrix[(col - 1) + ((row - 1) << 2)] = scalar;
}

void Mat4::set(real32 (&array)[16]) { std::memcpy(this->mMatrix, array, sizeof(this->mMatrix)); }

void Mat4::setRow(uint8 row, const Vec4 &vector) {
	assert(row > 0 && row < 5);
	this->mMatrix[(row - 1) << 2] = vector.mVector[0];
	this->mMatrix[((row - 1) << 2) + 1] = vector.mVector[1];
	this->mMatrix[((row - 1) << 2) + 2] = vector.mVector[2];
	this->mMatrix[((row - 1) << 2) + 3] = vector.mVector[3];
}

void Mat4::setCol(uint8 col, const Vec4 &vector) {
	assert(col > 0 && col < 5);
	this->mMatrix[col - 1] = vector.mVector[0];
	this->mMatrix[col - 1 + 4] = vector.mVector[1];
	this->mMatrix[col - 1 + 8] = vector.mVector[2];
	this->mMatrix[col - 1 + 12] = vector.mVector[3];
}

Mat4 Mat4::add(const Mat4 &matrixA, const Mat4 &matrixB) {
	auto tmpMat = matrixA;
	return tmpMat.add(matrixB);
}

Mat4 Mat4::sub(const Mat4 &matrixA, const Mat4 &matrixB) {
	auto tmpMat = matrixA;
	return tmpMat.sub(matrixB);
}

Mat4 Mat4::mul(const Mat4 &matrix, real32 scalar) {
	auto tmpMat = matrix;
	return tmpMat.mul(scalar);
}

Vec4 Mat4::mul(const Mat4 &matrix, const Vec4 &vector) { return matrix.mul(vector); }

Mat4 Mat4::mul(const Mat4 &matrixA, const Mat4 &matrixB) {
	auto tmpMat = matrixA;
	return tmpMat.mul(matrixB);
}

Mat4 Mat4::div(const Mat4 &matrix, real32 scalar) {
	assert(scalar);
	auto tmpMat = matrix;
	return tmpMat.div(scalar);
}

Mat4 Mat4::transpose(const Mat4 &matrix) {
	auto tmpMat = matrix;
	return tmpMat.transpose();
}

real32 Mat4::det(const Mat4 &matrix) { return matrix.det(); }

real32 Mat4::get(const Mat4 &matrix, int col, int row) {
	assert(col > 0 && col < 5);
	assert(row > 0 && row < 5);
	return matrix.get(col, row);
}

Vec4 Mat4::row(const Mat4 &matrix, int row) {
	assert(row > 0 && row < 5);
	return matrix.row(row);
}

Vec4 Mat4::col(const Mat4 &matrix, int col) {
	assert(col > 0 && col < 5);
	return matrix.col(col);
}

void Mat4::set(Mat4 &matrix, int col, int row, real32 scalar) {
	assert(col > 0 && col < 5);
	assert(row > 0 && row < 5);
	matrix.set(col, row, scalar);
}

void Mat4::set(Mat4 &matrix, real32 (&array)[16]) { matrix.set(array); }

void Mat4::setRow(Mat4 &matrix, int row, const Vec4 &vector) {
	assert(row > 0 && row < 5);
	matrix.setRow(row, vector);
}

void Mat4::setCol(Mat4 &matrix, int col, const Vec4 &vector) {
	assert(col > 0 && col < 5);
	matrix.setCol(col, vector);
}

} // namespace Core
