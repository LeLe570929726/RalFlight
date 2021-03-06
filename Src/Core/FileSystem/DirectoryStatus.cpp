// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2019/08/22 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "DirectoryStatus.h"

namespace Core {

PathPermisson DirectoryStatus::permission() const {
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

Date DirectoryStatus::createTime() const { return this->mCreateTime; }

} // namespace Core
