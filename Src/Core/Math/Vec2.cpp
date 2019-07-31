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
#include <cassert>
#include <cmath>
#include <cstring>
#if defined(RF_OS_WIN)
#include <intrin.h>
#elif defined(RF_OS_LINUX)
#include <xmmintrin.h>
#endif

namespace Core {

const Vec2 Vec2::zero(0.f, 0.0f);

Vec2::Vec2(real32 x, real32 y) : mVector{ x, y, 0.0f, 0.0f } {}

Vec2::Vec2(real32 (&array)[2]) : mVector{ array[0], array[1], 0.0f, 0.0f } {}

Vec2::Vec2(const Vec2 &other) : mVector{ other.mVector[0], other.mVector[1], 0.0f, 0.0f } {}

Vec2 &Vec2::operator=(const Vec2 &other) {
	std::memcpy(this->mVector, other.mVector, sizeof(this->mVector));
	return *this;
}

Vec2 &Vec2::add(const Vec2 &vector) {
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_load_ps(vector.mVector);
	sseRes = _mm_add_ps(sseA, sseB);
	_mm_store_ps(this->mVector, sseRes);
	return *this;
}

Vec2 &Vec2::sub(const Vec2 &vector) {
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_load_ps(vector.mVector);
	sseRes = _mm_sub_ps(sseA, sseB);
	_mm_store_ps(this->mVector, sseRes);
	return *this;
}

Vec2 &Vec2::mul(real32 scalar) {
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_broadcast_ss(&scalar);
	sseRes = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(this->mVector, sseRes);
	return *this;
}

Vec2 &Vec2::div(real32 scalar) {
	assert(scalar);
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_broadcast_ss(&scalar);
	sseRes = _mm_div_ps(sseA, sseB);
	_mm_store_ps(this->mVector, sseRes);
	return *this;
}

real32 Vec2::module() const { return std::hypot(this->mVector[0], this->mVector[1]); }

real32 Vec2::rmodule() const {
	RF_ALIGN16 real32 vecRes[4] = { 0.0f };
	__m128 sseA, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseRes = _mm_mul_ps(sseA, sseA);
	_mm_store_ps(vecRes, sseRes);
	return Scalar::rsqrt(vecRes[0] + vecRes[1]);
}

Vec2 &Vec2::normalize() {
	real32 rmoudule = this->rmodule();
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_broadcast_ss(&rmoudule);
	sseRes = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(this->mVector, sseRes);
	return *this;
}

real32 Vec2::dot(const Vec2 &vector) const {
	RF_ALIGN16 real32 vecRes[4] = { 0.0f };
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_load_ps(vector.mVector);
	sseRes = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(vecRes, sseRes);
	return vecRes[0] + vecRes[1];
}

real32 Vec2::cross(const Vec2 &vector) const {
	RF_ALIGN16 real32 vecRes[4] = { 0.0f };
	__m128 sseA, sseB, sseC, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_load_ps(vector.mVector);
	sseC = _mm_permute_ps(sseB, 0x11); // 00 01 00 01
	sseRes = _mm_mul_ps(sseA, sseC);
	_mm_store_ps(vecRes, sseRes);
	return vecRes[0] - vecRes[1];
}

real32 Vec2::angle(const Vec2 &vector) const {
	// Here use a small trick to avoid the situation when lose precision incalculating a real32 number.
	// a · b = |a| * |b| * cosθ = (xa * xb) + (ya * yb) a × b = |a| * |b| * sinθ
	//       = (xa * yb) - (ya * xb) tanθ = (a × b) / (a · b)
	// So we can use it to calculate tanθ, using this method can avoid some unnecessary calculating.
	RF_ALIGN16 real32 vecRes[4] = { 0.0f };
	__m128 sseA, sseB, sseC, sseD, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_load_ps(vector.mVector);
	sseC = _mm_permute_ps(sseA, 0x44); // 01 00 01 00
	sseD = _mm_permute_ps(sseB, 0x41); // 01 00 00 01
	sseRes = _mm_mul_ps(sseC, sseD);
	_mm_store_ps(vecRes, sseRes);
	return Scalar::atan2(vecRes[0] - vecRes[1], vecRes[2] + vecRes[3]);
}

Vec2 Vec2::project(const Vec2 &vector) const {
	Vec2 tmpVec = Vec2::zero;
	real32 scalar = this->dot(vector) * Scalar::pow(this->rmodule(), 2.0f); // a' = ((a · b) / |b| ^ 2) * b
	__m128 sseA, sseB, sseRes;
	sseA = _mm_load_ps(this->mVector);
	sseB = _mm_broadcast_ss(&scalar);
	sseRes = _mm_mul_ps(sseA, sseB);
	_mm_store_ps(tmpVec.mVector, sseRes);
	return tmpVec;
}

real32 Vec2::x() const { return this->mVector[0]; }

real32 Vec2::y() const { return this->mVector[1]; }

void Vec2::set(real32 (&array)[2]) { std::memcpy(this->mVector, array, sizeof(array)); }

void Vec2::setX(real32 x) { this->mVector[0] = x; }

void Vec2::setY(real32 y) { this->mVector[1] = y; }

bool Vec2::isZero() const { return this->mVector[0] == 0.0f && this->mVector[1] == 0.0f; }

bool Vec2::isOne() const { return this->mVector[0] == 1.0f && this->mVector[1] == 1.0f; }

Vec2 Vec2::add(const Vec2 &vectorA, const Vec2 &vectorB) {
	auto tmpVec = vectorA;
	return tmpVec.add(vectorB);
}

Vec2 Vec2::sub(const Vec2 &vectorA, const Vec2 &vectorB) {
	auto tmpVec = vectorA;
	return tmpVec.sub(vectorB);
}

Vec2 Vec2::mul(const Vec2 &vector, real32 scalar) {
	auto tmpVec = vector;
	return tmpVec.mul(scalar);
}

Vec2 Vec2::div(const Vec2 &vector, real32 scalar) {
	assert(scalar);
	auto tmpVec = vector;
	return tmpVec.div(scalar);
}

real32 Vec2::module(const Vec2 &vector) { return vector.module(); }

real32 Vec2::rmodule(const Vec2 &vector) { return vector.rmodule(); }

Vec2 Vec2::normalize(const Vec2 &vector) {
	auto tmpVec = vector;
	return tmpVec.normalize();
}

real32 Vec2::dot(const Vec2 &vectorA, const Vec2 &vectorB) { return vectorA.dot(vectorB); }

real32 Vec2::cross(const Vec2 &vectorA, const Vec2 &vectorB) { return vectorA.cross(vectorB); }

real32 Vec2::angle(const Vec2 &vectorA, const Vec2 &vectorB) { return vectorA.angle(vectorB); }

Vec2 Vec2::project(const Vec2 &vectorA, const Vec2 &vectorB) { return vectorA.project(vectorB); }

real32 Vec2::x(const Vec2 &vector) { return vector.x(); }

real32 Vec2::y(const Vec2 &vector) { return vector.y(); }

void Vec2::set(Vec2 &vector, real32 (&array)[2]) { vector.set(array); }

void Vec2::setX(Vec2 &vector, real32 x) { vector.setX(x); }

void Vec2::setY(Vec2 &vector, real32 y) { vector.setY(y); }

bool Vec2::isZero(const Vec2 &vector) { return vector.isZero(); }

bool Vec2::isOne(const Vec2 &vector) { return vector.isOne(); }

} // namespace Core