// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/3/11 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "String.h"

String::String(const char *text) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	int lenght = MultiByteToWideChar(CP_UTF8, NULL, text, -1, nullptr, 0);
	std::wstring tempBuffer(lenght, L' ');
	MultiByteToWideChar(CP_UTF8, NULL, text, -1, &tempBuffer.front(), lenght);
	this->mTextBuffer = tempBuffer;
#endif
}

String::String(const wchar_t *text) {
	this->mTextBuffer = text;
}

String::String(const String &other) {
	this->mTextBuffer = other.mTextBuffer;
}

String & String::operator=(const String &other) {
	this->mTextBuffer = other.mTextBuffer;
	return *this;
}