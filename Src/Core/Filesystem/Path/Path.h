// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/4/28 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_FILESYSTEM_PATH_H
#define RALFLIGHT_SRC_CORE_FILESYSTEM_PATH_H

#include "../../Global/Macro/Macro.h"
#include "../../STD/String/String.h"

// Core namespace
namespace Core {

	class RALFLIGHT_API Path {
	public:
		Path();
		Path(const Path &other);
		Path &operator=(const Path &other);
		~Path() = default;

	public:
		bool operator==(const Path &other);
		bool operator==(const String &path);
		bool operator!=(const Path &other);
		bool operator!=(const String &path);

	public:
		static Path fromLocal(String local);
		static Path fromCommon(String common);

	private:
		static String localToCommon(String local);
		static String commonToLocal(String common);

	private:
		String mPath;
	};

}

#endif				// RALFLIGHT_SRC_CORE_FILESYSTEM_PATH_H