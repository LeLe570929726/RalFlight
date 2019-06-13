// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/07/28 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "ConstStringIterator.h"

namespace Core {

ConstStringIterator::ConstStringIterator(const std::wstring::const_iterator itr) : mItr(itr) {}

ConstStringIterator &ConstStringIterator::operator+=(int64 number) {
	this->mItr += number;
	return *this;
}

ConstStringIterator &ConstStringIterator::operator-=(int64 number) {
	this->mItr -= number;
	return *this;
}

ConstStringIterator &ConstStringIterator::operator++() {
	++this->mItr;
	return *this;
}

ConstStringIterator &ConstStringIterator::operator--() {
	--this->mItr;
	return *this;
}

ConstStringIterator ConstStringIterator::operator++(int) {
	ConstStringIterator tmpPtr(this->mItr);
	++tmpPtr;
	return tmpPtr;
}

ConstStringIterator ConstStringIterator::operator--(int) {
	ConstStringIterator tmpPtr(this->mItr);
	--tmpPtr;
	return tmpPtr;
}

ConstStringIterator ConstStringIterator::operator+(int64 number) {
	ConstStringIterator tmpPtr(this->mItr);
	tmpPtr += number;
	return tmpPtr;
}

ConstStringIterator ConstStringIterator::operator-(int64 number) {
	ConstStringIterator tmpPtr(this->mItr);
	tmpPtr -= number;
	return tmpPtr;
}

Char ConstStringIterator::getReference() const { return Char(*this->mItr); }

UniquePointer<Char> ConstStringIterator::getPointer() const { return UniquePointer<Char>(new Char(*this->mItr)); }

} // namespace Core
