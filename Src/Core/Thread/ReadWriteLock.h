// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726.All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2018/1/27 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_THREAD_READWRITELOCK_H
#define RALFLIGHT_SRC_CORE_THREAD_READWRITELOCK_H

#include "../Global/Macro.h"
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	#include <Windows.h>
#elif defined(RALFLIGHT_SYSTEM_LINUX)
	#include <pthread.h>
#endif

// Core namespace
namespace Core {

	class RALFLIGHT_API ReadWriteLock {
	public:
		ReadWriteLock();
		ReadWriteLock(const ReadWriteLock &other) = delete;
		ReadWriteLock &operator=(const ReadWriteLock &other) = delete;
		~ReadWriteLock();

	public:
		void lockRead();
		void lockWrite();
		bool tryLockRead();
		bool tryLockWrite();
		void unlockRead();
		void unlockWrite();

	private:
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		PSRWLOCK mRWLock;
#elif defined(RALFLIGHT_SYSTEM_LINUX)
		pthread_rwlock_t mRWLock;
#endif
	};

}

#endif			// RALFLIGHT_SRC_CORE_THREAD_READWRITELOCK_H