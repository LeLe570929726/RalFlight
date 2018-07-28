// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/07/27 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "CharReference.h"
#include "Char.h"

namespace Core {

CharReference::CharReference(wchar_t *ptr) : mPtr(ptr) {}

CharReference &CharReference::operator=(const Char &ch) {
	*(this->mPtr) = ch.toWChar();
	return *this;
}

std::string CharReference::toString(const std::string &charset) const {
	return Convertor::fromWstring(std::wstring(1, *this->mPtr), charset);
}

} // namespace Core
