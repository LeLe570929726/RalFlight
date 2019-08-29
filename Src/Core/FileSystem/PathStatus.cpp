// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/11/30 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "PathStatus.h"
#include <cassert>

namespace Core {

PathPermisson PathStatus::permission() const {
	switch (this->mPathStatus.permissions()) {
	case boost::filesystem::perms::no_perms:
		return PathPermisson::None;
	case boost::filesystem::perms::owner_read:
		return PathPermisson::OwnerRead;
	case boost::filesystem::perms::owner_write:
		return PathPermisson::OwnerWrite;
	case boost::filesystem::perms::owner_exe:
		return PathPermisson::OwnerExec;
	case boost::filesystem::perms::owner_all:
		return PathPermisson::OwnerAll;
	case boost::filesystem::perms::group_read:
		return PathPermisson::GroupRead;
	case boost::filesystem::perms::group_write:
		return PathPermisson::GroupWrite;
	case boost::filesystem::perms::group_exe:
		return PathPermisson::GroupExec;
	case boost::filesystem::perms::group_all:
		return PathPermisson::GroupAll;
	case boost::filesystem::perms::others_read:
		return PathPermisson::OthersRead;
	case boost::filesystem::perms::others_write:
		return PathPermisson::OthersWrite;
	case boost::filesystem::perms::others_exe:
		return PathPermisson::OthersExec;
	case boost::filesystem::perms::others_all:
		return PathPermisson::OthersAll;
	case boost::filesystem::perms::all_all:
		return PathPermisson::All;
	default:
		return PathPermisson::Unknow;
	}
}

PathType PathStatus::type() const {
	switch (this->mPathStatus.type()) {
	case boost::filesystem::file_type::regular_file:
		return PathType::File;
	case boost::filesystem::file_type::directory_file:
		return PathType::Directory;
	case boost::filesystem::file_type::symlink_file:
		return PathType::Symlink;
	case boost::filesystem::file_type::block_file:
		return PathType::Block;
	case boost::filesystem::file_type::character_file:
		return PathType::Character;
	case boost::filesystem::file_type::fifo_file:
		return PathType::FIFO;
	case boost::filesystem::file_type::socket_file:
		return PathType::Socket;
	case boost::filesystem::file_type::file_not_found:
		return PathType::NotFound;
	default:
		return PathType::Unknow;
	}
}

} // namespace Core
