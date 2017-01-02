// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2016/12/17 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Mat4.h"
 
Mat4::Mat4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, 
	float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44) :
	mMatrix{m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44} {
}
 
Mat4::Mat4(float (&array)[16]) : 
	mMatrix{array[0], array[1], array[2], array[3], array[4], array[5], array[6], array[7], array[8], array[9],
		array[10], array[11], array[12], array[13], array[14], array[15]} {
}
 
Mat4::Mat4(const Mat4 &other) :
	mMatrix{other.mMatrix[0], other.mMatrix[1], other.mMatrix[2], other.mMatrix[3], other.mMatrix[4], other.mMatrix[5], 
		other.mMatrix[6], other.mMatrix[7], other.mMatrix[8], other.mMatrix[9], other.mMatrix[10], other.mMatrix[11],
		other.mMatrix[12], other.mMatrix[13], other.mMatrix[14], other.mMatrix[15]} {
}
 
Mat4 &Mat4::operator=(const Mat4 &other) {
	for(int i = 0; i < 15; ++i) {
		this->mMatrix[i] = other.mMatrix[i];
	}
    return *this;
}
 
Mat4 Mat4::operator+(const Mat4 &matrix) const {
	float tempArray[16] = {0.0f};
	for(int i = 0; i <= 12; i += 4) {
		__declspec(align(16)) float vectorA[4] = {this->mMatrix[i], this->mMatrix[i + 1], this->mMatrix[i + 2], this->mMatrix[i + 3]};
    	__declspec(align(16)) float vectorB[4] = {matrix.mMatrix[i], matrix.mMatrix[i + 1], matrix.mMatrix[i + 2], matrix.mMatrix[i + 3]};
    	__declspec(align(16)) float vectorResult[4] = {0.0f};
 
    	__m128 sseA;
    	__m128 sseB;
    	__m128 sseResult;
 
    	sseA = _mm_load_ps(vectorA);  
    	sseB = _mm_load_ps(vectorB);
 
    	sseResult = _mm_add_ps(sseA , sseB);
 
    	_mm_store_ps(vectorResult, sseResult);
 
    	tempArray[i] = vectorResult[0];
    	tempArray[i + 1] = vectorResult[1];
    	tempArray[i + 2] = vectorResult[2];
    	tempArray[i + 3] = vectorResult[3];
	}
	return Mat4(tempArray);
}
 
Mat4 &Mat4::operator+=(const Mat4 &matrix) {
	for(int i = 0; i <= 12; i += 4) {
		__declspec(align(16)) float vectorA[4] = {this->mMatrix[i], this->mMatrix[i + 1], this->mMatrix[i + 2], this->mMatrix[i + 3]};
    	__declspec(align(16)) float vectorB[4] = {matrix.mMatrix[i], matrix.mMatrix[i + 1], matrix.mMatrix[i + 2], matrix.mMatrix[i + 3]};
    	__declspec(align(16)) float vectorResult[4] = {0.0f};
 
    	__m128 sseA;
    	__m128 sseB;
    	__m128 sseResult;
 
    	sseA = _mm_load_ps(vectorA);  
    	sseB = _mm_load_ps(vectorB);
 
    	sseResult = _mm_add_ps(sseA , sseB);
 
    	_mm_store_ps(vectorResult, sseResult);
 
    	this->mMatrix[i] = vectorResult[0];
    	this->mMatrix[i + 1] = vectorResult[1];
    	this->mMatrix[i + 2] = vectorResult[2];
    	this->mMatrix[i + 3] = vectorResult[3];
	}
	return *this;
}
 
Mat4 Mat4::operator-(const Mat4 &matrix) const {
	float tempArray[16] = {0.0f};
	for(int i = 0; i <= 12; i += 4) {
		__declspec(align(16)) float vectorA[4] = {this->mMatrix[i], this->mMatrix[i + 1], this->mMatrix[i + 2], this->mMatrix[i + 3]};
    	__declspec(align(16)) float vectorB[4] = {matrix.mMatrix[i], matrix.mMatrix[i + 1], matrix.mMatrix[i + 2], matrix.mMatrix[i + 3]};
    	__declspec(align(16)) float vectorResult[4] = {0.0f};
 
    	__m128 sseA;
    	__m128 sseB;
    	__m128 sseResult;
 
    	sseA = _mm_load_ps(vectorA);  
    	sseB = _mm_load_ps(vectorB);
 
    	sseResult = _mm_sub_ps(sseA , sseB);
 
    	_mm_store_ps(vectorResult, sseResult);
 
    	tempArray[i] = vectorResult[0];
    	tempArray[i + 1] = vectorResult[1];
    	tempArray[i + 2] = vectorResult[2];
    	tempArray[i + 3] = vectorResult[3];
	}
	return Mat4(tempArray);
}
 
