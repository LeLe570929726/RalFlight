// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2019/09/15 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"

namespace Core {

class RF_API Clock {
public:
	Clock();
	Clock(const Clock &other) = default;
	Clock(Clock &&other) noexcept = default;
	Clock &operator=(const Clock &other) = default;
	Clock &operator=(Clock &&other) = default;
	~Clock() = default;

public:
	enum ErrorCode { Success, ClockDoesNotStart, ClockDoesNotStop };

public:
	ErrorCode start();
	ErrorCode stop();

public:
	long convertToMillisecond() const;
	double convertToSecond() const;
	double convertToMinute() const;

private:
	long mStartTick;
	long mStopTick;
	bool mIsStarted;
};

} // namespace Core
