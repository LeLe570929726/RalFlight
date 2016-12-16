// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/11 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Vec4.h"
 
Vec4::Vec4(float x, float y, float z, float w) : 
    mX(x), mY(y), mZ(z), mW(w) {
}
 
Vec4(const Vec4 &other) :
     mX(other.mX), mY(pther.mY), mZ(other.mZ), mW(other.mW){
}
 
Vec4 &operator=(const Vec4 &other) {
    this->mX = other.mX;
    this->mY = other.mY;
    this->mZ = other.mZ;
    this->mW = other.mW;
}
 
Vec4 Vec4::operator+(const Vec4 &vector) {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, this->mW};
    __declspec(align(16)) float vectorB[4] = {vector.mX, vector.mY, vector.mZ, vector.mW};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_add_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    return Vec4(vectorResult[0], vectorResult[1], vectorResult[2], vectorResult[3]);
}
 
Vec4 &Vec4::operator+=(const Vec4 &vector) {
     __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, this->mW};
    __declspec(align(16)) float vectorB[4] = {vector.mX, vector.mY, vector.mZ, vector.mW};
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
    this->mZ = vectorResult[2];
    this->mW = vectorResult[3];
 
    return *this;
}
 
Vec4 Vec4::operator-(const Vec4 &vector) {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, this->mW};
    __declspec(align(16)) float vectorB[4] = {vector.mX, vector.mY, vector.mZ, vector.mW};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_sub_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    return Vec4(vectorResult[0], vectorResult[1], vectorResult[2], vectorResult[3]);
}
 
Vec4 &Vec4::operator-=(const Vec4 &vector) {
     __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, this->mW};
    __declspec(align(16)) float vectorB[4] = {vector.mX, vector.mY, vector.mZ, vector.mW};
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
    this->mZ = vectorResult[2];
    this->mW = vectorResult[3];
 
    return *this;
}
 
Vec4 Vec4::operator*(float scalar) {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, this->mW};
    __declspec(align(16)) float vectorB[4] = {scalar, scalar, scalar, scalar};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_mul_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    return Vec2(vectorResult[0], vectorResult[1], vectorResult[2], vectorResult[3]);
}
 
Vec4 &Vec4::operator*=(float scalar) {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, this->mW};
    __declspec(align(16)) float vectorB[4] = {scalar, scalar, scalar, scalar};
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
    this->mZ = vectorResult[2];
    this->mW = vectorResult[3];
 
    return *this;
}
 
Vec4 Vec4::operator/(float scalar) {
     __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, this->mW};
    __declspec(align(16)) float vectorB[4] = {scalar, scalar, scalar, scalar};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_div_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    return Vec2(vectorResult[0], vectorResult[1], vectorResult[2], vectorResult[3]);
}
 
Vec4 &Vec4::operator/=(float scalar) {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, this->mW};
    __declspec(align(16)) float vectorB[4] = {scalar, scalar, scalar, scalar};
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
    this->mZ = vectorResult[2];
    this->mW = vectorResult[3];
 
    return *this;
}
 
// Module
float Vec4::mod() {
	__declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, this->mW};
    __declspec(align(16)) float vectorB[4] = {this->mX, this->mY, this->mZ, this->mW};
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
 
    vectorD[0] = vectorC[0] + vectorC[1] + vectorC[2] +vectorC[3];
 
    sseD = _mm_load_ps(vectorD);
 
    sseResult = _mm_sqrt_ps(sseD);
 
    _mm_store_ps(vectorResult, sseResult);
 
	return vectorResult[0];
}    
 
// Module's reciprocal
float Vec4::rmod() {
	__declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, this->mW};
    __declspec(align(16)) float vectorB[4] = {this->mX, this->mY, this->mZ, this->mW};
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
 
    vectorD[0] = vectorC[0] + vectorC[1] + vectorC[2] + vectorC[3];
 
    sseD = _mm_load_ps(vectorD);
 
    sseResult = _mm_rsqrt_ps(sseD);
 
    _mm_store_ps(vectorResult, sseResult);
 
	return vectorResult[0];
}
 
// Normalization
Vec4 &Vec4::nor() {
	float module = this->rmod();
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, this->mW};
    __declspec(align(16)) float vectorB[4] = {module, module, module, module};
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
    this->mZ = vectorResult[2];
    this->mW = vectorResult[3];
 
	return *this;
}
 
// Dot Product
float Vec4::dot(const Vec4 &vector) {
	__declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, this->mW};
	__declspec(align(16)) float vectorB[4] = {vector.mX, vector.mY, vector.mZ, vector.mW};
	__declspec(align(16)) float vectorResult[4] = {0.0f};
 
	__m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB);
 
    sseResult = _mm_mul_ps(sseA, sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    return vectorResult[0] + vectorResult[1] + vectorResult[2] + vectorResult[3];
}
 
// Projection
Vec4 Vec4::pro(const Vec4 &vector) {
	float module = vector.rmod();
	float scalar = this->dot(vector) * (module * module);		// u' = ((u · v) / |v|^2) * v
	__declspec(align(16)) float vectorA[4] = {vector.mX, vector.mY, vector.mZ, vector.mW};
    __declspec(align(16)) float vectorB[4] = {scalar, scalar, scalar, scalar};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB);
 
    sseResult = _mm_mul_ps(sseA, sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    return Vec4(vectroResult[0], vectroResult[1], vectroResult[2], vectroResult[3]);
}
 
float Vec4::x() {
	return this->mX;
}
 
float Vec4::y() {
	return this->mY;
}
 
float Vec4::z() {
	return this->mZ;
}
 
float Vec4::w() {
	return this->mW;
}