Mat4 &Mat4::operator-=(const Mat4 &matrix) {
	for(int i = 0; i <= 12; i += 4) {
		__declspec(align(16)) float vectorA[4] = {this->mMatrix[i], this->mMatrix[i + 1], this->mMatrix[i + 2], this->mMatrix[i + 3]};
    	__declspec(align(16)) float vectorB[4] = {matrix.mMatrix[i], matrix.mMatrix[i + 1], matrix.mMatrix[i + 2], matrix.mMatrix[i + 3]};
    	__declspec(align(16)) float vectorResult[4] = {0.0f};
 
    	__m128 sseA;
    	__m128 sseB;
    	__m128 sseResult;
 
    	sseA = _mm_load_ps(vectorA);  
    	sseB = _mm_load_ps(vectorB);
 
    	sseResult = _mm_sub_ps(sseA , sseB);
 
    	_mm_store_ps(vectorResult, sseResult);
 
    	this->mMatrix[i] = vectorResult[0];
    	this->mMatrix[i + 1] = vectorResult[1];
    	this->mMatrix[i + 2] = vectorResult[2];
    	this->mMatrix[i + 3] = vectorResult[3];
	}
	return *this;
}
 
Mat4 Mat4::operator*(float scalar) const {
	float tempArray[16] = {0.0f};
	for(int i = 0; i <= 12; i += 4) {
		__declspec(align(16)) float vectorA[4] = {this->mMatrix[i], this->mMatrix[i + 1], this->mMatrix[i + 2], this->mMatrix[i + 3]};
    	__declspec(align(16)) float vectorB[4] = {scalar, scalar, scalar, scalar};
    	__declspec(align(16)) float vectorResult[4] = {0.0f};
 
    	__m128 sseA;
    	__m128 sseB;
    	__m128 sseResult;
 
    	sseA = _mm_load_ps(vectorA);  
    	sseB = _mm_load_ps(vectorB);
 
    	sseResult = _mm_mul_ps(sseA , sseB);
 
    	_mm_store_ps(vectorResult, sseResult);
 
    	tempArray[i] = vectorResult[0];
    	tempArray[i + 1] = vectorResult[1];
    	tempArray[i + 2] = vectorResult[2];
    	tempArray[i + 3] = vectorResult[3];
	}
	return Mat4(tempArray);
}
 
Mat4 &Mat4::operator*=(float scalar) {
	for(int i = 0; i <= 12; i += 4) {
		__declspec(align(16)) float vectorA[4] = {this->mMatrix[i], this->mMatrix[i + 1], this->mMatrix[i + 2], this->mMatrix[i + 3]};
    	__declspec(align(16)) float vectorB[4] = {scalar, scalar, scalar, scalar};
    	__declspec(align(16)) float vectorResult[4] = {0.0f};
 
    	__m128 sseA;
    	__m128 sseB;
    	__m128 sseResult;
 
    	sseA = _mm_load_ps(vectorA);  
    	sseB = _mm_load_ps(vectorB);
 
    	sseResult = _mm_mul_ps(sseA , sseB);
 
    	_mm_store_ps(vectorResult, sseResult);
 
    	this->mMatrix[i] = vectorResult[0];
    	this->mMatrix[i + 1] = vectorResult[1];
    	this->mMatrix[i + 2] = vectorResult[2];
    	this->mMatrix[i + 3] = vectorResult[3];
	}
	return *this;
}
 
