// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/6/29 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "Global.h"

// Build token
#undef RF_API
#if defined(RF_CORE_BUILD)
#define RF_API RF_API_EXPORT
#else
#define RF_API RF_API_IMPORT
#endif

// Template class token
#undef RF_API_TEMPLATE
#define RF_API_TEMPLATE