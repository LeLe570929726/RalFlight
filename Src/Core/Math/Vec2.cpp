// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2016/12/7 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Vec2.h"
#include <assert.h>
#if defined(RF_OS_WIN)
#include <intrin.h>
#elif defined(RF_OS_LINUX)
#include <xmmintrin.h>
#endif

namespace Core {

Vec2::Vec2(real32 x, real32 y) : mX(x), mY(y) {}

Vec2::Vec2(real32 (&array)[2]) : mX(array[0]), mY(array[1]) {}

Vec2::Vec2(const Vec2 &other) : mX(other.mX), mY(other.mY) {}

Vec2 &Vec2::operator=(const Vec2 &other) {
	this->mX = other.mX;
	this->mY = other.mY;
	return *this;
}

Vec2 Vec2::add(const Vec2 &vectorA, const Vec2 &vectorB) {
	RF_ALIGN16 real32 vectorAA[4] = { vectorA.mX, vectorA.mY, 0.0f, 0.0f };
	RF_ALIGN16 real32 vectorAB[4] = { vectorB.mX, vectorB.mY, 0.0f, 0.0f };
	RF_ALIGN16 real32 vectorAResult[4] = { 0.0f };
	__m128 sseA, sseB, sseResult;
	sseA = _mm_load_ps(vectorAA);
	sseB = _mm_load_ps(vectorAB);
	sseResult = _mm_add_ps(sseA, sseB);
	_mm_store_ps(vectorAResult, sseResult);
	return Vec2(vectorAResult[0], vectorAResult[1]);
}

Vec2 Vec2::sub(const Vec2 &vectorA, const Vec2 &vectorB) {
	RF_ALIGN16 real32 vectorAA[4] = { vectorA.mX, vectorA.mY, 0.0f, 0.0f };
	RF_ALIGN16 real32 vectorAB[4] = { vectorB.mX, vectorB.mY, 0.0f, 0.0f };
	RF_ALIGN16 real32 vectorAResult[4] = { 0.0f };
	__m128 sseA, sseB, sseResult;
	sseA = _mm_load_ps(vectorAA);
	sseB = _mm_load_ps(vectorAB);
	sseResult = _mm_sub_ps(sseA, sseB);
	_mm_store_ps(vectorAResult, sseResult);
	return Vec2(vectorAResult[0], vectorAResult[1]);
}

Vec2 Vec2::mul(const Vec2 &vector, real32 scalar) {
	RF_ALIGN16 real32 vectorA[4] = { vector.mX, vector.mY, 0.0f, 0.0f };
	RF_ALIGN16 real32 vectorB[4] = { scalar, scalar, 0.0f, 0.0f };
	RF_ALIGN16 real32 vectorResult[4] = { 0.0f };
	__m128 sseA, sseB, sseResult;
	sseA = _mm_load_ps(vectorA);
	sseB = _mm_load_ps(vectorB);
	sseResult = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(vectorResult, sseResult);
	return Vec2(vectorResult[0], vectorResult[1]);
}

Vec2 Vec2::div(const Vec2 &vector, real32 scalar) {
	assert(scalar);
	RF_ALIGN16 real32 vectorA[4] = { vector.mX, vector.mY, 0.0f, 0.0f };
	RF_ALIGN16 real32 vectorB[4] = { scalar, scalar, 0.0f, 0.0f };
	RF_ALIGN16 real32 vectorResult[4] = { 0.0f };
	__m128 sseA, sseB, sseResult;
	sseA = _mm_load_ps(vectorA);
	sseB = _mm_load_ps(vectorB);
	sseResult = _mm_div_ps(sseA, sseB);
	_mm_store_ps(vectorResult, sseResult);
	return Vec2(vectorResult[0], vectorResult[1]);
}

real32 Vec2::module(const Vec2 &vector) {
	RF_ALIGN16 real32 vectorA[4] = { vector.mX, vector.mY, 0.0f, 0.0f };
	RF_ALIGN16 real32 vectorResult[4] = { 0.0f };
	__m128 sseA, sseB, sseResult;
	sseA = _mm_load_ps(vectorA);
	sseB = _mm_load_ps(vectorA);
	sseResult = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(vectorResult, sseResult);
	return Scalar::sqrt(vectorResult[0] + vectorResult[1]);
}

real32 Vec2::rmodule(const Vec2 &vector) {
	RF_ALIGN16 real32 vectorA[4] = { vector.mX, vector.mY, 0.0f, 0.0f };
	RF_ALIGN16 real32 vectorB[4] = { 0.0f }, vectorC[4] = { 0.0f }, vectorResult[4] = { 0.0f };
	__m128 sseA, sseB, sseC, sseD, sseResult;
	sseA = _mm_load_ps(vectorA);
	sseB = _mm_load_ps(vectorA);
	sseC = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(vectorB, sseC);
	vectorC[0] = vectorB[0] + vectorB[1];
	sseD = _mm_load_ps(vectorC);
	sseResult = _mm_rsqrt_ps(sseD);
	_mm_store_ps(vectorResult, sseResult);
	return vectorResult[0];
}

Vec2 Vec2::normalize(const Vec2 &vector) {
	real32 module = Vec2::rmodule(vector);
	assert(module);
	RF_ALIGN16 real32 vectorA[4] = { vector.mX, vector.mY, 0.0f, 0.0f };
	RF_ALIGN16 real32 vectorB[4] = { module, module, 0.0f, 0.0f };
	RF_ALIGN16 real32 vectorResult[4] = { 0.0f };
	__m128 sseA, sseB, sseResult;
	sseA = _mm_load_ps(vectorA);
	sseB = _mm_load_ps(vectorB);
	sseResult = _mm_mul_ps(sseA, sseB); // Because the module we getting is reciprocal(1/module), so use multiplication here.
	_mm_store_ps(vectorResult, sseResult);
	return Vec2(vectorResult[0], vectorResult[1]);
}

real32 Vec2::dot(const Vec2 &vectorA, const Vec2 &vectorB) {
	RF_ALIGN16 real32 vectorAA[4] = { vectorA.mX, vectorA.mY, 0.0f, 0.0f };
	RF_ALIGN16 real32 vectorAB[4] = { vectorB.mX, vectorB.mY, 0.0f, 0.0f };
	RF_ALIGN16 real32 vectorAResult[4] = { 0.0f };
	__m128 sseA, sseB, sseResult;
	sseA = _mm_load_ps(vectorAA);
	sseB = _mm_load_ps(vectorAB);
	sseResult = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(vectorAResult, sseResult);
	return vectorAResult[0] + vectorAResult[1];
}

real32 Vec2::cross(const Vec2 &vectorA, const Vec2 &vectorB) {
	RF_ALIGN16 real32 vectorAA[4] = { vectorA.mX, vectorA.mY, 0.0f, 0.0f };
	RF_ALIGN16 real32 vectorAB[4] = { vectorB.mY, vectorB.mX, 0.0f, 0.0f };
	RF_ALIGN16 real32 vectorAResult[4] = { 0.0f };
	__m128 sseA, sseB, sseResult;
	sseA = _mm_load_ps(vectorAA);
	sseB = _mm_load_ps(vectorAB);
	sseResult = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(vectorAResult, sseResult);
	return vectorAResult[0] - vectorAResult[1];
}

real32 Vec2::angle(const Vec2 &vectorA, const Vec2 &vectorB) {
	// Here use a small trick to avoid the situation when lose precision in
	// calculating a real32 number.
	// a · b = |a| * |b| * cosθ = (xa * xb) + (ya * yb) a × b = |a| * |b| * sinθ = (xa * yb) - (ya * xb) tanθ = (a × b) / (a ·
	// b) So we can use it to calculate tanθ, using this method can avoid some unnecessary calculating.
	RF_ALIGN16 real32 vectorAA[4] = { vectorA.mX, vectorA.mY, vectorA.mX, vectorA.mY };
	RF_ALIGN16 real32 vectorAB[4] = { vectorB.mY, vectorB.mX, vectorB.mX, vectorB.mY };
	RF_ALIGN16 real32 vectorAResult[4] = { 0.0f };
	__m128 sseA, sseB, sseResult;
	sseA = _mm_load_ps(vectorAA);
	sseB = _mm_load_ps(vectorAB);
	sseResult = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(vectorAResult, sseResult);
	return Scalar::atan2(vectorAResult[2] + vectorAResult[3], vectorAResult[0] - vectorAResult[1]);
}

Vec2 Vec2::project(const Vec2 &vectorA, const Vec2 &vectorB) {
	real32 module = Vec2::rmodule(vectorB);
	real32 scalar = Vec2::dot(vectorA, vectorB) * (module * module); // a' = ((a · b) / |b|^2) * b
	RF_ALIGN16 real32 vectorAA[4] = { vectorB.mX, vectorB.mY, 0.0f, 0.0f };
	RF_ALIGN16 real32 vectorAB[4] = { scalar, scalar, 0.0f, 0.0f };
	RF_ALIGN16 real32 vectorAResult[4] = { 0.0f };
	__m128 sseA;
	__m128 sseB;
	__m128 sseResult;
	sseA = _mm_load_ps(vectorAA);
	sseB = _mm_load_ps(vectorAB);
	sseResult = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(vectorAResult, sseResult);
	return Vec2(vectorAResult[0], vectorAResult[1]);
}

real32 Vec2::x(const Vec2 &vector) { return vector.mX; }

real32 Vec2::y(const Vec2 &vector) { return vector.mY; }

void Vec2::set(Vec2 &vector, real32 (&array)[2]) { vector = Vec2(array); }

void Vec2::setX(Vec2 &vector, real32 x) { vector.mX = x; }

void Vec2::setY(Vec2 &vector, real32 y) { vector.mY = y; }

bool Vec2::isZero(const Vec2 &vector) { return vector.mX == 0 && vector.mY == 0; }

bool Vec2::isOne(const Vec2 &vector) { return vector.mX == 1 && vector.mY == 1; }

} // namespace Core