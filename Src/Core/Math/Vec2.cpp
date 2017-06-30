// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/7 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Vec2.h"

// Core namespace
namespace Core {

	Vec2::Vec2(float x, float y) :
		mX(x), mY(y) {
	}

	Vec2::Vec2(float(&array)[2]) :
		mX(array[0]), mY(array[1]) {
	}

	Vec2::Vec2(const Vec2 &other) :
		mX(other.mX), mY(other.mY) {
	}

	Vec2 &Vec2::operator=(const Vec2 &other) {
		this->mX = other.mX;
		this->mY = other.mY;
		return *this;
	}

	Vec2 Vec2::operator+(const Vec2 &vector) const {
		return Vec2::add(*this, vector);
	}

	Vec2 &Vec2::operator+=(const Vec2 &vector) {
		Vec2 tempVector = Vec2::add(*this, vector);
		this->mX = tempVector.mX;
		this->mY = tempVector.mY;
		return *this;
	}

	Vec2 Vec2::operator-(const Vec2 &vector) const {
		return Vec2::sub(*this, vector);
	}

	Vec2 &Vec2::operator-=(const Vec2 &vector) {
		Vec2 tempVector = Vec2::sub(*this, vector);
		this->mX = tempVector.mX;
		this->mY = tempVector.mY;
		return *this;
	}

	Vec2 Vec2::operator*(float scalar) const {
		return Vec2::mul(*this, scalar);
	}

	Vec2 &Vec2::operator*=(float scalar) {
		Vec2 tempVector = Vec2::mul(*this, scalar);
		this->mX = tempVector.mX;
		this->mY = tempVector.mY;
		return *this;
	}

	Vec2 Vec2::operator/(float scalar) const {
		return Vec2::div(*this, scalar);
	}

	Vec2 &Vec2::operator/=(float scalar) {
		Vec2 tempVector = Vec2::div(*this, scalar);
		this->mX = tempVector.mX;
		this->mY = tempVector.mY;
		return *this;
	}

	Vec2 &Vec2::add(const Vec2 &vector) {
		Vec2 tempVector = Vec2::add(*this, vector);
		this->mX = tempVector.mX;
		this->mY = tempVector.mY;
		return *this;
	}

	Vec2 &Vec2::sub(const Vec2 &vector) {
		Vec2 tempVector = Vec2::sub(*this, vector);
		this->mX = tempVector.mX;
		this->mY = tempVector.mY;
		return *this;
	}

	Vec2 &Vec2::mul(float scalar) {
		Vec2 tempVector = Vec2::mul(*this, scalar);
		this->mX = tempVector.mX;
		this->mY = tempVector.mY;
		return *this;
	}

	Vec2 &Vec2::div(float scalar) {
		Vec2 tempVector = Vec2::div(*this, scalar);
		this->mX = tempVector.mX;
		this->mY = tempVector.mY;
		return *this;
	}

	float Vec2::module() const {
		return Vec2::module(*this);
	}

	// Module's reciprocal
	float Vec2::rmodule() const {
		return Vec2::rmodule(*this);
	}

	Vec2 &Vec2::normalize() {
		Vec2 tempVector = Vec2::normalize(*this);
		this->mX = tempVector.mX;
		this->mY = tempVector.mY;
		return *this;
	}

	float Vec2::dot(const Vec2 &vector) const {
		return Vec2::dot(*this, vector);
	}

	float Vec2::cross(const Vec2 & vector) const {
		return Vec2::cross(*this, vector);
	}

	float Vec2::angle(const Vec2 &vector) const {
		return Vec2::angle(*this, vector);
	}

	Vec2 Vec2::project(const Vec2 &vector) const {
		return Vec2::project(*this, vector);
	}

	inline void Vec2::set(float(&array)[2]) {
		this->mX = array[0];
		this->mY = array[1];
	}

	inline void Vec2::setX(float x) {
		this->mX = x;
	}

