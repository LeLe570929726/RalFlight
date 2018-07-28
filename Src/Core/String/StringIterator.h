// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/07/28 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"
#include "../Math/Scalar.h"
#include "../Memory/UniquePointer.h"
#include "Char.h"
#include "CharReference.h"
#include <iterator>

namespace Core {

class RF_API StringIterator : public std::iterator_traits<StringIterator> {
public:
	StringIterator(const std::wstring::iterator itr);
	StringIterator(const StringIterator &other) = default;
	StringIterator(StringIterator &&other) = default;
	StringIterator &operator=(const StringIterator &other) = default;
	StringIterator &operator=(StringIterator &&other) = default;
	~StringIterator() = default;

public:
	bool operator==(const StringIterator &other) const { return this->mItr == other.mItr; }
	bool operator!=(const StringIterator &other) const { return this->mItr != other.mItr; }
	StringIterator &operator+=(int64 number);
	StringIterator &operator-=(int64 number);
	StringIterator &operator++();
	StringIterator &operator--();
	StringIterator operator++(int);
	StringIterator operator--(int);
	StringIterator operator+(int64 number);
	StringIterator operator-(int64 number);
	CharReference operator*() { return this->getReference(); }
	UniquePointer<CharReference> operator->() { return this->getPointer(); }

public:
	CharReference getReference();
	UniquePointer<CharReference> getPointer();

public:
	using iterator_category = std::random_access_iterator_tag;
	using difference_type = std::wstring::difference_type;
	using value_type = Char;
	using reference = CharReference;
	using pointer = UniquePointer<CharReference>;

private:
	std::wstring::iterator mItr;
};

} // namespace Core