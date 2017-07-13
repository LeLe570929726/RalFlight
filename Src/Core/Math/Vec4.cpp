// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/11 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Vec4.h"

// Core namespace
namespace Core {

	Vec4::Vec4(float x, float y, float z, float w) :
		mX(x), mY(y), mZ(z), mW(w) {
	}

	Vec4::Vec4(float(&array)[4]) :
		mX(array[0]), mY(array[1]), mZ(array[2]), mW(array[3]) {
	}

	Vec4::Vec4(const Vec4 &other) :
		mX(other.mX), mY(other.mY), mZ(other.mZ), mW(other.mW) {
	}

	Vec4 &Vec4::operator=(const Vec4 &other) {
		this->mX = other.mX;
		this->mY = other.mY;
		this->mZ = other.mZ;
		this->mW = other.mW;
		return *this;
	}

	Vec4 Vec4::operator+(const Vec4 &vector) const {
		return Vec4::add(*this, vector);
	}

	Vec4 &Vec4::operator+=(const Vec4 &vector) {
		*this = Vec4::add(*this, vector);
		return *this;
	}

	Vec4 Vec4::operator-(const Vec4 &vector) const {
		return Vec4::sub(*this, vector);
	}

	Vec4 &Vec4::operator-=(const Vec4 &vector) {
		*this = Vec4::sub(*this, vector);
		return *this;
	}

	Vec4 Vec4::operator*(float scalar) const {
		return Vec4::mul(*this, scalar);
	}

	Vec4 &Vec4::operator*=(float scalar) {
		*this = Vec4::mul(*this, scalar);
		return *this;
	}

	Vec4 Vec4::operator/(float scalar) const {
		return Vec4::div(*this, scalar);
	}

	Vec4 &Vec4::operator/=(float scalar) {
		*this = Vec4::div(*this, scalar);
		return *this;
	}

	Vec4 &Vec4::add(const Vec4 &vector) {
		*this = Vec4::add(*this, vector);
		return *this;
	}

	Vec4 &Vec4::sub(const Vec4 &vector) {
		*this = Vec4::sub(*this, vector);
		return *this;
	}

	Vec4 &Vec4::mul(float scalar) {
		*this = Vec4::mul(*this, scalar);
		return *this;
	}

	Vec4 &Vec4::div(float scalar) {
		*this = Vec4::div(*this, scalar);
		return *this;
	}

	float Vec4::module() const {
		return Vec4::module(*this);
	}

	float Vec4::rmodule() const {
		return Vec4::rmodule(*this);
	}

	Vec4 &Vec4::normalize() {
		*this = Vec4::normalize(*this);
		return *this;
	}

	float Vec4::dot(const Vec4 &vector) const {
		return Vec4::dot(*this);
	}

	float Vec4::angle(const Vec4 &vector) const {
		return Vec4::angle(vector);
	}

	Vec4 Vec4::project(const Vec4 &vector) const {
		return Vec4::project(*this, vector);
	}

	inline void Vec4::set(float(&array)[4]) {
		this->mX = array[0];
		this->mY = array[1];
		this->mZ = array[2];
		this->mW = array[3];
	}

	inline void Vec4::setX(float x) {
		this->mX = x;
	}

	inline void Vec4::setY(float y) {
		this->mY = y;
	}

	inline void Vec4::setZ(float z) {
		this->mZ = z;
	}

	inline void Vec4::setW(float w) {
		this->mW = w;
	}

	inline bool Vec4::isZero() const {
		return this->mX == 0 && this->mY == 0 && this->mZ == 0 && this->mW == 0;
	}

	inline bool Vec4::isOne() const {
		return this->mX == 1 && this->mY == 1 && this->mZ == 1 && this->mW == 1;
	}

	inline float Vec4::x() const {
		return this->mX;
	}

	inline float Vec4::y() const {
		return this->mY;
	}

	inline float Vec4::z() const {
		return this->mZ;
	}

	inline float Vec4::w() const {
		return this->mW;
	}

