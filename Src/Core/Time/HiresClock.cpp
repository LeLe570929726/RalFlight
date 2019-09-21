// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2019/09/11 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "HiresClock.h"
#ifdef RF_OS_WIN
#include <Windows.h>
#endif

namespace Core {

HiresClock::HiresClock() : mStartTick(0), mStopTick(0), mIsStarted(false) {}

HiresClock::ErrorCode HiresClock::start() {
#ifdef RF_OS_WIN
	LARGE_INTEGER tickOrigin;
	QueryPerformanceCounter(&tickOrigin);
	long tick = tickOrigin.QuadPart;
#endif
	if (this->mIsStarted == true) {
		return ErrorCode::ClockDoesNotStop;
	} else {
		this->mIsStarted = true;
		this->mStartTick = tick;
		return ErrorCode::Success;
	}
}

HiresClock::ErrorCode HiresClock::stop() {
#ifdef RF_OS_WIN
	LARGE_INTEGER tickOrigin;
	QueryPerformanceCounter(&tickOrigin);
	long tick = tickOrigin.QuadPart;
#endif
	if (this->mIsStarted == false) {
		return ErrorCode::ClockDoesNotStart;
	} else {
		this->mIsStarted = false;
		this->mStopTick = tick;
		return ErrorCode::Success;
	}
}

long HiresClock::frequency() const {
#ifdef RF_OS_WIN
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);
	return static_cast<long>(frequency.QuadPart);
#endif
}

double HiresClock::convertToSecond() const {
	if (this->mStartTick >= this->mStopTick) {
		return 0.0f;
	} else {
		return (static_cast<double>(this->mStopTick) - static_cast<double>(this->mStartTick)) /
			   static_cast<double>(this->frequency());
	}
}

double HiresClock::convertToMillisecond() const {
	if (this->mStartTick >= this->mStopTick) {
		return 0.0f;
	} else {
		return ((static_cast<double>(this->mStopTick) - static_cast<double>(this->mStartTick)) * 1000.0f) /
			   static_cast<double>(this->frequency());
	}
}

double HiresClock::convertToMicrosecond() const {
	if (this->mStartTick >= this->mStopTick) {
		return 0.0f;
	} else {
		return ((static_cast<double>(this->mStopTick) - static_cast<double>(this->mStartTick)) * 1000000.0f) /
			   static_cast<double>(this->frequency());
	}
}

} // namespace Core
