// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/5 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Vec3.h"

namespace Core {

	Vec3::Vec3(float x, float y, float z) :
		mX(x), mY(y), mZ(z) {
	}

	Vec3::Vec3(float(&array)[3]) :
		mX(array[0]), mY(array[1]), mZ(array[2]) {
	}

	Vec3::Vec3(const Vec3 &other) :
		mX(other.mX), mY(other.mY), mZ(other.mZ) {
	}

	Vec3 &Vec3::operator=(const Vec3 &other) {
		this->mX = other.mX;
		this->mY = other.mY;
		this->mZ = other.mZ;
		return *this;
	}

	Vec3 Vec3::operator+(const Vec3 &vector) const {
		return Vec3::add(*this, vector);
	}

	Vec3 &Vec3::operator+=(const Vec3 &vector) {
		Vec3 tempVector = Vec3::add(*this, vector);
		this->mX = tempVector.mX;
		this->mY = tempVector.mY;
		this->mZ = tempVector.mZ;
		return *this;
	}

	Vec3 Vec3::operator-(const Vec3 &vector) const {
		return Vec3::sub(*this, vector);
	}

	Vec3 &Vec3::operator-=(const Vec3 &vector) {
		Vec3 tempVector = Vec3::sub(*this, vector);
		this->mX = tempVector.mX;
		this->mY = tempVector.mY;
		this->mZ = tempVector.mZ;
		return *this;
	}

	Vec3 Vec3::operator*(float scalar) const {
		return Vec3::mul(*this, scalar);
	}

	Vec3 &Vec3::operator*=(float scalar) {
		Vec3 tempVector = Vec3::mul(*this, scalar);
		this->mX = tempVector.mX;
		this->mY = tempVector.mY;
		this->mZ = tempVector.mZ;
		return *this;
	}

	Vec3 Vec3::operator/(float scalar) const {
		return Vec3::mul(*this, scalar);
	}

	Vec3 &Vec3::operator/=(float scalar) {
		Vec3 tempVector = Vec3::div(*this, scalar);
		this->mX = tempVector.mX;
		this->mY = tempVector.mY;
		this->mZ = tempVector.mZ;
		return *this;
	}

	Vec3 &Vec3::add(const Vec3 &vector) {
		Vec3 tempVector = Vec3::add(*this, vector);
		this->mX = tempVector.mX;
		this->mY = tempVector.mY;
		this->mZ = tempVector.mZ;
		return *this;
	}

	Vec3 &Vec3::sub(const Vec3 &vector) {
		Vec3 tempVector = Vec3::sub(*this, vector);
		this->mX = tempVector.mX;
		this->mY = tempVector.mY;
		this->mZ = tempVector.mZ;
		return *this;
	}

	Vec3 &Vec3::mul(float scalar) {
		Vec3 tempVector = Vec3::mul(*this, scalar);
		this->mX = tempVector.mX;
		this->mY = tempVector.mY;
		this->mZ = tempVector.mZ;
		return *this;
	}

	Vec3 &Vec3::div(float scalar) {
		Vec3 tempVector = Vec3::div(*this, scalar);
		this->mX = tempVector.mX;
		this->mY = tempVector.mY;
		this->mZ = tempVector.mZ;
		return *this;
	}

	float Vec3::module() const {
		return Vec3::module(*this);
	}

	// Module's reciprocal
	float Vec3::rmodule() const {
		return Vec3::rmodule(*this);
	}

	Vec3 &Vec3::normalize() {
		Vec3 tempVector = Vec3::add(*this);
		this->mX = tempVector.mX;
		this->mY = tempVector.mY;
		this->mZ = tempVector.mZ;
		return *this;
	}

	float Vec3::dot(const Vec3 &vector) const {
		return Vec3::dot(*this, vector);
	}

	Vec3 Vec3::cross(const Vec3 &vector) const {
		return Vec3::cross(*this, vector);
	}

	float Vec3::angle(const Vec3 &vector) const {
		return Vec3::angle(*this, vector);
	}

	Vec3 Vec3::project(const Vec3 &vector) const {
		return Vec3::project(*this, vector);
	}

	inline void Vec3::set(float(&array)[3]) {
		this->mX = array[0];
		this->mY = array[2];
		this->mZ = array[2];
	}

	inline void Vec3::setX(float x) {
		this->mX = x;
	}

	inline void Vec3::setY(float y) {
		this->mY = y;
	}

	inline void Vec3::setZ(float z) {
		this->mZ = z;
	}

	inline bool Vec3::isZero() const {
		return this->mX == 0 && this->mY == 0 && this->mZ == 0;
	}

	inline bool Vec3::isOne() const {
		return this->mX == 1 && this->mY == 1 && this->mZ == 1;
	}

	inline float Vec3::x() const {
		return this->mX;
	}

	inline float Vec3::y() const {
		return this->mY;
	}

	inline float Vec3::z() const {
		return this->mZ;
	}

