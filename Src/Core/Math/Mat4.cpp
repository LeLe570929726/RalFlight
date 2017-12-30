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

// Core namespace
namespace Core {

	const Mat4 Mat4::zero(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	const Mat4 Mat4::identity(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);

	Mat4::Mat4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24,
		float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44) :
		mMatrix{ m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44 } {
	}

	Mat4::Mat4(float(&array)[16]) :
		mMatrix{ array[0], array[1], array[2], array[3], array[4], array[5], array[6], array[7], array[8], array[9],
			array[10], array[11], array[12], array[13], array[14], array[15] } {
	}

	Mat4::Mat4(const Mat4 &other) :
		mMatrix{ other.mMatrix[0], other.mMatrix[1], other.mMatrix[2], other.mMatrix[3], other.mMatrix[4], other.mMatrix[5],
			other.mMatrix[6], other.mMatrix[7], other.mMatrix[8], other.mMatrix[9], other.mMatrix[10], other.mMatrix[11],
			other.mMatrix[12], other.mMatrix[13], other.mMatrix[14], other.mMatrix[15] } {
	}

	Mat4 &Mat4::operator=(const Mat4 &other) {
		for (int i = 0; i < 15; ++i) {
			this->mMatrix[i] = other.mMatrix[i];
		}
		return *this;
	}

	Mat4 Mat4::add(const Mat4 &matrixA, const Mat4 &matrixB) {
		float tempArray[16] = { 0.0f };
		for (int i = 0; i <= 12; i += 4) {
			ALIGN16 float vectorA[4] = { matrixA.mMatrix[i], matrixA.mMatrix[i + 1],
													   matrixA.mMatrix[i + 2], matrixA.mMatrix[i + 3] };
			ALIGN16 float vectorB[4] = { matrixB.mMatrix[i], matrixB.mMatrix[i + 1], 
													   matrixB.mMatrix[i + 2], matrixB.mMatrix[i + 3] };
			ALIGN16 float vectorResult[4] = { 0.0f };
			__m128 sseA, sseB, sseResult;
			sseA = _mm_load_ps(vectorA);
			sseB = _mm_load_ps(vectorB);
			sseResult = _mm_add_ps(sseA, sseB);
			_mm_store_ps(vectorResult, sseResult);
			tempArray[i] = vectorResult[0];
			tempArray[i + 1] = vectorResult[1];
			tempArray[i + 2] = vectorResult[2];
			tempArray[i + 3] = vectorResult[3];
		}
		return Mat4(tempArray);
	}

	Mat4 Mat4::sub(const Mat4 &matrixA, const Mat4 &matrixB) {
		float tempArray[16] = { 0.0f };
		for (int i = 0; i <= 12; i += 4) {
			ALIGN16 float vectorA[4] = { matrixA.mMatrix[i], matrixA.mMatrix[i + 1], 
													   matrixA.mMatrix[i + 2], matrixA.mMatrix[i + 3] };
			ALIGN16 float vectorB[4] = { matrixB.mMatrix[i], matrixB.mMatrix[i + 1], 
													   matrixB.mMatrix[i + 2], matrixB.mMatrix[i + 3] };
			ALIGN16 float vectorResult[4] = { 0.0f };
			__m128 sseA, sseB, sseResult;
			sseA = _mm_load_ps(vectorA);
			sseB = _mm_load_ps(vectorB);
			sseResult = _mm_sub_ps(sseA, sseB);
			_mm_store_ps(vectorResult, sseResult);
			tempArray[i] = vectorResult[0];
			tempArray[i + 1] = vectorResult[1];
			tempArray[i + 2] = vectorResult[2];
			tempArray[i + 3] = vectorResult[3];
		}
		return Mat4(tempArray);
	}

	Mat4 Mat4::mul(const Mat4 &matrix, float scalar) {
		float tempArray[16] = { 0.0f };
		for (int i = 0; i <= 12; i += 4) {
			ALIGN16 float vectorA[4] = { matrix.mMatrix[i], matrix.mMatrix[i + 1], 
													   matrix.mMatrix[i + 2], matrix.mMatrix[i + 3] };
			ALIGN16 float vectorB[4] = { scalar, scalar, scalar, scalar };
			ALIGN16 float vectorResult[4] = { 0.0f };
			__m128 sseA, sseB, sseResult;
			sseA = _mm_load_ps(vectorA);
			sseB = _mm_load_ps(vectorB);
			sseResult = _mm_mul_ps(sseA, sseB);
			_mm_store_ps(vectorResult, sseResult);
			tempArray[i] = vectorResult[0];
			tempArray[i + 1] = vectorResult[1];
			tempArray[i + 2] = vectorResult[2];
			tempArray[i + 3] = vectorResult[3];
		}
		return Mat4(tempArray);
	}

