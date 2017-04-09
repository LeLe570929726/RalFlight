// ----------------------------------------------------------------------------------------------------
// Copyright © 2016-2017 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/3/11 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "String.h"

String::String(const char *text) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	int lenght = MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, nullptr, 0);
	this->mTextBuffer.clear();
	this->mTextBuffer.resize(lenght);
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, &this->mTextBuffer.front(), lenght);
#endif
}

String::String(const wchar_t *text) {
	this->mTextBuffer = text;
}

String::String(const String &other, int begin, int lenght) {
	this->mTextBuffer.clear();
	this->mTextBuffer.append(other.mTextBuffer, begin, lenght);
}

String::String(const String &other) {
	this->mTextBuffer = other.mTextBuffer;
}

String::String(char text, int lenght) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	wchar_t tempText = L' ';
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, &text, 1, &tempText, 1);
	this->mTextBuffer.clear();
	this->mTextBuffer.append(lenght, tempText);
#endif
}

String::String(wchar_t text, int lenght) {
	this->mTextBuffer.clear();
	this->mTextBuffer.append(lenght, text);
}

String & String::operator=(const String &other) {
	this->mTextBuffer = other.mTextBuffer;
	return *this;
}

String String::operator+(char text) const {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	wchar_t tempText = L' ';
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, &text, 1, &tempText, 1);
	String tempString(*this);
	tempString += tempText;
#endif
	return tempString;
}

String String::operator+(wchar_t text) const {
	String tempString(*this);
	tempString += text;
	return tempString;
}

String String::operator+(const char *text) const {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	int lenght = MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, nullptr, 0);
	wchar_t *tempBuffer = reinterpret_cast<wchar_t *>(malloc(lenght * sizeof(wchar_t)));
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, tempBuffer, lenght);
	String tempString(*this);
	tempString += tempBuffer;
	free(tempBuffer);
#endif
	return tempString;
}

String String::operator+(const wchar_t *text) const {
	String tempString(*this);
	tempString += text;
	return tempString;
}

String String::operator+(const String & text) const {
	String tempString(*this);
	tempString += text;
	return tempString;
}

String &String::operator=(const char *text) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	int lenght = MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, nullptr, 0);
	this->mTextBuffer.clear();
	this->mTextBuffer.resize(lenght);
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, &this->mTextBuffer.front(), lenght);
#endif
	return *this;
}

String &String::operator=(const wchar_t *text) {
	this->mTextBuffer = text;
	return *this;
}

String &String::operator=(char text) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	wchar_t tempText = L' ';
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, &text, 1, &tempText, 1);
	this->mTextBuffer = tempText;
#endif
	return *this;
}

String &String::operator=(wchar_t text) {
	this->mTextBuffer = text;
	return *this;
}

wchar_t &String::operator[](int position) {
	return this->mTextBuffer[position];
}

const wchar_t &String::operator[](int position) const {
	return this->mTextBuffer[position];
}

String &String::operator+=(const String &other) {
	this->mTextBuffer += other.mTextBuffer;
	return *this;
}

String &String::operator+=(const char *text) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	int lenght = MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, nullptr, 0);
	wchar_t *tempBuffer = reinterpret_cast<wchar_t *>(malloc(lenght * sizeof(wchar_t)));
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, tempBuffer, lenght);
	this->mTextBuffer += tempBuffer;
	free(tempBuffer);
#endif
		return *this;
}

String &String::operator+=(const wchar_t *text) {
	this->mTextBuffer += text;
	return *this;
}

String &String::operator+=(char text) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	wchar_t tempText = L' ';
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, &text, 1, &tempText, 1);
	this->mTextBuffer += tempText;
#endif
	return *this;
}

String &String::operator+=(wchar_t text) {
	this->mTextBuffer += text;
	return *this;
}

bool String::operator==(const String &other) const {
	return this->mTextBuffer == other.mTextBuffer;
}

bool String::operator!=(const String &other) const {
	return this->mTextBuffer != other.mTextBuffer;
}

StringIterator String::begin() {
	StringIterator tempIterator(this->mTextBuffer.begin());
	return tempIterator;
}

StringConstIterator String::begin() const {
	StringConstIterator tempIteraotr(this->mTextBuffer.begin());
	return tempIteraotr;
}

StringIterator String::end() {
	StringIterator tempIterator(this->mTextBuffer.end());
	return tempIterator;
}

StringConstIterator String::end() const {
	StringConstIterator tempIterator(this->mTextBuffer.end());
	return tempIterator;
}

