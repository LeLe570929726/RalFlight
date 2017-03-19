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

// TODO: Finish all function about iterator
// TODO: change some place use new to the malloc

#include "../../Global/Macro/Macro.h"
#include "../Iterator/Iteartor.h"
#include <string>
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	#include<Windows.h> 
#endif

using StringIterator = Iterator<std::wstring::iterator>;

enum RALFLIGHT_API TextCodeFormat {
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
	StringIterator begin();
	StringIterator end();

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
	String &append(StringIterator begin, StringIterator end);

public:
	String &assign(const String &other);
	String &assign(const String &other, int begin, int lenght);
	String &assign(const char *text);
	String &assign(const wchar_t *text);
	String &assign(char text, int lenght);
	String &assign(wchar_t text, int lenght);

public:
	String &insert(const String &other, int position);
	String &insert(const String &other, int begin, int position, int lenght);
	String &insert(const char *text, int position);
	String &insert(const wchar_t *text, int position);
	String &insert(char text, int position);
	String &insert(wchar_t text, int position);
	String &insert(char text, int position, int lenght);
	String &insert(wchar_t text, int position, int lenght);

public:
	void pushBack(char text);
	void pushBack(wchar_t text);
	String &erase(int position, int lenght);

public:
	String &replace(const String &other, int position, int lenght);
	String &replace(const String &other, int position, int lenght, int subPosition, int subLenght);
	String &replace(const char *text, int position, int lenght);
	String &replace(const wchar_t *text, int position, int lenght);
	String &replace(char text, int position, int lenght, int subLenght);
	String &replace(wchar_t text, int position, int lenght, int subLenght);

private:
	std::wstring mTextBuffer;
};

#endif          // RALFLIGHT_SRC_CORE_STD_STRING_H