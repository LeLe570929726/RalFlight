// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2016/12/5 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Vec3.h"
#include <assert.h>
#if defined(RF_OS_WIN)
#include <intrin.h>
#elif defined(RF_OS_LINUX)
#include <xmmintrin.h>
#endif

namespace Core {

Vec3::Vec3(real32 x, real32 y, real32 z) : mX(x), mY(y), mZ(z) {}

Vec3::Vec3(real32 (&array)[3]) : mX(array[0]), mY(array[1]), mZ(array[2]) {}

Vec3::Vec3(const Vec3 &other) : mX(other.mX), mY(other.mY), mZ(other.mZ) {}

Vec3 &Vec3::operator=(const Vec3 &other) {
	this->mX = other.mX;
	this->mY = other.mY;
	this->mZ = other.mZ;
	return *this;
}

Vec3 Vec3::add(const Vec3 &vectorA, const Vec3 &vectorB) {
	RF_ALIGN16 real32 vectorAA[4] = { vectorA.mX, vectorA.mY, vectorA.mZ, 0.0f };
	RF_ALIGN16 real32 vectorAB[4] = { vectorB.mX, vectorB.mY, vectorB.mZ, 0.0f };
	RF_ALIGN16 real32 vectorAResult[4] = { 0.0f };
	__m128 sseA, sseB, sseResult;
	sseA = _mm_load_ps(vectorAA);
	sseB = _mm_load_ps(vectorAB);
	sseResult = _mm_add_ps(sseA, sseB);
	_mm_store_ps(vectorAResult, sseResult);
	return Vec3(vectorAResult[0], vectorAResult[1], vectorAResult[2]);
}

Vec3 Vec3::sub(const Vec3 &vectorA, const Vec3 &vectorB) {
	RF_ALIGN16 real32 vectorAA[4] = { vectorA.mX, vectorA.mY, vectorA.mZ, 0.0f };
	RF_ALIGN16 real32 vectorAB[4] = { vectorB.mX, vectorB.mY, vectorB.mZ, 0.0f };
	RF_ALIGN16 real32 vectorAResult[4] = { 0.0f };
	__m128 sseA, sseB, sseResult;
	sseA = _mm_load_ps(vectorAA);
	sseB = _mm_load_ps(vectorAB);
	sseResult = _mm_sub_ps(sseA, sseB);
	_mm_store_ps(vectorAResult, sseResult);
	return Vec3(vectorAResult[0], vectorAResult[1], vectorAResult[2]);
}

Vec3 Vec3::mul(const Vec3 &vector, real32 scalar) {
	RF_ALIGN16 real32 vectorA[4] = { vector.mX, vector.mY, vector.mZ, 0.0f };
	RF_ALIGN16 real32 vectorB[4] = { scalar, scalar, scalar, 0.0f };
	RF_ALIGN16 real32 vectorResult[4] = { 0.0f };
	__m128 sseA, sseB, sseResult;
	sseA = _mm_load_ps(vectorA);
	sseB = _mm_load_ps(vectorB);
	sseResult = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(vectorResult, sseResult);
	return Vec3(vectorResult[0], vectorResult[1], vectorResult[2]);
}

Vec3 Vec3::div(const Vec3 &vector, real32 scalar) {
	assert(scalar);
	RF_ALIGN16 real32 vectorA[4] = { vector.mX, vector.mY, vector.mZ, 0.0f };
	RF_ALIGN16 real32 vectorB[4] = { scalar, scalar, scalar, 0.0f };
	RF_ALIGN16 real32 vectorResult[4] = { 0.0f };
	__m128 sseA, sseB, sseResult;
	sseA = _mm_load_ps(vectorA);
	sseB = _mm_load_ps(vectorB);
	sseResult = _mm_div_ps(sseA, sseB);
	_mm_store_ps(vectorResult, sseResult);
	return Vec3(vectorResult[0], vectorResult[1], vectorResult[2]);
}

real32 Vec3::module(const Vec3 &vector) {
	RF_ALIGN16 real32 vectorA[4] = { vector.mX, vector.mY, vector.mZ, 0.0f };
	RF_ALIGN16 real32 vectorResult[4] = { 0.0f };
	__m128 sseA, sseB, sseResult;
	sseA = _mm_load_ps(vectorA);
	sseB = _mm_load_ps(vectorA);
	sseResult = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(vectorResult, sseResult);
	return Scalar::sqrt(vectorResult[1] + vectorResult[2] + vectorResult[3]);
}

real32 Vec3::rmodule(const Vec3 &vector) {
	RF_ALIGN16 real32 vectorA[4] = { vector.mX, vector.mY, vector.mZ, 0.0f };
	RF_ALIGN16 real32 vectorB[4] = { 0.0f }, vectorC[4] = { 0.0f }, vectorResult[4] = { 0.0f };
	__m128 sseA, sseB, sseC, sseD, sseResult;
	sseA = _mm_load_ps(vectorA);
	sseB = _mm_load_ps(vectorA);
	sseC = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(vectorB, sseC);
	vectorC[0] = vectorB[0] + vectorB[1] + vectorB[2];
	sseD = _mm_load_ps(vectorC);
	sseResult = _mm_rsqrt_ps(sseD);
	_mm_store_ps(vectorResult, sseResult);
	return vectorResult[0];
}

Vec3 Vec3::normalize(const Vec3 &vector) {
	real32 module = Vec3::rmodule(vector);
	assert(module);
	RF_ALIGN16 real32 vectorA[4] = { vector.mX, vector.mY, vector.mZ, 0.0f };
	RF_ALIGN16 real32 vectorB[4] = { module, module, module, 0.0f };
	RF_ALIGN16 real32 vectorResult[4] = { 0.0f };
	__m128 sseA, sseB, sseResult;
	sseA = _mm_load_ps(vectorA);
	sseB = _mm_load_ps(vectorB);
	sseResult = _mm_mul_ps(sseA, sseB); // Because the module we getting is reciprocal(1/module), so use multiplication here.
	_mm_store_ps(vectorResult, sseResult);
	return Vec3(vectorResult[0], vectorResult[1], vectorResult[2]);
}

real32 Vec3::dot(const Vec3 &vectorA, const Vec3 &vectorB) {
	RF_ALIGN16 real32 vectorAA[4] = { vectorA.mX, vectorA.mY, vectorA.mZ, 0.0f };
	RF_ALIGN16 real32 vectorAB[4] = { vectorB.mX, vectorB.mY, vectorB.mZ, 0.0f };
	RF_ALIGN16 real32 vectorAResult[4] = { 0.0f };
	__m128 sseA, sseB, sseResult;
	sseA = _mm_load_ps(vectorAA);
	sseB = _mm_load_ps(vectorAB);
	sseResult = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(vectorAResult, sseResult);
	return vectorAResult[0] + vectorAResult[1] + vectorAResult[2];
}

Vec3 Vec3::cross(const Vec3 &vectorA, const Vec3 &vectorB) {
	RF_ALIGN16 real32 vectorAA[4] = { vectorA.mY, vectorA.mZ, vectorA.mX, 0.0f };
	RF_ALIGN16 real32 vectorAB[4] = { vectorB.mZ, vectorB.mX, vectorB.mY, 0.0f };
	RF_ALIGN16 real32 vectorAC[4] = { vectorA.mZ, vectorA.mX, vectorA.mY, 0.0f };
	RF_ALIGN16 real32 vectorAD[4] = { vectorB.mY, vectorB.mZ, vectorB.mX, 0.0f };
	RF_ALIGN16 real32 vectorAResult[4] = { 0.0f };
	__m128 sseA, sseB, sseC, sseD, sseE, sseF, sseResult;
	sseA = _mm_load_ps(vectorAA);
	sseB = _mm_load_ps(vectorAB);
	sseC = _mm_load_ps(vectorAC);
	sseD = _mm_load_ps(vectorAD);
	sseE = _mm_mul_ps(sseA, sseB);
	sseF = _mm_mul_ps(sseC, sseD);
	sseResult = _mm_sub_ps(sseE, sseF);
	_mm_store_ps(vectorAResult, sseResult);
	return Vec3(vectorAResult[0], vectorAResult[1], vectorAResult[2]);
}

real32 Vec3::angle(const Vec3 &vectorA, const Vec3 &vectorB) {
	return Scalar::radianToDegree(Scalar::atan(Vec3::cross(vectorA, vectorB).module() / Vec3::dot(vectorA, vectorB)));
}

Vec3 Vec3::project(const Vec3 &vectorA, const Vec3 &vectorB) {
	real32 module = Vec3::rmodule(vectorB);
	real32 scalar = Vec3::dot(vectorA, vectorB) * (module * module); // u' = ((u · v) / |v|^2) * v
	RF_ALIGN16 real32 vectorAA[4] = { vectorB.mX, vectorB.mY, vectorB.mZ, 0.0f };
	RF_ALIGN16 real32 vectorAB[4] = { scalar, scalar, scalar, 0.0f };
	RF_ALIGN16 real32 vectorAResult[4] = { 0.0f };
	__m128 sseA, sseB, sseResult;
	sseA = _mm_load_ps(vectorAA);
	sseB = _mm_load_ps(vectorAB);
	sseResult = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(vectorAResult, sseResult);
	return Vec3(vectorAResult[0], vectorAResult[1], vectorAResult[2]);
}

real32 Vec3::getX(const Vec3 &vector) { return vector.mX; }

real32 Vec3::getY(const Vec3 &vector) { return vector.mY; }

real32 Vec3::getZ(const Vec3 &vector) { return vector.mZ; }

void Vec3::set(Vec3 &vector, real32 (&array)[3]) { vector = Vec3(array); }

void Vec3::setX(Vec3 &vector, real32 x) { vector.mX = x; }

void Vec3::setY(Vec3 &vector, real32 y) { vector.mY = y; }

void Vec3::setZ(Vec3 &vector, real32 z) { vector.mZ = z; }

bool Vec3::isZero(const Vec3 &vector) { return vector.mX == 0 && vector.mY == 0 && vector.mZ == 0; }

bool Vec3::isOne(const Vec3 &vector) { return vector.mX == 1 && vector.mY == 1 && vector.mZ == 1; }

} // namespace Core