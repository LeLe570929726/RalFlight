// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/3/17 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_STD_ITERATOR_H
#define RALFLIGHT_SRC_CORE_STD_ITERATOR_H

#include "../Global/Macro.h"

// Core namespace
namespace Core {

	template<class T>
	class RALFLIGHT_API Iterator {
	public:
		Iterator() = default;
		Iterator(const T &iterator) :
			mIterator(iterator) {
		}
		Iterator(const Iterator &other) :
			mIterator(other.mIterator) {
		}
		Iterator &operator=(const Iterator &other) {
			this->mIterator = other.mIterator;
			return *this;
		}
		~Iterator() = default;

	public:
		bool operator==(const Iterator &other) const {
			return this->mIterator == other.mIterator;
		}
		bool operator!=(const Iterator &other) const {
			return this->mIterator != other.mIterator;
		}
		bool operator<(const Iterator &other) const {
			return this->mIterator < other.mIterator;
		}
		bool operator>(const Iterator &other) const {
			return this->mIterator > other.mIterator;
		}
		bool operator<=(const Iterator &other) const {
			return this->mIterator <= other.mIterator;
		}
		bool operator>=(const Iterator &other) const {
			return this->mIterator >= other.mIterator;
		}

	public:
		Iterator &operator++() {
			++this->mIterator;
			return *this;
		}
		Iterator operator++(int) {
			return this->mIterator++;
		}
		Iterator &operator--() {
			--this->mIterator;
			return *this;
		}
		Iterator operator--(int) {
			return this->mIterator--;
		}
		Iterator operator+(int size) const {
			return this->mIterator + size;
		}
		Iterator operator-(int size) const {
			return this->mIterator + size;
		}
		Iterator &operator+=(int size) {
			this->mIterator += size;
			return *this;
		}
		Iterator &operator-=(int size) {
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

#endif			// RALFLIGHT_SRC_CORE_STD_ITERATOR_H