// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2018/3/4 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "RegExTraits.h"

// Core namespace
namespace Core {

	size_t RegExTraits::length(const Char *text) {
		size_t length = 0;
		while(text->toChar() != 0) {
			++text;
			++length;
		}
		return length;
	}

}