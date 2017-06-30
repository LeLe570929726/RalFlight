// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/5/13 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_THREAD_THREAD_H
#define RALFLIGHT_SRC_CORE_THREAD_THREAD_H

#include "../../Global/Macro/Macro.h"
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
#include <Windows.h>
#endif

namespace Core {

	template<typename TF, typename ...TP>
	class RALFLIGHT_API Thread {
	public:
		Thread(TF &&lambda);
		~Thread() = default;
	};

}

#endif				// RALFLIGHT_SRC_CORE_THREAD_THREAD_H