// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/07/27 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"
#include "Convertor.h"
#include <string>

namespace Core {

class Char;

class RF_API CharReference {
public:
	CharReference(wchar_t *ptr);
	CharReference(const CharReference &other) = default;
	CharReference(CharReference &&other) = default;
	CharReference &operator=(const CharReference &other) = default;
	CharReference &operator=(CharReference &&other) = default;
	CharReference &operator=(const Char &ch);
	~CharReference() = default;

public:
	char toChar() const { return static_cast<char>(*(this->mPtr)); }
	std::string toString(const std::string &charset = Charset::Utf8) const;
	wchar_t toWChar() const { return *this->mPtr; }

private:
	wchar_t *mPtr;
};

} // namespace Core
