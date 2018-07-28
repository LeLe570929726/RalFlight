// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/7/13 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"
#include "CharReference.h"
#include "Convertor.h"
#include <string>

namespace Core {

class RF_API Char {
public:
	Char() = default;
	Char(char ch);
	Char(const std::string &ch, const std::string &charset = Charset::Utf8);
	Char(wchar_t ch);
	Char(int code);
	Char(const Char &other) = default;
	Char(Char &&other) = default;
	Char &operator=(const CharReference &chref);
	Char &operator=(char ch);
	Char &operator=(const std::string &ch);
	Char &operator=(wchar_t ch);
	Char &operator=(int code);
	Char &operator=(const Char &other) = default;
	Char &operator=(Char &&other) = default;
	~Char() = default;

public:
	bool operator==(const Char &other) const { return this->mChar == other.mChar; }
	bool operator!=(const Char &other) const { return this->mChar != other.mChar; }
	bool operator<(const Char &other) const { return this->mChar < other.mChar; }
	bool operator<=(const Char &other) const { return this->mChar <= other.mChar; }
	bool operator>(const Char &other) const { return this->mChar > other.mChar; }
	bool operator>=(const Char &other) const { return this->mChar >= other.mChar; }

public:
	char toChar() const { return static_cast<char>(this->mChar); }
	std::string toString(const std::string &charset = Charset::Utf8) const;
	wchar_t toWChar() const { return this->mChar; }

private:
	wchar_t mChar;
};

} // namespace Core