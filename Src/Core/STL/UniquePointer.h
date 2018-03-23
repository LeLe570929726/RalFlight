// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2017/12/23 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_STL_UNIQUEPOINTER_H
#define RALFLIGHT_SRC_CORE_STL_UNIQUEPOINTER_H

#include "../Global/Macro.h"
#include <memory>
#include <utility>

// Core namespace
namespace Core {

	template <class T>
	class RALFLIGHT_API_TEMPLATE UniquePointer {
	public:
		UniquePointer() :
			mPointer() {
		}
		UniquePointer(T *pointer) :
			mPointer(pointer) {
		}
		UniquePointer(const UniquePointer &other) = delete;
		UniquePointer(UniquePointer &&other) :
			mPointer(std::forward<std::unique_ptr<T>>(other.mPointer)) {
		}
		UniquePointer &operator=(const UniquePointer &other) = delete;
		UniquePointer &operator=(UniquePointer &&other) {
			this->mPointer = std::forward<std::unique_ptr<T>>(other.mPointer);
			return *this;
		}
		~UniquePointer() = default;

	public:
		T &operator*() const {
			return *(this->mPointer);
		}
		T *operator->() const {
			return this->mPointer.get();
		}

	public:
		T *release() {
			return this->mPointer.release();
		}
		void reset(T *pointer) {
			this->mPointer.reset(pointer);
		}
		T *get() const {
			return this->mPointer.get();
		}

	private:
		std::unique_ptr<T> mPointer;
	};

}

#endif			// RALFLIGHT_SRC_CORE_STL_UNIQUEPOINTER_H