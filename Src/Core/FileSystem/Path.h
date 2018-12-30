// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/6/30 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "PathStatus.h"
#include "../Global/Token.h"
#include "../String/String.h"
#include <boost/filesystem.hpp>

namespace Core {

class RF_API Path {
public:
	Path() = default;
	Path(const String &path);
	Path(const Path &other) = default;
	Path(Path &&other) noexcept = default;
	Path &operator=(const String &path);
	Path &operator=(const Path &other) = default;
	Path &operator=(Path &&other) noexcept = default;
	~Path() = default;

public:
	Path &operator/=(const Path &other);
	Path &operator/=(const String &path);
	Path &operator+=(const Path &other);
	Path &operator+=(const String &path);
	bool operator==(const Path &other) const;
	bool operator==(const String &path) const;

public:
	Path &append(const Path &other);
	Path &append(const String &path);

public:
	Path rootName() const;
	Path rootDirectory() const;
	Path rootPath() const;
	Path parentPath() const;
	Path fileName() const;
	Path extension() const;

public:
	String native() const;
	String generic() const;

public:
	bool isExist() const;
	bool isAbsolute() const;
	bool isRelative() const;
	PathStatus status() const;

public:
	static Path currentPath();

public:
	void clear();
	bool empty();

private:
	boost::filesystem::wpath mPath;
};

} // namespace Core