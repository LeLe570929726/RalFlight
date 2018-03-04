// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2018/3/4 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_STRING_REGEX_H
#define RALFLIGHT_SRC_CORE_STRING_REGEX_H

#include "../Global/Macro.h"
#include <regex>

// Core namespace
namespace Core {

	class RALFLIGHT_API RegEx {
	public:
		RegEx();
		~RegEx();

	private:
		std::basic_regex mRegEx;
	};

}

#endif			// RALFLIGHT_SRC_CORE_STRING_REGEX_H