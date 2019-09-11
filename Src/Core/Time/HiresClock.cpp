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

namespace Core {

void HiresClock::record() {
#ifdef RF_OS_WIN
	QueryPerformanceCounter(&this->mTick);
#endif
}

} // namespace Core
