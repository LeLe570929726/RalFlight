// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726.All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2017/12/24 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_THREAD_THREADPOOL_H
#define RALFLIGHT_SRC_CORE_THREAD_THREADPOOL_H

#include "../Global/Macro.h"
#include "../STL/UniquePointer.h"
#include "../STL/Map.h"
#include "RunnableBase.h"
#include "Runnable.h"
#include <assert.h>
#include <utility>
#include <tuple>
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
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		template <class F, class... FP>
		int submit(F &&func, FP&&... para) {
			UniquePointer<RunnableBase> runnable(dynamic_cast<RunnableBase *>(new Runnable<F, FP...>(std::forward<F>(func), std::forward<FP>(para)...)));
			this->mWork.insert(static_cast<int>(&runnable), runnable);
			std::tuple<>
			auto work = CreateThreadpoolWork(ThreadPool::doRun, static_cast<int>(&runnable), this->mEnvironment);
			if(work == NULL) {
				return ErrorCode::FailToCreateWork;
			}
			SubmitThreadpoolWork(work);
			return ErrorCode::Success;
		}
#endif

	public:
		enum ThreadNumber {
			Maximum = 250,
			Minimum = 5
		};

		enum ErrorCode {
			Success = 0,
			FailToCreateWork = 1
		};

	public:
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		static void WINAPI doRun(PTP_CALLBACK_INSTANCE instance, PVOID context, PTP_WORK work);
#endif

	private:
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		void initialize();
		void destory();
#endif

	private:
		int mThreadMax;
		int mThreadMin;
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		Map<int, UniquePointer<RunnableBase>> mWork;
		PTP_POOL mPool;
		PTP_CALLBACK_ENVIRON mEnvironment;
		PTP_CLEANUP_GROUP mCleanupGroup;
#endif
	};

}

#endif