	Vec4 Vec4::add(const Vec4 &vectorA, const Vec4 &vectorB) {
		__declspec(align(16)) float vectorAA[4] = { vectorA.mX, vectorA.mY, vectorA.mZ, vectorA.mW };
		__declspec(align(16)) float vectorAB[4] = { vectorB.mX, vectorB.mY, vectorB.mZ, vectorB.mW };
		__declspec(align(16)) float vectorAResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorAA);
		sseB = _mm_load_ps(vectorAB);
		sseResult = _mm_add_ps(sseA, sseB);
		_mm_store_ps(vectorAResult, sseResult);
		return Vec4(vectorAResult[0], vectorAResult[1], vectorAResult[2], vectorAResult[3]);
	}

	Vec4 Vec4::sub(const Vec4 &vectorA, const Vec4 &vectorB) {
		__declspec(align(16)) float vectorAA[4] = { vectorA.mX, vectorA.mY, vectorA.mZ, vectorA.mW };
		__declspec(align(16)) float vectorAB[4] = { vectorB.mX, vectorB.mY, vectorB.mZ, vectorB.mW };
		__declspec(align(16)) float vectorAResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorAA);
		sseB = _mm_load_ps(vectorAB);
		sseResult = _mm_sub_ps(sseA, sseB);
		_mm_store_ps(vectorAResult, sseResult);
		return Vec4(vectorAResult[0], vectorAResult[1], vectorAResult[2], vectorAResult[3]);
	}

	Vec4 Vec4::mul(const Vec4 &vector, float scalar){
		__declspec(align(16)) float vectorA[4] = { vector.mX, vector.mY, vector.mZ, vector.mW };
		__declspec(align(16)) float vectorB[4] = { scalar, scalar, scalar, scalar };
		__declspec(align(16)) float vectorResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorA);
		sseB = _mm_load_ps(vectorB);
		sseResult = _mm_mul_ps(sseA, sseB);
		_mm_store_ps(vectorResult, sseResult);
		return Vec4(vectorResult[0], vectorResult[1], vectorResult[2], vectorResult[3]);
	}

	Vec4 Vec4::div(const Vec4 &vector, float scalar) {
		__declspec(align(16)) float vectorA[4] = { vector.mX, vector.mY, vector.mZ, vector.mW };
		__declspec(align(16)) float vectorB[4] = { scalar, scalar, scalar, scalar };
		__declspec(align(16)) float vectorResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorA);
		sseB = _mm_load_ps(vectorB);
		sseResult = _mm_div_ps(sseA, sseB);
		_mm_store_ps(vectorResult, sseResult);
		return Vec4(vectorResult[0], vectorResult[1], vectorResult[2], vectorResult[3]);
	}

	float Vec4::module(const Vec4 &vector) {
		__declspec(align(16)) float vectorA[4] = { vector.mX, vector.mY, vector.mZ, vector.mW };
		__declspec(align(16)) float vectorB[4] = { vector.mX, vector.mY, vector.mZ, vector.mW };
		__declspec(align(16)) float vectorResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorA);
		sseB = _mm_load_ps(vectorB);
		sseResult = _mm_mul_ps(sseA, sseB);
		_mm_store_ps(vectorResult, sseResult);
		return Scalar<float>::sqrt(vectorResult[0] + vectorResult[1] + vectorResult[2] + vectorResult[3]);
	}

	// Module's reciprocal
	float Vec4::rmodule(const Vec4 &vector) {
		__declspec(align(16)) float vectorA[4] = { vector.mX, vector.mY, vector.mZ, vector.mW };
		__declspec(align(16)) float vectorB[4] = { vector.mX, vector.mY, vector.mZ, vector.mW };
		__declspec(align(16)) float vectorC[4] = { 0.0f }, vectorD[4] = { 0.0f }, vectorResult[4] = { 0.0f };
		__m128 sseA, sseB, sseC, sseD, sseResult;
		sseA = _mm_load_ps(vectorA);
		sseB = _mm_load_ps(vectorB);
		sseC = _mm_mul_ps(sseA, sseB);
		_mm_store_ps(vectorC, sseC);
		vectorD[0] = vectorC[0] + vectorC[1] + vectorC[2] + vectorC[3];
		sseD = _mm_load_ps(vectorD);
		sseResult = _mm_rsqrt_ps(sseD);
		_mm_store_ps(vectorResult, sseResult);
		return vectorResult[0];
	}

	Vec4 Vec4::normalize(const Vec4 &vector) {
		float module = vector.rmodule();
		__declspec(align(16)) float vectorA[4] = { vector.mX, vector.mY, vector.mZ, vector.mW };
		__declspec(align(16)) float vectorB[4] = { module, module, module, module };
		__declspec(align(16)) float vectorResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorA);
		sseB = _mm_load_ps(vectorB);
		sseResult = _mm_mul_ps(sseA, sseB);        // Because the module we getting is reciprocal(1/module), so use multiplication here.
		_mm_store_ps(vectorResult, sseResult);
		return Vec4(vectorResult[0], vectorResult[1], vectorResult[2], vectorResult[3]);
	}

	float Vec4::dot(const Vec4 &vectorA, const Vec4 &vectorB) {
		__declspec(align(16)) float vectorAA[4] = { vectorA.mX, vectorA.mY, vectorA.mZ, vectorA.mW };
		__declspec(align(16)) float vectorAB[4] = { vectorB.mX, vectorB.mY, vectorB.mZ, vectorB.mW };
		__declspec(align(16)) float vectorAResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorAA);
		sseB = _mm_load_ps(vectorAB);
		sseResult = _mm_mul_ps(sseA, sseB);
		_mm_store_ps(vectorAResult, sseResult);
		return vectorAResult[0] + vectorAResult[1] + vectorAResult[2] + vectorAResult[3];
	}

	float Vec4::angle(const Vec4 &vectorA, const Vec4 &vectorB) {
		__declspec(align(16)) float vectorAA[4] = { vectorA.mW, vectorA.mX, vectorA.mY, vectorA.mZ };
		__declspec(align(16)) float vectorAB[4] = { vectorB.mX, vectorB.mW, vectorB.mZ, vectorB.mY };
		__declspec(align(16)) float vectorAC[4] = { vectorA.mW, vectorA.mY, vectorA.mZ, vectorA.mX };
		__declspec(align(16)) float vectorAD[4] = { vectorB.mY, vectorB.mW, vectorB.mX, vectorB.mZ };
		__declspec(align(16)) float vectorAE[4] = { vectorA.mW, vectorA.mZ, vectorA.mX, vectorA.mY };
		__declspec(align(16)) float vectorAF[4] = { vectorB.mZ, vectorB.mW, vectorB.mY, vectorB.mX };
		__declspec(align(16)) float vectorAResult[4] = { 0.0f };
		__m128 sseA, sseB, sseC, sseD, sseE, sseF, sseResult;
		Vec3 tempVector(0.0f ,0.0f ,0.0f);
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
		return Scalar<float>::atan(tempVector.module() / Vec4::dot(vectorA, vectorB));
	}

	Vec4 Vec4::project(const Vec4 &vectorA, const Vec4 &vectorB) {
		float module = vectorB.rmodule();
		float scalar = Vec4::dot(vectorA, vectorB) * (module * module);		// u' = ((u · v) / |v|^2) * v
		__declspec(align(16)) float vectorAA[4] = { vectorB.mX, vectorB.mY, vectorB.mZ, vectorB.mW };
		__declspec(align(16)) float vectorAB[4] = { scalar, scalar, scalar, scalar };
		__declspec(align(16)) float vectoraResult[4] = { 0.0f };
		__m128 sseA, sseB, sseResult;
		sseA = _mm_load_ps(vectorAA);
		sseB = _mm_load_ps(vectorAB);
		sseResult = _mm_mul_ps(sseA, sseB);
		_mm_store_ps(vectoraResult, sseResult);
		return Vec4(vectoraResult[0], vectoraResult[1], vectoraResult[2], vectoraResult[3]);
	}

}