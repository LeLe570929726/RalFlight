// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726.All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2018/01/27 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "ReadWriteLock.h"

// Core namespace
namespace Core {

#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	ReadWriteLock::ReadWriteLock() {
		InitializeSRWLock(this->mRWLock);
	}

	ReadWriteLock::~ReadWriteLock() {
		// Do nothing
	}

	void ReadWriteLock::lockRead() {
		AcquireSRWLockShared(this->mRWLock);
	}

	void ReadWriteLock::lockWrite() {
		AcquireSRWLockExclusive(this->mRWLock);
	}

	bool ReadWriteLock::tryLockRead() {
		if(TryAcquireSRWLockShared(this->mRWLock) == FALSE) {
			return false;
		} else {
			return true;
		}
	}

	bool ReadWriteLock::tryLockWrite() {
		if(TryAcquireSRWLockExclusive(this->mRWLock) == FALSE) {
			return false;
		} else {
			return true;
		}
	}

	void ReadWriteLock::unlockRead() {
		ReleaseSRWLockShared(this->mRWLock);
	}

	void ReadWriteLock::unlockWrite() {
		ReleaseSRWLockExclusive(this->mRWLock);
	}
#elif defined(RALFLIGHT_SYSTEM_LINUX)
	ReadWriteLock::ReadWriteLock() {
		pthread_rwlock_init(&this->mRWLock, NULL);
	}

	ReadWriteLock::~ReadWriteLock() {
		pthread_rwlock_destroy(&this->mRWLock);
	}

	void ReadWriteLock::lockRead() {
		pthread_rwlock_rdlock(&this->mRWLock);
	}

	void ReadWriteLock::lockWrite() {
		pthread_rwlock_wrlock(&this->mRWLock);
	}

	bool ReadWriteLock::tryLockRead() {
		if(pthread_rwlock_tryrdlock(&this->mRWLock) == 0) {
			return true;
		} else {
			return false;
		}
	}

	bool ReadWriteLock::tryLockWrite() {
		if(pthread_rwlock_trywrlock(&this->mRWLock) == 0) {
			return true;
		} else {
			return false;
		}
	}

	void ReadWriteLock::unlockRead() {
		pthread_rwlock_unlock(&this->mRWLock);
	}

	void ReadWriteLock::unlockWrite() {
		pthread_rwlock_unlock(&this->mRWLock);
	}
#endif

}