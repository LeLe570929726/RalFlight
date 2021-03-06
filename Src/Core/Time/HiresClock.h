﻿// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2019/09/11 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"

namespace Core {

class RF_API HiresClock {
public:
	HiresClock();
	HiresClock(const HiresClock &other) = default;
	HiresClock(HiresClock &&other) noexcept = default;
	HiresClock &operator=(const HiresClock &other) = default;
	HiresClock &operator=(HiresClock &&other) noexcept = default;
	~HiresClock() = default;

public:
	enum ErrorCode { Success, ClockDoesNotStart, ClockDoesNotStop };

public:
	ErrorCode start();
	ErrorCode stop();

public:
	long frequency() const;
	double convertToSecond() const;
	double convertToMillisecond() const;
	double convertToMicrosecond() const;

private:
	long mStartTick;
	long mStopTick;
	bool mIsStarted;
};

} // namespace Core
