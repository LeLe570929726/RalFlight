// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Create: 2018/6/23 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Container/LockFreeQueue.h"
#include "../Global/Token.h"
#include "../String/String.h"
#include "StackTracer.h"

namespace Core {

enum class LogLevel { Error, Warning, Text };

class RF_API Log {
public:
	static bool initialize();
	static void log();

private:
	Log() = default;
	~Log() = default;

private:
	struct LogItem {
		String mLogContent;
		LogLevel mLogLevel;
	};

private:
	static Log mLog;

private:
	LockFreeQueue<LogItem> mLogQueue;
};

} // namespace Core