	Vec4 Mat4::mul(const Mat4 &matrix, const Vec4 &vector) {
		float tempArray[4] = { 0.0f };
		ALIGN16 float vectorA[4] = { vector.getX(), vector.getY(), vector.getZ(), vector.getW() };
		__m128 sseA;
		sseA = _mm_load_ps(vectorA);
		for (int i = 0; i <= 12; i += 12) {
			ALIGN16 float vectorB[4] = { matrix.mMatrix[i], matrix.mMatrix[i + 1], 
													   matrix.mMatrix[i + 2], matrix.mMatrix[i + 3] };
			ALIGN16 float vectorResult[4] = { 0.0f };
			__m128 sseB, sseResult;
			sseB = _mm_load_ps(vectorB);
			sseResult = _mm_mul_ps(sseA, sseB);
			_mm_store_ps(vectorResult, sseResult);
			tempArray[static_cast<int>(i >> 2)] = vectorResult[0] + vectorResult[1] + vectorResult[2] + vectorResult[3];
		}
		return Vec4(tempArray);
	}

	Mat4 Mat4::mul(const Mat4 &matrixA, const Mat4 &matrixB) {
		float tempArray[16] = { 0.0f };
		for (int i = 0; i < 16; ++i) {
			ALIGN16 float vectorA[4] = { matrixA.mMatrix[static_cast<int>(i >> 2)], matrixA.mMatrix[static_cast<int>(i >> 2) + 1],
													   matrixA.mMatrix[static_cast<int>(i >> 2) + 2], matrixA.mMatrix[static_cast<int>(i >> 2) + 3] };
			ALIGN16 float vectorB[4] = { matrixB.mMatrix[(i % 4)], matrixB.mMatrix[(i % 4) + 4],
													   matrixB.mMatrix[(i % 4) + 8], matrixB.mMatrix[(i % 4) + 12] };
			ALIGN16 float vectorResult[4] = { 0.0f };
			__m128 sseA, sseB, sseResult;
			sseA = _mm_load_ps(vectorA);
			sseB = _mm_load_ps(vectorB);
			sseResult = _mm_mul_ps(sseA, sseB);
			_mm_store_ps(vectorResult, sseResult);
			tempArray[i] = vectorResult[0] + vectorResult[1] + vectorResult[2] + vectorResult[3];
		}
		return Mat4(tempArray);
	}

	Mat4 Mat4::div(const Mat4 &matrix, float scalar) {
		assert(scalar);
		float tempArray[16] = { 0.0f };
		for (int i = 0; i <= 12; i += 4) {
			ALIGN16 float vectorA[4] = { matrix.mMatrix[i], matrix.mMatrix[i + 1], 
													   matrix.mMatrix[i + 2], matrix.mMatrix[i + 3] };
			ALIGN16 float vectorB[4] = { scalar, scalar, scalar, scalar };
			ALIGN16 float vectorResult[4] = { 0.0f };
			__m128 sseA, sseB, sseResult;
			sseA = _mm_load_ps(vectorA);
			sseB = _mm_load_ps(vectorB);
			sseResult = _mm_div_ps(sseA, sseB);
			_mm_store_ps(vectorResult, sseResult);
			tempArray[i] = vectorResult[0];
			tempArray[i + 1] = vectorResult[1];
			tempArray[i + 2] = vectorResult[2];
			tempArray[i + 3] = vectorResult[3];
		}
		return Mat4(tempArray);
	}

