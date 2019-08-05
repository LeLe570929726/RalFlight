// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2016/12/11 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Vec4.h"
#include <cassert>
#include <cstring>
#if defined(RF_OS_WIN)
#include <intrin.h>
#elif defined(RF_OS_LINUX)
#include <xmmintrin.h>
#endif

// Core namespace
namespace Core {

const Vec4 Vec4::zero(0.0f, 0.0f, 0.0f, 0.0f);

Vec4::Vec4(real32 x, real32 y, real32 z, real32 w) : mVector{ x, y, z, w } {}

Vec4::Vec4(real32 (&array)[4]) : mVector{ array[0], array[1], array[2], array[3] } {}

Vec4::Vec4(const Vec4 &other) : mVector{ other.mVector[0], other.mVector[1], other.mVector[2], other.mVector[3] } {}

Vec4 &Vec4::operator=(const Vec4 &other) {
	std::memcpy(this->mVector, other.mVector, sizeof(this->mVector));
	return *this;
}

Vec4 &Vec4::add(const Vec4 &vector) {
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_load_ps(vector.mVector);
	sseRes = _mm_add_ps(sseA, sseB);
	_mm_store_ps(this->mVector, sseRes);
	return *this;
}

Vec4 &Vec4::sub(const Vec4 &vector) {
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_load_ps(vector.mVector);
	sseRes = _mm_sub_ps(sseA, sseB);
	_mm_store_ps(this->mVector, sseRes);
	return *this;
}

Vec4 &Vec4::mul(real32 scalar) {
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_broadcast_ss(&scalar);
	sseRes = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(this->mVector, sseRes);
	return *this;
}

Vec4 &Vec4::div(real32 scalar) {
	assert(scalar);
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_broadcast_ss(&scalar);
	sseRes = _mm_div_ps(sseA, sseB);
	_mm_store_ps(this->mVector, sseRes);
	return *this;
}

real32 Vec4::module() const {
	RF_ALIGN16 real32 vecRes[4] = { 0.0f };
	__m128 sseA, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseRes = _mm_mul_ps(sseA, sseA);
	_mm_store_ps(vecRes, sseRes);
	return Scalar::sqrt(vecRes[0] + vecRes[1] + vecRes[2] + vecRes[3]);
}

real32 Vec4::rmodule() const {
	RF_ALIGN16 real32 vecRes[4] = { 0.0f };
	__m128 sseA, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseRes = _mm_mul_ps(sseA, sseA);
	_mm_store_ps(vecRes, sseRes);
	return Scalar::rsqrt(vecRes[0] + vecRes[1] + vecRes[2] + vecRes[3]);
}

Vec4 &Vec4::normalize() {
	real32 scalar = this->rmodule();
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_broadcast_ss(&scalar);
	sseRes = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(this->mVector, sseRes);
	return *this;
}

real32 Vec4::dot(const Vec4 &vector) const {
	RF_ALIGN16 real32 vecRes[4] = { 0.0f };
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_load_ps(vector.mVector);
	sseRes = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(vecRes, sseRes);
	return vecRes[0] + vecRes[1] + vecRes[2] + vecRes[3];
}

// TODO

Vec4 Vec4::add(const Vec4 &vectorA, const Vec4 &vectorB) {
	auto tmpVec = vectorA;
	return tmpVec.add(vectorB);
}

Vec4 Vec4::sub(const Vec4 &vectorA, const Vec4 &vectorB) {
	auto tmpVec = vectorA;
	return tmpVec.sub(vectorB);
}

Vec4 Vec4::mul(const Vec4 &vector, real32 scalar) {
	auto tmpVec = vector;
	return tmpVec.mul(scalar);
}

Vec4 Vec4::div(const Vec4 &vector, real32 scalar) {
	assert(scalar);
	auto tmpVec = vector;
	return tmpVec.div(scalar);
}

real32 Vec4::module(const Vec4 &vector) { return vector.module(); }

real32 Vec4::rmodule(const Vec4 &vector) { return vector.rmodule(); }

Vec4 Vec4::normalize(const Vec4 &vector) {
	auto tmpVec = vector;
	return tmpVec.normalize();
}

real32 Vec4::dot(const Vec4 &vectorA, const Vec4 &vectorB) { return vectorA.dot(vectorB); }

real32 Vec4::angle(const Vec4 &vectorA, const Vec4 &vectorB) {
	RF_ALIGN16 real32 vectorAA[4] = { vectorA.mW, vectorA.mX, vectorA.mY, vectorA.mZ };
	RF_ALIGN16 real32 vectorAB[4] = { vectorB.mX, vectorB.mW, vectorB.mZ, vectorB.mY };
	RF_ALIGN16 real32 vectorAC[4] = { vectorA.mW, vectorA.mY, vectorA.mZ, vectorA.mX };
	RF_ALIGN16 real32 vectorAD[4] = { vectorB.mY, vectorB.mW, vectorB.mX, vectorB.mZ };
	RF_ALIGN16 real32 vectorAE[4] = { vectorA.mW, vectorA.mZ, vectorA.mX, vectorA.mY };
	RF_ALIGN16 real32 vectorAF[4] = { vectorB.mZ, vectorB.mW, vectorB.mY, vectorB.mX };
	RF_ALIGN16 real32 vectorAResult[4] = { 0.0f };
	__m128 sseA, sseB, sseC, sseD, sseE, sseF, sseResult;
	Vec3 tempVector(0.0f, 0.0f, 0.0f);
	sseA = _mm_load_ps(vectorAA);
	sseB = _mm_load_ps(vectorAB);
	sseC = _mm_load_ps(vectorAC);
	sseD = _mm_load_ps(vectorAD);
	sseE = _mm_load_ps(vectorAE);
	sseF = _mm_load_ps(vectorAF);
	sseResult = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(vectorAResult, sseResult);
	tempVector.setX(vectorAResult[0] - vectorAResult[1] - vectorAResult[2] + vectorAResult[3]);
	sseResult = _mm_mul_ps(sseC, sseD);
	_mm_store_ps(vectorAResult, sseResult);
	tempVector.setY(vectorAResult[0] - vectorAResult[1] - vectorAResult[2] + vectorAResult[3]);
	sseResult = _mm_mul_ps(sseE, sseF);
	_mm_store_ps(vectorAResult, sseResult);
	tempVector.setZ(vectorAResult[0] - vectorAResult[1] - vectorAResult[2] + vectorAResult[3]);
	return Scalar::radianToDegree(Scalar::atan(tempVector.module() / Vec4::dot(vectorA, vectorB)));
}

Vec4 Vec4::project(const Vec4 &vectorA, const Vec4 &vectorB) {
	real32 module = vectorB.rmodule();
	real32 scalar = Vec4::dot(vectorA, vectorB) * (module * module); // u' = ((u · v) / |v|^2) * v
	RF_ALIGN16 real32 vectorAA[4] = { vectorB.mX, vectorB.mY, vectorB.mZ, vectorB.mW };
	RF_ALIGN16 real32 vectorAB[4] = { scalar, scalar, scalar, scalar };
	RF_ALIGN16 real32 vectoraResult[4] = { 0.0f };
	__m128 sseA, sseB, sseResult;
	sseA = _mm_load_ps(vectorAA);
	sseB = _mm_load_ps(vectorAB);
	sseResult = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(vectoraResult, sseResult);
	return Vec4(vectoraResult[0], vectoraResult[1], vectoraResult[2], vectoraResult[3]);
}

real32 Vec4::x(const Vec4 &vector) { return vector.mX; }

real32 Vec4::y(const Vec4 &vector) { return vector.mY; }

real32 Vec4::z(const Vec4 &vector) { return vector.mZ; }

real32 Vec4::w(const Vec4 &vector) { return vector.mW; }

void Vec4::set(Vec4 &vector, real32 (&array)[4]) { vector = Vec4(array); }

void Vec4::setX(Vec4 &vector, real32 x) { vector.mX = x; }

void Vec4::setY(Vec4 &vector, real32 y) { vector.mY = y; }

void Vec4::setZ(Vec4 &vector, real32 z) { vector.mZ = z; }

void Vec4::setW(Vec4 &vector, real32 w) { vector.mW = w; }

bool Vec4::isZero(const Vec4 &vector) { return vector.mX == 0 && vector.mY == 0 && vector.mZ == 0 && vector.mW == 0; }

bool Vec4::isOne(const Vec4 &vector) { return vector.mX == 1 && vector.mY == 1 && vector.mZ == 1 && vector.mW == 1; }

} // namespace Core
