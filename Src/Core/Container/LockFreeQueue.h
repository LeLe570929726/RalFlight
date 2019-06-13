// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/09/02 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"
#include "../Math/Scalar.h"
#include <boost/lockfree/queue.hpp>

namespace Core {

enum class PushCase { Synchronized, Bounded, Unsynchronized };
enum class PopCase { Synchronized, Unsynchronized };

template <class T>
class RF_API_TEMPLATE LockFreeQueue {
public:
	LockFreeQueue() = default;
	LockFreeQueue(uint64 size) : mQueue(size) {}
	LockFreeQueue(const LockFreeQueue &other) = delete;
	LockFreeQueue(LockFreeQueue &&other) = delete;
	LockFreeQueue &operator=(const LockFreeQueue &other) = delete;
	LockFreeQueue &operator=(LockFreeQueue &&other) = delete;
	~LockFreeQueue() = default;

public:
	bool push(const T &value, PushCase pc = PushCase::Synchronized) {
		switch (pc) {
		case PushCase::Synchronized:
			return this->mQueue.push(value);
		case PushCase::Bounded:
			return this->mQueue.bounded_push(value);
		case PushCase::Unsynchronized:
			return this->mQueue.unsynchronized_push(value);
		}
	}
	bool pop(T &out, PopCase pc = PopCase::Synchronized) {
		switch (pc) {
		case PopCase::Synchronized:
			return this->mQueue.pop(out);
		case PopCase ::Unsynchronized:
			return this->mQueue.unsynchronized_pop(out);
		}
	}

public:
	void reserve(uint64 size) { this->mQueue.reserve(size); }
	bool empty() const { return this->mQueue.empty(); }
	bool isLockFree() const { return this->mQueue.is_lock_free(); }

private:
	boost::lockfree::queue<T> mQueue;
};

} // namespace Core