// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2017/3/11 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "String.h"

// Core namespace
namespace Core {

	String::String(const Char *text) :
		mTextBuffer(text) {
	}

	String::String(const String &other, int begin, int lenght) :
		mTextBuffer(other.mTextBuffer, begin, lenght) {
	}

	String::String(Char text, int lenght) {
		this->mTextBuffer.append(lenght, text.toUTF16());
	}

	String::String(const String &other) {
		this->mTextBuffer = other.mTextBuffer;
	}

	String::String(String &&other) {
		this->mTextBuffer = std::forward<StringBufferType>(other.mTextBuffer);
	}

	String &String::operator=(const String &other) {
		this->mTextBuffer = other.mTextBuffer;
		return *this;
	}

	String &String::operator=(String &&other) {
		this->mTextBuffer = std::forward<StringBufferType>(other.mTextBuffer);
		return *this;
	}

	String String::operator+(Char text) const {
		String tmpString(*this);
		tmpString.mTextBuffer += text;
		return tmpString;
	}

	String String::operator+(const Char *text) const {
		String tmpString(*this);
		tmpString.mTextBuffer += text;
		return tmpString;
	}

	String String::operator+(const String &text) const {
		String tmpString(*this);
		tmpString.mTextBuffer += text.mTextBuffer;
		return tmpString;
	}

	String &String::operator=(const Char *text) {
		this->mTextBuffer = text;
		return *this;
	}

	String &String::operator=(Char text) {
		this->mTextBuffer = text;
		return *this;
	}

	Char &String::operator[](int position) {
		return this->mTextBuffer[position];
	}

	const Char &String::operator[](int position) const {
		return this->mTextBuffer[position];
	}

	String &String::operator+=(const String &other) {
		this->mTextBuffer += other.mTextBuffer;
		return *this;
	}

	String &String::operator+=(const Char *text) {
		this->mTextBuffer += text;
		return *this;
	}

