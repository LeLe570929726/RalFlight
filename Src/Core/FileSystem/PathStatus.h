// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/11/30 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"
#include <boost/filesystem.hpp>

namespace Core {

class Path;

enum class PathPermisson {
	None,
	OwnerRead,
	OwnerWrite,
	OwnerExec,
	OwnerAll,
	GroupRead,
	GroupWrite,
	GroupExec,
	GroupAll,
	OthersRead,
	OthersWrite,
	OthersExec,
	OthersAll,
	All,
	Unknow
};

enum class PathType { File, Directory, Symlink, Block, Character, FIFO, Socket, Unknow };

class RF_API PathStatus {
public:
	PathStatus() = default;
	PathStatus(const PathStatus &other) = default;
	PathStatus(PathStatus &&other) noexcept = default;
	PathStatus &operator=(const PathStatus &other) = default;
	PathStatus &operator=(PathStatus &&other) noexcept = default;
	~PathStatus() = default;

public:
	void setPermission(PathPermisson permisson);
	PathPermisson permission() const;
	void setType(PathType type);
	PathType type() const;

private:
	friend Path;

private:
	boost::filesystem::file_status mFileStatus;
};

} // namespace Core