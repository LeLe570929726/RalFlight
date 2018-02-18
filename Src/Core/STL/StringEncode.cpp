#include "StringEncode.h"
#include "StringEncode.h"
// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
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

	namespace CodePage {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		// Code page in windows reference from [MSDN](https://msdn.microsoft.com/library/windows/desktop/dd317756.aspx)
		const int UCS4 = 12000;
		const int UTF16 = 1200;
		const int UTF8 = CP_UTF8;
		const int Latin1 = 28591;
		const int GB2312 = 936;
		const int GBK = 936;
		const int GB18030 = 54936;
#elif defined(RALFLIGHT_SYSTEM_LINUX)
		const char *UCS4 = "UCS4";
		const char *UTF16 = "UTF-16";
		const char *UTF8 = "UTF-8";
		const char *Latin1 = "LATIN1";
		const char *GBK = "CP936";
#endif
	}

#if defined(RALFLIGHT_SYSTEM_WINDOWS)

	unsigned int StringEncode::convertToUTF16(const std::string &source, std::u16string &contain, unsigned int codepage) {
		assert(codepage != CodePage::UCS4);
		assert(codepage != CodePage::UTF16);
		if(source.size() == 0) {
			contain.resize(0);
			return ErrorCode::Success;
		}
		int size = MultiByteToWideChar(codepage, NULL, source.c_str(), static_cast<int>(source.size()), NULL, 0);
		if(size == 0) {
			switch(GetLastError()) {
			case ERROR_INVALID_PARAMETER:
				return ErrorCode::InvalidCodePage;
			case ERROR_NO_UNICODE_TRANSLATION:
				return ErrorCode::InvalidString;
			}
		}
		std::u16string tempString(size, NULL);
		MultiByteToWideChar(codepage, NULL, source.c_str(), static_cast<int>(source.size()), reinterpret_cast<LPWSTR>(&tempString.front()), size);
		contain = tempString;
		return ErrorCode::Success;
	}

	unsigned int StringEncode::convertFromUTF16(const std::u16string &source, std::string &contain, unsigned int codepage) {
		assert(codepage != CodePage::UCS4);
		assert(codepage != CodePage::UTF16);
		if(source.size() == 0) {
			contain.resize(0);
			return ErrorCode::Success;
		}
		int size = WideCharToMultiByte(codepage, NULL, reinterpret_cast<LPCWCH>(source.c_str()), static_cast<int>(source.size()), NULL, 0, NULL, NULL);
		if(size == 0) {
			switch(GetLastError()) {
			case ERROR_INVALID_PARAMETER:
				return ErrorCode::InvalidCodePage;
			case ERROR_NO_UNICODE_TRANSLATION:
				return ErrorCode::InvalidString;
			}
		}
		std::string tempString(size, NULL);
		WideCharToMultiByte(codepage, NULL, reinterpret_cast<LPCWCH>(source.c_str()), static_cast<int>(source.size()), &tempString.front(), size, NULL, NULL);
		contain = tempString;
		return ErrorCode::Success;
	}

	unsigned int StringEncode::convertToUCS4(const std::string &source, std::u32string &contain, unsigned int codepage) {
		assert(codepage != CodePage::UCS4);
		assert(codepage != CodePage::UTF16);
		if(source.size() == 0) {
			contain.resize(0);
			return ErrorCode::Success;
		}
		int utf16Size = MultiByteToWideChar(codepage, NULL, source.c_str(), static_cast<int>(source.size()), NULL, 0);
		if(utf16Size == 0) {
			switch(GetLastError()) {
			case ERROR_INVALID_PARAMETER:
				return ErrorCode::InvalidCodePage;
			case ERROR_NO_UNICODE_TRANSLATION:
				return ErrorCode::InvalidString;
			}
		}
		wchar_t *utf16Buffer = static_cast<wchar_t *>(malloc(utf16Size << 1));
		MultiByteToWideChar(codepage, NULL, source.c_str(), static_cast<int>(source.size()), utf16Buffer, utf16Size);
		// Accoding to [MSDN](https://msdn.microsoft.com/library/windows/desktop/dd317756.aspx)
		// UTF-32 available only to managed applications.
		// So we should implement the function of UTF-16 to UTF-32.
		// Accoding to [Wiki](https://en.wikipedia.org/wiki/UTF-16)
		std::u32string tempString;
		tempString.reserve(utf16Size << 2);
		wchar_t proBuffer = 0;
		wchar_t *tempPtr = utf16Buffer;
		for(int i = 0; i < utf16Size; ++i) {
			if(*tempPtr < 0xD800 || *tempPtr > 0xDFFF) {
				tempString.push_back(static_cast<char32_t>(*tempPtr));
			} else {
				if(proBuffer != 0) {
					int high = proBuffer - 0xD800;
					int low = *tempPtr - 0xDC00;
					tempString.push_back((high << 10) + low + 0x10000);
					proBuffer = 0;
				} else {
					proBuffer = *tempPtr;
				}
			}
			++tempPtr;
		}
		contain = tempString;
		free(utf16Buffer);
		return ErrorCode::Success;
	}

	unsigned int StringEncode::convertFromUCS4(const std::u32string &source, std::string &contain, unsigned int codepage) {
		assert(codepage != CodePage::UCS4);
		assert(codepage != CodePage::UTF16);
		if(source.size() == 0) {
			contain.resize(0);
			return ErrorCode::Success;
		}
		// Accoding to [MSDN](https://msdn.microsoft.com/library/windows/desktop/dd317756.aspx)
		// UTF-32 available only to managed applications.
		// So we should implement the function of UTF-32 to UTF-16.
		// Accoding to [Wiki](https://en.wikipedia.org/wiki/UTF-16)
		wchar_t *utf16Buffer = static_cast<wchar_t *>(malloc(source.size() << 1));
		wchar_t *tempPtr = utf16Buffer;
		int utf16Size = 0;
		for(auto nowChar : source) {
			if(nowChar < 0x10000) {
				*tempPtr = static_cast<wchar_t>(nowChar);
				++tempPtr;
				++utf16Size;
			} else {
				*tempPtr = static_cast<wchar_t>(((nowChar - 0x10000) >> 10) + 0xD800);
				++tempPtr;
				*tempPtr = static_cast<wchar_t>((((nowChar - 0x10000) << 22) >> 22) + 0xDC00);
				++tempPtr;
				utf16Size += 2;
			}
		}
		int containSize = WideCharToMultiByte(codepage, NULL, utf16Buffer, utf16Size, NULL, 0, NULL, NULL);
		if(utf16Size == 0) {
			switch(GetLastError()) {
			case ERROR_INVALID_PARAMETER:
				return ErrorCode::InvalidCodePage;
			case ERROR_NO_UNICODE_TRANSLATION:
				return ErrorCode::InvalidString;
			}
		}
		std::string tempString(containSize, NULL);
		WideCharToMultiByte(codepage, NULL, utf16Buffer, utf16Size, &tempString.front(), containSize, NULL, NULL);
		contain = tempString;
		free(utf16Buffer);
		return ErrorCode::Success;
	}

	unsigned int StringEncode::convertToWString(const std::string &source, std::wstring &contain, unsigned int codepage) {
		assert(codepage != CodePage::UCS4);
		assert(codepage != CodePage::UTF16);
		if(source.size() == 0) {
			contain.resize(0);
			return ErrorCode::Success;
		}
		int size = MultiByteToWideChar(codepage, NULL, source.c_str(), static_cast<int>(source.size()), NULL, 0);
		if(size == 0) {
			switch(GetLastError()) {
			case ERROR_INVALID_PARAMETER:
				return ErrorCode::InvalidCodePage;
			case ERROR_NO_UNICODE_TRANSLATION:
				return ErrorCode::InvalidString;
			}
		}
		std::wstring tempString(size, NULL);
		MultiByteToWideChar(codepage, NULL, source.c_str(), static_cast<int>(source.size()), &tempString.front(), size);
		contain = tempString;
		return ErrorCode::Success;
	}

	unsigned int StringEncode::convertFromWString(const std::wstring & source, std::string & contain, unsigned int codepage) {
		assert(codepage != CodePage::UCS4);
		assert(codepage != CodePage::UTF16);
		if(source.size() == 0) {
			contain.resize(0);
			return ErrorCode::Success;
		}
		int size = WideCharToMultiByte(codepage, NULL, source.c_str(), static_cast<int>(source.size()), NULL, 0, NULL, NULL);
		if(size == 0) {
			switch(GetLastError()) {
			case ERROR_INVALID_PARAMETER:
				return ErrorCode::InvalidCodePage;
			case ERROR_NO_UNICODE_TRANSLATION:
				return ErrorCode::InvalidString;
			}
		}
		std::string tempString(size, NULL);
		WideCharToMultiByte(codepage, NULL, source.c_str(), static_cast<int>(source.size()), &tempString.front(), size, NULL, NULL);
		contain = tempString;
		return ErrorCode::Success;
	}
	
	unsigned int StringEncode::convert(const std::string &source, std::string &contain, unsigned int sourceCP, unsigned int targetCP) {
		assert(sourceCP != CodePage::UCS4);
		assert(sourceCP != CodePage::UTF16);
		assert(targetCP != CodePage::UCS4);
		assert(targetCP != CodePage::UTF16);
		if(sourceCP == targetCP) {
			contain = source;
			return ErrorCode::Success;
		}
		if(source.size() == 0) {
			contain.resize(0);
			return ErrorCode::Success;
		}
		int utf16Size = MultiByteToWideChar(sourceCP, NULL, source.c_str(), static_cast<int>(source.size()), NULL, 0);
		if(utf16Size == 0) {
			switch(GetLastError()) {
			case ERROR_INVALID_PARAMETER:
				return ErrorCode::InvalidCodePage;
			case ERROR_NO_UNICODE_TRANSLATION:
				return ErrorCode::InvalidString;
			}
		}
		wchar_t *utf16Buffer = static_cast<wchar_t *>(malloc(utf16Size << 1));
		MultiByteToWideChar(sourceCP, NULL, source.c_str(), static_cast<int>(source.size()), utf16Buffer, utf16Size);
		int containSize = WideCharToMultiByte(targetCP, NULL, utf16Buffer, utf16Size, NULL, 0, NULL, NULL);
		if(containSize == 0) {
			switch(GetLastError()) {
			case ERROR_INVALID_PARAMETER:
				return ErrorCode::InvalidCodePage;
			case ERROR_NO_UNICODE_TRANSLATION:
				return ErrorCode::InvalidString;
			}
		}
		std::string tempString(containSize, NULL);
		WideCharToMultiByte(targetCP, NULL, utf16Buffer, utf16Size, &tempString.front(), containSize, NULL, NULL);
		contain = tempString;
		return ErrorCode::Success;
	}

	unsigned int StringEncode::getLocalCP() {
		return GetACP();
	}

