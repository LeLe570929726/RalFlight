// ----------------------------------------------------------------------------------------------------
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
#ifdef RF_OS_WIN
#include <Windows.h>
#endif

namespace Core {

class RF_API HiresClock {
public:
	HiresClock() = default;
	HiresClock(const HiresClock &other) = default;
	HiresClock(HiresClock &&other) noexcept = default;
	HiresClock &operator=(const HiresClock &other) = default;
	HiresClock &operator=(HiresClock &&other) noexcept = default;
	~HiresClock() = default;

public:
	void record();

public:
	long frequency() const;

private:
#ifdef RF_OS_WIN
	LARGE_INTEGER mTick;
#endif
};

} // namespace Core
