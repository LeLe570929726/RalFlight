// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/6/30 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "String.h"
#include <boost/algorithm/string.hpp>
#include <utility>

namespace Core {

String::String(const char *text, const std::string &charset)
    : mBuffer(Convertor::toWstring(text, charset)) {}

String::String(const std::string &text, const std::string &charset)
    : mBuffer(Convertor::toWstring(text, charset)) {}

String::String(const wchar_t *text) : mBuffer(text) {}

String::String(const std::wstring &text) : mBuffer(text) {}

String::String(const String &other) : mBuffer(other.mBuffer) {}

String::String(const Char &ch, uint32 number) : mBuffer(number, ch.toWChar()) {}

String::String(String &&other)
    : mBuffer(std::forward<std::wstring>(other.mBuffer)) {}

String &String::operator=(const String &other) {
  this->mBuffer = other.mBuffer;
  return *this;
}

String &String::operator=(String &&other) {
  this->mBuffer = std::forward<std::wstring>(other.mBuffer);
  return *this;
}

String &String::append(const String &other) {
  this->mBuffer.append(other.mBuffer);
  return *this;
}

String &String::append(const Char &ch, uint32 number) {
  this->mBuffer.append(number, ch.toWChar());
  return *this;
}

bool String::contains(const String &other, CaseSensitive cs) const {
  if (cs == CaseSensitive::Sensitive) {
    if (this->mBuffer.find(other.mBuffer) == std::wstring::npos) {
      return false;
    } else {
      return true;
    }
  } else {
    return boost::algorithm::icontains(this->mBuffer, other.mBuffer);
  }
}

bool String::contains(const Char &ch, CaseSensitive cs) const {
  return this->contains(ch, cs);
}

bool String::contains(const Char &ch, uint32 number, CaseSensitive cs) const {
  return this->contains(String(ch, number), cs);
}

} // namespace Core