wchar_t &String::at(int position) {
	return this->mTextBuffer.at(position);
}

const wchar_t &String::at(int position) const {
	return this->mTextBuffer.at(position);
}

wchar_t &String::back() {
	return this->mTextBuffer.back();
}

const wchar_t &String::back() const {
	return this->mTextBuffer.back();
}

wchar_t &String::front() {
	return this->mTextBuffer.front();
}

const wchar_t &String::front() const {
	return this->mTextBuffer.front();
}

int String::lenght() const {
	return this->mTextBuffer.length();
}

int String::maxLenght() const {
	return this->mTextBuffer.max_size();
}

void String::resize(int size) {
	this->mTextBuffer.resize(size);
}

void String::resize(int size, char text) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	wchar_t tempText = L' ';
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, &text, 1, &tempText, 1);
	this->mTextBuffer.resize(size, tempText);
#endif
}

void String::resize(int size, wchar_t text) {
	this->mTextBuffer.resize(size, text);
}

int String::capacity() const {
	return this->mTextBuffer.capacity();
}

void String::reserve(int size) {
	this->mTextBuffer.reserve(size);
}

void String::clear() {
	this->mTextBuffer.clear();
}

bool String::isEmpty() const {
	return this->mTextBuffer.empty();
}

String &String::append(const String &other) {
	this->mTextBuffer.append(other.mTextBuffer);
	return *this;
}

String &String::append(const String &other, int begin, int lenght) {
	this->mTextBuffer.append(other.mTextBuffer, begin, lenght);
	return *this;
}

String &String::append(const char *text) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	int lenght = MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, nullptr, 0);
	wchar_t *tempBuffer = reinterpret_cast<wchar_t *>(malloc(lenght * sizeof(wchar_t)));
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, tempBuffer, lenght);
	this->mTextBuffer.append(tempBuffer);
	free(tempBuffer);
#endif
	return *this;
}

String &String::append(const wchar_t *text) {
	this->mTextBuffer.append(text);
	return *this;
}

String &String::append(char text, int lenght) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	wchar_t tempText = L' ';
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, &text, 1, &tempText, 1);
	this->mTextBuffer.append(lenght, tempText);
#endif
	return *this;
}

String &String::append(wchar_t text, int lenght) {
	this->mTextBuffer.append(lenght, text);
	return *this;
}

String &String::append(StringIterator begin, StringIterator end) {
	this->mTextBuffer.append(begin.get(), end.get());
	return *this;
}

String &String::assign(const String &other) {
	this->mTextBuffer.assign(other.mTextBuffer);
	return *this;
}

String &String::assign(const String &other, int begin, int lenght) {
	this->mTextBuffer.assign(other.mTextBuffer, begin, lenght);
	return *this;
}

String &String::assign(const char *text) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	int lenght = MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, nullptr, 0);
	wchar_t *tempBuffer = reinterpret_cast<wchar_t *>(malloc(lenght * sizeof(wchar_t)));
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, tempBuffer, lenght);
	this->mTextBuffer.assign(tempBuffer);
	free(tempBuffer);
#endif
	return *this;
}

String &String::assign(const wchar_t *text) {
	this->mTextBuffer.assign(text);
	return *this;
}

String &String::assign(char text, int lenght) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	wchar_t tempText = L' ';
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, &text, 1, &tempText, 1);
	this->mTextBuffer.assign(lenght, tempText);
#endif
	return *this;
}

String &String::assign(wchar_t text, int lenght) {
	this->mTextBuffer.assign(lenght, text);
	return *this;
}

String &String::assign(StringIterator begin, StringIterator end) {
	this->mTextBuffer.assign(begin.get(), end.get());
	return *this;
}

String &String::insert(const String &other, int position) {
	this->mTextBuffer.insert(position, other.mTextBuffer);
	return *this;
}

String &String::insert(const String &other, int begin, int position, int lenght) {
	this->mTextBuffer.insert(begin, other.mTextBuffer, position, lenght);
	return *this;
}

String &String::insert(const char *text, int position) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	int lenght = MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, nullptr, 0);
	wchar_t *tempBuffer = reinterpret_cast<wchar_t *>(malloc(lenght * sizeof(wchar_t)));
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, tempBuffer, lenght);
	this->mTextBuffer.insert(position, tempBuffer);
	free(tempBuffer);
#endif
	return *this;
}

String &String::insert(const wchar_t *text, int position) {
	this->mTextBuffer.insert(position, text);
	return *this;
}

