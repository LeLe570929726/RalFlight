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

#elif defined(RALFLIGHT_SYSTEM_LINUX)

	unsigned int StringEncode::convertToUTF16(const std::string &source, std::u16string &contain, const std::string &codepage) {
		assert(codepage == CodePage::UTF16);
		if(source.size() == 0) {
			contain.resize(0);
			return ErrorCode::Success;
		}
		// Create iconv handle
		iconv_t handle = iconv_open(CodePage::UTF16, codepage.c_str());
		if(handle == reinterpret_cast<iconv_t>(-1)) {
			return ErrorCode::InvalidCodePage;
		}
		// Create buffer
		char *sourceBuf = static_cast<char *>(malloc(source.size()));
		char *containBuf=static_cast<char *>(malloc(source.size()));
		char *tempSrcPtr = sourceBuf;
		std::u16string tempString;
		size_t sourceSize = source.size();
		size_t restSize = source.size();
		memcpy(sourceBuf, source.c_str(), source.size());
		// Convert
		while(true) {
			char *tempCtnPtr = containBuf;
			restSize = source.size();
			if(iconv(handle, &tempSrcPtr, &sourceSize, &tempCtnPtr, &restSize) == -1) {
				switch(errno) {
				case E2BIG:
					tempString.append(reinterpret_cast<char16_t *>(containBuf), (source.size() - restSize) >> 1);
					break;
				case EILSEQ:
					free(sourceBuf);
					free(containBuf);
					return ErrorCode::InvalidCodePage;
				case EINVAL:
					free(sourceBuf);
					free(containBuf);
					return ErrorCode::InvalidString;
				}
			} else {
				tempString.append(reinterpret_cast<char16_t *>(containBuf), (source.size() - restSize) >> 1);
				break;
			}
		}
		free(sourceBuf);
		free(containBuf);
		contain = tempString;
		return ErrorCode::Success;
	}

	unsigned int StringEncode::convertFromUTF16(const std::wstring &source, std::string &contain, const std::string &codepage) {
		assert(codepage == CodePage::UTF16);
		if(source.size() == 0) {
			contain.resize(0);
			return ErrorCode::Success;
		}
		// Create iconv handle
		iconv_t handle = iconv_open(codepage.c_str(), CodePage::UTF16);
		if(handle == reinterpret_cast<iconv_t>(-1)) {
			return ErrorCode::InvalidCodePage;
		}
		// Create buffer
		char *sourceBuf = static_cast<char *>(malloc(source.size() << 1));
		char *containBuf = static_cast<char *>(malloc(source.size() << 1));
		char *tempSrcPtr = sourceBuf;
		std::string tempString;
		size_t sourceSize = source.size() << 1;
		size_t restSize = source.size() << 1;
		memcpy(sourceBuf, reinterpret_cast<const char *>(source.c_str()), source.size() << 1);
		// Convert
		while(true) {
			char *tempCtnPtr = containBuf;
			restSize = source.size() << 1;
			if(iconv(handle, &tempSrcPtr, &sourceSize, &tempCtnPtr, &restSize) == -1) {
				switch(errno) {
				case E2BIG:
					tempString.append(containBuf, (source.size() << 1) - restSize);
					break;
				case EILSEQ:
					free(sourceBuf);
					free(containBuf);
					return ErrorCode::InvalidCodePage;
				case EINVAL:
					free(sourceBuf);
					free(containBuf);
					return ErrorCode::InvalidString;
				}
			} else {
				tempString.append(containBuf, (source.size() << 1) - restSize);
				break;
			}
		}
		free(sourceBuf);
		free(containBuf);
		contain = tempString;
		return 0;
	}

	unsigned int StringEncode::convertToUCS4(const std::string &source, std::u32string &contain, const std::string &codepage) {
		assert(codepage == CodePage::UCS4);
		if(source.size() == 0) {
			contain.resize(0);
			return ErrorCode::Success;
		}
		// Create iconv handle
		iconv_t handle = iconv_open(CodePage::UCS4, codepage.c_str());
		if(handle == reinterpret_cast<iconv_t>(-1)) {
			return ErrorCode::InvalidCodePage;
		}
		// Create buffer
		char *sourceBuf = static_cast<char *>(malloc(source.size()));
		char *containBuf=static_cast<char *>(malloc(source.size()));
		char *tempSrcPtr = sourceBuf;
		std::u32string tempString;
		size_t sourceSize = source.size();
		size_t restSize = source.size();
		memcpy(sourceBuf, source.c_str(), source.size());
		// Convert
		while(true) {
			char *tempCtnPtr = containBuf;
			restSize = source.size();
			if(iconv(handle, &tempSrcPtr, &sourceSize, &tempCtnPtr, &restSize) == -1) {
				switch(errno) {
				case E2BIG:
					tempString.append(reinterpret_cast<char32_t *>(containBuf), (source.size() - restSize) >> 2);
					break;
				case EILSEQ:
					free(sourceBuf);
					free(containBuf);
					return ErrorCode::InvalidCodePage;
				case EINVAL:
					free(sourceBuf);
					free(containBuf);
					return ErrorCode::InvalidString;
				}
			} else {
				tempString.append(reinterpret_cast<char32_t *>(containBuf), (source.size() - restSize) >> 2);
				break;
			}
		}
		free(sourceBuf);
		free(containBuf);
		contain = tempString;
		return ErrorCode::Success;
	}

	unsigned int StringEncode::convertFromUCS4(const std::u32string &source, std::string &contain, const std::string &codepage) {
		assert(codepage) == CodePage::UCS4);
		if(source.size() == 0) {
			contain.resize(0);
			return ErrorCode::Success;
		}
		// Create iconv handle
		iconv_t handle = iconv_open(codepage.c_str(), CodePage::UCS4);
		if(handle == reinterpret_cast<iconv_t>(-1)) {
			return ErrorCode::InvalidCodePage;
		}
		// Create buffer
		char *sourceBuf = static_cast<char *>(malloc(source.size() << 2));
		char *containBuf = static_cast<char *>(malloc(source.size() << 2));
		char *tempSrcPtr = sourceBuf;
		std::string tempString;
		size_t sourceSize = source.size() << 2;
		size_t restSize = source.size() << 2;
		memcpy(sourceBuf, reinterpret_cast<const char *>(source.c_str()), source.size() << 2);
		// Convert
		while(true) {
			char *tempCtnPtr = containBuf;
			restSize = source.size() << 2;
			if(iconv(handle, &tempSrcPtr, &sourceSize, &tempCtnPtr, &restSize) == -1) {
				switch(errno) {
				case E2BIG:
					tempString.append(containBuf, (source.size() << 2) - restSize);
					break;
				case EILSEQ:
					free(sourceBuf);
					free(containBuf);
					return ErrorCode::InvalidCodePage;
				case EINVAL:
					free(sourceBuf);
					free(containBuf);
					return ErrorCode::InvalidString;
				}
			} else {
				tempString.append(containBuf, (source.size() << 2) - restSize);
				break;
			}
		}
		free(sourceBuf);
		free(containBuf);
		contain = tempString;
		return ErrorCode::Success;
	}

	unsigned int StringEncode::convertToWString(const std::string &source, std::wstring &contain, const std::string &codepage) {
		assert(codepage == CodePage::UCS4);
		if(source.size() == 0) {
			contain.resize(0);
			return ErrorCode::Success;
		}
		// Create iconv handle
		iconv_t handle = iconv_open(CodePage::UCS4, codepage.c_str());
		if(handle == reinterpret_cast<iconv_t>(-1)) {
			return ErrorCode::InvalidCodePage;
		}
		// Create buffer
		char *sourceBuf = static_cast<char *>(malloc(source.size()));
		char *containBuf=static_cast<char *>(malloc(source.size()));
		char *tempSrcPtr = sourceBuf;
		std::wstring tempString;
		size_t sourceSize = source.size();
		size_t restSize = source.size();
		memcpy(sourceBuf, source.c_str(), source.size());
		// Convert
		while(true) {
			char *tempCtnPtr = containBuf;
			restSize = source.size();
			if(iconv(handle, &tempSrcPtr, &sourceSize, &tempCtnPtr, &restSize) == -1) {
				switch(errno) {
				case E2BIG:
					tempString.append(reinterpret_cast<wchar_t *>(containBuf), (source.size() - restSize) >> 2);
					break;
				case EILSEQ:
					free(sourceBuf);
					free(containBuf);
					return ErrorCode::InvalidCodePage;
				case EINVAL:
					free(sourceBuf);
					free(containBuf);
					return ErrorCode::InvalidString;
				}
			} else {
				tempString.append(reinterpret_cast<wchar_t *>(containBuf), (source.size() - restSize) >> 2);
				break;
			}
		}
		free(sourceBuf);
		free(containBuf);
		contain = tempString;
		return ErrorCode::Success;
	}

	unsigned int StringEncode::convertFromWString(const std::wstring &source, std::string &contain, const std::string &codepage) {
		assert(codepage) == CodePage::UCS4);
		if(source.size() == 0) {
			contain.resize(0);
			return ErrorCode::Success;
		}
		// Create iconv handle
		iconv_t handle = iconv_open(codepage.c_str(), CodePage::UCS4);
		if(handle == reinterpret_cast<iconv_t>(-1)) {
			return ErrorCode::InvalidCodePage;
		}
		// Create buffer
		char *sourceBuf = static_cast<char *>(malloc(source.size() << 2));
		char *containBuf = static_cast<char *>(malloc(source.size() << 2));
		char *tempSrcPtr = sourceBuf;
		std::string tempString;
		size_t sourceSize = source.size() << 2;
		size_t restSize = source.size() << 2;
		memcpy(sourceBuf, reinterpret_cast<const char *>(source.c_str()), source.size() << 2);
		// Convert
		while(true) {
			char *tempCtnPtr = containBuf;
			restSize = source.size() << 2;
			if(iconv(handle, &tempSrcPtr, &sourceSize, &tempCtnPtr, &restSize) == -1) {
				switch(errno) {
				case E2BIG:
					tempString.append(containBuf, (source.size() << 2) - restSize);
					break;
				case EILSEQ:
					free(sourceBuf);
					free(containBuf);
					return ErrorCode::InvalidCodePage;
				case EINVAL:
					free(sourceBuf);
					free(containBuf);
					return ErrorCode::InvalidString;
				}
			} else {
				tempString.append(containBuf, (source.size() << 2) - restSize);
				break;
			}
		}
		free(sourceBuf);
		free(containBuf);
		contain = tempString;
		return ErrorCode::Success;
	}

	unsigned int StringEncode::convert(const std::string &source, std::string &contain, const std::string &sourceCP, const std::string &targetCP) {
		assert(sourceCP == CodePage::UTF16);
		assert(targetCP == CodePage::UTF16);
		if(sourceCP == targetCP) {
			contain = source;
			return ErrorCode::Success;
		}
		// Create iconv handle
		iconv_t handle = iconv_open(sourceCP, targetCP);
		if(handle == reinterpret_cast<iconv_t>(-1)) {
			return ErrorCode::InvalidCodePage;
		}
		// Create buffer
		char *sourceBuf = static_cast<char *>(malloc(source.size() * sizeof(char)));
		char *containBuf = static_cast<char *>(malloc(source.size() * sizeof(char)));
		char *tempSource = sourceBuf;
		char *tempContain = containBuf;
		std::string tempString;
		size_t sourceSize = source.size();
		size_t lastSize = source.size();
		// Copy source string to the buffer
		strcpy(sourceBuf, source.c_str());
		// Convert
		while(true) {
			if(iconv(handle, &tempSource, &sourceSize, &tempContain, &lastSize) == -1 && errno != E2BIG) {
				if(errno == E2BIG) {
					tempString.append(containBuf, source.size() - lastSize);
				} else {
					free(sourceBuf);
					free(containBuf);
					return ErrorCode::InvalidString;
				}
			} else {
				tempString.append(containBuf, source.size() - lastSize);
				break;
			}
		}
		free(sourceBuf);
		free(containBuf);
		contain = tempString;
		return ErrorCode::Success;
	}

	std::string StringEncode::getLocalCP() {
		// Get the LANG environment var.
		std::string envLang = getenv("LANG");
		// Check the LANG environment var. If it is empty, return UTF-8.
		if(envLang.empty()) {
			return CodePage::UTF8;
		}
		// Split the string.
		int position = envLang.find_first_of(".");
		// Check the position.
		if(position == std::string::npos || position == envLang.size() - 1) {
			return CodePage::UTF8;
		}
		envLang = envLang.substr(position + 1);
		// Check the final code page.
		iconv_t checker = iconv_open(envLang.c_str(), envLang.c_str());
		if(checker == reinterpret_cast<iconv_t>(-1)) {
			return CodePage::UTF8;
		} else {
			iconv_close(checker);
			return envLang;
		}
	}

#endif

}