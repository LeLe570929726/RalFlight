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

#include "../Global/Token.h"
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
		static Mat4 createPerspective(real32 fov, real32 near, real32 far, real32 ratio);
		static Mat4 createOrtho(real32 width, real32 height, real32 near, real32 far);
		static Mat4 createOrtho(real32 width, real32 height, real32 depth);
	};

}