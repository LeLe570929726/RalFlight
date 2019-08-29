// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2019/01/31 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"
#include "../Math/Scalar.h"
#include "DirectoryStatus.h"
#include "Path.h"
#include <boost/filesystem.hpp>

namespace Core {
class RF_API Directory : public Path {
public:
	Directory() = default;
	Directory(const Path &path);
	Directory(const Directory &other) = default;
	Directory(Directory &&other) noexcept = default;
	Directory &operator=(const Directory &other) = default;
	Directory &operator=(Directory &&other) noexcept = default;
	~Directory() = default;

public:
	enum ErrorCode {
		Success,
		Failed, 
		DirectoryAlreadyExist,
		DirectoryDoesNotEsist
	};

public:
	ErrorCode mkdir() const;
	ErrorCode rmdir() const;

public:
	DirectoryStatus status() const;
};

} // namespace Core
