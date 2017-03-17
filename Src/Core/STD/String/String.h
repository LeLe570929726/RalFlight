// ----------------------------------------------------------------------------------------------------
// Copyright Â© 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/1/18 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_STD_STRING_H
#define RALFLIGHT_SRC_CORE_STD_STRING_H

// TODO: Function: insert
// TODO: Class iterator

#include "../../Global/Macro/Macro.h"
#include <string>
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
#include<Windows.h> 
#endif

enum TextCodeFormat {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	UTF16 = 1200,				// This value is according to MSDN: https://msdn.microsoft.com/library/windows/desktop/dd317756(v=vs.85).aspx
	UTF8 = CP_UTF8
#endif
};

class RALFLIGHT_API String {
public:
	String() = default;
	String(const char *text);
	String(const wchar_t *text);
	String(const String &other, int begin, int lenght);
	String(char text, int lenght);
	String(wchar_t text, int lenght);
	String(const String &other);
	String &operator=(const String &other);
	~String() = default;

public:
	String &operator=(const char *text);
	String &operator=(const wchar_t *text);
	String &operator=(char text);
	String &operator=(wchar_t text);
	wchar_t &operator[](int position);
	const wchar_t &operator[](int position) const;
	String &operator+=(const String &other);
	String &operator+=(const char *text);
	String &operator+=(const wchar_t *text);
	String &operator+=(char text);
	String &operator+=(wchar_t text);

public:
	wchar_t &at(int position);
	const wchar_t &at(int position) const;
	wchar_t &back();
	const wchar_t &back() const;
	wchar_t &front();
	const wchar_t &front() const;

public:
	int lenght() const;
	int maxLenght() const;
	void resize(int size);
	void resize(int size, char text);
	void resize(int size, wchar_t text);
	int capacity() const;
	void reserve(int size);
	void clear();
	bool empty() const;

public:
	String &append(const String &other);
	String &append(const String &other, int begin, int lenght);
	String &append(const char *text);
	String &append(const wchar_t *text);
	String &append(char text, int lenght);
	String &append(wchar_t text, int lenght);

public:
	String &assign(const String &other);
	String &assign(const String &other, int begin, int lenght);
	String &assign(const char *text);
	String &assign(const wchar_t *text);
	String &assign(char text, int lenght);
	String &assign(wchar_t text, int lenght);

public:
	String &insert(const String &other, int position);
	String &insert(const String &other, int begin, int lenght, int position);
	String &insert(const char *text, int position);
	String &insert(const wchar_t *text, int position);
	String &insert(char text, int position);
	String &insert(wchar_t text, int position);
	String &insert(char text, int lenght, int position);
	String &insert(wchar_t text, int lenght, int position);

public:
	void pushBack(char text);
	void pushBack(wchar_t text);

private:
	std::wstring mTextBuffer;
};

#endif          // RALFLIGHT_SRC_CORE_STD_STRING_H