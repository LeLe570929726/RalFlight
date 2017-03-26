// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/1/17 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#ifndef RALFLIGHT_SRC_CORE_PLUGIN_LIBRARYLOADER_H
#define RALFLIGHT_SRC_CORE_PLUGIN_LIBRARYLOADER_H

#include "../../Global/Macro/Macro.h"
#include "../../Global/FunctionPointer/FunctionPointer.h"
#include "../../STD/String/String.h"
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
    #include <Windows.h>
#endif

class RALFLIGHT_API LibraryLoader {
public:
    LibraryLoader();
	LibraryLoader(const String &fileName);
    LibraryLoader(const LibraryLoader &other);
    LibraryLoader &operator=(const LibraryLoader &other);
    ~LibraryLoader();

public:
    bool setFileName(const String &fileName);
    String getFileName();
    
public:
    bool load();
    bool unload();
    bool isLoaded();

public:
	FunctionPointer reslove(const String &functionName);

private:
    int *mCount;
    String mFileName;
    bool mIsLoad;
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
    HMODULE mHandle;
#endif
};

#endif          // RALFLIGHT_SRC_CORE_PLUGIN_LIBRARYLOADER_H