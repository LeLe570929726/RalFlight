// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/07/13 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_MATH_MATRIXHELPER_H
#define RALFLIGHT_SRC_CORE_MATH_MATRIXHELPER_H

#include "../Global/Macro.h"
#include "Scalar.h"
#include "Mat4.h"
#include <assert.h>

// Core namespace
namespace Core {

	class RALFLIGHT_API MatrixHelper {
	public:
		MatrixHelper() = delete;
		MatrixHelper(const MatrixHelper &other) = delete;
		~MatrixHelper() = delete;
		MatrixHelper &operator=(const MatrixHelper &other) = delete;

	public:
		static Mat4 create();
		static Mat4 createPerspective(float fov, float near, float far, float ratio);
		static Mat4 createOrtho(float width, float height, float near, float far);
		static Mat4 createOrtho(float width, float height, float depth);
	};

}

#endif		// RALFLIGHT_SRC_CORE_MATH_MATRIXHELPER_H