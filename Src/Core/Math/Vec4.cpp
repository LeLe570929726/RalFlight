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

real32 Vec4::angle(const Vec4 &vector) const {
	RF_ALIGN16 real32 vecRes[4] = { 0.0f };
	__m128 sseA, sseB, sseC, sseD, sseRes;
	Vec3 tmpVec = Vec3::zero;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_load_ps(vector.mVector);
	sseC = _mm_permute_ps(sseA, 0x93); // 10 01 00 11
	sseD = _mm_permute_ps(sseB, 0x6C); // 01 10 11 00
	sseRes = _mm_mul_ps(sseC, sseD);
	_mm_store_ps(vecRes, sseRes);
	tmpVec.setX(vecRes[0] - vecRes[1] - vecRes[2] + vecRes[3]);
	sseC = _mm_permute_ps(sseA, 0x27); // 00 10 01 11
	sseD = _mm_permute_ps(sseB, 0x8D); // 10 00 11 01
	sseRes = _mm_mul_ps(sseC, sseD);
	_mm_store_ps(vecRes, sseRes);
	tmpVec.setY(vecRes[0] - vecRes[1] - vecRes[2] + vecRes[3]);
	sseC = _mm_permute_ps(sseA, 0x4B); // 01 00 10 11
	sseD = _mm_permute_ps(sseB, 0x1E); // 00 01 11 10
	sseRes = _mm_mul_ps(sseC, sseD);
	_mm_store_ps(vecRes, sseRes);
	tmpVec.setZ(vecRes[0] - vecRes[1] - vecRes[2] + vecRes[3]);
	return Scalar::atan2(tmpVec.module(), this->dot(vector));
}

Vec4 Vec4::project(const Vec4 &vector) const {
	Vec4 tmpVec = Vec4::zero;
	real32 scalar = this->dot(vector) * Scalar::pow(vector.rmodule(), 2.0f);
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_broadcast_ss(&scalar);
	sseRes = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(tmpVec.mVector, sseRes);
	return tmpVec;
}

real32 Vec4::x() const { return this->mVector[0]; }

real32 Vec4::y() const { return this->mVector[1]; }

real32 Vec4::z() const { return this->mVector[2]; }

real32 Vec4::w() const { return this->mVector[3]; }

void Vec4::set(real32 (&array)[4]) { std::memcpy(this->mVector, array, sizeof(array)); }

void Vec4::setX(real32 x) { this->mVector[0] = x; }

void Vec4::setY(real32 y) { this->mVector[1] = y; }

void Vec4::setZ(real32 z) { this->mVector[2] = z; }

void Vec4::setW(real32 w) { this->mVector[3] = w; }

bool Vec4::isZero() const {
	return this->mVector[0] == 0.0f && this->mVector[1] == 0.0f && this->mVector[2] == 0.0f && this->mVector[3] == 0.0f;
}

bool Vec4::isOne() const {
	return this->mVector[0] == 1.0f && this->mVector[1] == 1.0f && this->mVector[2] == 1.0f && this->mVector[3] == 1.0f;
}

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

real32 Vec4::angle(const Vec4 &vectorA, const Vec4 &vectorB) { return vectorA.angle(vectorB); }

Vec4 Vec4::project(const Vec4 &vectorA, const Vec4 &vectorB) { return vectorA.project(vectorB); }

real32 Vec4::x(const Vec4 &vector) { return vector.x(); }

real32 Vec4::y(const Vec4 &vector) { return vector.y(); }

real32 Vec4::z(const Vec4 &vector) { return vector.z(); }

real32 Vec4::w(const Vec4 &vector) { return vector.w(); }

void Vec4::set(Vec4 &vector, real32 (&array)[4]) { vector.set(array); }

void Vec4::setX(Vec4 &vector, real32 x) { vector.setX(x); }

void Vec4::setY(Vec4 &vector, real32 y) { vector.setY(y); }

void Vec4::setZ(Vec4 &vector, real32 z) { vector.setZ(z); }

void Vec4::setW(Vec4 &vector, real32 w) { vector.setW(w); }

bool Vec4::isZero(const Vec4 &vector) { return vector.isZero(); }

bool Vec4::isOne(const Vec4 &vector) { return vector.isOne(); }

} // namespace Core
