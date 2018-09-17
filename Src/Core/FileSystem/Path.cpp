// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/6/30 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Path.h"

namespace Core {

Path::Path(const String &path) : mPath(path.toWString()) {}

Path &Path::operator=(const String &path) {
	this->mPath = path.toWString();
	return *this;
}

Path &Path::operator/=(const Path &other) {
	this->mPath /= other.mPath;
	return *this;
}

Path &Path::operator/=(const String &path) {
	this->mPath /= path.toWString();
	return *this;
}

Path &Path::append(const Path &other) {
	this->mPath /= other.mPath;
	return *this;
}

Path &Path::append(const String &path) {
	this->mPath.append(path.toWString());
	return *this;
}

Path Path::currentPath() {
	Path tmpPath;
	tmpPath.mPath = boost::filesystem::current_path();
	return tmpPath;
}

} // namespace Core