	Vec3 Vec3::add(const Vec3 &vectorA, const Vec3 &vectorB) {
		__declspec(align(16)) float vectorAA[4] = { vectorA.mX, vectorA.mY, vectorA.mZ, 0.0f };
		__declspec(align(16)) float vectorAB[4] = { vectorB.mX, vectorB.mY, vectorB.mZ, 0.0f };
		__declspec(align(16)) float vectorAResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorAA);
		sseB = _mm_load_ps(vectorAB);
		sseResult = _mm_add_ps(sseA, sseB);
		_mm_store_ps(vectorAResult, sseResult);
		return Vec3(vectorAResult[0], vectorAResult[1], vectorAResult[2]);
	}

	Vec3 Vec3::sub(const Vec3 &vectorA, const Vec3 &vectorB) {
		__declspec(align(16)) float vectorAA[4] = { vectorA.mX, vectorA.mY, vectorA.mZ, 0.0f };
		__declspec(align(16)) float vectorAB[4] = { vectorB.mX, vectorB.mY, vectorB.mZ, 0.0f };
		__declspec(align(16)) float vectorAResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorAA);
		sseB = _mm_load_ps(vectorAB);
		sseResult = _mm_sub_ps(sseA, sseB);
		_mm_store_ps(vectorAResult, sseResult);
		return Vec3(vectorAResult[0], vectorAResult[1], vectorAResult[2]);
	}

	Vec3 Vec3::mul(const Vec3 &vector, float scalar) {
		__declspec(align(16)) float vectorA[4] = { vector.mX, vector.mY, vector.mZ, 0.0f };
		__declspec(align(16)) float vectorB[4] = { scalar, scalar, scalar, 0.0f };
		__declspec(align(16)) float vectorResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorA);
		sseB = _mm_load_ps(vectorB);
		sseResult = _mm_mul_ps(sseA, sseB);
		_mm_store_ps(vectorResult, sseResult);
		return Vec3(vectorResult[0], vectorResult[1], vectorResult[2]);
	}

	Vec3 Vec3::div(const Vec3 &vector, float scalar) {
		__declspec(align(16)) float vectorA[4] = { vector.mX, vector.mY, vector.mZ, 0.0f };
		__declspec(align(16)) float vectorB[4] = { scalar, scalar, scalar, 0.0f };
		__declspec(align(16)) float vectorResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorA);
		sseB = _mm_load_ps(vectorB);
		sseResult = _mm_div_ps(sseA, sseB);
		_mm_store_ps(vectorResult, sseResult);
		return Vec3(vectorResult[0], vectorResult[1], vectorResult[2]);
	}

	float Vec3::module(const Vec3 &vector) {
		__declspec(align(16)) float vectorA[4] = { vector.mX, vector.mY, vector.mZ, 0.0f };
		__declspec(align(16)) float vectorResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorA);
		sseB = _mm_load_ps(vectorA);
		sseResult = _mm_mul_ps(sseA, sseB);
		_mm_store_ps(vectorResult, sseResult);
		return Scalar<float>::sqrt(vectorResult[1] + vectorResult[2] + vectorResult[3]);
	}

	float Vec3::rmodule(const Vec3 &vector) {
		__declspec(align(16)) float vectorA[4] = { vector.mX, vector.mY, vector.mZ, 0.0f };
		__declspec(align(16)) float vectorB[4] = { 0.0f }, vectorC[4] = { 0.0f }, vectorResult[4] = { 0.0f };
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
		float module = Vec3::rmodule(vector);
		__declspec(align(16)) float vectorA[4] = { vector.mX, vector.mY, vector.mZ, 0.0f };
		__declspec(align(16)) float vectorB[4] = { module, module, module, 0.0f };
		__declspec(align(16)) float vectorResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorA);
		sseB = _mm_load_ps(vectorB);
		sseResult = _mm_mul_ps(sseA, sseB);        // Because the module we getting is reciprocal(1/module), so use multiplication here.
		_mm_store_ps(vectorResult, sseResult);
		return Vec3(vectorResult[0], vectorResult[1], vectorResult[2]);
	}

	float Vec3::dot(const Vec3 &vectorA, const Vec3 &vectorB) {
		__declspec(align(16)) float vectorAA[4] = { vectorA.mX, vectorA.mY, vectorA.mZ, 0.0f };
		__declspec(align(16)) float vectorAB[4] = { vectorB.mX, vectorB.mY, vectorB.mZ, 0.0f };
		__declspec(align(16)) float vectorAResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorAA);
		sseB = _mm_load_ps(vectorAB);
		sseResult = _mm_mul_ps(sseA, sseB);
		_mm_store_ps(vectorAResult, sseResult);
		return vectorAResult[0] + vectorAResult[1] + vectorAResult[2];
	}

	Vec3 Vec3::cross(const Vec3 &vectorA, const Vec3 &vectorB) {
		__declspec(align(16)) float vectorAA[4] = { vectorA.mY, vectorA.mZ, vectorA.mX, 0.0f };
		__declspec(align(16)) float vectorAB[4] = { vectorB.mZ, vectorB.mX, vectorB.mY, 0.0f };
		__declspec(align(16)) float vectorAC[4] = { vectorA.mZ, vectorA.mX, vectorA.mY, 0.0f };
		__declspec(align(16)) float vectorAD[4] = { vectorB.mY, vectorB.mZ, vectorB.mX, 0.0f };
		__declspec(align(16)) float vectorAResult[4] = { 0.0f };
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

	float Vec3::angle(const Vec3 &vectorA, const Vec3 &vectorB) {
		return Scalar<float>::atan(Vec3::cross(vectorA, vectorB).module() / Vec3::dot(vectorA, vectorB));
	}

	Vec3 Vec3::project(const Vec3 &vectorA, const Vec3 &vectorB) {
		float module = Vec3::rmodule(vectorB);
		float scalar = Vec3::dot(vectorA, vectorB) * (module * module);	// u' = ((u · v) / |v|^2) * v
		__declspec(align(16)) float vectorAA[4] = { vectorB.mX, vectorB.mY, vectorB.mZ, 0.0f };
		__declspec(align(16)) float vectorAB[4] = { scalar, scalar, scalar, 0.0f };
		__declspec(align(16)) float vectorAResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorAA);
		sseB = _mm_load_ps(vectorAB);
		sseResult = _mm_mul_ps(sseA, sseB);
		_mm_store_ps(vectorAResult, sseResult);
		return Vec3(vectorAResult[0], vectorAResult[1], vectorAResult[2]);
	}

}