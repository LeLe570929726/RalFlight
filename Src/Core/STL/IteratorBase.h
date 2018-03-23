// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2017/3/17 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_STL_ITERATORBASE_H
#define RALFLIGHT_SRC_CORE_STL_ITERATORBASE_H

#include "../Global/Macro.h"

// Core namespace
namespace Core {

	template<class T>
	class RALFLIGHT_API_TEMPLATE IteratorBase {
	public:
		IteratorBase() = default;
		IteratorBase(const T &iterator) :
			mIterator(iterator) {
		}
		IteratorBase(const IteratorBase &other) :
			mIterator(other.mIterator) {
		}
		IteratorBase &operator=(const IteratorBase &other) {
			this->mIterator = other.mIterator;
			return *this;
		}
		~IteratorBase() = default;

	public:
		bool operator==(const IteratorBase &other) const {
			return this->mIterator == other.mIterator;
		}
		bool operator!=(const IteratorBase &other) const {
			return this->mIterator != other.mIterator;
		}
		bool operator<(const IteratorBase &other) const {
			return this->mIterator < other.mIterator;
		}
		bool operator>(const IteratorBase &other) const {
			return this->mIterator > other.mIterator;
		}
		bool operator<=(const IteratorBase &other) const {
			return this->mIterator <= other.mIterator;
		}
		bool operator>=(const IteratorBase &other) const {
			return this->mIterator >= other.mIterator;
		}

	public:
		IteratorBase & operator++() {
			++this->mIterator;
			return *this;
		}
		IteratorBase operator++(int) {
			return this->mIterator++;
		}
		IteratorBase &operator--() {
			--this->mIterator;
			return *this;
		}
		IteratorBase operator--(int) {
			return this->mIterator--;
		}
		IteratorBase operator+(int size) const {
			return this->mIterator + size;
		}
		IteratorBase operator-(int size) const {
			return this->mIterator + size;
		}
		IteratorBase &operator+=(int size) {
			this->mIterator += size;
			return *this;
		}
		IteratorBase &operator-=(int size) {
			this->mIterator -= size;
			return *this;
		}

	public:
		T get() const {
			return this->mIterator;
		}

	private:
		T mIterator;

	public:
		auto operator*() const -> decltype(*this->mIterator) {
			return *this->mIterator;
		}
		auto operator->() const -> decltype(&(*this->mIterator)) {
			return &(*this->mIterator);
		}
	};

}

#endif			// RALFLIGHT_SRC_CORE_STL_ITERATORBASE_H