// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/3/23 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

// System token
#define @RF_OS@

// Share library token
#if defined(RF_OS_WIN)
#define RF_API_EXPORT __declspec(dllexport)
#define RF_API_IMPORT __declspec(dllimport)
#endif

// Alignment token
#if defined(RF_OS_WIN)
#define RF_ALIGN16 __declspec(align(16))
#elif defined(RF_OS_LINUX)
#define RF_ALIGN16 __attribute__((aligned(16)))
#endif