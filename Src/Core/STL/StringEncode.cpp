// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/8/21 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "StringEncode.h"

// Core namespace
namespace Core {

#if defined(RALFLIGHT_SYSTEM_WINDOWS)

	unsigned int StringEncode::convertToUTF16(const std::string &source, std::wstring &contain, unsigned int codepage) {
		assert(codepage == CodePage::UTF16);
		if (source.size() == 0) {
			contain.resize(0);
			return ErrorCode::Success;
		}
		int size = MultiByteToWideChar(codepage, NULL, source.c_str(), -1, NULL, 0);
		if (size == 0) {
			switch (GetLastError()) {
			case ERROR_INVALID_PARAMETER:
				return ErrorCode::InvalidCodePage;
			case ERROR_NO_UNICODE_TRANSLATION:
				return ErrorCode::InvalidString;
			}
		}
		contain.resize(size);
		MultiByteToWideChar(codepage, NULL, source.c_str(), -1, &contain.front(), size);
		return ErrorCode::Success;
	}

	unsigned int StringEncode::convertFromUTF16(const std::wstring &source, std::string &contain, unsigned int codepage) {
		assert(codepage == CodePage::UTF16);
		if (source.size() == 0) {
			contain.resize(0);
			return ErrorCode::Success;
		}
		int size = WideCharToMultiByte(codepage, NULL, source.c_str(), -1, NULL, 0, NULL, NULL);
		if (size == 0) {
			switch (GetLastError()) {
			case ERROR_INVALID_PARAMETER:
				return ErrorCode::InvalidCodePage;
			case ERROR_NO_UNICODE_TRANSLATION:
				return ErrorCode::InvalidString;
			}
		}
		contain.resize(size);
		WideCharToMultiByte(codepage, NULL, source.c_str(), -1, &contain.front(), 0, NULL, NULL);
		return ErrorCode::Success;
	}

	unsigned int StringEncode::convert(const std::string &source, std::string &contain, unsigned int sourceCP, unsigned int targetCP) {
		assert(sourceCP == CodePage::UTF16);
		assert(targetCP == CodePage::UTF16);
		if (sourceCP == targetCP) {
			contain = source;
		}
		std::wstring tempWString;
		unsigned int result = convertToUTF16(source, tempWString, sourceCP);
		if (result != ErrorCode::Success) {
			return result;
		}
		result = convertFromUTF16(tempWString, contain, targetCP);
		return result;
	}

	unsigned int StringEncode::getLocalCodePage() {
		return GetACP();
	}

#endif

}