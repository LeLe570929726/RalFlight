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

namespace Core {

String::String(const String &other) : mBuffer(other.mBuffer) {}

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

} // namespace Core