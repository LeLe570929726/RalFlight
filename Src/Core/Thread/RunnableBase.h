// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726.All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2017/12/23 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_THREAD_RUNNABLEBASE_H
#define RALFLIGHT_SRC_CORE_THREAD_RUNNABLEBASE_H

#include "../Global/Macro.h"

// Core namespace
namespace Core {

	class RALFLIGHT_API RunnableBase {
	public:
		RunnableBase() = default;
		RunnableBase(const RunnableBase &other) = delete;
		RunnableBase(RunnableBase &&other) = default;
		RunnableBase &operator=(const RunnableBase &other) = delete;
		virtual ~RunnableBase() = default;

	public:
		virtual void run();
	};

}

#endif			// RALFLIGHT_SRC_CORE_THREAD_RUNNABLEBASE_H