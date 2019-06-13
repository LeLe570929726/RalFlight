// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
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

class RF_API ConstStringIterator {
public:
	ConstStringIterator(const std::wstring::const_iterator itr);
	ConstStringIterator(const ConstStringIterator &other) = default;
	ConstStringIterator(ConstStringIterator &&other) = default;
	ConstStringIterator &operator=(const ConstStringIterator &other) = default;
	ConstStringIterator &operator=(ConstStringIterator &&other) = default;
	~ConstStringIterator() = default;

public:
	bool operator==(const ConstStringIterator &other) const { return this->mItr == other.mItr; }
	bool operator!=(const ConstStringIterator &other) const { return this->mItr != other.mItr; }
	ConstStringIterator &operator+=(int64 number);
	ConstStringIterator &operator-=(int64 number);
	ConstStringIterator &operator++();
	ConstStringIterator &operator--();
	ConstStringIterator operator++(int);
	ConstStringIterator operator--(int);
	ConstStringIterator operator+(int64 number);
	ConstStringIterator operator-(int64 number);
	Char operator*() const { return this->getReference(); }
	UniquePointer<Char> operator->() const { return this->getPointer(); }

public:
	std::wstring::const_iterator get() { return this->mItr; }
	Char getReference() const;
	UniquePointer<Char> getPointer() const;

private:
	std::wstring::const_iterator mItr;
};

using ConstStringReverseIterator = std::reverse_iterator<ConstStringIterator>;

} // namespace Core

template <>
struct std::iterator_traits<Core::ConstStringIterator> {
	using iterator_category = std::random_access_iterator_tag;
	using difference_type = std::wstring::difference_type;
	using value_type = Core::Char;
	using reference = Core::Char;
	using pointer = Core::UniquePointer<Core::Char>;
};