// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726.All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2018/1/21 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_THREAD_MUTEX
#define RALFLIGHT_SRC_CORE_THREAD_MUTEX

#include "../Global/Macro.h"
#include <mutex>

// Core namespace
namespace Core {

	class RALFLIGHT_API Mutex {
	public:
		Mutex() = default;
		Mutex(const Mutex &other) = delete;
		Mutex &operator=(const Mutex &other) = delete;
		~Mutex() = default;

	public:
		inline void lock() {
			this->mMutex.lock();
		}
		inline bool tryLock() {
			return this->mMutex.try_lock();
		}
		inline void unlock() {
			this->mMutex.unlock();
		}

	private:
		std::mutex mMutex;
	};

}

#endif			// RALFLIGHT_SRC_CORE_THREAD_MUTEX