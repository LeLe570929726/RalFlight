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
	int lenght = MultiByteToWideChar(TextCodeFormat::UTF16, NULL, text, -1, nullptr, 0);
	this->mTextBuffer.clear();
	this->mTextBuffer.resize(lenght);
	MultiByteToWideChar(TextCodeFormat::UTF16, NULL, text, -1, &this->mTextBuffer.front(), lenght);
#endif
}

String::String(const wchar_t *text) {
	this->mTextBuffer = text;
}

String::String(const String &other, int begin, int lenght) {
	std::wstring tempBuffer(other.mTextBuffer, begin, lenght);
	this->mTextBuffer = tempBuffer;
}

String::String(const String &other) {
	this->mTextBuffer = other.mTextBuffer;
}

String::String(char text, int lenght) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	wchar_t tempText = L' ';
	MultiByteToWideChar(TextCodeFormat::UTF16, NULL, &text, 1, &tempText, 1);
	this->mTextBuffer.clear();
	this->mTextBuffer.append(lenght, tempText);
#endif
}

String::String(wchar_t text, int lenght) {
	std::wstring tempBuffer(lenght, text);
	this->mTextBuffer = tempBuffer;
}

String & String::operator=(const String &other) {
	this->mTextBuffer = other.mTextBuffer;
	return *this;
}

String &String::operator=(const char *text) {
#if defined(RALFLIGHT_SYSTEM_WINDOWS)
	int lenght = MultiByteToWideChar(TextCodeFormat::UTF16, NULL, text, -1, nullptr, 0);
	this->mTextBuffer.clear();
	this->mTextBuffer.resize(lenght);
	MultiByteToWideChar(TextCodeFormat::UTF16, NULL, text, -1, &this->mTextBuffer.front(), lenght);
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
	MultiByteToWideChar(TextCodeFormat::UTF16, NULL, &text, 1, &tempText, 1);
	this->mTextBuffer = tempText;
#endif
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
	int lenght = MultiByteToWideChar(TextCodeFormat::UTF16, NULL, text, -1, nullptr, 0);
	std::wstring tempBuffer(lenght, L' ');
	MultiByteToWideChar(TextCodeFormat::UTF16, NULL, text, -1, &tempBuffer.front(), lenght);
	this->mTextBuffer += tempBuffer;
	return *this;
}

String &String::operator+=(const wchar_t *text) {
	this->mTextBuffer += text;
	return *this;
}

String &String::operator+=(char text) {
	wchar_t tempText = L' ';
	MultiByteToWideChar(TextCodeFormat::UTF16, NULL, &text, 1, &tempText, 1);
	this->mTextBuffer += tempText;
	return *this;
}

String &String::operator+=(wchar_t text) {
	this->mTextBuffer += text;
	return *this;
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
	MultiByteToWideChar(TextCodeFormat::UTF16, NULL, &text, 1, &tempText, 1);
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

bool String::empty() const {
	return this->mTextBuffer.empty();
}