	Mat4 Mat4::transpose(const Mat4 &matrix) {
		Mat4 tempMatrix = matrix;
		float tempScalar;
		tempScalar = tempMatrix.mMatrix[1];
		tempMatrix.mMatrix[1] = tempMatrix.mMatrix[4];
		tempMatrix.mMatrix[4] = tempScalar;
		tempScalar = tempMatrix.mMatrix[2];
		tempMatrix.mMatrix[2] = tempMatrix.mMatrix[8];
		tempMatrix.mMatrix[8] = tempScalar;
		tempScalar = tempMatrix.mMatrix[3];
		tempMatrix.mMatrix[3] = tempMatrix.mMatrix[12];
		tempMatrix.mMatrix[12] = tempScalar;
		tempScalar = tempMatrix.mMatrix[7];
		tempMatrix.mMatrix[7] = tempMatrix.mMatrix[13];
		tempMatrix.mMatrix[13] = tempScalar;
		tempScalar = tempMatrix.mMatrix[11];
		tempMatrix.mMatrix[11] = tempMatrix.mMatrix[14];
		tempMatrix.mMatrix[14] = tempScalar;
		tempScalar = tempMatrix.mMatrix[6];
		tempMatrix.mMatrix[6] = tempMatrix.mMatrix[9];
		tempMatrix.mMatrix[9] = tempScalar;
		return tempMatrix;
	}

	float Mat4::determinant(const Mat4 &matrix) {
		ALIGN16 float vectorA[4] = { matrix.mMatrix[0], matrix.mMatrix[0], matrix.mMatrix[0], matrix.mMatrix[1] };
		ALIGN16 float vectorB[4] = { matrix.mMatrix[5], matrix.mMatrix[6], matrix.mMatrix[7], matrix.mMatrix[6] };
		ALIGN16 float vectorC[4] = { matrix.mMatrix[1], matrix.mMatrix[2], matrix.mMatrix[8], matrix.mMatrix[8] };
		ALIGN16 float vectorD[4] = { matrix.mMatrix[7], matrix.mMatrix[7], matrix.mMatrix[13], matrix.mMatrix[14] };
		ALIGN16 float vectorE[4] = { matrix.mMatrix[8], matrix.mMatrix[9], matrix.mMatrix[9], matrix.mMatrix[10] };
		ALIGN16 float vectorF[4] = { matrix.mMatrix[15], matrix.mMatrix[14], matrix.mMatrix[15], matrix.mMatrix[15] };
		ALIGN16 float vectorG[4] = { matrix.mMatrix[1], matrix.mMatrix[2], matrix.mMatrix[3], matrix.mMatrix[2] };
		ALIGN16 float vectorH[4] = { matrix.mMatrix[4], matrix.mMatrix[4], matrix.mMatrix[4], matrix.mMatrix[5] };
		ALIGN16 float vectorI[4] = { matrix.mMatrix[3], matrix.mMatrix[3], matrix.mMatrix[9], matrix.mMatrix[10] };
		ALIGN16 float vectorJ[4] = { matrix.mMatrix[5], matrix.mMatrix[6], matrix.mMatrix[12], matrix.mMatrix[12] };
		ALIGN16 float vectorK[4] = { matrix.mMatrix[11], matrix.mMatrix[10], matrix.mMatrix[11], matrix.mMatrix[11] };
		ALIGN16 float vectorL[4] = { matrix.mMatrix[12], matrix.mMatrix[13], matrix.mMatrix[13], matrix.mMatrix[14] };
		ALIGN16 float vectorResultA[4] = { 0.0f };
		ALIGN16 float vectorResultB[4] = { 0.0f };
		ALIGN16 float vectorResultC[4] = { 0.0f };
		ALIGN16 float vectorResultD[4] = { 0.0f };
		ALIGN16 float vectorResultE[4] = { 0.0f };
		__m128 sseA, sseB, sseC, sseD, sseE, sseF, sseG, sseH, sseI, sseJ, sseK, sseL, sseM, sseN, sseO, sseP, sseResultA, sseResultB, sseResultC;
		sseA = _mm_load_ps(vectorA);
		sseB = _mm_load_ps(vectorB);
		sseC = _mm_load_ps(vectorC);
		sseD = _mm_load_ps(vectorD);
		sseE = _mm_load_ps(vectorE);
		sseF = _mm_load_ps(vectorF);
		sseG = _mm_load_ps(vectorG);
		sseH = _mm_load_ps(vectorH);
		sseI = _mm_load_ps(vectorI);
		sseJ = _mm_load_ps(vectorJ);
		sseK = _mm_load_ps(vectorK);
		sseL = _mm_load_ps(vectorL);
		sseB = _mm_mul_ps(sseA, sseB);
		sseD = _mm_mul_ps(sseC, sseD);
		sseF = _mm_mul_ps(sseE, sseF);
		sseH = _mm_mul_ps(sseG, sseH);
		sseJ = _mm_mul_ps(sseI, sseJ);
		sseL = _mm_mul_ps(sseK, sseL);
		sseResultA = _mm_sub_ps(sseB, sseH);
		sseResultB = _mm_sub_ps(sseD, sseJ);
		sseResultC = _mm_sub_ps(sseF, sseL);
		_mm_store_ps(vectorResultA, sseResultA);
		_mm_store_ps(vectorResultB, sseResultB);
		_mm_store_ps(vectorResultC, sseResultC);
		ALIGN16 float vectorM[4] = { vectorResultA[0], vectorResultA[1], vectorResultA[2], 0.0f };
		ALIGN16 float vectorN[4] = { vectorResultC[3], vectorResultC[2], vectorResultC[1], 0.0f };
		ALIGN16 float vectorO[4] = { vectorResultA[4], vectorResultB[0], vectorResultB[1], 0.0f };
		ALIGN16 float vectorP[4] = { vectorResultC[0], vectorResultB[3], vectorResultB[2], 0.0f };
		sseM = _mm_load_ps(vectorM);
		sseN = _mm_load_ps(vectorN);
		sseO = _mm_load_ps(vectorO);
		sseP = _mm_load_ps(vectorP);
		sseN = _mm_mul_ps(sseM, sseN);
		sseP = _mm_mul_ps(sseO, sseP);
		_mm_store_ps(vectorResultD, sseN);
		_mm_store_ps(vectorResultE, sseP);
		return vectorResultD[0] - vectorResultD[1] + vectorResultD[2] + vectorResultE[0] - vectorResultE[1] + vectorResultE[2];
	}

