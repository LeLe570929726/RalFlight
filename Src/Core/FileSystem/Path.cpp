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
	this->mPath = boost::filesystem::path(path.toWString());
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

Path &Path::operator+=(const Path &other) {
	this->mPath += other.mPath;
	return *this;
}

Path &Path::operator+=(const String &path) {
	this->mPath += path.toWString();
	return *this;
}

bool Path::operator==(const Path &other) const { return this->mPath == other.mPath; }

bool Path::operator==(const String &path) const { return this->mPath == path.toWString(); }

Path &Path::append(const Path &other) {
	this->mPath /= other.mPath;
	return *this;
}

Path &Path::append(const String &path) {
	this->mPath.append(path.toWString());
	return *this;
}

Path Path::rootName() const {
	Path tmpPath;
	tmpPath.mPath = this->mPath.root_name();
	return tmpPath;
}

Path Path::rootDirectory() const {
	Path tmpPath;
	tmpPath.mPath = this->mPath.root_directory();
	return tmpPath;
}

Path Path::rootPath() const {
	Path tmpPath;
	tmpPath.mPath = this->mPath.root_path();
	return tmpPath;
}

Path Path::parentPath() const {
	Path tmpPath;
	tmpPath.mPath = this->mPath.parent_path();
	return tmpPath;
}

Path Path::fileName() const {
	Path tmpPath;
	tmpPath.mPath = this->mPath.filename();
	return tmpPath;
}

Path Path::extension() const {
	Path tmpPath;
	tmpPath.mPath = this->mPath.extension();
	return tmpPath;
}

String Path::native() const { return String(this->mPath.native()); }

String Path::generic() const { return String(this->mPath.generic_string()); }

bool Path::isExist() const { return boost::filesystem::exists(this->mPath); }

bool Path::isAbsolute() const { return this->mPath.is_absolute(); }

bool Path::isRelative() const { return this->mPath.is_relative(); }

PathStatus Path::status() const {
	PathStatus tmpStatus;
	tmpStatus.mFileStatus = boost::filesystem::status(this->mPath);
	tmpStatus.mIsEmpty = this->mPath.empty();
	return tmpStatus;
}

Path Path::currentPath() {
	Path tmpPath;
	tmpPath.mPath = boost::filesystem::current_path();
	return tmpPath;
}

void Path::clear() { this->mPath.clear(); }

bool Path::empty() { return this->mPath.empty(); }

} // namespace Core