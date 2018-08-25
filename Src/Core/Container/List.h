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
#include <assert.h>
#include <initializer_list>
#include <list>
#include <utility>

namespace Core {

template <class T, class Allocator = std::allocator<T>>
using ListIterator = typename std::list<T, Allocator>::iterator;
template <class T, class Allocator = std::allocator<T>>
using ConstListIterator = typename std::list<T, Allocator>::const_iterator;
template <class T, class Allocator = std::allocator<T>>
using ListReverseIterator = typename std::list<T, Allocator>::reverse_iterator;
template <class T, class Allocator = std::allocator<T>>
using ConstListReverseIterator = typename std::list<T, Allocator>::const_reverse_iterator;

template <class T, class Allocator = std::allocator<T>>
class RF_API_TEMPLATE List {
public:
	explicit List(const Allocator &alloc) : mList(alloc) {}
	List(const T &value, uint64 number, const Allocator &alloc = Allocator()) : mList(number, value, alloc) {}
	List(uint64 number, const Allocator &alloc = Allocator()) : mList(number, alloc) {}
	List(std::initializer_list<T> init, const Allocator &alloc = Allocator()) : mList(init, alloc) {}
	List(const std::list<T, Allocator> &list) : mList(list) {}
	List(std::list<T, Allocator> &&list) : mList(std::forward<std::list<T, Allocator>>(list)) {}
	List(const List &other) = default;
	List(List &&other) noexcept = default;
	List &operator=(const List &other) = default;
	List &operator=(List &&other) noexcept = default;
	~List() = default;

public:
	bool operator==(const List &other) { return this->mList == other.mList; }
	bool operator!=(const List &other) { return this->mList != other.mList; }
	bool operator<(const List &other) { return this->mList < other.mList; }
	bool operator<=(const List &other) { return this->mList <= other.mList; }
	bool operator>(const List &other) { return this->mList > other.mList; }
	bool operator>=(const List &other) { return this->mList >= other.mList; }

public:
	ListIterator<T, Allocator> begin() { return this->mList.begin(); }
	ConstListIterator<T, Allocator> begin() const { return this->mList.cbegin(); }
	ConstListIterator<T, Allocator> cbegin() const { return this->mList.cbegin(); }
	ListReverseIterator<T, Allocator> rbegin() { return this->mList.rbegin(); }
	ConstListReverseIterator<T, Allocator> rbegin() const { return this->mList.crbegin(); }
	ConstListReverseIterator<T, Allocator> crbegin() const { return this->mList.crbegin(); }
	ListIterator<T, Allocator> end() { return this->mList.end(); }
	ConstListIterator<T, Allocator> end() const { return this->mList.cend(); }
	ConstListIterator<T, Allocator> cend() const { return this->mList.cend(); }
	ListReverseIterator<T, Allocator> rend() { return this->mList.rend(); }
	ConstListReverseIterator<T, Allocator> rend() const { return this->mList.crend(); }
	ConstListReverseIterator<T, Allocator> crend() const { return this->mList.crend(); }

public:
	T &front() { return this->mList.front(); }
	const T &front() const { return this->mList.front(); }
	T &back() { return this->mList.back(); }
	const T &back() const { return this->mList.back(); }

public:
	List &append(const T &value) {
		this->mList.push_back(value);
		return *this;
	}
	List &append(T &&value) {
		this->mList.push_back(std::forward<T>(value));
		return *this;
	}
	List &insert(const T &value, uint64 position) {
		assert(position < this->mList.size());
		auto posItr = this->mList.cbegin();
		for (uint64 i = 0; i < position; ++i) {
			++posItr;
		}
		this->mList.insert(posItr, value);
		return *this;
	}
	List &insert(T &&value, uint64 position) {
		assert(position < this->mList.size());
		auto posItr = this->mList.cbegin();
		for (uint64 i = 0; i < position; ++i) {
			++posItr;
		}
		this->mList.insert(posItr, std::forward<T>(value));
		return *this;
	}
	ListIterator<T, Allocator> insert(const T &value, ConstListIterator<T, Allocator> position) {
		return this->mList.insert(position, value);
	}
	ListIterator<T, Allocator> insert(T &&value, ConstListIterator<T, Allocator> position) {
		return this->mList.insert(position, std::forward<T>(value));
	}
	List &remove(uint64 position, uint64 number = 1) {
		assert((position + number) <= this->mList.size());
		auto firstItr = this->mList.cbegin();
		for (uint64 i = 0; i < position; ++i) {
			++firstItr;
		}
		auto endItr = firstItr;
		for (uint64 i = 0; i < number; ++i) {
			++endItr;
		}
		this->mList.erase(firstItr, endItr);
		return *this;
	}
	ListIterator<T, Allocator> remove(ConstListIterator<T, Allocator> position) { return this->mList.erase(position); }
	ListIterator<T, Allocator> remove(ConstListIterator<T, Allocator> first, ConstListIterator<T, Allocator> last) {
		return this->mList.erase(first, last);
	}

public:
	uint64 length() const { return this->mList.size(); }
	bool empty() const { return this->mList.empty(); }
	void clear() { this->mList.clear(); }

private:
	std::list<T, Allocator> mList;
};

} // namespace Core