Vec4 Mat4::operator*(const Vec4 &vector) const {
	float tempArray[4] = {0.0f};
	__declspec(align(16)) float vectorA[4] = {vector.x(), vector.y(), vector.z(), vector.w()};
 
	__m128 sseA;
 
	sseA = _mm_load_ps(vectorA);
 
	for(int i = 0; i <= 12; i += 12) {
		__declspec(align(16)) float vectorB[4] = {this->mMatrix[i], this->mMatrix[i + 1], this->mMatrix[i + 2], this->mMatrix[i + 3]};
		__declspec(align(16)) float vectorResult[4] = {0.0f};
 
		__m128 sseB;
    	__m128 sseResult;
 
    	sseB = _mm_load_ps(vectorB);
 
    	sseResult = _mm_mul_ps(sseA , sseB);
 
    	_mm_store_ps(vectorResult, sseResult);
 
    	tempArray[static_cast<int>(i >> 2)] = vectorResult[0] + vectorResult[1] + vectorResult[2] + vectorResult[3];
	}
	return Vec4(tempArray);
}
 
Mat4 Mat4::operator*(const Mat4 &matrix) const {
	float tempArray[16] = {0.0f};
	for(int i = 0; i < 16; ++i) {
		__declspec(align(16)) float vectorA[4] = {this->mMatrix[static_cast<int>(i >> 2)], this->mMatrix[static_cast<int>(i >> 2) + 1], 
			this->mMatrix[static_cast<int>(i >> 2) + 2], this->mMatrix[static_cast<int>(i >> 2) + 3]};
		__declspec(align(16)) float vectorB[4] = {matrix.mMatrix[(i % 4)], matrix.mMatrix[(i % 4) + 4], 
			matrix.mMatrix[(i % 4) + 8], matrix.mMatrix[(i % 4) + 12]};
		__declspec(align(16)) float vectorResult[4] = {0.0f};
 
		__m128 sseA;
		__m128 sseB;
    	__m128 sseResult;
 
    	sseA = _mm_load_ps(vectorA);
    	sseB = _mm_load_ps(vectorB);
 
    	sseResult = _mm_mul_ps(sseA , sseB);
 
    	_mm_store_ps(vectorResult, sseResult);
 
    	tempArray[i] = vectorResult[0] + vectorResult[1] + vectorResult[2] + vectorResult[3];
	}
	return Mat4(tempArray);
}
 
Mat4 &Mat4::operator*=(const Mat4 &matrix) {
	for(int i = 0; i < 16; ++i) {
		__declspec(align(16)) float vectorA[4] = {this->mMatrix[static_cast<int>(i >> 2)], this->mMatrix[static_cast<int>(i >> 2) + 1], 
			this->mMatrix[static_cast<int>(i >> 2) + 2], this->mMatrix[static_cast<int>(i >> 2) + 3]};
		__declspec(align(16)) float vectorB[4] = {matrix.mMatrix[(i % 4)], matrix.mMatrix[(i % 4) + 4], 
			matrix.mMatrix[(i % 4) + 8], matrix.mMatrix[(i % 4) + 12]};
		__declspec(align(16)) float vectorResult[4] = {0.0f};
 
		__m128 sseA;
		__m128 sseB;
    	__m128 sseResult;
 
    	sseA = _mm_load_ps(vectorA);
    	sseB = _mm_load_ps(vectorB);
 
    	sseResult = _mm_mul_ps(sseA , sseB);
 
    	_mm_store_ps(vectorResult, sseResult);
 
    	this->mMatrix[i] = vectorResult[0] + vectorResult[1] + vectorResult[2] + vectorResult[3];
	}
	return *this;
}
 
Mat4 Mat4::operator/(float scalar) const {
	float tempArray[16] = {0.0f};
	for(int i = 0; i <= 12; i += 4) {
		__declspec(align(16)) float vectorA[4] = {this->mMatrix[i], this->mMatrix[i + 1], this->mMatrix[i + 2], this->mMatrix[i + 3]};
    	__declspec(align(16)) float vectorB[4] = {scalar, scalar, scalar, scalar};
    	__declspec(align(16)) float vectorResult[4] = {0.0f};
 
    	__m128 sseA;
    	__m128 sseB;
    	__m128 sseResult;
 
    	sseA = _mm_load_ps(vectorA);  
    	sseB = _mm_load_ps(vectorB);
 
    	sseResult = _mm_div_ps(sseA , sseB);
 
    	_mm_store_ps(vectorResult, sseResult);
 
    	tempArray[i] = vectorResult[0];
    	tempArray[i + 1] = vectorResult[1];
    	tempArray[i + 2] = vectorResult[2];
    	tempArray[i + 3] = vectorResult[3];
	}
	return Mat4(tempArray);
}
 