#elif defined(RALFLIGHT_SYSTEM_LINUX)

	unsigned int StringEncode::convertToUTF16(const std::string &source, std::u16string &contain, const std::string &codepage) {
		assert(codepage != CodePage::UCS4);
		assert(codepage != CodePage::UTF16);
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

	unsigned int StringEncode::convertFromUTF16(const std::u16string &source, std::string &contain, const std::string &codepage) {
		assert(codepage != CodePage::UCS4);
		assert(codepage != CodePage::UTF16);
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
		assert(codepage != CodePage::UCS4);
		assert(codepage != CodePage::UTF16);
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
		assert(codepage != CodePage::UCS4);
		assert(codepage != CodePage::UTF16);
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
		assert(codepage != CodePage::UCS4);
		assert(codepage != CodePage::UTF16);
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
		assert(codepage != CodePage::UCS4);
		assert(codepage != CodePage::UTF16);
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
		assert(sourceCP != CodePage::UCS4);
		assert(sourceCP != CodePage::UTF16);
		assert(targetCP != CodePage::UCS4);
		assert(targetCP != CodePage::UTF16);
		if(sourceCP == targetCP) {
			contain = source;
			return ErrorCode::Success;
		}
		// Create iconv handle
		iconv_t handle = iconv_open(sourceCP.c_str(), targetCP.c_str());
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