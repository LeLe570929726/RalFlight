// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/07/13 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "MatrixHelper.h"

// Core namespace
namespace Core {

	Mat4 MatrixHelper::createPerspective(float fov, float near, float far, float ratio) {
		assert(near != far);
		assert(ratio);
		assert(fov);
		float tangent = 1.0f / Scalar<float>::tan(fov * 0.5f);
		float distance = far - near;
		Mat4 tempMatrix = Mat4::zero;
		tempMatrix.set(1, 1, 1.0f / ratio * tangent);
		tempMatrix.set(2, 2, tangent);
		tempMatrix.set(3, 3, far / distance);
		tempMatrix.set(4, 3, near * far / distance);
		tempMatrix.set(3, 4, 1.0f);
		return tempMatrix;
	}

	Mat4 MatrixHelper::createOrtho(float width, float height, float near, float far) {
		assert(width);
		assert(height);
		assert(near != far);
		float distance = far - near;
		Mat4 tempMatrix = Mat4::zero;
		tempMatrix.set(1, 1, 2.0f / width);
		tempMatrix.set(2, 2, 2.0f / height);
		tempMatrix.set(3, 3, 1.0f / distance);
		tempMatrix.set(3, 4, - (near / distance));
		tempMatrix.set(4, 4, 1.0f);
		return tempMatrix;
	}

	Mat4 MatrixHelper::createOrtho(float width, float height, float depth) {
		assert(width);
		assert(height);
		assert(depth);
		Mat4 tempMatrix = Mat4::zero;
		tempMatrix.set(1, 1, 2.0f / width);
		tempMatrix.set(2, 2, 2.0f / height);
		tempMatrix.set(3, 3, 2.0f / depth);
		tempMatrix.set(4, 4, 1.0f);
		return tempMatrix;
	}

}