// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2017/07/13 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "MatrixHelper.h"

// Core namespace
namespace Core {

    Mat4 MatrixHelper::createZero() {
        return Mat4::zero;
    }

	Mat4 MatrixHelper::createPerspective(real32 fov, real32 near, real32 far, real32 ratio) {
		assert(near != far);
		assert(ratio);
		assert(fov);
		real32 tangent = 1.0f / Scalar::tan(fov * 0.5f);
		real32 distance = far - near;
		Mat4 tempMatrix = Mat4::zero;
		tempMatrix.set(1, 1, 1.0f / ratio * tangent);
		tempMatrix.set(2, 2, tangent);
		tempMatrix.set(3, 3, far / distance);
		tempMatrix.set(4, 3, near * far / distance);
		tempMatrix.set(3, 4, 1.0f);
		return tempMatrix;
	}

	Mat4 MatrixHelper::createOrtho(real32 width, real32 height, real32 near, real32 far) {
		assert(width);
		assert(height);
		assert(near != far);
		real32 distance = far - near;
		Mat4 tempMatrix = Mat4::zero;
		tempMatrix.set(1, 1, 2.0f / width);
		tempMatrix.set(2, 2, 2.0f / height);
		tempMatrix.set(3, 3, 1.0f / distance);
		tempMatrix.set(3, 4, - (near / distance));
		tempMatrix.set(4, 4, 1.0f);
		return tempMatrix;
	}

	Mat4 MatrixHelper::createOrtho(real32 width, real32 height, real32 depth) {
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