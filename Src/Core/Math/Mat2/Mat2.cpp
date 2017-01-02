// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/16 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Mat2.h"
 
Mat2::Mat2(float m11, float m12, float m21, float m22) :
    mMatrix{m11, m12, m21, m22} {
}
 
Mat2::Mat2(float (&array)[4]) :
    mMatrix{array[0], array[1], array[2], array[3]} {
}
 
Mat2::Mat2(const Mat2 &other) :
    mMatrix{other.mMatrix[0], other.mMatrix[1], other.mMatrix[2], other.mMatrix[3]} {
}
 
Mat2 &Mat2::operator=(const Mat2 &other) {
    this->mMatrix[0] = other.mMatrix[0];
    this->mMatrix[1] = other.mMatrix[1];
    this->mMatrix[2] = other.mMatrix[2];
    this->mMatrix[3] = other.mMatrix[3];
    return *this;
}
 
Mat2 Mat2::operator+(const Mat2 &matrix) const {
    __declspec(align(16)) float vectorA[4] = {this->mMatrix[0], this->mMatrix[1], this->mMatrix[2], this->mMatrix[3]};
    __declspec(align(16)) float vectorB[4] = {matrix.mMatrix[0], matrix.mMatrix[1], matrix.mMatrix[2], matrix.mMatrix[3]};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_add_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    return Mat2(vectorResult[0], vectorResult[1], vectorResult[2], vectorResult[3]);
}
 
Mat2 &Mat2::operator+=(const Mat2 &matrix) {
    __declspec(align(16)) float vectorA[4] = {this->mMatrix[0], this->mMatrix[1], this->mMatrix[2], this->mMatrix[3]};
    __declspec(align(16)) float vectorB[4] = {matrix.mMatrix[0], matrix.mMatrix[1], matrix.mMatrix[2], matrix.mMatrix[3]};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_add_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    this->mMatrix[0] = vectorResult[0];
    this->mMatrix[1] = vectorResult[1];
    this->mMatrix[2] = vectorResult[2];
    this->mMatrix[3] = vectorResult[3];
 
    return *this;
}
 
Mat2 Mat2::operator-(const Mat2 &matrix) const {
    __declspec(align(16)) float vectorA[4] = {this->mMatrix[0], this->mMatrix[1], this->mMatrix[2], this->mMatrix[3]};
    __declspec(align(16)) float vectorB[4] = {matrix.mMatrix[0], matrix.mMatrix[1], matrix.mMatrix[2], matrix.mMatrix[3]};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_sub_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    return Mat2(vectorResult[0], vectorResult[1], vectorResult[2], vectorResult[3]);
}
 
Mat2 &Mat2::operator-=(const Mat2 &matrix) {
    __declspec(align(16)) float vectorA[4] = {this->mMatrix[0], this->mMatrix[1], this->mMatrix[2], this->mMatrix[3]};
    __declspec(align(16)) float vectorB[4] = {matrix.mMatrix[0], matrix.mMatrix[1], matrix.mMatrix[2], matrix.mMatrix[3]};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_sub_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    this->mMatrix[0] = vectorResult[0];
    this->mMatrix[1] = vectorResult[1];
    this->mMatrix[2] = vectorResult[2];
    this->mMatrix[3] = vectorResult[3];
 
    return *this;
}
 
Mat2 Mat2::operator*(float scalar) const {
    __declspec(align(16)) float vectorA[4] = {this->mMatrix[0], this->mMatrix[1], this->mMatrix[2], this->mMatrix[3]};
    __declspec(align(16)) float vectorB[4] = {scalar, scalar, scalar, scalar};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_mul_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    return Mat2(vectorResult[0], vectorResult[1], vectorResult[2], vectorResult[3]);
}
 
Mat2 &Mat2::operator*=(float scalar) {
    __declspec(align(16)) float vectorA[4] = {this->mMatrix[0], this->mMatrix[1], this->mMatrix[2], this->mMatrix[3]};
    __declspec(align(16)) float vectorB[4] = {scalar, scalar, scalar, scalar};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_mul_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    this->mMatrix[0] = vectorResult[0];
    this->mMatrix[1] = vectorResult[1];
    this->mMatrix[2] = vectorResult[2];
    this->mMatrix[3] = vectorResult[3];
 
    return *this;
}
 
Vec2 Mat2::operator*(const Vec2 &vector) const {
    __declspec(align(16)) float vectorA[4] = {this->mMatrix[0], this->mMatrix[1], this->mMatrix[2], this->mMatrix[3]};
    __declspec(align(16)) float vectorB[4] = {vector.x(), vector.y(), vector.x(), vector.y()};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB);
 
    sseResult = _mm_mul_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    return Vec2(vectorResult[0] + vectorResult[1], vectorResult[2] + vectorResult[3]);
}
 
