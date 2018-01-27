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
#endif

}