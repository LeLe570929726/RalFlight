// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726.All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/12/24 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "ThreadPool.h"

// Core namespace
namespace Core {

#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	ThreadPool::ThreadPool() :
		mThreadMax(ThreadNumber::Maximum), mThreadMin(ThreadNumber::Minimum), mPool(CreateThreadpool(NULL)) {
		this->initialize();
	}

	ThreadPool::ThreadPool(int minimum, int maximum) :
		mThreadMax(maximum), mThreadMin(minimum), mPool(CreateThreadpool(NULL)) {
		assert(minimum >= 0);
		assert(maximum >= 0);
		assert(minimum <= maximum);
		this->initialize();
	}

	ThreadPool::ThreadPool(ThreadPool && other) :
		mThreadMax(std::forward<int>(other.mThreadMax)), mThreadMin(std::forward<int>(other.mThreadMin)), mPool(std::forward<PTP_POOL>(other.mPool)),
		mEnvironment(std::forward<PTP_CALLBACK_ENVIRON>(other.mEnvironment)), mCleanupGroup(std::forward<PTP_CLEANUP_GROUP>(other.mCleanupGroup)) {
	}

	ThreadPool::~ThreadPool() {
		this->destory();
	}

	void ThreadPool::initialize() {
		if(this->mPool != NULL) {
			// Set pool thread's number
			SetThreadpoolThreadMaximum(this->mPool, this->mThreadMax);
			SetThreadpoolThreadMinimum(this->mPool, this->mThreadMin);
			// Create pool's environment
			InitializeThreadpoolEnvironment(this->mEnvironment);
			SetThreadpoolCallbackPool(this->mEnvironment, this->mPool);
			// Create clean-up group
			this->mCleanupGroup = CreateThreadpoolCleanupGroup();
			if(this->mCleanupGroup == NULL) {
				DestroyThreadpoolEnvironment(this->mEnvironment);
				CloseThreadpool(this->mPool);
			}
			SetThreadpoolCallbackCleanupGroup(this->mEnvironment, this->mCleanupGroup, NULL);
		}
	}

	void ThreadPool::destory() {
		if(this->mPool != NULL) {
			CloseThreadpoolCleanupGroupMembers(this->mCleanupGroup, false, NULL);
			CloseThreadpoolCleanupGroup(this->mCleanupGroup);
			DestroyThreadpoolEnvironment(this->mEnvironment);
			CloseThreadpool(this->mPool);
		}
	}
#endif

}