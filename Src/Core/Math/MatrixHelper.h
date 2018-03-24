// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2017/07/13 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Global.h"
#include "Scalar.h"
#include "Mat4.h"
#include <assert.h>

// Core namespace
namespace Core {

	class RF_API MatrixHelper {
	public:
		MatrixHelper() = delete;
		MatrixHelper(const MatrixHelper &other) = delete;
        MatrixHelper &operator=(const MatrixHelper &other) = delete;
		~MatrixHelper() = delete;

	public:
		static Mat4 createZero();
		static Mat4 createPerspective(float fov, float near, float far, float ratio);
		static Mat4 createOrtho(float width, float height, float near, float far);
		static Mat4 createOrtho(float width, float height, float depth);
	};

}