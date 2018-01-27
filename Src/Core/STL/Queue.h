// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2018/1/21 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_STL_QUEUE
#define RALFLIGHT_SRC_CORE_STL_QUEUE

#include "../Global/Macro.h"
#include <queue>

// Core namespace
namespace Core {

	template <class T, class Container = std::deque<T>>
	using Queue = std::queue<T, Container>;

}

#endif			// RALFLIGHT_SRC_CORE_STL_QUEUE