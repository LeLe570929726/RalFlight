// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/1/19 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_PLUGIN_PLUGINLOADER_H
#define RALFLIGHT_SRC_CORE_PLUGIN_PLUGINLOADER_H

#include "../../Global/Macro/Macro.h"
#include "../LibraryLoader/LibraryLoader.h"
#include "../../Global/FunctionPointer/FunctionPointer.h"
#include "../../STD/String/String.h"

class RALFLIGHT_API PluginLoader {
public:
    PluginLoader();
    ~PluginLoader();
};

#endif          // RALFLIGHT_SRC_CORE_PLUGIN_PLUGINLOADER_H