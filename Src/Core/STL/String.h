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

#include "../Global/Macro.h"
#include "Iteartor.h"
#include <string>
#include <malloc.h>
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	#include<Windows.h> 
#endif

// Core namespace
namespace Core {

	using StringIterator = Iterator<std::wstring::iterator>;
	using StringConstIterator = Iterator<std::wstring::const_iterator>;

	enum RALFLIGHT_API TextCodeFormat {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		UTF16 = 1200,
		UTF8 = CP_UTF8,
		Latin1 = 28591,
		ANSI = CP_ACP
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
		String operator+(char text) const;
		String operator+(wchar_t text) const;
		String operator+(const char *text) const;
		String operator+(const wchar_t *text) const;
		String operator+(const String & text) const;
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
		bool operator==(const String &other) const;
		bool operator!=(const String &other) const;

	public:
		StringIterator begin();
		StringConstIterator begin() const;
		StringIterator end();
		StringConstIterator end() const;

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
		bool isEmpty() const;

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
		String &assign(StringIterator begin, StringIterator end);

	public:
		String &insert(const String &other, int position);
		String &insert(const String &other, int begin, int position, int lenght);
		String &insert(const char *text, int position);
		String &insert(const wchar_t *text, int position);
		String &insert(char text, int position);
		String &insert(char text, StringIterator position);
		String &insert(wchar_t text, int position);
		String &insert(wchar_t text, StringIterator position);
		String &insert(char text, int position, int lenght);
		String &insert(char text, StringIterator position, int lenght);
		String &insert(wchar_t text, int position, int lenght);
		String &insert(wchar_t text, StringIterator position, int lenght);
		String &insert(StringIterator position, StringIterator begin, StringIterator end);

	public:
		void pushBack(char text);
		void pushBack(wchar_t text);
		String &remove(int position, int lenght);
		StringIterator remove(StringIterator position);
		StringIterator remove(StringIterator begin, StringIterator end);

	public:
		String &replace(const String &other, int position, int lenght);
		String &replace(const String &other, StringIterator begin, StringIterator end);
		String &replace(const String &other, int position, int lenght, int subPosition, int subLenght);
		String &replace(const char *text, int position, int lenght);
		String &replace(const char *text, StringIterator begin, StringIterator end);
		String &replace(const wchar_t *text, int position, int lenght);
		String &replace(const wchar_t *text, StringIterator begin, StringIterator end);
		String &replace(char text, int position, int lenght, int subLenght);
		String &replace(char text, StringIterator begin, StringIterator end, int subLenght);
		String &replace(wchar_t text, int position, int lenght, int subLenght);
		String &replace(wchar_t text, StringIterator begin, StringIterator end, int subLenght);
		String &replace(StringIterator begin, StringIterator end, StringIterator subBegin, StringIterator subEnd);

	public:
		std::string toStdString() const;
		std::wstring toStdWString() const;
		std::string toUtf8() const;
		std::string toLatin1() const;
		std::wstring toUtf16() const;

	public:
		static String fromStdString(const std::string &text);
		static String fromStdWString(const std::wstring &text);
		static String fromLatin1(const std::string &text);
		static String fromLatin1(const char *text);
		static String fromUtf8(const std::string &text);
		static String fromUtf8(const char *text);
		static String fromUtf16(const std::wstring &text);
		static String fromUtf16(const wchar_t *text);

	private:
		std::wstring mTextBuffer;
	};

}

#endif          // RALFLIGHT_SRC_CORE_STD_STRING_H