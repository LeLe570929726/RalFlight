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
class RF_API_TEMPLATE SharedPointer {
public:
	SharedPointer() : mPointer(nullptr), mCount(nullptr), mDeleter(nullptr) {}
	SharedPointer(T *pointer) : mPointer(pointer), mCount(new int(1)), mDeleter(new Deleter) {}
	SharedPointer(T *pointer, const Deleter &deleter) : mPointer(pointer), mCount(new int(1)), mDeleter(new Deleter(deleter)) {}
	SharedPointer(const SharedPointer &other) : mPointer(other.mPointer), mCount(other.mCount), mDeleter(other.mDeleter) {
		if (this->mPointer != nullptr) {
			++(*this->mCount);
		}
	}
	SharedPointer(SharedPointer &&other) : mPointer(other.mPointer), mCount(other.mCount), mDeleter(other.mDeleter) noexcept {
		if (this->mPointer != nullptr) {
			++(*this->mCount);
		}
	}
	SharedPointer &operator=(const SharedPointer &other) {
		this->mPointer = other.mPointer;
		this->mCount = other.mCount;
		this->mDeleter = other.mDeleter;
		if (this->mPointer != nullptr) {
			++(*this->mCount);
		}
		return *this;
	}
	SharedPointer &operator=(SharedPointer &&other) noexcept {
		this->mPointer = other.mPointer;
		this->mCount = other.mCount;
		this->mDeleter = other.mDeleter;
		if (this->mPointer != nullptr) {
			++(*this->mCount);
		}
		return *this;
	}
	~SharedPointer() { this->release(); }

public:
	bool operator==(const SharedPointer &other) const { return this->mPointer == other.mPointer; }
	bool operator!=(const SharedPointer &other) const { return this->mPointer != other.mPointer; }
	bool operator<(const SharedPointer &other) const { return this->mPointer < other.mPointer; }
	bool operator<=(const SharedPointer &other) const { return this->mPointer <= other.mPointer; }
	bool operator>(const SharedPointer &other) const { return this->mPointer > other.mPointer; }
	bool operator>=(const SharedPointer &other) const { return this->mPointer >= other.mPointer; }
	operator bool() const { return this->mPointer != nullptr; }
	bool operator!() const { return this->mPointer == nullptr; }
	T &operator*() const { return *this->mPointer; }
	T *operator->() const { return this->mPointer; }

public:
	void release() {
		if (this->mPointer != nullptr) {
			--(*this->mCount);
			if (*this->mCount == 0) {
				(*this->mDeleter)(this->mPointer);
				delete this->mCount;
				delete this->mDeleter;
				this->mPointer = nullptr;
				this->mCount = nullptr;
				this->mDeleter = nullptr;
			}
		}
	}
	void reset() {
		this->release();
		this->mPointer = nullptr;
		this->mCount = nullptr;
		this->mDeleter = nullptr;
	}
	void reset(T *pointer) {
		this->release();
		this->mPointer = pointer;
		this->mCount = new int(1);
		this->mDeleter = new Deleter;
	}
	void reset(T *pointer, const Deleter &deleter) {
		this->release();
		this->mPointer = pointer;
		this->mCount = new int(1);
		this->mDeleter = new Deleter(deleter);
	}
	void swap(SharedPointer &other) {
		std::swap(this->mPointer, other.mPointer);
		std::swap(this->mCount, this->mCount);
		std::swap(this->mDeleter, this->mDeleter);
	}

public:
	T *get() const { return this->mPointer; }
	uint16 count() const { return *this->mCount; }

public:
	static decltype(auto) make() { return SharedPointer<std::nullptr_t>; }
	template <typename T>
	static decltype(auto) make(T *pointer) {
		return SharedPointer<T>(pointer);
	}
	template <typename T, typename Deleter>
	static decltype(auto) make(T *pointer, const Deleter &deleter) {
		return SharedPointer<T, Deleter>(pointer, deleter);
	}

private:
	T *mPointer;
	uint16 *mCount;
	Deleter *mDeleter;
};

