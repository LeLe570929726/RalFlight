// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/4/28 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Path.h"

namespace Core {

	Path::Path() : 
		mPath(L"") {
	}

	Path::Path(const Path &other) :
		mPath(other.mPath) {
	}

	Path &Path::operator=(const Path &other) {
		this->mPath = other.mPath;
		return *this;
	}

	bool Path::operator==(const Path &other) {
		return this->mPath == other.mPath;
	}

	bool Path::operator==(const String &path) {
		return this->mPath == path;
	}

	bool Path::operator!=(const Path &other) {
		return this->mPath != other.mPath;
	}

	bool Path::operator!=(const String &path) {
		return this->mPath != path;
	}

	Path Path::fromLocal(String local) {

	}

	Path Path::fromCommon(String local) {

	}

	String Path::localToCommon(String local) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		
#endif
	}

	String Path::commonToLocal(String common) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)

#endif
	}

}