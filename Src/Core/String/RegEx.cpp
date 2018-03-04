// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2018/3/4 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "RegEx.h"

// Core namespace
namespace Core {

	RegEx::RegEx(const String &text) :
		mRegEx(text.constData()) {
	}

	RegEx::RegEx(StringIterator begin, StringIterator end) :
		mRegEx(begin.get(), end.get()) {
	}

	RegEx::RegEx(const RegEx &other) :
		mRegEx(other.mRegEx) {
	}

	RegEx::RegEx(RegEx &&other) :
		mRegEx(std::forward<std::basic_regex<Char>>(other.mRegEx)) {
	}

	RegEx &RegEx::operator=(const String &text) {
		this->mRegEx = text.constData();
		return *this;
	}

	RegEx &RegEx::operator=(const RegEx &other) {
		this->mRegEx = other.mRegEx;
		return *this;
	}

	RegEx &RegEx::operator=(RegEx &&other) {
		this->mRegEx = std::forward<std::basic_regex<Char>>(other.mRegEx);
		return *this;
	}

}