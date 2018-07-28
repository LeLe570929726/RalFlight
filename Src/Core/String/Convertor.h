// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/6/30 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"
#include <string>

namespace Core {

struct RF_API Charset {
	static const std::string Latin1;
	static const std::string Utf8;
	static const std::string Gb2312;
};

class RF_API Convertor {
public:
	Convertor() = delete;
	Convertor(const Convertor &other) = delete;
	Convertor(Convertor &&other) = delete;
	Convertor &operator=(const Convertor &other) = delete;
	Convertor &operator=(Convertor &&other) = delete;
	~Convertor() = delete;

public:
	static std::string convert(const std::string &text, const std::string &from, const std::string &to);
	static std::wstring toWstring(const std::string &text, const std::string &from);
	static std::string fromWstring(const std::wstring &text, const std::string &to);
	static bool isCharsetExist(const std::string &charset);
};

} // namespace Core