Mat4 &Mat4::operator/=(float scalar) {
	for(int i = 0; i <= 12; i += 4) {
		__declspec(align(16)) float vectorA[4] = {this->mMatrix[i], this->mMatrix[i + 1], this->mMatrix[i + 2], this->mMatrix[i + 3]};
    	__declspec(align(16)) float vectorB[4] = {scalar, scalar, scalar, scalar};
    	__declspec(align(16)) float vectorResult[4] = {0.0f};
 
    	__m128 sseA;
    	__m128 sseB;
    	__m128 sseResult;
 
    	sseA = _mm_load_ps(vectorA);  
    	sseB = _mm_load_ps(vectorB);
 
    	sseResult = _mm_div_ps(sseA , sseB);
 
    	_mm_store_ps(vectorResult, sseResult);
 
    	this->mMatrix[i] = vectorResult[0];
    	this->mMatrix[i + 1] = vectorResult[1];
    	this->mMatrix[i + 2] = vectorResult[2];
    	this->mMatrix[i + 3] = vectorResult[3];
	}
	return *this;
}
 
// Transpose
Mat4 &Mat4::tra() {
	float tempScalar;
	// Exchange m12 to m21
	tempScalar = this->mMatrix[1];
	this->mMatrix[1] = this->mMatrix[3];
	this->mMatrix[3] = tempScalar;
	tempScalar = this->mMatrix[2];
	this->mMatrix[2] = this->mMatrix[6];
	this->mMatrix[6] = tempScalar;
	tempScalar = this->mMatrix[5];
	this->mMatrix[5] = this->mMatrix[7];
	this->mMatrix[7] = tempScalar;
 
	return *this;
}

float Mat4::get(int col, int row) const {
	if(col > 0 && col < 5 && row > 0 && row < 5) {
		return this->mMatrix[(col - 1) + ((row - 1) << 4)];
	} else {
		return 0.0f;
	}
}

Vec4 Mat4::row(int row) const {
	if(row > 0 && row < 5) {
		return Vec4(this->mMatrix[(row - 1) << 2], this->mMatrix[((row - 1) << 2) + 1], this->mMatrix[((row - 1) << 2) + 2], this->mMatrix[((row - 1) << 2) + 3]);
	} else {
		return Vec4(0.0f, 0.0f, 0.0f, 0.0f);
	}
}

Vec4 Mat4::col(int col) const {
	if(col > 0 && col < 5) {
		return Vec4(this->mMatrix[col - 1], this->mMatrix[col - 1 + 4], this->mMatrix[col - 1 + 8], this->mMatrix[col - 1 + 12]);
	} else {
		return Vec4(0.0f, 0.0f, 0.0f, 0.0f);
	}
}

bool Mat4::set(int col, int row, float scalar) {
	if(col > 0 && col < 5 && row > 0 && row < 5) {
		this->mMatrix[(col - 1) + ((row - 1) << 4)] = scalar;
		return true;
	} else {
		return false;
	}
}

void Mat4::set(float (&array)[16]) {
	for(int i = 0; i < 16; ++i) {
		this->mMatrix[i] = array[i];
	}
}

bool Mat4::setRow(int row, const Vec4 &vector) {
	if(row > 0 && row < 5) {
		this->mMatrix[(row - 1) << 2] = vector.x();
		this->mMatrix[((row - 1) << 2) + 1] = vector.y();
		this->mMatrix[((row - 1) << 2) + 2] = vector.z();
		this->mMatrix[((row - 1) << 2) + 3] = vector.w();
		return true;
	} else {
		return false;
	}
}

bool Mat4::setCol(int col, const Vec4 &vector) {
	if(col > 0 && col < 5) {
		this->mMatrix[col - 1] = vector.x();
		this->mMatrix[col - 1 + 4] = vector.y();
		this->mMatrix[col - 1 + 8] = vector.z();
		this->mMatrix[col - 1 + 12] = vector.w();
		return false;
	} else {
		return false;
	}
}
