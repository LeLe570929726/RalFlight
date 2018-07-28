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
#include <cwctype>
#include <utility>

namespace Core {

String::String(const char *text, const std::string &charset) : mBuffer(Convertor::toWstring(text, charset)) {}

String::String(const std::string &text, const std::string &charset) : mBuffer(Convertor::toWstring(text, charset)) {}

String::String(const wchar_t *text) : mBuffer(text) {}

String::String(const std::wstring &text) : mBuffer(text) {}

String::String(const Char &ch, uint64 number) : mBuffer(number, ch.toWChar()) {}

String::String(String &&other) noexcept : mBuffer(std::forward<std::wstring>(other.mBuffer)) {}

String &String::operator=(String &&other) noexcept {
	this->mBuffer = std::forward<std::wstring>(other.mBuffer);
	return *this;
}

CharReference String::operator[](uint64 position) {
	assert(position < this->mBuffer.length());
	return CharReference(&this->mBuffer[position]);
}

Char String::operator[](uint64 position) const {
	assert(position < this->mBuffer.length());
	return Char(this->mBuffer[position]);
}

StringIterator String::begin() { return StringIterator(this->mBuffer.begin()); }

StringIterator String::end() { return StringIterator(this->mBuffer.end()); }

CharReference String::at(uint64 position) {
	assert(position < this->mBuffer.length());
	return CharReference(&this->mBuffer.at(position));
}

Char String::at(uint64 position) const {
	assert(position < this->mBuffer.length());
	return Char(this->mBuffer.at(position));
}

String &String::append(const String &other) {
	this->mBuffer.append(other.mBuffer);
	return *this;
}

String &String::insert(uint64 position, const String &text) {
	this->mBuffer.insert(position, text.mBuffer);
	return *this;
}

String &String::remove(uint64 position, uint64 number) {
	assert((position + number) <= this->mBuffer.length());
	this->mBuffer.erase(position, number);
	return *this;
}

String &String::remove(const String &other, CaseFind cf, int64 index) {
	assert(index < this->mBuffer.length());
	switch (cf) {
	case CaseFind::Index:
		boost::algorithm::erase_nth(this->mBuffer, other.mBuffer, index);
		break;
	case CaseFind::First:
		boost::algorithm::erase_first(this->mBuffer, other.mBuffer);
		break;
	case CaseFind::Last:
		boost::algorithm::erase_last(this->mBuffer, other.mBuffer);
		break;
	default:
		boost::algorithm::erase_all(this->mBuffer, other.mBuffer);
		break;
	}
	return *this;
}

String &String::replace(const String &other, uint64 position, uint64 number) {
	assert((position + number) <= this->mBuffer.length());
	this->mBuffer.replace(position, number, other.mBuffer);
	return *this;
}

String &String::replace(const String &search, const String &text, CaseFind cf, uint64 index) {
	assert(index < this->mBuffer.length());
	switch (cf) {
	case CaseFind::Index:
		boost::algorithm::replace_nth(this->mBuffer, search.mBuffer, index, text.mBuffer);
		break;
	case CaseFind::First:
		boost::algorithm::replace_first(this->mBuffer, search.mBuffer, text.mBuffer);
		break;
	case CaseFind::Last:
		boost::algorithm::replace_last(this->mBuffer, search.mBuffer, text.mBuffer);
		break;
	default:
		boost::algorithm::replace_all(this->mBuffer, search.mBuffer, text.mBuffer);
		break;
	}
	return *this;
}

bool String::contains(const String &other, CaseSensitive cs) const {
	if (cs == CaseSensitive::Sensitive) {
		return this->mBuffer.find(other.mBuffer) != std::wstring::npos;
	} else {
		return boost::algorithm::contains(this->mBuffer, other.mBuffer, [](wchar_t a, wchar_t b) {
			return std::towlower(static_cast<wint_t>(a)) == std::towlower(static_cast<wint_t>(b));
		});
	}
}

} // namespace Core