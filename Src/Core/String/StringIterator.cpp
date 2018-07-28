// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/07/28 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "StringIterator.h"

namespace Core {

StringIterator::StringIterator(const std::wstring::iterator itr) : mItr(itr) {}

StringIterator &StringIterator::operator+=(int64 number) {
	this->mItr += number;
	return *this;
}

StringIterator &StringIterator::operator-=(int64 number) {
	this->mItr -= number;
	return *this;
}

StringIterator &StringIterator::operator++() {
	++this->mItr;
	return *this;
}

StringIterator &StringIterator::operator--() {
	--this->mItr;
	return *this;
}

StringIterator StringIterator::operator++(int) {
	StringIterator tmpPtr(this->mItr);
	++tmpPtr;
	return tmpPtr;
}

StringIterator StringIterator::operator--(int) {
	StringIterator tmpPtr(this->mItr);
	--tmpPtr;
	return tmpPtr;
}

StringIterator StringIterator::operator+(int64 number) {
	StringIterator tmpPtr(this->mItr);
	tmpPtr += number;
	return tmpPtr;
}

StringIterator StringIterator::operator-(int64 number) {
	StringIterator tmpPtr(this->mItr);
	tmpPtr -= number;
	return tmpPtr;
}

CharReference StringIterator::getReference() { return CharReference(&(*this->mItr)); }

UniquePointer<CharReference> StringIterator::getPointer() {
	return UniquePointer<CharReference>(new CharReference(&(*this->mItr)));
}

} // namespace Core