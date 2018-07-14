// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/7/13 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Char.h"

namespace Core {

Char::Char(char ch)
    : mChar(Convertor::toWstring(std::string(1, ch), Charset::Latin1)[0]) {}

Char::Char(const std::string &ch, const std::string &charset)
    : mChar(Convertor::toWstring(ch, charset)[0]) {}

Char::Char(wchar_t ch) : mChar(ch) {}

Char::Char(int code) : mChar(static_cast<wchar_t>(code)) {}

Char &Char::operator=(char ch) {
  this->mChar = Convertor::toWstring(std::string(1, ch), Charset::Latin1)[0];
  return *this;
}

Char &Char::operator=(const std::string &ch) {
  this->mChar = Convertor::toWstring(ch, Charset::Utf8)[0];
  return *this;
}

Char &Char::operator=(wchar_t ch) {
  this->mChar = ch;
  return *this;
}

Char &Char::operator=(int code) {
  this->mChar = static_cast<wchar_t>(code);
  return *this;
}

std::string Char::toString(const std::string &charset) const {
  return Convertor::fromWstring(std::wstring(1, this->mChar), charset);
}

} // namespace Core