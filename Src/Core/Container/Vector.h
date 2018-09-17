// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/08/04 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"
#include "../Math/Scalar.h"
#include <assert.h>
#include <initializer_list>
#include <utility>
#include <vector>

namespace Core {

template <class T, class Allocator = std::allocator<T>>
using VectorIterator = typename std::vector<T, Allocator>::iterator;
template <class T, class Allocator = std::allocator<T>>
using ConstVectorIterator = typename std::vector<T, Allocator>::const_iterator;
template <class T, class Allocator = std::allocator<T>>
using VectorReverseIterator = typename std::vector<T, Allocator>::reverse_iterator;
template <class T, class Allocator = std::allocator<T>>
using ConstVectorReverseIterator = typename std::vector<T, Allocator>::const_reverse_iterator;

template <class T, class Allocator = std::allocator<T>>
class RF_API_TEMPLATE Vector {
public:
	explicit Vector(const Allocator &alloc = Allocator()) : mVector(alloc) {}
	Vector(const T &value, uint64 number, const Allocator &alloc = Allocator()) : mVector(number, value, alloc) {}
	Vector(uint64 number, const Allocator &alloc = Allocator()) : mVector(number, alloc) {}
	Vector(std::initializer_list<T> init, const Allocator &alloc = Allocator()) : mVector(init, alloc) {}
	Vector(const std::vector<T, Allocator> &vector) : mVector(vector) {}
	Vector(std::vector<T, Allocator> &&vector) : mVector(std::forward<std::vector<T, Allocator>>(vector)) {}
	Vector(const Vector &other) = default;
	Vector(Vector &&other) noexcept = default;
	Vector &operator=(const Vector &other) = default;
	Vector &operator=(Vector &&other) noexcept = default;
	~Vector() = default;

public:
	bool operator==(const Vector &other) { return this->mVector == other.mVector; }
	bool operator!=(const Vector &other) { return this->mVector != other.mVector; }
	bool operator<(const Vector &other) { return this->mVector < other.mVector; }
	bool operator<=(const Vector &other) { return this->mVector <= other.mVector; }
	bool operator>(const Vector &other) { return this->mVector > other.mVector; }
	bool operator>=(const Vector &other) { return this->mVector >= other.mVector; }

public:
	VectorIterator<T, Allocator> begin() { return this->mVector.begin(); }
	ConstVectorIterator<T, Allocator> begin() const { return this->mVector.cbegin(); }
	ConstVectorIterator<T, Allocator> cbegin() const { return this->mVector.cbegin(); }
	VectorReverseIterator<T, Allocator> rbegin() { return this->mVector.rbegin(); }
	ConstVectorReverseIterator<T, Allocator> rbegin() const { return this->mVector.crbegin(); }
	ConstVectorReverseIterator<T, Allocator> crbegin() const { return this->mVector.crbegin(); }
	VectorIterator<T, Allocator> end() { return this->mVector.end(); }
	ConstVectorIterator<T, Allocator> end() const { return this->mVector.cend(); }
	ConstVectorIterator<T, Allocator> cend() const { return this->mVector.cend(); }
	VectorReverseIterator<T, Allocator> rend() { return this->mVector.rend(); }
	ConstVectorReverseIterator<T, Allocator> rend() const { return this->mVector.crend(); }
	ConstVectorReverseIterator<T, Allocator> crend() const { return this->mVector.crend(); }

public:
	T &at(uint64 position) { return this->mVector.at(position); }
	const T &at(uint64 position) const { return this->mVector.at(position); }
	T &front() { return this->mVector.front(); }
	const T &front() const { return this->mVector.front(); }
	T &back() { return this->mVector.back(); }
	const T &back() const { return this->mVector.back(); }

public:
	Vector &append(const T &value) {
		this->mVector.push_back(value);
		return *this;
	}
	Vector &append(T &&value) {
		this->mVector.push_back(value);
		return *this;
	}
	Vector &insert(const T &value, uint64 position) {
		assert(position < this->mVector.size());
		auto posItr = this->mVector.cbegin();
		for (uint64 i = 0; i < position; ++i) {
			++posItr;
		}
		this->mVector.insert(posItr, value);
		return *this;
	}
	Vector &insert(T &&value, uint64 position) {
		assert(position < this->mVector.size());
		auto posItr = this->mVector.cbegin();
		for (uint64 i = 0; i < position; ++i) {
			++posItr;
		}
		this->mVector.insert(posItr, std::forward<T>(value));
		return *this;
	}
	VectorIterator<T, Allocator> insert(const T &value, ConstVectorIterator<T, Allocator> position) {
		return this->mVector.insert(position, value);
	}
	VectorIterator<T, Allocator> insert(T &&value, ConstVectorIterator<T, Allocator> position) {
		return this->mVector.insert(position, std::forward<T>(value));
	}
	Vector &remove(uint64 position, uint64 number = 1) {
		assert((position + number) <= this->mVector.size());
		auto firstItr = this->mVector.cbegin();
		for (uint64 i = 0; i < position; ++i) {
			++firstItr;
		}
		auto endItr = firstItr;
		for (uint64 i = 0; i < number; ++i) {
			++endItr;
		}
		this->mVector.erase(firstItr, endItr);
		return *this;
	}
	VectorIterator<T, Allocator> remove(ConstVectorIterator<T, Allocator> position) { return this->mVector.erase(position); }
	VectorIterator<T, Allocator> remove(ConstVectorIterator<T, Allocator> first, ConstVectorIterator<T, Allocator> last) {
		return this->mVector.erase(first, last);
	}
	void resize(uint64 size) { this->mVector.resize(size); }
	void resize(const T &value, uint64 size) { this->mVector.resize(size, value); }

public:
	uint64 capacity() const { return this->mVector.capacity(); }
	void reserve(uint64 size) { this->mVector.reserve(size); }
	uint64 length() const { return this->mVector.size(); }
	bool empty() const { return this->mVector.empty(); }
	void clear() { this->mVector.clear(); }

private:
	std::vector<T, Allocator> mVector;
};

} // namespace Core