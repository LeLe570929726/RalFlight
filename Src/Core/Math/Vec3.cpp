// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2016/12/5 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Vec3.h"
#include <cassert>
#include <cmath>
#include <cstring>
#if defined(RF_OS_WIN)
#include <intrin.h>
#elif defined(RF_OS_LINUX)
#include <xmmintrin.h>
#endif

namespace Core {

const Vec3 Vec3::zero(0.0f, 0.0f, 0.0f);

Vec3::Vec3(real32 x, real32 y, real32 z) : mVector{ x, y, z, 0.0f } {}

Vec3::Vec3(real32 (&array)[3]) : mVector{ array[0], array[1], array[2], 0.0f } {}

Vec3::Vec3(const Vec3 &other) : mVector{ other.mVector[0], other.mVector[1], other.mVector[2], 0.0f } {}

Vec3 &Vec3::operator=(const Vec3 &other) {
	std::memcpy(this->mVector, other.mVector, sizeof(this->mVector));
	return *this;
}

Vec3 &Vec3::add(const Vec3 &vector) {
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_load_ps(vector.mVector);
	sseRes = _mm_add_ps(sseA, sseB);
	_mm_store_ps(this->mVector, sseRes);
	return *this;
}

Vec3 &Vec3::sub(const Vec3 &vector) {
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_load_ps(vector.mVector);
	sseRes = _mm_sub_ps(sseA, sseB);
	_mm_store_ps(this->mVector, sseRes);
	return *this;
}

Vec3 &Vec3::mul(real32 scalar) {
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_broadcast_ss(&scalar);
	sseRes = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(this->mVector, sseRes);
	return *this;
}

Vec3 &Vec3::div(real32 scalar) {
	assert(scalar);
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_broadcast_ss(&scalar);
	sseRes = _mm_div_ps(sseA, sseB);
	_mm_store_ps(this->mVector, sseRes);
	return *this;
}

real32 Vec3::module() const { return std::hypot(this->mVector[0], this->mVector[1], this->mVector[2]); }

real32 Vec3::rmodule() const {
	RF_ALIGN16 real32 vecRes[4] = { 0.0f };
	__m128 sseA, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseRes = _mm_mul_ps(sseA, sseA);
	return Scalar::rsqrt(vecRes[0] + vecRes[1] + vecRes[2]);
}

Vec3 &Vec3::normalize() {
	real32 rmoudule = this->rmodule();
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_broadcast_ss(&rmoudule);
	sseRes = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(this->mVector, sseRes);
	return *this;
}

real32 Vec3::dot(const Vec3 &vector) const {
	RF_ALIGN16 real32 vecRes[4] = { 0.0f };
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_load_ps(vector.mVector);
	sseRes = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(vecRes, sseRes);
	return vecRes[0] + vecRes[1] + vecRes[2];
}

Vec3 Vec3::cross(const Vec3 &vector) const {
	Vec3 tmpVec = Vec3::zero;
	__m128 sseA, sseB, sseC, sseD, sseE, sseF, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_load_ps(vector.mVector);
	sseC = _mm_permute_ps(sseA, 0x09); // 00 00 10 01
	sseD = _mm_permute_ps(sseB, 0x12); // 00 01 00 10
	sseE = _mm_permute_ps(sseA, 0x12); // 00 01 00 10
	sseF = _mm_permute_ps(sseB, 0x09); // 00 00 10 01
	sseA = _mm_mul_ps(sseC, sseD);
	sseB = _mm_mul_ps(sseE, sseF);
	sseRes = _mm_sub_ps(sseA, sseB);
	_mm_store_ps(tmpVec.mVector, sseRes);
	return tmpVec;
}

// TODO

Vec3 Vec3::add(const Vec3 &vectorA, const Vec3 &vectorB) {
	auto tmpVec = vectorA;
	return tmpVec.add(vectorB);
}

Vec3 Vec3::sub(const Vec3 &vectorA, const Vec3 &vectorB) {
	auto tmpVec = vectorA;
	return tmpVec.sub(vectorB);
}

Vec3 Vec3::mul(const Vec3 &vector, real32 scalar) {
	auto tmpVec = vector;
	return tmpVec.mul(scalar);
}

Vec3 Vec3::div(const Vec3 &vector, real32 scalar) {
	assert(scalar);
	auto tmpVec = vector;
	return tmpVec.div(scalar);
}

real32 Vec3::module(const Vec3 &vector) { return vector.module(); }

real32 Vec3::rmodule(const Vec3 &vector) { return vector.rmodule(); }

Vec3 Vec3::normalize(const Vec3 &vector) {
	auto tmpVec = vector;
	return tmpVec.normalize();
}

real32 Vec3::dot(const Vec3 &vectorA, const Vec3 &vectorB) { return vectorA.dot(vectorB); }

Vec3 Vec3::cross(const Vec3 &vectorA, const Vec3 &vectorB){ return vectorA.cross(vectorB); }

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

real32 Vec3::x(const Vec3 &vector) { return vector.mX; }

real32 Vec3::y(const Vec3 &vector) { return vector.mY; }

real32 Vec3::z(const Vec3 &vector) { return vector.mZ; }

void Vec3::set(Vec3 &vector, real32 (&array)[3]) { vector = Vec3(array); }

void Vec3::setX(Vec3 &vector, real32 x) { vector.mX = x; }

void Vec3::setY(Vec3 &vector, real32 y) { vector.mY = y; }

void Vec3::setZ(Vec3 &vector, real32 z) { vector.mZ = z; }

bool Vec3::isZero(const Vec3 &vector) { return vector.mX == 0 && vector.mY == 0 && vector.mZ == 0; }

bool Vec3::isOne(const Vec3 &vector) { return vector.mX == 1 && vector.mY == 1 && vector.mZ == 1; }

} // namespace Core