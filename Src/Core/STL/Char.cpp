// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2018 LeLe570929726. All rights reserved.
// 
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator.
//
// @Craete: 2018/2/14 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Char.h"

// Core namespace
namespace Core {

	Char::Char(char text) {
		std::string tmpBuf8(text, 1);
		std::u16string tmpBuf16;
		StringEncode::convertToUTF16(tmpBuf8, tmpBuf16, CodePage::Latin1);
		this->mChar = tmpBuf16[0];
	}

	Char::Char(wchar_t text) {
#ifdef RALFLIGHT_SYSTEM_WINDOWS
		this->mChar = static_cast<char16_t>(text);
#elif defined(RALFLIGHT_SYSTEM_LINUX)
		std::wstring tmpBufW(text, 1);
		std::string tmpBuf8;
		std::u16string tmpBuf16;
		StringEncode::convertFromWString(tmpBufW, tmpBuf8, CodePage::UTF8);
		StringEncode::convertToUTF16(tmpBuf8, tmpBuf16, CodePage::UTF8);
		this->mChar = tmpBuf16[0];
#endif
	}

	Char::Char(char16_t text) {
		this->mChar = text;
	}

	Char::Char(char32_t text) {
		std::u32string tmpBuf32(text, 1);
		std::string tmpBuf8;
		std::u16string tmpBuf16;
		StringEncode::convertFromUCS4(tmpBuf32, tmpBuf8, CodePage::UTF8);
		StringEncode::convertToUTF16(tmpBuf8, tmpBuf16, CodePage::UTF8);
		this->mChar = tmpBuf16[0];
	}

	bool Char::operator==(const Char &other) const {
		return this->mChar == other.mChar;
	}

	bool Char::operator!=(const Char &other) const {
		return this->mChar != other.mChar;
	}

	bool Char::operator>(const Char &other) const {
		return this->mChar > other.mChar;
	}

	bool Char::operator>=(const Char &other) const {
		return this->mChar >= other.mChar;
	}

	bool Char::operator<(const Char &other) const {
		return this->mChar < other.mChar;
	}

	bool Char::operator<=(const Char &other) const {
		return this->mChar <= other.mChar;
	}

	char Char::toChar() const {
		std::u16string tmpBuf16(this->mChar, 1);
		std::string tmpBuf8;
		StringEncode::convertFromUTF16(tmpBuf16, tmpBuf8, CodePage::Latin1);
		return tmpBuf8[0];
	}

	wchar_t Char::toWChar() const {
		std::u16string tmpBuf16(this->mChar, 1);
		std::string tmpBuf8;
		std::wstring tmpBufW;
		StringEncode::convertFromUTF16(tmpBuf16, tmpBuf8, CodePage::UTF8);
		StringEncode::convertToWString(tmpBuf8, tmpBufW, CodePage::UTF8);
		return tmpBufW[0];
	}

	char16_t Char::toUTF16() const {
		return this->mChar;
	}
	
	char32_t Char::toUCS4() const {
		std::u16string tmpBuf16(this->mChar, 1);
		std::string tmpBuf8;
		std::u32string tmpBuf32;
		StringEncode::convertFromUTF16(tmpBuf16, tmpBuf8, CodePage::UTF8);
		StringEncode::convertToUCS4(tmpBuf8, tmpBuf32, CodePage::UTF8);
		return tmpBuf32[0];
	}

}