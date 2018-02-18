// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
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
#include "Char.h"
#include "StringEncode.h"
#include <string>
#include <malloc.h>
#include <utility>

// Core namespace
namespace Core {
	using StringBufferType = std::basic_string<Char>;
	using StringIterator = Iterator<StringBufferType::iterator>;
	using StringConstIterator = Iterator<StringBufferType::const_iterator>;

	class RALFLIGHT_API String {
	public:
		String() = default;
		String(const Char *text);
		String(const String &other, int begin, int lenght);
		String(Char text, int lenght);
		String(const String &other);
		String(String &&other);
		String &operator=(const String &other);
		String &operator=(String &&other);
		~String() = default;

	public:
		String operator+(Char text) const;
		String operator+(const Char *text) const;
		String operator+(const String &text) const;
		String &operator=(const Char *text);
		String &operator=(Char text);
		Char &operator[](int position);
		const Char &operator[](int position) const;
		String &operator+=(const String &other);
		String &operator+=(const Char *text);
		String &operator+=(Char text);
		bool operator==(const String &other) const;
		bool operator!=(const String &other) const;

	public:
		StringIterator begin();
		StringConstIterator cbegin() const;
		StringIterator end();
		StringConstIterator cend() const;

	public:
		Char &at(int position);
		const Char &at(int position) const;
		Char &back();
		const Char &back() const;
		Char &front();
		const Char &front() const;

	public:
		size_t lenght() const;
		size_t maxLenght() const;
		void resize(size_t size);
		void resize(size_t size, Char text);
		size_t capacity() const;
		void reserve(size_t size);
		void clear();
		bool isEmpty() const;

	public:
		String &append(const String &other);
		String &append(const String &other, int begin, int lenght);
		String &append(const Char *text);
		String &append(Char text, int lenght);
		String &append(StringIterator begin, StringIterator end);

	public:
		String &assign(const String &other);
		String &assign(const String &other, int begin, int lenght);
		String &assign(const Char *text);
		String &assign(Char text, int lenght);
		String &assign(StringIterator begin, StringIterator end);

	public:
		String &insert(const String &other, int position);
		String &insert(const String &other, int begin, int position, int lenght);
		String &insert(const Char *text, int position);
		String &insert(Char text, int position);
		String &insert(Char text, StringIterator position);
		String &insert(Char text, int position, int lenght);
		String &insert(Char text, StringIterator position, int lenght);
		String &insert(StringIterator position, StringIterator begin, StringIterator end);

	public:
		void pushBack(Char text);
		String &remove(int position, int lenght);
		StringIterator remove(StringIterator position);
		StringIterator remove(StringIterator begin, StringIterator end);

	public:
		String &replace(const String &other, int position, int lenght);
		String &replace(const String &other, StringIterator begin, StringIterator end);
		String &replace(const String &other, int position, int lenght, int subPosition, int subLenght);
		String &replace(const Char *text, int position, int lenght);
		String &replace(const Char *text, StringIterator begin, StringIterator end);
		String &replace(Char text, int position, int lenght, int subLenght);
		String &replace(Char text, StringIterator begin, StringIterator end, int subLenght);
		String &replace(StringIterator begin, StringIterator end, StringIterator subBegin, StringIterator subEnd);

	public:
		std::string toStdString() const;
		std::wstring toStdWString() const;
		std::u16string toStdU16String() const;
		std::u32string toStdU32String() const;
		std::string toUTF8() const;
		std::string toLatin1() const;
		std::u16string toUTF16() const;
		std::u32string toUCS4() const;

	public:
		static String fromStdString(const std::string &text);
		static String fromStdU16String(const std::u16string &text);
		static String fromStdU32String(const std::u32string &text);
		static String fromLatin1(const std::string &text);
		static String fromLatin1(const char *text);
		static String fromUTF8(const std::string &text);
		static String fromUTF8(const char *text);
		static String fromUTF16(const std::u16string &text);
		static String fromUTF16(const char16_t *text);
		static String fromUCS4(const std::u32string &text);
		static String fromUCS4(const char32_t *text);

	private:
		StringBufferType mTextBuffer;
	};

}

#endif          // RALFLIGHT_SRC_CORE_STD_STRING_H