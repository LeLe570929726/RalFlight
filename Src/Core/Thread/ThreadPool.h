// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726.All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/12/24 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_THREAD_THREADPOOL_H
#define RALFLIGHT_SRC_CORE_THREAD_THREADPOOL_H

#include "../Global/Macro.h"
#include <assert.h>
#include <utility>
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	#include <Windows.h>
#endif

// Core namespace
namespace Core {

	class RALFLIGHT_API ThreadPool {
	public:
		ThreadPool();
		ThreadPool(int min, int max);
		ThreadPool(const ThreadPool &other) = delete;
		ThreadPool(ThreadPool &&other);
		ThreadPool &operator=(const ThreadPool &other) = delete;
		~ThreadPool();

	public:
		enum ThreadNumber {
			Maximum = 250,
			Minimum = 5
		};

	private:
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		void initialize();
		void destory();
#endif

	private:
		int mThreadMax;
		int mThreadMin;
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		PTP_POOL mPool;
		PTP_CALLBACK_ENVIRON mEnvironment;
		PTP_CLEANUP_GROUP mCleanupGroup;
#endif
	};

}

#endif