// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/8/21 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_STL_STRINGENCODE_H
#define RALFLIGHT_SRC_CORE_STL_STRINGENCODE_H

#include "../Global/Macro.h"
#include <string>
#include <assert.h>
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	#include <Windows.h>
#elif defined(RALFLIGHT_SYSTEM_LINUX)
	#include <iconv.h>
#endif

// Core namespace
namespace Core {

	enum CodePage {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		// Code page in windows reference from [MSDN](https://msdn.microsoft.com/library/windows/desktop/dd317756.aspx)
		UTF16 = 1200,
		UTF8 = CP_UTF8,
		Latin1 = 28591,
		GB2312 = 20936,
		GBK = 936,
		GB18030 = 54936
#endif
	};

	class RALFLIGHT_API StringEncode {
	public:
		StringEncode() = delete;
		~StringEncode() = delete;
		StringEncode(const StringEncode &other) = delete;
		StringEncode &operator=(const StringEncode &other) = delete;

	public:
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		static unsigned int convertToUTF16(const std::string &source, std::wstring &contain, unsigned int codepage);
		static unsigned int convertFromUTF16(const std::wstring &source, std::string &contain, unsigned int codepage);
		static unsigned int convert(const std::string &source, std::string &contain, unsigned int sourceCP, unsigned int targetCP);
		static unsigned int getLocalCodePage();
#endif

	public:
		enum ErrorCode {
			Success = 0,
			InvalidCodePage = 1,
			InvalidString = 2
		};
	};

}

#endif		// RALFLIGHT_SRC_CORE_STL_STRINGENCODE_H