	String &String::operator+=(Char text) {
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

	StringConstIterator String::cbegin() const {
		StringConstIterator tempIteraotr(this->mTextBuffer.begin());
		return tempIteraotr;
	}

	StringIterator String::end() {
		StringIterator tempIterator(this->mTextBuffer.end());
		return tempIterator;
	}

	StringConstIterator String::cend() const {
		StringConstIterator tempIterator(this->mTextBuffer.end());
		return tempIterator;
	}

	Char &String::at(int position) {
		return this->mTextBuffer.at(position);
	}

	const Char &String::at(int position) const {
		return this->mTextBuffer.at(position);
	}

	Char &String::back() {
		return this->mTextBuffer.back();
	}

	const Char &String::back() const {
		return this->mTextBuffer.back();
	}

	Char &String::front() {
		return this->mTextBuffer.front();
	}

	const Char &String::front() const {
		return this->mTextBuffer.front();
	}

	size_t String::lenght() const {
		return this->mTextBuffer.length();
	}

	size_t String::maxLenght() const {
		return this->mTextBuffer.max_size();
	}

	void String::resize(size_t size) {
		this->mTextBuffer.resize(size);
	}

	void String::resize(size_t size, Char text) {
		this->mTextBuffer.resize(size, text);
	}

	size_t String::capacity() const {
		return this->mTextBuffer.capacity();
	}

	void String::reserve(size_t size) {
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

	String &String::append(const Char *text) {
		this->mTextBuffer.append(text);
		return *this;
	}

	String &String::append(Char text, int lenght) {
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

	String &String::assign(const Char *text) {
		this->mTextBuffer.assign(text);
		return *this;
	}

	String &String::assign(Char text, int lenght) {
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

	String &String::insert(const Char *text, int position) {
		this->mTextBuffer.insert(position, text);
		return *this;
	}

	String &String::insert(Char text, int position) {
		this->mTextBuffer.insert(position, 1, text);
		return *this;
	}

	String &String::insert(Char text, StringIterator position) {
		this->mTextBuffer.insert(position.get(), 1, text);
		return *this;
	}

	String &String::insert(Char text, int position, int lenght) {
		this->mTextBuffer.insert(position, lenght, text);
		return *this;
	}

	String &String::insert(Char text, StringIterator position, int lenght) {
		this->mTextBuffer.insert(position.get(), lenght, text);
		return *this;
	}

	String &String::insert(StringIterator position, StringIterator begin, StringIterator end) {
		this->mTextBuffer.insert(position.get(), begin.get(), end.get());
		return *this;
	}

	void String::pushBack(Char text) {
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

	String &String::replace(const Char *text, int position, int lenght) {
		this->mTextBuffer.replace(position, lenght, text);
		return *this;
	}

	String &String::replace(const Char *text, StringIterator begin, StringIterator end) {
		this->mTextBuffer.replace(begin.get(), end.get(), text);
		return *this;
	}

	String &String::replace(Char text, int position, int lenght, int subLenght) {
		this->mTextBuffer.replace(position, lenght, subLenght, text);
		return *this;
	}

	String &String::replace(Char text, StringIterator begin, StringIterator end, int subLenght) {
		this->mTextBuffer.replace(begin.get(), end.get(), subLenght, text);
		return *this;
	}

	String &String::replace(StringIterator begin, StringIterator end, StringIterator subBegin, StringIterator subEnd) {
		this->mTextBuffer.replace(begin.get(), end.get(), subBegin.get(), subEnd.get());
		return *this;
	}

	std::string String::toStdString() const {
		return this->toUTF8();
	}

	std::wstring String::toStdWString() const {
		std::string tmpBuf8;
		std::wstring tmpBufString;
		StringEncode::convertFromUTF16(this->toUTF16(), tmpBuf8, CodePage::UTF8);
		StringEncode::convertToWString(tmpBuf8, tmpBufString, CodePage::UTF8);
		return tmpBufString;
	}

	std::u16string String::toStdU16String() const {
		return this->toUTF16();
	}

	std::u32string String::toStdU32String() const {
		return this->toUCS4();
	}

	std::string String::toUTF8() const {
		std::string tmpBuf;
		StringEncode::convertFromUTF16(this->toUTF16(), tmpBuf, CodePage::UTF8);
		return tmpBuf;
	}

	std::string String::toLatin1() const {
		std::string tmpBuf;
		StringEncode::convertFromUTF16(this->toUTF16(), tmpBuf, CodePage::Latin1);
		return tmpBuf;
	}

	std::u16string String::toUTF16() const {
		std::u16string tmpBuf;
		for(auto itr = this->cbegin(); itr != this->cend(); ++itr) {
			tmpBuf.append((*itr).toUTF16(), 1);
		}
		return tmpBuf;
	}

	std::u32string String::toUCS4() const {
		std::string tmpBuf8;
		std::u32string tmpBuf32;
		StringEncode::convertFromUTF16(this->toUTF16(), tmpBuf8, CodePage::UTF8);
		StringEncode::convertToUCS4(tmpBuf8, tmpBuf32, CodePage::UTF8);
		return tmpBuf32;
	}

	String String::fromStdString(const std::string &text) {
		return String::fromUTF8(text);
	}

	String String::fromStdU16String(const std::u16string &text) {
		return String::fromUTF16(text);
	}

	String String::fromStdU32String(const std::u32string &text) {
		return String::fromUCS4(text);
	}

	String String::fromLatin1(const std::string &text) {
		String tmpString;
		std::u16string tmpBuf16;
		StringEncode::convertToUTF16(text, tmpBuf16, CodePage::Latin1);
		tmpString.reserve(tmpBuf16.size());
		for(auto itr = tmpBuf16.begin(); itr != tmpBuf16.end(); ++itr) {
			tmpString.append(*itr, 1);
		}
		return tmpString;
	}

	String String::fromLatin1(const char *text) {
		std::string tmpBuf(text);
		return String::fromLatin1(tmpBuf);
	}

	String String::fromUTF8(const std::string &text) {
		String tmpString;
		std::u16string tmpBuf16;
		StringEncode::convertToUTF16(text, tmpBuf16, CodePage::UTF8);
		tmpString.reserve(tmpBuf16.size());
		for(auto itr = tmpBuf16.begin(); itr != tmpBuf16.end(); ++itr) {
			tmpString.append(*itr, 1);
		}
		return tmpString;
	}
	
	String String::fromUTF8(const char *text) {
		std::string tmpBuf(text);
		return String::fromUTF8(tmpBuf);
	}
	
	String String::fromUTF16(const std::u16string &text) {
		String tmpString;
		tmpString.reserve(text.size());
		for(auto itr = text.begin(); itr != text.end(); ++itr) {
			tmpString.append(*itr, 1);
		}
		return tmpString;
	}
	
	String String::fromUTF16(const char16_t *text) {
		std::u16string tmpBuf(text);
		return String::fromUTF16(tmpBuf);
	}

	String String::fromUCS4(const std::u32string &text) {
		String tmpString;
		std::string tmpBuf8;
		std::u16string tmpBuf16;
		StringEncode::convertFromUCS4(text, tmpBuf8, CodePage::UTF8);
		StringEncode::convertToUTF16(tmpBuf8, tmpBuf16, CodePage::UTF8);
		tmpString.reserve(tmpBuf16.size());
		for(auto itr = tmpBuf16.begin(); itr != tmpBuf16.end(); ++itr) {
			tmpString.append(*itr, 1);
		}
		return tmpString;
	}

	String String::fromUCS4(const char32_t *text) {
		std::u32string tmpBuf(text);
		return String::fromUCS4(tmpBuf);
	}

}