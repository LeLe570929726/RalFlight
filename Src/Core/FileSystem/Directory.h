// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2019/01/31 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"
#include "Path.h"
#include <boost/filesystem.hpp>

namespace Core {
class RF_API Directory {
public:
	Directory() = default;
	Directory(const Path &path);
	Directory(const Directory &other) = default;
	Directory(Directory &&other) noexcept = default;
	Directory &operator=(const Directory &other) = default;
	Directory &operator=(Directory &&other) = default;
	~Directory() = default;

public:
	bool operator==(const Directory &other);
	bool operator!=(const Directory &other);
	bool operator<(const Directory &other);
	bool operator<=(const Directory &other);
	bool operator>(const Directory &other);
	bool operator>=(const Directory &other);

public:
	void replaceFileName(const Path &path);

private:
	boost::filesystem::directory_entry mDirectory;
};

} // namespace Core