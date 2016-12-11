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

// TODO: Other function refer to [glm](https://github.com/g-truc/glm/blob/master/glm/detail/type_vec4.inl)