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
 
Vec2::Vec2(float x, float y) : 
    mX(x), mY(y) {
}

Vec2::Vec2(float (&array)[2]) :
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
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, 0.0f, 0.0f};
    __declspec(align(16)) float vectorB[4] = {vector.mX, vector.mY, 0.0f, 0.0f};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_add_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    return Vec2(vectorResult[0], vectorResult[1]);
}
 
Vec2 &Vec2::operator+=(const Vec2 &vector) {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, 0.0f, 0.0f};
    __declspec(align(16)) float vectorB[4] = {vector.mX, vector.mY, 0.0f, 0.0f};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_add_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    this->mX = vectorResult[0];
    this->mY = vectorResult[1];
 
    return *this;
}
 
Vec2 Vec2::operator-(const Vec2 &vector) const {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, 0.0f, 0.0f};
    __declspec(align(16)) float vectorB[4] = {vector.mX, vector.mY, 0.0f, 0.0f};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_sub_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    return Vec2(vectorResult[0], vectorResult[1]);
}
 
Vec2 &Vec2::operator-=(const Vec2 &vector) {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, 0.0f, 0.0f};
    __declspec(align(16)) float vectorB[4] = {vector.mX, vector.mY, 0.0f, 0.0f};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_sub_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    this->mX = vectorResult[0];
    this->mY = vectorResult[1];
 
    return *this;
}
 
Vec2 Vec2::operator*(float scalar) const {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, 0.0f, 0.0f};
    __declspec(align(16)) float vectorB[4] = {scalar, scalar, 0.0f, 0.0f};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_mul_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    return Vec2(vectorResult[0], vectorResult[1]);
}
 
Vec2 &Vec2::operator*=(float scalar) {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, 0.0f, 0.0f};
    __declspec(align(16)) float vectorB[4] = {scalar, scalar, 0.0f, 0.0f};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_mul_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    this->mX = vectorResult[0];
    this->mY = vectorResult[1];
 
    return *this;
}
 
Vec2 Vec2::operator/(float scalar) const {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, 0.0f, 0.0f};
    __declspec(align(16)) float vectorB[4] = {scalar, scalar, 0.0f, 0.0f};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_div_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    return Vec2(vectorResult[0], vectorResult[1]);
}
 
Vec2 &Vec2::operator/=(float scalar) {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, 0.0f, 0.0f};
    __declspec(align(16)) float vectorB[4] = {scalar, scalar, 0.0f, 0.0f};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_div_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    this->mX = vectorResult[0];
    this->mY = vectorResult[1];
 
    return *this;
}
 
// Module
float Vec2::mod() const {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, 0.0f, 0.0f};
    __declspec(align(16)) float vectorB[4] = {this->mX, this->mY, 0.0f, 0.0f};
    __declspec(align(16)) float vectorC[4] = {0.0f};
    __declspec(align(16)) float vectorD[4] = {0.0f};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseC;
    __m128 sseD;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB);
 
    sseC = _mm_mul_ps(sseA, sseB);
 
    _mm_store_ps(vectorC, sseC);
 
    vectorD[0] = vectorC[0] + vectorC[1];
 
    sseD = _mm_load_ps(vectorD);
 
    sseResult = _mm_sqrt_ps(sseD);
 
    _mm_store_ps(vectorResult, sseResult);
 
    return vectorResult[0];
}
 
// Module's reciprocal
float Vec2::rmod() const {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, 0.0f, 0.0f};
    __declspec(align(16)) float vectorB[4] = {this->mX, this->mY, 0.0f, 0.0f};
    __declspec(align(16)) float vectorC[4] = {0.0f};
    __declspec(align(16)) float vectorD[4] = {0.0f};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseC;
    __m128 sseD;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB);
 
    sseC = _mm_mul_ps(sseA, sseB);
 
    _mm_store_ps(vectorC, sseC);
 
    vectorD[0] = vectorC[0] + vectorC[1];
 
    sseD = _mm_load_ps(vectorD);
 
    sseResult = _mm_rsqrt_ps(sseD);
 
    _mm_store_ps(vectorResult, sseResult);
 
    return vectorResult[0];
}
 
// Normalization
Vec2 &Vec2::nor() {
    float module = this->rmod();
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, 0.0f, 0.0f};
    __declspec(align(16)) float vectorB[4] = {module, module, 0.0f, 0.0f};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB);
 
    sseResult = _mm_mul_ps(sseA, sseB);        // Because the module we getting is reciprocal(1/module), so use multiplication here.
 
    _mm_store_ps(vectorResult, sseResult);
 
    this->mX = vectorResult[0];
    this->mY = vectorResult[1];
 
    return *this;
}
 
// Dot Product
float Vec2::dot(const Vec2 &vector) const {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, 0.0f, 0.0f};
	__declspec(align(16)) float vectorB[4] = {vector.mX, vector.mY, 0.0f, 0.0f};
	__declspec(align(16)) float vectorResult[4] = {0.0f};
 
	__m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB);
 
    sseResult = _mm_mul_ps(sseA, sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    return vectorResult[0] + vectorResult[1];
}
 
// Projection
Vec2 Vec2::pro(const Vec2 &vector) const {
	float module = vector.rmod();
	float scalar = this->dot(vector) * (module * module);	// u' = ((u · v) / |v|^2) * v
	__declspec(align(16)) float vectorA[4] = {vector.mX, vector.mY, 0.0f, 0.0f};
    __declspec(align(16)) float vectorB[4] = {scalar, scalar, 0.0f, 0.0f};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB);
 
    sseResult = _mm_mul_ps(sseA, sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    return Vec2(vectorResult[0], vectorResult[1]);
}

void Vec2::set(float (&array)[2]) {
    this->mX = array[0];
    this->mY = array[1];
}

void Vec2::setX(float x) {
    this->mX = x;
}

void Vec2::setY(float y) {
    this->mY = y;
}
 
float Vec2::x() const {
    return this->mX;
}
 
float Vec2::y() const {
    return this->mY;
}
