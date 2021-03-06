// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/6/30 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Convertor.h"
#include <boost/locale.hpp>
#include <cassert>

namespace Core {

const std::string Charset::Latin1("iso-8859-1");
const std::string Charset::Utf8("utf8");
const std::string Charset::Gb2312("gb2312");

std::string Convertor::convert(const std::string &text, const std::string &from, const std::string &to) {
	assert(Convertor::isCharsetExist(from));
	assert(Convertor::isCharsetExist(to));
	return boost::locale::conv::between(text, to, from);
}

void Convertor::convert(const std::string &text, const std::string &from, const std::string &to, std::string &out) {
	assert(Convertor::isCharsetExist(from));
	assert(Convertor::isCharsetExist(to));
	out = boost::locale::conv::between(text, to, from);
}

std::wstring Convertor::toWString(const std::string &text, const std::string &from) {
	assert(Convertor::isCharsetExist(from));
	return boost::locale::conv::to_utf<wchar_t>(text, from);
}

void Convertor::toWString(const std::string &text, const std::string &from, std::wstring &out) {
	assert(Convertor::isCharsetExist(from));
	out = boost::locale::conv::to_utf<wchar_t>(text, from);
}

std::string Convertor::fromWString(const std::wstring &text, const std::string &to) {
	assert(Convertor::isCharsetExist(to));
	return boost::locale::conv::from_utf(text, to);
}

void Convertor::fromWString(const std::wstring &text, const std::string &to, std::string &out) {
	assert(Convertor::isCharsetExist(to));
	out = boost::locale::conv::from_utf(text, to);
}

bool Convertor::isCharsetExist(const std::string &charset) {
	try {
		boost::locale::conv::between("", charset, "utf8");
	} catch (boost::locale::conv::invalid_charset_error) {
		return false;
	}
	return true;
}

} // namespace Core