// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/1/18 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_STD_STRING_H
#define RALFLIGHT_SRC_CORE_STD_STRING_H

#include "../../Global/Macro/Macro.h"
#include <string>
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	#include<Windows.h> 
#endif

class RALFLIGHT_API String {
public:
	String() = default;
	String(const char *text);
	String(const wchar_t *text);
	String(const String &other);
	String &operator=(const String &other);
	~String() = default;

private:
	std::wstring mTextBuffer;
};

#endif          // RALFLIGHT_SRC_CORE_STD_STRING_H