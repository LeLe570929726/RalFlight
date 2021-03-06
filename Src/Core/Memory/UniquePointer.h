// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2019/09/20 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"
#include "../Math/Scalar.h"
#include "DefaultPointerDeleter.h"
#include <cstddef>
#include <utility>

namespace Core {

template <typename T, typename Deleter = DefaultPointerDeleter<T>>
class RF_API_TEMPLATE UniquePointer {
public:
	UniquePointer() : mPointer(nullptr), mDeleter(Deleter()) {}
	UniquePointer(T *pointer) : mPointer(pointer), mDeleter(Deleter()) {}
	UniquePointer(T *pointer, const Deleter &deleter) : mPointer(pointer), mDeleter(deleter) {}
	UniquePointer(const UniquePointer &other) = delete;
	UniquePointer(UniquePointer &&other) : mPointer(other.mPointer), mDeleter(other.mDeleter) noexcept {
		other.mPointer = nullptr;
	}
	UniquePointer &operator=(const UniquePointer &other) = delete;
	UniquePointer &operator=(UniquePointer &&other) noexcept {
		this->mPointer = other.mPointer;
		this->mDeleter = other.mDeleter;
		other.mPointer = nullptr;
		return *this;
	}
	~UniquePointer() {
		if (this->mPointer != nullptr) {
			this->mDeleter(this->mPointer);
		}
	}

public:
	bool operator==(const UniquePointer &other) const { return this->mPointer == other.mPointer; }
	bool operator!=(const UniquePointer &other) const { return this->mPointer != other.mPointer; }
	bool operator<(const UniquePointer &other) const { return this->mPointer < other.mPointer; }
	bool operator<=(const UniquePointer &other) const { return this->mPointer <= other.mPointer; }
	bool operator>(const UniquePointer &other) const { return this->mPointer > other.mPointer; }
	bool operator>=(const UniquePointer &other) const { return this->mPointer >= other.mPointer; }
	T &operator*() const { return *this->mPointer; }
	T *operator->() const { return this->mPointer; }

public:
	T *release() {
		auto tmpPtr = this->mPointer;
		this->mPointer = nullptr;
		return tmpPtr;
	}
	void reset() {
		if (this->mPointer != nullptr) {
			this->mDeleter(this->mPointer);
			this->mPointer = nullptr;
		}
	}
	void reset(T *pointer) {
		if (this->mPointer != nullptr) {
			this->mDeleter(this->mPointer);
		}
		this->mPointer = pointer;
	}
	void swap(UniquePointer &other) {
		std::swap(this->mPointer, other.mPointer);
		std::swap(this->mDeleter, other.mDeleter);
	}

public:
	T *get() const { return this->mPointer; }

public:
	static decltype(auto) make() { return UniquePointer<std::nullptr_t>; }
	template <typename T>
	static decltype(auto) make(T *pointer) {
		return UniquePointer<T>(pointer);
	}
	template <typename T, typename Deleter>
	static decltype(auto) make(T *pointer, const Deleter &deleter) {
		return UniquePointer<T, Deleter>(pointer, deleter);
	}

private:
	T *mPointer;
	Deleter mDeleter;
};

template <typename T, typename Deleter>
class RF_API_TEMPLATE UniquePointer<T[], Deleter> {
	UniquePointer() : mPointer(nullptr), mDeleter(Deleter()) {}
	UniquePointer(T *pointer) : mPointer(pointer), mDeleter(Deleter()) {}
	UniquePointer(T *pointer, const Deleter &deleter) : mPointer(pointer), mDeleter(deleter) {}
	UniquePointer(const UniquePointer &other) = delete;
	UniquePointer(UniquePointer &&other) noexcept {
		this->mPointer = other.mPointer;
		this->mDeleter = other.mDeleter;
		other.mPointer = nullptr;
	}
	UniquePointer &operator=(const UniquePointer &other) = delete;
	UniquePointer &operator=(UniquePointer &&other) noexcept {
		this->mPointer = other.mPointer;
		this->mDeleter = other.mDeleter;
		other.mPointer = nullptr;
	}
	~UniquePointer() {
		if (this->mPointer != nullptr) {
			this->mDeleter(this->mPointer);
		}
	}

public:
	template <typename TA, typename DeleterA>
	bool operator==(const UniquePointer<TA, DeleterA> &other) {
		return this->mPointer == other.mPointer;
	}
	template <typename TA, typename DeleterA>
	bool operator!=(const UniquePointer<TA, DeleterA> &other) {
		return this->mPointer != other.mPointer;
	}
	template <typename TA, typename DeleterA>
	bool operator<(const UniquePointer<TA, DeleterA> &other) {
		return this->mPointer < other.mPointer;
	}
	template <typename TA, typename DeleterA>
	bool operator<=(const UniquePointer<TA, DeleterA> &other) {
		return this->mPointer <= other.mPointer;
	}
	template <typename TA, typename DeleterA>
	bool operator>(const UniquePointer<TA, DeleterA> &other) {
		return this->mPointer > other.mPointer;
	}
	template <typename TA, typename DeleterA>
	bool operator>=(const UniquePointer<TA, DeleterA> &other) {
		return this->mPointer >= other.mPointer;
	}
	operator bool() const { return this->mPointer != nullptr; }
	bool operator!() const { return this->mPointer == nullptr; }
	T &operator[](uint16 position) const { return *this->mPointer[position]; }

public:
	T *release() {
		auto tmpPtr = this->mPointer;
		this->mPointer = nullptr;
		return tmpPtr;
	}
	void reset() {
		if (this->mPointer != nullptr) {
			this->mDeleter(this->mPointer);
			this->mPointer = nullptr;
		}
	}
	void reset(T *pointer) {
		if (this->mPointer != nullptr) {
			this->mDeleter(this->mPointer);
		}
		this->mPointer = pointer;
	}
	void swap(UniquePointer &other) {
		auto tmpPtr = this->mPointer;
		auto tmpDeleter = this->mDeleter;
		this->mPointer = other.mPointer;
		this->mDeleter = other.mDeleter;
		other.mPointer = tmpPtr;
		other.mDeleter = tmpDeleter;
	}

public:
	T *get() const { return this->mPointer; }

private:
	T *mPointer;
	Deleter mDeleter;
};

} // namespace Core
