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
#elif defined(RALFLIGHT_SYSTEM_LINUX) || defined(RALFLIGHT_SYSTEM_MAC)
	#include <pthread.h>
#endif

// Core namespace
namespace Core {

	template <class F, class... FP>
	class RALFLIGHT_API Thread : public ThreadBase<F, FP...> {
	public:
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		Thread(F func, FP... para) :
			ThreadBase<F, FP...>(func, para...), mHandle(CreateThread(NULL, 0, ThreadBase<F, FP...>::doRun, this, CREATE_SUSPENDED, NULL)) {
		}
		~Thread() {
			if(this->mHandle != NULL) {
				CloseHandle(this->mHandle);
			}
		}
#elif defined(RALFLIGHT_SYSTEM_LINUX) || defined(RALFLIGHT_SYSTEM_MAC)
		Thread(F func, FP... para) :
			ThreadBase<F, FP...>(func, para...), mHandle(0) {
		}
		~Thread() {
		}
#endif
		Thread(const Thread &other) = delete;
		Thread &operator=(copnst Thread &other) = delete;

	public:
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		int detach() {
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
		int join() {
			if(this->mHandle != NULL) {
				if(ResumeThread(this->mHandle) != static_cast<DWORD>(-1)) {
					WaitForSingleObject(this->mHandle, INFINITE);
					return ErrorCode::Success;
				} else {
					return ErrorCode::FailToResumeThread;
				}
			} else {
				return ErrorCode::FailToCreateThread;
			}
		}
		int terminate() {
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
#elif defined(RALFLIGHT_SYSTEM_LINUX) || defined(RALFLIGHT_SYSTEM_MAC)
		int detach() {
			if(pthread_create(&this->mHandle, NULL, &ThreadBase<F, FP...>::doRun, this) == 0) {
				if(pthread_detach(this->mHandle) == 0) {
					return ErrorCode::Success;
				} else {
					return ErrorCode::FailToResumeThread;
				}
			} else {
				return ErrorCode::FailToCreateThread;
			}
		}
		int join() {
			if(pthread_create(&this->mHandle, NULL, &ThreadBase<F, FP...>::doRun, this) == 0) {
				if(pthread_join(this->mHandle, NULL) == 0) {
					return ErrorCode::Success;
				} else {
					return ErrorCode::FailToResumeThread;
				}
			} else {
				return ErrorCode::FailToCreateThread;
			}
		}
		int terminate() {
			// TODO
		}
#endif

	public:
		enum ErrorCode {
			Success = 0,
			FailToCreateThread = 1,
			FailToResumeThread = 2,
			FailToTerminateThread = 3
		};

	private:
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		HANDLE mHandle;
#elif defined(RALFLIGHT_SYSTEM_LINUX) || defined(RALFLIGHT_SYSTEM_MAC)
		pthread_t mHandle;
#endif
	};
}

#endif		// RALFLIGHT_SRC_CORE_THREAD_THRAED_H