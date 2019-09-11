// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2019/01/31 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Directory.h"
#ifdef RF_OS_WIN
#include <Windows.h>
#endif

namespace Core {

Directory::Directory(const Path &path) : Path(path) {}

Directory::ErrorCode Directory::mkdir() const {
	if (this->isExist() == false) {
#ifdef RF_OS_WIN
		if (CreateDirectoryW(this->native().toWString().c_str(), NULL) != 0) {
			return ErrorCode::Success;
		} else {
			if (GetLastError() == ERROR_ALREADY_EXISTS) {
				return ErrorCode::DirectoryAlreadyExist;
			} else {
				return ErrorCode::Failed;
			}
		}
#endif
	} else {
		return ErrorCode::DirectoryAlreadyExist;
	}
}

Directory::ErrorCode Directory::rmdir() const {
	if (this->isExist() == true) {
#ifdef RF_OS_WIN
		if (RemoveDirectoryW(this->native().toWString().c_str()) != 0) {
			return ErrorCode::Success;
		} else {
			return ErrorCode::Failed;
		}
#endif
	} else {
		return ErrorCode::DirectoryDoesNotEsist;
	}
}

DirectoryStatus Directory::status() const {
	DirectoryStatus tmpStatus;
	tmpStatus.mPathStatus = boost::filesystem::status(this->mPath);
	// Get directory's attributes
	if (this->isExist() == true) {
#ifdef RF_OS_WIN
		WIN32_FILE_ATTRIBUTE_DATA fileInfo;
		if (GetFileAttributesExW(this->native().toWString().c_str(), GetFileExInfoStandard, &fileInfo) != 0) {
			SYSTEMTIME systemTime;
			// Set create time
			if (FileTimeToSystemTime(&fileInfo.ftCreationTime, &systemTime) != 0) {
				tmpStatus.mCreateTime.setYear(systemTime.wYear);
				tmpStatus.mCreateTime.setMonth(systemTime.wMonth);
				tmpStatus.mCreateTime.setDay(systemTime.wDay);
				tmpStatus.mCreateTime.setHour(systemTime.wHour);
				tmpStatus.mCreateTime.setMinute(systemTime.wMinute);
				tmpStatus.mCreateTime.setSecond(systemTime.wSecond);
			}
			// Set write time
			if (FileTimeToSystemTime(&fileInfo.ftLastWriteTime, &systemTime) != 0) {
				tmpStatus.mWriteTime.setYear(systemTime.wYear);
				tmpStatus.mWriteTime.setMonth(systemTime.wMonth);
				tmpStatus.mWriteTime.setDay(systemTime.wDay);
				tmpStatus.mWriteTime.setHour(systemTime.wHour);
				tmpStatus.mWriteTime.setMinute(systemTime.wMinute);
				tmpStatus.mWriteTime.setSecond(systemTime.wSecond);
			}
		}
#endif
	}
	return tmpStatus;
}

} // namespace Core
