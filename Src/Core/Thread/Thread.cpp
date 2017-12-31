// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726.All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/12/2 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Thread.h"

// Core namespace
namespace Core {

#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	Thread::Thread(Thread &&other) :
		mRunnable(std::forward<UniquePointer<RunnableBase>>(other.mRunnable)), mHandle(std::forward<HANDLE>(other.mHandle)) {
	}

	Thread::~Thread() {
		this->terminate();
		CloseHandle(this->mHandle);
	}

	int Thread::join() {
		if(this->mHandle != NULL) {
			WaitForSingleObject(this->mHandle, INFINITE);
			return ErrorCode::Success;
		} else {
			return ErrorCode::FailToCreateThread;
		}
	}

	int Thread::detach() {
		if(this->mHandle != NULL) {
			return ErrorCode::Success;
		} else {
			return ErrorCode::FailToCreateThread;
		}
	}

	int Thread::terminate() {
		if(this->mHandle != NULL) {
			if(this->isFinished() == false) {
				if(TerminateThread(this->mHandle, NULL) != FALSE) {
					return ErrorCode::Success;
				} else {
					return ErrorCode::FailToTerminateThread;
				}
			} else {
				return ErrorCode::Success;
			}
		} else {
			return ErrorCode::FailToCreateThread;
		}
	}

	bool Thread::isFinished() {
		if(this->mHandle != NULL) {
			DWORD exitCode;
			GetExitCodeThread(this->mHandle, &exitCode);
			if(exitCode == STILL_ACTIVE) {
				return false;
			} else {
				return true;
			}
		} else {
			return true;
		}
	}

	DWORD WINAPI Thread::doRun(LPVOID para) {
		auto object = static_cast<UniquePointer<RunnableBase> *>(para);
		(**object).run();
		return 0;
	}
#elif defined(RALFLIGHT_SYSTEM_LINUX)
	Thread::Thread(Thread &&other) :
		mRunnable(std::forward<UniquePointer<RunnableBase>>(other.mRunnable)), mHandle(std::forward<pthread_t>(other.mHandle)), 
		mIsSuccessed(std::forward<bool>(other.mIsSuccessed)) {
	}

	Thread::~Thread() {
		this->terminate();
	}

	int Thread::join() {
		if(this->mIsSuccessed == true) {
			if(this->isFinished() == false) {
				pthread_join(this->mHandle, NULL);
				return ErrorCode::Success;
			} else {
				return ErrorCode::Success;
			}
		} else {
			return ErrorCode::FailToCreateThread;
		}
	}

	int Thread::detach() {
		if(this->mIsSuccessed == true) {
			if(this->isFinished() == false) {
				pthread_detach(this->mHandle);
				return ErrorCode::Success;
			} else {
				return ErrorCode::Success;
			}
		} else {
			return ErrorCode::FailToCreateThread;
		}
	}

	int Thread::terminate() {
		if(this->mIsSuccessed == true) {
			if(this->isFinished() == false) {
				pthread_cancel(this->mHandle);
				return ErrorCode::Success;
			} else {
				return ErrorCode::Success;
			}
		} else {
			return ErrorCode::FailToCreateThread;
		}
	}

	bool Thread::isFinished() {
		if(this->mIsSuccessed == true) {
			if(pthread_kill(this->mHandle, 0) != 0) {
				return true;
			} else {
				return false;
			}
		} else {
			return true;
		}
	}

	void *Thread::doRun(void *para) {
		auto object = static_cast<UniquePointer<RunnableBase> *>(para);
		(**object).run();
		return 0;
}
#endif

}