// ----------------------------------------------------------------------------------------------------
// Copyright © 2016 - 2019 LeLe570929726. All rights reserved.
//
// @Project: RalFlight
// @License: Licensed under GNU General Public License v3.
// @Description: A free and open-source flight simulator which is based on Qt.
//
// @Create: 2019/08/26 by LeLe570929726
// ----------------------------------------------------------------------------------------------------
#pragma once

#include "../Global/Token.h"
#include "../Math/Scalar.h"

enum CommonEra { BC, AD };

namespace Core {

class RF_API Date {
public:
	Date();
	Date(const Date &other) = default;
	Date(Date &&other) noexcept = default;
	Date &operator=(const Date &other) = default;
	Date &operator=(Date &&other) noexcept = default;
	~Date() = default;

public:
	enum ErrorCode {
		Success,
		YearOutOfRange,
		MonthOutOfRange,
		DayOutOfRange,
		HourOutOfRange,
		MinuteOutOfRange,
		SecondOutOfRange
	};

public:
	bool operator==(const Date &other) const;
	bool operator!=(const Date &other) const;

public:
	bool isLeapYear() const;

public:
	CommonEra ce() const;
	uint16 year() const;
	uint8 month() const;
	uint8 day() const;
	uint8 hour() const;
	uint8 minute() const;
	uint8 second() const;
	void setCE(CommonEra ce);
	ErrorCode setYear(uint16 year);
	ErrorCode setMonth(uint8 month);
	ErrorCode setDay(uint8 day);
	ErrorCode setHour(uint8 hour);
	ErrorCode setMinute(uint8 minute);
	ErrorCode setSecond(uint8 second);

public:
	static Date fromLocal();

private:
	CommonEra mCE;
	uint16 mYear;
	uint8 mMonth;
	uint8 mDay;
	uint8 mHour;
	uint8 mMinute;
	uint8 mSecond;
};

} // namespace Core