String &String::insert(char text, int position) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	wchar_t tempText = L' ';
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, &text, 1, &tempText, 1);
	this->mTextBuffer.insert(position, 1, tempText);
#endif
	return *this;
}

String &String::insert(char text, StringIterator position) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	wchar_t tempText = L' ';
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, &text, 1, &tempText, 1);
	this->mTextBuffer.insert(position.get(), 1, tempText);
#endif
	return *this;
}

String &String::insert(wchar_t text, int position) {
	this->mTextBuffer.insert(position, 1, text);
	return *this;
}

String &String::insert(wchar_t text, StringIterator position) {
	this->mTextBuffer.insert(position.get(), 1, text);
	return *this;
}

String &String::insert(char text, int position, int lenght) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	wchar_t tempText = L' ';
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, &text, 1, &tempText, 1);
	this->mTextBuffer.insert(position, lenght, tempText);
#endif
	return *this;
}

String &String::insert(char text, StringIterator position, int lenght) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	wchar_t tempText = L' ';
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, &text, 1, &tempText, 1);
	this->mTextBuffer.insert(position.get(), lenght, tempText);
#endif
	return *this;
}

String &String::insert(wchar_t text, int position, int lenght) {
	this->mTextBuffer.insert(position, lenght, text);
	return *this;
}

String &String::insert(wchar_t text, StringIterator position, int lenght) {
	this->mTextBuffer.insert(position.get(), lenght, text);
	return *this;
}

String &String::insert(StringIterator position, StringIterator begin, StringIterator end) {
	this->mTextBuffer.insert(position.get(), begin.get(), end.get());
	return *this;
}

void String::pushBack(char text) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	wchar_t tempText = L' ';
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, &text, 1, &tempText, 1);
	this->mTextBuffer.push_back(tempText);
#endif
}

void String::pushBack(wchar_t text) {
	this->mTextBuffer.push_back(text);
}

String &String::remove(int position, int lenght) {
	this->mTextBuffer.erase(position, lenght);
	return *this;
}

StringIterator String::remove(StringIterator position) {
	StringIterator tempIterator(this->mTextBuffer.erase(position.get()));
	return tempIterator;
}

StringIterator String::remove(StringIterator begin, StringIterator end) {
	StringIterator tempIterator(this->mTextBuffer.erase(begin.get(), end.get()));
	return tempIterator;
}

String &String::replace(const String &other, int position, int lenght) {
	this->mTextBuffer.replace(position, lenght, other.mTextBuffer);
	return *this;
}

String &String::replace(const String &other, StringIterator begin, StringIterator end) {
	this->mTextBuffer.replace(begin.get(), end.get(), other.mTextBuffer);
	return *this;
}

String &String::replace(const String &other, int position, int lenght, int subPosition, int subLenght) {
	this->mTextBuffer.replace(position, lenght, other.mTextBuffer, subPosition, subLenght);
	return *this;
}

String &String::replace(const char *text, int position, int lenght) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	int tempLenght = MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, nullptr, 0);
	wchar_t *tempBuffer = reinterpret_cast<wchar_t *>(malloc(lenght * sizeof(wchar_t)));
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, tempBuffer, tempLenght);
	this->mTextBuffer.replace(position, lenght, tempBuffer);
	free(tempBuffer);
#endif
	return *this;
}

String &String::replace(const char *text, StringIterator begin, StringIterator end) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	int lenght = MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, nullptr, 0);
	wchar_t *tempBuffer = reinterpret_cast<wchar_t *>(malloc(lenght * sizeof(wchar_t)));
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, tempBuffer, lenght);
	this->mTextBuffer.replace(begin.get(), end.get(), tempBuffer);
	free(tempBuffer);
#endif
	return *this;
}

String &String::replace(const wchar_t *text, int position, int lenght) {
	this->mTextBuffer.replace(position, lenght, text);
	return *this;
}

String &String::replace(const wchar_t *text, StringIterator begin, StringIterator end) {
	this->mTextBuffer.replace(begin.get(), end.get(), text);
	return *this;
}

String &String::replace(char text, int position, int lenght, int subLenght) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	wchar_t tempText = L' ';
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, &text, 1, &tempText, 1);
	this->mTextBuffer.replace(position, lenght, subLenght, tempText);
#endif
	return *this;
}

