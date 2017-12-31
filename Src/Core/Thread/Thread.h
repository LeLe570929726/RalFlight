// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726.All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/12/2 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_THREAD_THRAED_H
#define RALFLIGHT_SRC_CORE_THREAD_THREAD_H

#include "../Global/Macro.h"
#include "../STL/UniquePointer.h"
#include "RunnableBase.h"
#include "Runnable.h"
#include <utility>
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	#include <Windows.h>
#elif defined(RALFLIGHT_SYSTEM_LINUX)
	#include <pthread.h>
	#include <signal.h>
#endif

// Core namespace
namespace Core {

	class Thread {
	public:
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		template <class F, class... FP>
		Thread(F &&func, FP&&... para) :
			mRunnable(dynamic_cast<RunnableBase *>(new Runnable<F, FP...>(std::forward<F>(func), std::forward<FP>(para)...))),
			mHandle(CreateThread(NULL, 0, Thread::doRun, &this->mRunnable, 0, NULL)) {
		}
		Thread(const Thread &other) = delete;
		Thread(Thread &&other);
		Thread &operator=(const Thread &other) = delete;
		~Thread();
#elif defined(RALFLIGHT_SYSTEM_LINUX)
		template <class F, class... FP>
		Thread(F &&func, FP&&... para) :
			mRunnable(dynamic_cast<RunnableBase *>(new Runnable<F, FP...>(std::forward<F>(func), std::forward<FP>(para)...))) {
			if(pthread_create(&this->mHandle, NULL, &Thread::doRun, &this->mRunnable) == 0) {
				this->mIsSuccessed = true;
			} else {
				this->mIsSuccessed = false;
			}
		}
		Thread(const Thread &other) = delete;
		Thread(Thread &&other);
		Thread &operator=(const Thread &other) = delete;
		~Thread();
#endif

	public:
		int join();
		int detach();
		int terminate();

	public:
		bool isFinished();

	public:
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		static DWORD WINAPI doRun(LPVOID para);
#elif defined(RALFLIGHT_SYSTEM_LINUX)
		static void *doRun(void *para);
#endif

	public:
		enum ErrorCode {
			Success = 0,
			FailToCreateThread = 1,
			FailToTerminateThread = 2
		};

	private:
		UniquePointer<RunnableBase> mRunnable;
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		HANDLE mHandle;
#elif defined(RALFLIGHT_SYSTEM_LINUX)
		pthread_t mHandle;
		bool mIsSuccessed;
#endif
	};

}

#endif		// RALFLIGHT_SRC_CORE_THREAD_THRAED_H