// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2019/08/22 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"
#include "../Time/Date.h"
#include "PathStatus.h"
#include <boost/filesystem.hpp>

namespace Core {

class Directory;

class RF_API DirectoryStatus {
public:
	DirectoryStatus() = default;
	DirectoryStatus(const DirectoryStatus &other) = default;
	DirectoryStatus(DirectoryStatus &&other) noexcept = default;
	DirectoryStatus &operator=(const DirectoryStatus &other) = default;
	DirectoryStatus &operator=(DirectoryStatus &&other) noexcept = default;
	~DirectoryStatus() = default;

public:
	PathPermisson permission() const;

public:
	Date createTime() const;

private:
	friend Directory;

private:
	boost::filesystem::file_status mPathStatus;
	Date mCreateTime;
	Date mWriteTime;
};

} // namespace Core
