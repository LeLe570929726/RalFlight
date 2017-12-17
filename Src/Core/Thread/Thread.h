// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2017 LeLe570929726.All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/12/2 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_THREAD_THRAED_H
#define RALFLIGHT_SRC_CORE_THREAD_THREAD_H

#include "ThreadBase.h"
#include "../Global/Macro.h"
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	#include <Windows.h>
#endif

// Core namespace
namespace Core {

	template <class F, class... FP>
	class RALFLIGHT_API Thread : public ThreadBase<F, FP...> {
	public:
		Thread(F func, FP... para) :
			ThreadBase<F, FP...>(func, para...) {
			createThread();
		}
		Thread(const Thread &other) = delete;
		Thread &operator=(copnst Thread &other) = delete;
		~Thread() {
			destoryThread();
		}

	public:
		int run() {
			return this->resumeThread();
		}
		int suspend() {
			return this->suspendThread();
		}
		int resume() {
			return this->resumeThread();
		}
		int terminate() {
			return this->terminateThread();
		}

	private:
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		void createThread() {
			this->mHandle = CreateThread(NULL, 0, ThreadBase<F, FP...>::doRun, this, CREATE_SUSPENDED, NULL);
		}
		void destoryThread() {
			if(this->mHandle != NULL) {
				CloseHandle(this->mHandle);
			}
		}
		int resumeThread() {
			if(this->mHandle != NULL) {
				if(ResumeThread(this->mHandle) != static_cast<DWORD>(-1)) {
					return ErrorCode::Success;
				} else {
					return ErrorCode::FailToResumeThread;
				}
			} else {
				return ErrorCode::FailToCreateThread;
			}
		}
		int suspendThread() {
			if(this->mHandle != NULL) {
				if(SuspendThread(this->mHandle) != static_cast<DWORD>(-1)) {
					return ErrorCode::Success;
				} else {
					return ErrorCode::FailToSuspendThread;
				}
			} else {
				return ErrorCode::FailToCreateThread;
			}
		}
		int terminateThread() {
			if(this->mHandle != NULL) {
				if(TerminateThread(this->mHandle, NULL) != FALSE) {
					return ErrorCode::Success;
				} else {
					return ErrorCode::FailToTerminateThread;
				}
			} else {
				return ErrorCode::FailToCreateThread;
			}
		}
#endif

	public:
		enum ErrorCode {
			Success = 0,
			FailToCreateThread = 1,
			FailToResumeThread = 2,
			FailToSuspendThread = 3,
			FailToTerminateThread = 4
		};

	private:
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		HANDLE mHandle;
#endif
	};
}

#endif		// RALFLIGHT_SRC_CORE_THREAD_THRAED_H