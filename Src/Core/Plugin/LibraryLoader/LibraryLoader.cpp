// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/1/17 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "LibraryLoader.h"

LibraryLoader::LibraryLoader() :
     mCount(nullptr), mFileName(), mIsLoad(false), mHandle() {
}

LibraryLoader::LibraryLoader(const String &fileName) :
	mCount(nullptr), mFileName(fileName), mIsLoad(false), mHandle() {
}

LibraryLoader::LibraryLoader(const LibraryLoader &other) {
	if (other.mIsLoad == true) {
		this->mCount = other.mCount;
		this->mFileName = other.mFileName;
		this->mHandle = other.mHandle;
		this->mIsLoad = true;
		++*this->mCount;
	} else {
		this->mCount = nullptr;
		this->mFileName = other.mFileName;
		this->mHandle = NULL;
		this->mIsLoad = false;
	}
}

LibraryLoader &LibraryLoader::operator=(const LibraryLoader &other) {
	if (other.mIsLoad == true) {
		this->mCount = other.mCount;
		this->mFileName = other.mFileName;
		this->mHandle = other.mHandle;
		this->mIsLoad = true;
		++*this->mCount;
	} else {
		this->mCount = nullptr;
		this->mFileName = other.mFileName;
		this->mHandle = NULL;
		this->mIsLoad = false;
	}
	return *this;
}

LibraryLoader::~LibraryLoader() {
	if (this->mIsLoad == true) {
		this->unload();
	}
}

bool LibraryLoader::setFileName(const String &fileName) {
	if (this->mIsLoad == false) {
		this->mFileName = fileName;
		return true;
	} else {
		return false;
	}
}

String LibraryLoader::getFileName() {
	return this->mFileName;
}

bool LibraryLoader::load() {
	if (this->mIsLoad == false) {
		if (this->mFileName.isEmpty() == false) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
			HMODULE tempHandle;// = LoadLibraryW(this->mFileName.c_str());
			if (tempHandle != NULL) {
				this->mHandle = tempHandle;
				this->mCount = new int(1);
				this->mIsLoad = true;
				return true;
			} else {
				return false;
			}
#elif defined(RALFLIGHT_SYSTEM_LINUX)
#elif defined(RALFLIGHT_SYSTEM_MAC)
#endif
		} else {
			return false;
		}
	} else {
		return false;
	}
}

bool LibraryLoader::unload() {
	if (this->mIsLoad == true) {
		--*this->mCount;
		if (*this->mCount == 0) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
			FreeLibrary(this->mHandle);
			this->mHandle = NULL;
			delete this->mCount;
			this->mCount = nullptr;
			this->mIsLoad = false;
#elif defined(RALFLIGHT_SYSTEM_LINUX)
#elif defined(RALFLIGHT_SYSTEM_MAC)
#endif
		}
		return true;
	} else {
		return false;
	}
}

bool LibraryLoader::isLoaded() {
	return this->mIsLoad;
}

FunctionPointer LibraryLoader::reslove(const String &functionName) {
	if (this->mIsLoad == true) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
		FARPROC tempPointer = GetProcAddress(this->mHandle, functionName.toLatin1().c_str());
		if (tempPointer != NULL) {
			return reinterpret_cast<FunctionPointer>(tempPointer);
		} else {
			return nullptr;
		}
#elif defined(RALFLIGHT_SYSTEM_LINUX)
#elif defined(RALFLIGHT_SYSTEM_MAC)
#endif
	} else {
		return nullptr;
	}
}