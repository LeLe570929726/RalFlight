// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2018/3/10 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_STL_SHAREDPOINTER_H
#define RALFLIGHT_SRC_CORE_STL_SHAREDPOINTER_H

#include "../Global/Macro.h"
#include <memory>
#include <utility>

// Core namespace
namespace Core {

	template <class T>
	class RALFLIGHT_API_TEMPLATE SharedPointer {
	public:
		SharedPointer() = default;
		SharedPointer(T *pointer) :
			mPointer(pointer) {
		}
		SharedPointer(const SharedPointer &other) :
			mPointer(other.mPointer) {
		}
		SharedPointer(SharedPointer &&other) :
			mPointer(other.mPointer) {
		}
		SharedPointer &operator=(const SharedPointer &other) {
			this->mPointer = other.mPointer;
			return *this;
		}
		SharedPointer &operator=(SharedPointer &&other) {
			this->mPointer = other.mPointer;
			return *this;
		}
		virtual ~SharedPointer() = default;

	public:
		T &operator*() const override {
			return *(this->mPointer);
		}
		T *operator->() const override {
			return this->mPointer.get();
		}

	public:
		void reset(T *pointer) override {
			this->mPointer.reset(pointer);
		}
		T *get() const override {
			return this->mPointer.get();
		}

	private:
		std::shared_ptr<T> mPointer;
	};

}


#endif			// RALFLIGHT_SRC_CORE_STL_SHAREDPOINTER_H