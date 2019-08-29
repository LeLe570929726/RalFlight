// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2019/08/26 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#include "Date.h"
#ifdef RF_OS_WIN
#include <Windows.h>
#endif

namespace Core {

Date::Date() : mCE(CommonEra::AD), mYear(1970), mMonth(1), mDay(1), mHour(0), mMinute(0), mSecond(0) {}

bool Date::operator==(const Date &other) const {
	if (this->mCE == other.mCE && this->mYear == other.mYear && this->mMonth == other.mMonth && this->mDay == other.mDay &&
		this->mHour == other.mHour && this->mMinute == other.mMinute && this->mSecond == other.mSecond) {
		return true;
	} else {
		return false;
	}
}

bool Date::operator!=(const Date &other) const { return !(*this == other); }

bool Date::isLeapYear() const {
	uint16 tmpYear = 0;
	if (this->mCE == CommonEra::AD) {
		tmpYear = this->mYear;
	} else {
		tmpYear = this->mYear - 1;
	}
	if ((tmpYear % 4 == 0 && tmpYear % 100 != 0) || (tmpYear % 400 == 0 && tmpYear % 3200 != 0) || tmpYear == 0) {
		return true;
	} else {
		return false;
	}
}

CommonEra Date::ce() const { return this->mCE; }

uint16 Date::year() const { return this->mYear; }

uint8 Date::month() const { return this->mMonth; }

uint8 Date::day() const { return this->mDay; }

uint8 Date::hour() const { return this->mHour; }

uint8 Date::minute() const { return this->mMinute; }

uint8 Date::second() const { return this->mSecond; }

void Date::setCE(CommonEra ce) { this->mCE = ce; }

Date::ErrorCode Date::setYear(uint16 year) {
	if (year == 0) {
		return ErrorCode::YearOutOfRange;
	} else {
		this->mYear = year;
		return ErrorCode::Success;
	}
}

Date::ErrorCode Date::setMonth(uint8 month) {
	if (month > 12 || month == 0) {
		return ErrorCode::MonthOutOfRange;
	} else {
		this->mMonth = month;
		return ErrorCode::Success;
	}
}

Date::ErrorCode Date::setDay(uint8 day) {
	if (day > 31 || day == 0) {
		return ErrorCode::DayOutOfRange;
	} else if ((this->mMonth == 4 || this->mMonth == 6 || this->mMonth == 9 || this->mMonth == 11) && day > 30) {
		return ErrorCode::DayOutOfRange;
	} else {
		if (this->isLeapYear() == true) {
			if (this->mMonth == 2 && day > 29) {
				return ErrorCode::DayOutOfRange;
			}
		} else {
			if (this->mMonth == 2 && day > 28) {
				return ErrorCode::DayOutOfRange;
			}
		}
		this->mDay = day;
		return ErrorCode::Success;
	}
}

Date::ErrorCode Date::setHour(uint8 hour) {
	if (hour > 23) {
		return ErrorCode::HourOutOfRange;
	} else {
		this->mHour = hour;
		return ErrorCode::Success;
	}
}

Date::ErrorCode Date::setMinute(uint8 minute) {
	if (minute > 59) {
		return ErrorCode::MinuteOutOfRange;
	} else {
		this->mMinute = minute;
		return ErrorCode::Success;
	}
}

Date::ErrorCode Date::setSecond(uint8 second) {
	if (second > 59) {
		return ErrorCode::SecondOutOfRange;
	} else {
		this->mSecond = second;
		return ErrorCode::Success;
	}
}

Date Date::fromLocal() {
	Date tmpDate;
#ifdef RF_OS_WIN
	SYSTEMTIME systemTime;
	GetLocalTime(&systemTime);
	tmpDate.mCE = CommonEra::AD;
	tmpDate.mYear = systemTime.wYear;
	tmpDate.mMonth = systemTime.wMonth;
	tmpDate.mDay = systemTime.wDay;
	tmpDate.mHour = systemTime.wHour;
	tmpDate.mMinute = systemTime.wMinute;
	tmpDate.mSecond = systemTime.wSecond;
#endif
	return tmpDate;
}

} // namespace Core
