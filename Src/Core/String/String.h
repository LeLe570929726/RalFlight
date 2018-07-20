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
#include "../Math/Scalar.h"
#include "Char.h"
#include "Convertor.h"
#include <string>

namespace Core {

enum class CaseSensitive { Sensitive, Insensitive };

class RF_API String {
public:
  String() = default;
  String(const char *text, const std::string &charset = Charset::Utf8);
  String(const std::string &text, const std::string &charset = Charset::Utf8);
  String(const wchar_t *text);
  String(const std::wstring &text);
  String(const Char &ch, uint32 number);
  String(const String &other);
  String(String &&other);
  String &operator=(const String &other);
  String &operator=(String &&other);
  ~String() = default;

public:
  String &append(const String &other);
  String &append(const Char &ch, uint32 number = 1);
  bool contains(const String &other, CaseSensitive cs = CaseSensitive::Sensitive) const;
  bool contains(const Char &ch, CaseSensitive cs = CaseSensitive::Sensitive) const;
  bool contains(const Char &ch, uint32 number, CaseSensitive cs = CaseSensitive::Sensitive) const;

private:
  std::wstring mBuffer;
};

} // namespace Core