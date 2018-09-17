// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/08/25 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Container/Vector.h"
#include "../Global/Token.h"
#include "../Math/Scalar.h"
#include "../String/String.h"

namespace Core {

class RF_API StackTracer {
public:
	StackTracer();
	StackTracer(const StackTracer &other) = delete;
	StackTracer(StackTracer &&other) = delete;
	StackTracer &operator=(const StackTracer &other) = delete;
	StackTracer &operator=(StackTracer &&other) = delete;
	~StackTracer() = default;

public:
	String name(uint64 position) const;
	String file(uint64 position) const;
	uint64 line(uint64 position) const;
	uint64 address(uint64 position) const;
	String formatOut() const;

public:
	uint64 length() const { return this->mFrameList.length(); }
	bool empty() const { return this->mFrameList.empty(); };

private:
	struct StackFrame {
		String mName;
		String mFile;
		uint64 mLine;
		uint64 mAddress;
	};

private:
	Vector<StackFrame> mFrameList;
};

} // namespace Core