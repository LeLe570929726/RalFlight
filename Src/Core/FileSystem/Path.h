// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/6/30 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"
#include <boost/filesystem.hpp>

namespace Core {

class RF_API Path {
public:
	Path() = default;

	~Path() = default;

private:
	boost::filesystem::path mPath;
};

} // namespace Core