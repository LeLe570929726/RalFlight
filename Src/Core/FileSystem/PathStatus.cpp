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

void PathStatus::setPermission(PathPermisson permisson) {
	assert(permisson != PathPermisson::Unknow);
	switch (permisson) {
	case PathPermisson::None:
		this->mFileStatus.permissions(boost::filesystem::perms::no_perms);
		break;
	case PathPermisson::OwnerRead:
		this->mFileStatus.permissions(boost::filesystem::perms::owner_read);
		break;
	case PathPermisson::OwnerWrite:
		this->mFileStatus.permissions(boost::filesystem::perms::owner_write);
		break;
	case PathPermisson::OwnerExec:
		this->mFileStatus.permissions(boost::filesystem::perms::owner_exe);
		break;
	case PathPermisson::OwnerAll:
		this->mFileStatus.permissions(boost::filesystem::perms::owner_all);
		break;
	case PathPermisson::GroupRead:
		this->mFileStatus.permissions(boost::filesystem::perms::group_read);
		break;
	case PathPermisson::GroupWrite:
		this->mFileStatus.permissions(boost::filesystem::perms::group_write);
		break;
	case PathPermisson::GroupExec:
		this->mFileStatus.permissions(boost::filesystem::perms::group_exe);
		break;
	case PathPermisson::GroupAll:
		this->mFileStatus.permissions(boost::filesystem::perms::group_all);
		break;
	case PathPermisson::OthersRead:
		this->mFileStatus.permissions(boost::filesystem::perms::others_read);
		break;
	case PathPermisson::OthersWrite:
		this->mFileStatus.permissions(boost::filesystem::perms::others_write);
		break;
	case PathPermisson::OthersExec:
		this->mFileStatus.permissions(boost::filesystem::perms::others_exe);
		break;
	case PathPermisson::OthersAll:
		this->mFileStatus.permissions(boost::filesystem::perms::others_all);
		break;
	case PathPermisson::All:
		this->mFileStatus.permissions(boost::filesystem::perms::all_all);
		break;
	default:
 		break;
	}
}

PathPermisson PathStatus::permission() const {
	switch (this->mFileStatus.permissions()) {
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

void PathStatus::setType(PathType type) {
	assert(type != PathType::Unknow);
	switch (type) {
	case PathType::File:
		this->mFileStatus.type(boost::filesystem::file_type::regular_file);
		break;
	case PathType::Directory:
		this->mFileStatus.type(boost::filesystem::file_type::directory_file);
		break;
	case PathType::Symlink:
		this->mFileStatus.type(boost::filesystem::file_type::symlink_file);
		break;
	case PathType::Block:
		this->mFileStatus.type(boost::filesystem::file_type::block_file);
		break;
	case PathType::Character:
		this->mFileStatus.type(boost::filesystem::file_type::character_file);
		break;
	case PathType::FIFO:
		this->mFileStatus.type(boost::filesystem::file_type::fifo_file);
		break;
	case PathType::Socket:
		this->mFileStatus.type(boost::filesystem::file_type::socket_file);
		break;
	default:
		break;
	}
}

PathType PathStatus::type() const {
	switch (this->mFileStatus.type()) {
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
	default:
		return PathType::Unknow;
	}
}

} // namespace Core