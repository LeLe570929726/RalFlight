// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2019/09/22 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"

namespace Core {

template <typename T>
class RF_API_TEMPLATE DefaultPointerDeleter {
public:
	DefaultPointerDeleter() = default;
	DefaultPointerDeleter(const DefaultPointerDeleter &other) = default;
	DefaultPointerDeleter(DefaultPointerDeleter &&other) noexcept = default;
	DefaultPointerDeleter &operator=(const DefaultPointerDeleter &other) = default;
	DefaultPointerDeleter &operator=(DefaultPointerDeleter &&other) = default;
	~DefaultPointerDeleter() = default;

public:
	void operator()(T *pointer) { delete pointer; }
};

template <typename T>
class RF_API_TEMPLATE DefaultPointerDeleter<T[]> {
public:
	DefaultPointerDeleter() = default;
	DefaultPointerDeleter(const DefaultPointerDeleter &other) = default;
	DefaultPointerDeleter(DefaultPointerDeleter &&other) noexcept = default;
	DefaultPointerDeleter &operator=(const DefaultPointerDeleter &other) = default;
	DefaultPointerDeleter &operator=(DefaultPointerDeleter &&other) = default;
	~DefaultPointerDeleter() = default;

public:
	void operator()(T *pointer) { delete[] pointer; }
};

} // namespace Core