String &String::replace(char text, StringIterator begin, StringIterator end, int subLenght) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	wchar_t tempText = L' ';
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, &text, 1, &tempText, 1);
	this->mTextBuffer.replace(begin.get(), end.get(), subLenght, tempText);
#endif
	return *this;
}

String &String::replace(wchar_t text, int position, int lenght, int subLenght) {
	this->mTextBuffer.replace(position, lenght, subLenght, text);
	return *this;
}

String &String::replace(wchar_t text, StringIterator begin, StringIterator end, int subLenght) {
	this->mTextBuffer.replace(begin.get(), end.get(), subLenght, text);
	return *this;
}

String &String::replace(StringIterator begin, StringIterator end, StringIterator subBegin, StringIterator subEnd) {
	this->mTextBuffer.replace(begin.get(), end.get(), subBegin.get(), subEnd.get());
	return *this;
}

std::string String::toStdString() const {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	int lenght = WideCharToMultiByte(TextCodeFormat::ANSI, NULL, this->mTextBuffer.c_str(), -1, nullptr, 0, nullptr, nullptr);
	std::string tempString(lenght, ' ');
	WideCharToMultiByte(TextCodeFormat::ANSI, NULL, this->mTextBuffer.c_str(), -1, &tempString.front(), 0, nullptr, nullptr);
#endif
	return tempString;
}

std::wstring String::toStdWString() const {
	return this->mTextBuffer;
}

std::string String::toUtf8() const {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	int lenght = WideCharToMultiByte(TextCodeFormat::ANSI, NULL, this->mTextBuffer.c_str(), -1, nullptr, 0, nullptr, nullptr);
	std::string tempString(lenght, ' ');
	WideCharToMultiByte(TextCodeFormat::ANSI, NULL, this->mTextBuffer.c_str(), -1, &tempString.front(), 0, nullptr, nullptr);
#endif
	return tempString;
}

std::string String::toLatin1() const {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	int lenght = WideCharToMultiByte(TextCodeFormat::Latin1, NULL, this->mTextBuffer.c_str(), -1, nullptr, 0, nullptr, nullptr);
	std::string tempString(lenght, ' ');
	WideCharToMultiByte(TextCodeFormat::Latin1, NULL, this->mTextBuffer.c_str(), -1, &tempString.front(), 0, nullptr, nullptr);
#endif
	return tempString;
}

std::wstring String::toUtf16() const {
	return this->mTextBuffer;
}

String String::fromStdString(const std::string &text) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	int lenght = MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text.c_str(), -1, nullptr, 0);
	wchar_t *tempBuffer = reinterpret_cast<wchar_t *>(malloc(lenght * sizeof(wchar_t)));
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text.c_str(), -1, tempBuffer, lenght);
	String tempString(tempBuffer);
#endif
	return tempString;
}

String String::fromStdWString(const std::wstring &text) {
	String tempString(text.c_str());
	return tempString;
}

String String::fromLatin1(const std::string &text) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	int lenght = MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text.c_str(), -1, nullptr, 0);
	wchar_t *tempBuffer = reinterpret_cast<wchar_t *>(malloc(lenght * sizeof(wchar_t)));
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text.c_str(), -1, tempBuffer, lenght);
	String tempString(tempBuffer);
#endif
	return tempString;
}

String String::fromLatin1(const char *text) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	int lenght = MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, nullptr, 0);
	wchar_t *tempBuffer = reinterpret_cast<wchar_t *>(malloc(lenght * sizeof(wchar_t)));
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, tempBuffer, lenght);
	String tempString(tempBuffer);
#endif
	return tempString;
}

String String::fromUtf8(const std::string &text) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	int lenght = MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text.c_str(), -1, nullptr, 0);
	wchar_t *tempBuffer = reinterpret_cast<wchar_t *>(malloc(lenght * sizeof(wchar_t)));
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text.c_str(), -1, tempBuffer, lenght);
	String tempString(tempBuffer);
#endif
	return tempString;
}

String String::fromUtf8(const char *text) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	int lenght = MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, nullptr, 0);
	wchar_t *tempBuffer = reinterpret_cast<wchar_t *>(malloc(lenght * sizeof(wchar_t)));
	MultiByteToWideChar(TextCodeFormat::ANSI, NULL, text, -1, tempBuffer, lenght);
	String tempString(tempBuffer);
#endif
	return tempString;
}

String String::fromUtf16(const std::wstring &text) {
	String tempString(text.c_str());
	return tempString;
}

String String::fromUtf16(const wchar_t *text) {
	String tempString(text);
	return tempString;
}