// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2018/7/13 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"
#include "../Math/Scalar.h"
#include "Char.h"
#include "CharReference.h"
#include "Convertor.h"
#include "StringIterator.h"
#include <string>

namespace Core {

enum class CaseSensitive { Sensitive, Insensitive };

enum class CaseFind { All, First, Last, Index };

class RF_API String {
public:
	String() = default;
	String(const char *text, const std::string &charset = Charset::Utf8);
	String(const std::string &text, const std::string &charset = Charset::Utf8);
	String(const wchar_t *text);
	String(const std::wstring &text);
	String(const Char &ch, uint64 number = 1);
	String(const String &other) = default;
	String(String &&other) noexcept;
	String &operator=(const String &other) = default;
	String &operator=(String &&other) noexcept;
	~String() = default;

public:
	bool operator==(const String &other) const { return this->mBuffer == other.mBuffer; }
	bool operator!=(const String &other) const { return this->mBuffer != other.mBuffer; }
	bool operator<(const String &other) const { return this->mBuffer < other.mBuffer; }
	bool operator<=(const String &other) const { return this->mBuffer <= other.mBuffer; }
	bool operator>(const String &other) const { return this->mBuffer > other.mBuffer; }
	bool operator>=(const String &other) const { return this->mBuffer >= other.mBuffer; }
	CharReference operator[](uint64 position);
	Char operator[](uint64 position) const;

public:
	StringIterator begin();
	StringIterator end();

public:
	CharReference at(uint64 position);
	Char at(uint64 position) const;
	CharReference front() { return CharReference(&this->mBuffer.front()); }
	Char front() const { return Char(this->mBuffer.front()); }
	CharReference back() { return CharReference(&this->mBuffer.back()); }
	Char back() const { return Char(this->mBuffer.back()); }

public:
	String &append(const String &other);
	String &insert(uint64 position, const String &text);
	String &remove(uint64 position, uint64 number = 1);
	String &remove(const String &other, CaseFind cf = CaseFind::All, int64 index = 0);
	String &replace(const String &other, uint64 position, uint64 number = 1);
	String &replace(const String &search, const String &text, CaseFind cf = CaseFind::All, uint64 index = 0);
	void resize(uint64 size) { this->mBuffer.resize(size); }
	void resize(const Char &ch, uint64 size) { this->mBuffer.resize(size, ch.toWChar()); }

public:
	bool contains(const String &other, CaseSensitive cs = CaseSensitive::Sensitive) const;

public:
	uint64 capacity() const { return this->mBuffer.capacity(); }
	void reserve(uint64 size) { this->mBuffer.reserve(size); }
	uint64 length() const { return this->mBuffer.length(); }
	bool isEmpty() const { return this->mBuffer.empty(); }
	void clear() { this->mBuffer.clear(); }

private:
	std::wstring mBuffer;
};

} // namespace Core