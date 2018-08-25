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
#include <memory>

namespace Core {

template <class T, class Deleter = std::default_delete<T>>
using RF_API_TEMPLATE UniquePointer = std::unique_ptr<T, Deleter>;

} // namespace Core