Mat2 Mat2::operator*(const Mat2 &matrix) const {
    __declspec(align(16)) float vectorA[4] = {this->mMatrix[0], this->mMatrix[1], this->mMatrix[0], this->mMatrix[1]};
    __declspec(align(16)) float vectorB[4] = {matrix.mMatrix[0], matrix.mMatrix[2], matrix.mMatrix[1], matrix.mMatrix[3]};
    __declspec(align(16)) float vectorC[4] = {this->mMatrix[2], this->mMatrix[3], this->mMatrix[2], this->mMatrix[3]};
    __declspec(align(16)) float vectorD[4] = {matrix.mMatrix[0], matrix.mMatrix[2], matrix.mMatrix[1], matrix.mMatrix[3]};
    __declspec(align(16)) float vectorResultA[4] = {0.0f};
    __declspec(align(16)) float vectorResultB[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseC;
    __m128 sseD;
    __m128 sseResultA;
    __m128 sseResultB;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
    sseC = _mm_load_ps(vectorC);  
    sseD = _mm_load_ps(vectorD); 
 
    sseResultA = _mm_mul_ps(sseA , sseB);
    sseResultB = _mm_mul_ps(sseC , sseD);
 
    _mm_store_ps(vectorResultA, sseResultA);
    _mm_store_ps(vectorResultB, sseResultB);
 
    return Mat2(vectorResultA[0] + vectorResultA[1], vectorResultA[2] + vectorResultA[3], vectorResultB[0] + vectorResultB[1], vectorResultB[2] + vectorResultB[3]);
}
 
Mat2 &Mat2::operator*=(const Mat2 &matrix) {
    __declspec(align(16)) float vectorA[4] = {this->mMatrix[0], this->mMatrix[1], this->mMatrix[0], this->mMatrix[1]};
    __declspec(align(16)) float vectorB[4] = {matrix.mMatrix[0], matrix.mMatrix[2], matrix.mMatrix[1], matrix.mMatrix[3]};
    __declspec(align(16)) float vectorC[4] = {this->mMatrix[2], this->mMatrix[3], this->mMatrix[2], this->mMatrix[3]};
    __declspec(align(16)) float vectorD[4] = {matrix.mMatrix[0], matrix.mMatrix[2], matrix.mMatrix[1], matrix.mMatrix[3]};
    __declspec(align(16)) float vectorResultA[4] = {0.0f};
    __declspec(align(16)) float vectorResultB[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseC;
    __m128 sseD;
    __m128 sseResultA;
    __m128 sseResultB;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
    sseC = _mm_load_ps(vectorC);  
    sseD = _mm_load_ps(vectorD); 
 
    sseResultA = _mm_mul_ps(sseA , sseB);
    sseResultB = _mm_mul_ps(sseC , sseD);
 
    _mm_store_ps(vectorResultA, sseResultA);
    _mm_store_ps(vectorResultB, sseResultB);
 
    this->mMatrix[0] = vectorResultA[0] + vectorResultA[1];
    this->mMatrix[1] = vectorResultA[2] + vectorResultA[3];
    this->mMatrix[2] = vectorResultB[0] + vectorResultB[1];
    this->mMatrix[3] = vectorResultB[2] + vectorResultB[3];
 
    return *this;
}
 
Mat2 Mat2::operator/(float scalar) const {
    __declspec(align(16)) float vectorA[4] = {this->mMatrix[0], this->mMatrix[1], this->mMatrix[2], this->mMatrix[3]};
    __declspec(align(16)) float vectorB[4] = {scalar, scalar, scalar, scalar};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_div_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    return Mat2(vectorResult[0], vectorResult[1], vectorResult[2], vectorResult[3]);
}
 
Mat2 &Mat2::operator/=(float scalar) {
    __declspec(align(16)) float vectorA[4] = {this->mMatrix[0], this->mMatrix[1], this->mMatrix[2], this->mMatrix[3]};
    __declspec(align(16)) float vectorB[4] = {scalar, scalar, scalar, scalar};
    __declspec(align(16)) float vectorResult[4] = {0.0f};
 
    __m128 sseA;
    __m128 sseB;
    __m128 sseResult;
 
    sseA = _mm_load_ps(vectorA);  
    sseB = _mm_load_ps(vectorB); 
 
    sseResult = _mm_div_ps(sseA , sseB);
 
    _mm_store_ps(vectorResult, sseResult);
 
    this->mMatrix[0] = vectorResult[0];
    this->mMatrix[1] = vectorResult[1];
    this->mMatrix[2] = vectorResult[2];
    this->mMatrix[3] = vectorResult[3];
 
    return *this;
}
 
// Transpose
Mat2 &Mat2::tra() {
    float tempScalar = this->mMatrix[1];
    this->mMatrix[1] = this->mMatrix[2];
    this->mMatrix[2] = tempScalar;
}

float Mat2::get(int col, int row) const {
    if(col > 0 && col < 3 && row > 0 && row < 3) {
        return this->mMatrix[(col - 1) + (2 * (row - 1))];
    } else {
        return 0.0f;
    }
}

Vec2 Mat2::row(int row) const {
    if(row > 0 && row < 3) {
        return Vec2(this->mMatrix[(row - 1) << 1], this->mMatrix[((row - 1) << 1) + 1]);
    } else {
        return Vec2(0.0f, 0.0f);
    }
}

Vec2 Mat2::col(int col) const {
    if(col > 0 && col < 3) {
        return Vec2(this->mMatrix[col - 1], this->mMatrix[col - 1 + 2]);
    } else {
        return Vec2(0.0f, 0.0f);
    }
}

bool Mat2::set(int col, int row, float scalar) {
    if(col > 0 && col < 3 && row > 0 && row < 3) {
        this->mMatrix[(col - 1) + (2 * (row - 1))] = scalar;
        return true;
    } else {
        return false;
    }
}

void Mat2::set(float (&array)[4]) {
    this->mMatrix[0] = array[0];
    this->mMatrix[1] = array[1];
    this->mMatrix[2] = array[2];
    this->mMatrix[3] = array[3];
}

bool Mat2::setRow(int row, const Vec2 &vector) {
    if(row > 0 && row < 3) {
        this->mMatrix[(row - 1) << 1] = vector.x();
        this->mMatrix[((row - 1) << 1) + 1] = vector.y();
        return true;
    } else {
        return false;
    }
}

bool Mat2::setCol(int col, const Vec2 &vector) {
    if(col > 0 && col < 3) {
        this->mMatrix[col - 1] = vector.x();
        this->mMatrix[col - 1 + 2] = vector.y();
        return true;
    } else {
        return false;
    }
}
