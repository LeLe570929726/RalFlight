// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/12/23 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_STL_UNIQUEPOINTER_H
#define RALFLIGHT_SRC_CORE_STL_UNIQUEPOINTER_H

#include "../Global/Macro.h"
#include <memory>

// Core namespace
namespace Core {

	template <class T>
	using RALFLIGHT_API_TEMPLATE UniquePointer = std::unique_ptr<T>;

}

#endif			// RALFLIGHT_SRC_CORE_STL_UNIQUEPOINTER_H