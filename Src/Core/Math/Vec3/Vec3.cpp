// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/5 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Vec3.h"

Vec3::Vec3(float x, float y, float z) : 
    mX(x), mY(y), mZ(z) {
}

Vec3::Vec3(const vec3 &other) : 
    mX(other.mX), mY(other.mY), mZ(other.mZ) {
}

Vec3 &Vec3::operator=(const vec3 &other) {
    this->mX = other.mX;
    this->mY = other.mY;
    this->mZ = other.mZ;
    return *this;
}

Vec3 Vec3::operator+(const Vec3 &vector) {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, 0.0f};
    __declspec(align(16)) float vectorB[4] = {vector.mX, vector.mY, vector.mZ, 0.0f};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
    
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;

    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 

    sseResult = _mm_add_ps(sseA , sseB);
    
    _mm_store_ps(vectorResult, sseResult);

    return Vec3(vectorResult[0], vectorResult[1], vectorResult[2]);
}

Vec3 &Vec3::operator+=(const Vec3 &vector) {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, 0.0f};
    __declspec(align(16)) float vectorB[4] = {vector.mX, vector.mY, vector.mZ, 0.0f};
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

    return *this;
}

Vec3 Vec3::operator-(const Vec3 &vector) {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, 0.0f};
    __declspec(align(16)) float vectorB[4] = {vector.mX, vector.mY, vector.mZ, 0.0f};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
    
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;

    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 

    sseResult = _mm_sub_ps(sseA , sseB);
    
    _mm_store_ps(vectorResult, sseResult);

    return Vec3(vectorResult[0], vectorResult[1], vectorResult[2]);
}

Vec3 &Vec3::operator-=(const Vec3 &vector) {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, 0.0f};
    __declspec(align(16)) float vectorB[4] = {vector.mX, vector.mY, vector.mZ, 0.0f};
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

    return *this;
}

Vec3 Vec3::operator*(float scalar) {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, 0.0f};
    __declspec(align(16)) float vectorB[4] = {scalar, scalar, scalar, 0.0f};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
    
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;

    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 

    sseResult = _mm_mul_ps(sseA , sseB);
    
    _mm_store_ps(vectorResult, sseResult);

    return Vec3(vectorResult[0], vectorResult[1], vectorResult[2]);
}

Vec3 &Vec3::operator*=(float scalar) {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, 0.0f};
    __declspec(align(16)) float vectorB[4] = {scalar, scalar, scalar, 0.0f};
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

    return *this;
}

Vec3 Vec3::operator/(float scalar) {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, 0.0f};
    __declspec(align(16)) float vectorB[4] = {scalar, scalar, scalar, 0.0f};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
    
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;

    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 

    sseResult = _mm_div_ps(sseA , sseB);
    
    _mm_store_ps(vectorResult, sseResult);

    return Vec3(vectorResult[0], vectorResult[1], vectorResult[2]);
}

Vec3 &Vec3::operator/=(float scalar) {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, 0.0f};
    __declspec(align(16)) float vectorB[4] = {scalar, scalar, scalar, 0.0f};
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

    return *this;
}

// Module
float Vec3::mod() {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, 0.0f};
    __declspec(align(16)) float vectorB[4] = {this->mX, this->mY, this->mZ, 0.0f};
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
    
    vectorD[0] = vectorC[0] + vectorC[1] + vectorC[2];

    sseD = _mm_load_ps(vectorD);

    sseResult = _mm_sqrt_ps(sseD);

    _mm_store_ps(vectorResult, sseResult);

    return vectorResult[0];
}

// Module's reciprocal
float Vec3::rmod() {
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, 0.0f};
    __declspec(align(16)) float vectorB[4] = {this->mX, this->mY, this->mZ, 0.0f};
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
    
    vectorD[0] = vectorC[0] + vectorC[1] + vectorC[2];

    sseD = _mm_load_ps(vectorD);

    sseResult = _mm_rsqrt_ps(sseD);

    _mm_store_ps(vectorResult, sseResult);

    return vectorResult[0];
}

// Normalization
Vec3 &Vec3::nor() {
    float module = this->rmod();
    __declspec(align(16)) float vectorA[4] = {this->mX, this->mY, this->mZ, 0.0f};
    __declspec(align(16)) float vectorB[4] = {module, module, module, 0.0f};
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

    return *this;
}

// Dot Product
float Vec3::dot(const Vec3 &vector) {
    return (this->mX * vector.mX) + (this->mY * vector.mY) + (this->mZ * vector.mZ);
}

// Cross Product
Vec3 Vec3::cro(const Vec3 &vector) {
    __declspec(align(16)) float vectorA[4] = {this->mY, this->mZ, this->mX, 0.0f};
    __declspec(align(16)) float vectorB[4] = {vector.mZ, vector.mX, vector.mY, 0.0f};
    __declspec(align(16)) float vectorC[4] = {this->mZ, this->mX, this->mY, 0.0f};
    __declspec(align(16)) float vectorD[4] = {vector.mY, vector.mZ, vector.mX, 0.0f};
    __declspec(align(16)) float vectorResult[4] = {0.0f};

    __m128 sseA;
    __m128 sseB;
    __m128 sseC;
    __m128 sseD;
    __m128 sseE;
    __m128 sseF;
    __m128 sseResult;

    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
    sseC = _mm_load_ps(vectorC);  
    sseD = _mm_load_ps(vectorD); 

    sseE= _mm_mul_ps(sseA , sseB);
    sseF= _mm_mul_ps(sseC , sseD);
    sseResult = _mm_sub_ps(sseE, sseF);

    _mm_store_ps(vectorResult, sseResult);

    return Vec3(vectorResult[0], vectorResult[1], vectorResult[2])
}

float Vec3::x() {
    return this->mX;
}

float Vec3::y() {
    return this->mY;
}

float Vec3::z() {
    return this->mZ;
}