	float Mat4::get(const Mat4 &matrix, int col, int row) {
		assert(col > 0 && col < 5);
		assert(row > 0 && row < 5);
		return matrix.mMatrix[(col - 1) + ((row - 1) << 2)];
	}

	Vec4 Mat4::getRow(const Mat4 &matrix, int row) {
		assert(row > 0 && row < 5);
		return Vec4(matrix.mMatrix[(row - 1) << 2], matrix.mMatrix[((row - 1) << 2) + 1], matrix.mMatrix[((row - 1) << 2) + 2], matrix.mMatrix[((row - 1) << 2) + 3]);
	}

	Vec4 Mat4::getCol(const Mat4 &matrix, int col) {
		assert(col > 0 && col < 5);
		return Vec4(matrix.mMatrix[col - 1], matrix.mMatrix[col - 1 + 4], matrix.mMatrix[col - 1 + 8], matrix.mMatrix[col - 1 + 12]);
	}

	void Mat4::set(Mat4 &matrix, int col, int row, float scalar) {
		assert(col > 0 && col < 5);
		assert(row > 0 && row < 5);
		matrix.mMatrix[(col - 1) + ((row - 1) << 2)] = scalar;
	}

	void Mat4::set(Mat4 &matrix, float(&array)[16]) {
		for (int i = 0; i < 16; ++i) {
			matrix.mMatrix[i] = array[i];
		}
	}

	void Mat4::setRow(Mat4 &matrix, int row, const Vec4 &vector) {
		assert(row > 0 && row < 5);
		matrix.mMatrix[(row - 1) << 2] = vector.getX();
		matrix.mMatrix[((row - 1) << 2) + 1] = vector.getY();
		matrix.mMatrix[((row - 1) << 2) + 2] = vector.getZ();
		matrix.mMatrix[((row - 1) << 2) + 3] = vector.getW();
	}

	void Mat4::setCol(Mat4 &matrix, int col, const Vec4 &vector) {
		assert(col > 0 && col < 5);
		matrix.mMatrix[col - 1] = vector.getX();
		matrix.mMatrix[col - 1 + 4] = vector.getY();
		matrix.mMatrix[col - 1 + 8] = vector.getZ();
		matrix.mMatrix[col - 1 + 12] = vector.getW();
	}

}