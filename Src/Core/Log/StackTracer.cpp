// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/08/25 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "StackTracer.h"
#include <cassert>
#include <boost/stacktrace.hpp>

namespace Core {

StackTracer::StackTracer() {
	auto stObj = boost::stacktrace::stacktrace();
	this->mFrameList.reserve(stObj.size());
	for (auto &frame : stObj) {
		StackFrame tmpSF;
		tmpSF.mName = String(frame.name());
		tmpSF.mFile = String(frame.source_file());
		tmpSF.mLine = static_cast<uint64>(frame.source_line());
		tmpSF.mAddress = reinterpret_cast<uint64>(frame.address());
		this->mFrameList.append(tmpSF);
	}
}

String StackTracer::name(uint64 position) const {
	assert(position < this->mFrameList.length());
	return this->mFrameList.at(position).mName;
}

String StackTracer::file(uint64 position) const {
	assert(position < this->mFrameList.length());
	return this->mFrameList.at(position).mFile;
}

uint64 StackTracer::line(uint64 position) const {
	assert(position < this->mFrameList.length());
	return this->mFrameList.at(position).mLine;
}

uint64 StackTracer::address(uint64 position) const {
	assert(position < this->mFrameList.length());
	return this->mFrameList.at(position).mAddress;
}

String StackTracer::formatOut() const {
	String tmpStr;
	for(auto &frame : this->mFrameList) {
		// TODO: StackTrace output format.
	}
	return tmpStr;
}

} // namespace Core