template <typename T, typename Deleter>
class RF_API_TEMPLATE SharedPointer<T[], Deleter> {
public:
	SharedPointer() : mPointer(nullptr), mCount(nullptr), mDeleter(nullptr) {}
	SharedPointer(T *pointer) : mPointer(pointer), mCount(new int(1)), mDeleter(new Deleter) {}
	SharedPointer(T *pointer, const Deleter &deleter) : mPointer(pointer), mCount(new int(1)), mDeleter(new Deleter(deleter)) {}
	SharedPointer(const SharedPointer &other) : mPointer(other.mPointer), mCount(other.mCount), mDeleter(other.mDeleter) {
		if (this->mPointer != nullptr) {
			++(*this->mCount);
		}
	}
	SharedPointer(SharedPointer &&other) : mPointer(other.mPointer), mCount(other.mCount), mDeleter(other.mDeleter) noexcept {
		if (this->mPointer != nullptr) {
			++(*this->mCount);
		}
	}
	SharedPointer &operator=(const SharedPointer &other) {
		this->mPointer = other.mPointer;
		this->mCount = other.mCount;
		this->mDeleter = other.mDeleter;
		if (this->mPointer != nullptr) {
			++(*this->mCount);
		}
		return *this;
	}
	SharedPointer &operator=(SharedPointer &&other) noexcept {
		this->mPointer = other.mPointer;
		this->mCount = other.mCount;
		this->mDeleter = other.mDeleter;
		if (this->mPointer != nullptr) {
			++(*this->mCount);
		}
		return *this;
	}
	~SharedPointer() { this->release(); }

public:
	bool operator==(const SharedPointer &other) const { return this->mPointer == other.mPointer; }
	bool operator!=(const SharedPointer &other) const { return this->mPointer != other.mPointer; }
	bool operator<(const SharedPointer &other) const { return this->mPointer < other.mPointer; }
	bool operator<=(const SharedPointer &other) const { return this->mPointer <= other.mPointer; }
	bool operator>(const SharedPointer &other) const { return this->mPointer > other.mPointer; }
	bool operator>=(const SharedPointer &other) const { return this->mPointer >= other.mPointer; }
	operator bool() const { return this->mPointer != nullptr; }
	bool operator!() const { return this->mPointer == nullptr; }
	T &operator[](uint16 position) const { return *this->mPointer[position]; }

public:
	void release() {
		if (this->mPointer != nullptr) {
			--(*this->mCount);
			if (*this->mCount == 0) {
				(*this->mDeleter)(this->mPointer);
				delete this->mCount;
				delete this->mDeleter;
				this->mPointer = nullptr;
				this->mCount = nullptr;
				this->mDeleter = nullptr;
			}
		}
	}
	void reset() {
		this->release();
		this->mPointer = nullptr;
		this->mCount = nullptr;
		this->mDeleter = nullptr;
	}
	void reset(T *pointer) {
		this->release();
		this->mPointer = pointer;
		this->mCount = new int(1);
		this->mDeleter = new Deleter;
	}
	void reset(T *pointer, const Deleter &deleter) {
		this->release();
		this->mPointer = pointer;
		this->mCount = new int(1);
		this->mDeleter = new Deleter(deleter);
	}
	void swap(SharedPointer &other) {
		std::swap(this->mPointer, other.mPointer);
		std::swap(this->mCount, this->mCount);
		std::swap(this->mDeleter, this->mDeleter);
	}

public:
	T *get() const { return this->mPointer; }
	uint16 count() const { return *this->mCount; }

public:
	static decltype(auto) make() { return SharedPointer<std::nullptr_t>; }
	template <typename T>
	static decltype(auto) make(T *pointer) {
		return SharedPointer<T>(pointer);
	}
	template <typename T, typename Deleter>
	static decltype(auto) make(T *pointer, const Deleter &deleter) {
		return SharedPointer<T, Deleter>(pointer, deleter);
	}

private:
	T *mPointer;
	uint16 *mCount;
	Deleter *mDeleter;
};

} // namespace Core
