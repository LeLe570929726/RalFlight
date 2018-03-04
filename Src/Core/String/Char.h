// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2018/2/14 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_STRING_CHAR_H
#define RALFLIGHT_SRC_CORE_STRING_CHAR_H

#include "../Global/Macro.h"
#include "StringEncode.h"

// Core namespace
namespace Core {

	class RALFLIGHT_API Char {
	public:
		Char() = default;
		Char(char text);
		Char(wchar_t text);
		Char(char16_t text);
		Char(char32_t text);
		Char(const Char &other);
		Char(Char &&other);
		Char &operator=(char text);
		Char &operator=(wchar_t text);
		Char &operator=(char16_t text);
		Char &operator=(char32_t text);
		Char &operator=(const Char &other);
		Char &operator=(Char &&other);
		~Char() = default;

	public:
		bool operator==(const Char &other) const;
		bool operator!=(const Char &other) const;
		bool operator>(const Char &other) const;
		bool operator>=(const Char &other) const;
		bool operator<(const Char &other) const;
		bool operator<=(const Char &other) const;

	public:
		char toChar() const;
		wchar_t toWChar() const;
		char16_t toUTF16() const;
		char32_t toUCS4() const;

	private:
		char16_t mChar;
	};

}

#endif			// RALFLIGHT_SRC_CORE_STRING_CHAR_H