	inline void Vec2::setY(float y) {
		this->mY = y;
	}

	inline bool Vec2::isZero() const {
		return this->mX == 0 && this->mY == 0;
	}

	inline bool Vec2::isOne() const {
		return this->mX == 1 && this->mY == 1;
	}

	inline float Vec2::x() const {
		return this->mX;
	}

	inline float Vec2::y() const {
		return this->mY;
	}

	Vec2 Vec2::add(const Vec2 &vectorA, const Vec2 &vectorB) {
		__declspec(align(16)) float vectorAA[4] = { vectorA.mX, vectorA.mY, 0.0f, 0.0f };
		__declspec(align(16)) float vectorAB[4] = { vectorB.mX, vectorB.mY, 0.0f, 0.0f };
		__declspec(align(16)) float vectorAResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorAA);
		sseB = _mm_load_ps(vectorAB);
		sseResult = _mm_add_ps(sseA, sseB);
		_mm_store_ps(vectorAResult, sseResult);
		return Vec2(vectorAResult[0], vectorAResult[1]);
	}

	Vec2 Vec2::sub(const Vec2 &vectorA, const Vec2 &vectorB) {
		__declspec(align(16)) float vectorAA[4] = { vectorA.mX, vectorA.mY, 0.0f, 0.0f };
		__declspec(align(16)) float vectorAB[4] = { vectorB.mX, vectorB.mY, 0.0f, 0.0f };
		__declspec(align(16)) float vectorAResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorAA);
		sseB = _mm_load_ps(vectorAB);
		sseResult = _mm_sub_ps(sseA, sseB);
		_mm_store_ps(vectorAResult, sseResult);
		return Vec2(vectorAResult[0], vectorAResult[1]);
	}

	Vec2 Vec2::mul(const Vec2 &vector, float scalar) {
		__declspec(align(16)) float vectorA[4] = { vector.mX, vector.mY, 0.0f, 0.0f };
		__declspec(align(16)) float vectorB[4] = { scalar, scalar, 0.0f, 0.0f };
		__declspec(align(16)) float vectorResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorA);
		sseB = _mm_load_ps(vectorB);
		sseResult = _mm_mul_ps(sseA, sseB);
		_mm_store_ps(vectorResult, sseResult);
		return Vec2(vectorResult[0], vectorResult[1]);
	}

	Vec2 Vec2::div(const Vec2 &vector, float scalar) {
		__declspec(align(16)) float vectorA[4] = { vector.mX, vector.mY, 0.0f, 0.0f };
		__declspec(align(16)) float vectorB[4] = { scalar, scalar, 0.0f, 0.0f };
		__declspec(align(16)) float vectorResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorA);
		sseB = _mm_load_ps(vectorB);
		sseResult = _mm_div_ps(sseA, sseB);
		_mm_store_ps(vectorResult, sseResult);
		return Vec2(vectorResult[0], vectorResult[1]);
	}

	float Vec2::module(const Vec2 &vector) {
		__declspec(align(16)) float vectorA[4] = { vector.mX, vector.mY, 0.0f, 0.0f };
		__declspec(align(16)) float vectorResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorA);
		sseB = _mm_load_ps(vectorA);
		sseResult = _mm_mul_ps(sseA, sseB);
		_mm_store_ps(vectorResult, sseResult);
		return Scalar<float>::sqrt(vectorResult[0] + vectorResult[1]);
	}

	float Vec2::rmodule(const Vec2 &vector) {
		__declspec(align(16)) float vectorA[4] = { vector.mX, vector.mY, 0.0f, 0.0f };
		__declspec(align(16)) float vectorB[4] = { 0.0f }, vectorC[4] = { 0.0f }, vectorResult[4] = { 0.0f };
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
		float module = Vec2::rmodule(vector);
		__declspec(align(16)) float vectorA[4] = { vector.mX, vector.mY, 0.0f, 0.0f };
		__declspec(align(16)) float vectorB[4] = { module, module, 0.0f, 0.0f };
		__declspec(align(16)) float vectorResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorA);
		sseB = _mm_load_ps(vectorB);
		sseResult = _mm_mul_ps(sseA, sseB);        // Because the module we getting is reciprocal(1/module), so use multiplication here.
		_mm_store_ps(vectorResult, sseResult);
		return Vec2(vectorResult[0], vectorResult[1]);
	}

	float Vec2::dot(const Vec2 &vectorA, const Vec2 &vectorB) {
		__declspec(align(16)) float vectorAA[4] = { vectorA.mX, vectorA.mY, 0.0f, 0.0f };
		__declspec(align(16)) float vectorAB[4] = { vectorB.mX, vectorB.mY, 0.0f, 0.0f };
		__declspec(align(16)) float vectorAResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorAA);
		sseB = _mm_load_ps(vectorAB);
		sseResult = _mm_mul_ps(sseA, sseB);
		_mm_store_ps(vectorAResult, sseResult);
		return vectorAResult[0] + vectorAResult[1];
	}

	float Vec2::cross(const Vec2 &vectorA, const Vec2 &vectorB) {
		__declspec(align(16)) float vectorAA[4] = { vectorA.mX, vectorA.mY, 0.0f, 0.0f };
		__declspec(align(16)) float vectorAB[4] = { vectorB.mY, vectorB.mX, 0.0f, 0.0f };
		__declspec(align(16)) float vectorAResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorAA);
		sseB = _mm_load_ps(vectorAB);
		sseResult = _mm_mul_ps(sseA, sseB);
		_mm_store_ps(vectorAResult, sseResult);
		return vectorAResult[0] - vectorAResult[1];
	}

	float Vec2::angle(const Vec2 &vectorA, const Vec2 &vectorB) {
		// Here use a small trick to avoid the situation when lose precision in calculating a float number.
		// a · b = |a| * |b| * cosθ = (xa * xb) + (ya * yb)
		// a × b = |a| * |b| * sinθ = (xa * yb) - (ya * xb)
		// tanθ = (a × b) / (a · b)
		// So we can use it to calculate tanθ, using this method can avoid some unnecessary calculating.
		__declspec(align(16)) float vectorAA[4] = { vectorA.mX, vectorA.mY, vectorA.mX, vectorA.mY };
		__declspec(align(16)) float vectorAB[4] = { vectorB.mY, vectorB.mX, vectorB.mX, vectorB.mY };
		__declspec(align(16)) float vectorAResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorAA);
		sseB = _mm_load_ps(vectorAB);
		sseResult = _mm_mul_ps(sseA, sseB);
		_mm_store_ps(vectorAResult, sseResult);
		return Scalar<float>::atan((vectorAResult[0] - vectorAResult[1]) / (vectorAResult[2] + vectorAResult[3]));
	}

	Vec2 Vec2::project(const Vec2 &vectorA, const Vec2 &vectorB) {
		float module = Vec2::rmodule(vectorB);
		float scalar = Vec2::dot(vectorA, vectorB) * (module * module);	// a' = ((a · b) / |b|^2) * b
		__declspec(align(16)) float vectorAA[4] = { vectorB.mX, vectorB.mY, 0.0f, 0.0f };
		__declspec(align(16)) float vectorAB[4] = { scalar, scalar, 0.0f, 0.0f };
		__declspec(align(16)) float vectorAResult[4] = { 0.0f };
		__m128 sseA;
		__m128 sseB;
		__m128 sseResult;
		sseA = _mm_load_ps(vectorAA);
		sseB = _mm_load_ps(vectorAB);
		sseResult = _mm_mul_ps(sseA, sseB);
		_mm_store_ps(vectorAResult, sseResult);
		return Vec2(vectorAResult[0], vectorAResult[1]);
	}

}