// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2019/09/15 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Clock.h"
#ifdef RF_OS_WIN
#include <Windows.h>
#pragma comment(lib, "winmm.lib")
#endif

namespace Core {

Clock::Clock() : mStartTick(0), mStopTick(0), mIsStarted(false) {}

Clock::ErrorCode Clock::start() {
#ifdef RF_OS_WIN
	auto tickOrigin = timeGetTime();
	long tick = static_cast<long>(tickOrigin);
#endif
	if (this->mIsStarted == true) {
		return ErrorCode::ClockDoesNotStop;
	} else {
		this->mIsStarted = true;
		this->mStartTick = tick;
		return ErrorCode::Success;
	}
}

Clock::ErrorCode Clock::stop() {
#ifdef RF_OS_WIN
	auto tickOrigin = timeGetTime();
	long tick = static_cast<long>(tickOrigin);
#endif
	if (this->mIsStarted == false) {
		return ErrorCode::ClockDoesNotStart;
	} else {
		this->mIsStarted = false;
		this->mStopTick = tick;
		return ErrorCode::Success;
	}
}

long Clock::convertToMillisecond() const {
	if (this->mStartTick >= this->mStopTick) {
		return 0;
	} else {
		return this->mStopTick - this->mIsStarted;
	}
}

double Clock::convertToSecond() const {
	if (this->mStartTick >= this->mStopTick) {
		return 0;
	} else {
		return static_cast<double>(this->mStopTick) - static_cast<double>(this->mStartTick) / 1000.0f;
	}
}

double Clock::convertToMinute() const {
	if (this->mStartTick >= this->mStopTick) {
		return 0;
	} else {
		return static_cast<double>(this->mStopTick) - static_cast<double>(this->mStartTick) / 60000.0f;
	}
}

} // namespace Core
