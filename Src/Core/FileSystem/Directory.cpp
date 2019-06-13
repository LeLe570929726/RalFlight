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

namespace Core {

Directory::Directory(const Path &path) : mDirectory(path.mPath) {}

bool Directory::operator==(const Directory &other) { return this->mDirectory == other.mDirectory; }

bool Directory::operator!=(const Directory &other) { return this->mDirectory != other.mDirectory; }

bool Directory::operator<(const Directory &other) { return this->mDirectory < other.mDirectory; }

bool Directory::operator<=(const Directory &other) { return this->mDirectory <= other.mDirectory; }

bool Directory::operator>(const Directory &other) { return this->mDirectory > other.mDirectory; }

bool Directory::operator>=(const Directory &other) { return this->mDirectory >= other.mDirectory; }

void Directory::replaceFileName(const Path &path) { this->mDirectory.replace_filename(path.mPath); }

} // namespace Core