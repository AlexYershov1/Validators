#pragma once
#include "FieldValidator.h"
#include <chrono>
#include <ctime>

const int MIN_DATE_SIZE = 1010000;
const int MAX_DATE_SIZE = 31129999;
const int PART_OF_DATE = 100;
const int MONTH_IN_YEAR = 12;
const int DAY_IN_MONTH = 31;

template < class T >
class DateValidator : public FieldValidator<T>
{
public:
	DateValidator();
	virtual void IsValid(const T&) const;
	~DateValidator();

private:
	int m_year;
	int m_month;
	int m_day;

	void currentTime();
};

template < class T >
DateValidator<T>::DateValidator()
{
	currentTime();
}

template<class T>
inline void DateValidator<T>::IsValid(const T& date) const
{
	if (date < MIN_DATE_SIZE || date > MAX_DATE_SIZE)
		throw NoValid("Not a 'ddmmyyyy' format");

	auto chDate = date;		// changeable variable 
	auto year = chDate % (PART_OF_DATE * PART_OF_DATE);	// pull year out of date
	chDate /= PART_OF_DATE * PART_OF_DATE;
	auto month = chDate % PART_OF_DATE;		// pull month out of date
	if(month > MONTH_IN_YEAR)
		throw NoValid("Invalid month");
	chDate /= PART_OF_DATE;
	auto day = chDate;		// pull day out of date
	if (day > DAY_IN_MONTH)
		throw NoValid("Invalid day");

	if (year < m_year)
		throw NoValid("date passed- Invalid year");
	else if (year == m_year){
		if(month < m_month)
			throw NoValid("date passed- Invalid month");
		else if (month == m_month) {
			if (day < m_day)
				throw NoValid("date passed- Invalid day");
		}
	}
}

template < class T >
DateValidator<T>::~DateValidator()
{
}

template<class T>
inline void DateValidator<T>::currentTime()
{
	using clock = std::chrono::system_clock;
	const auto now = clock::to_time_t(clock::now());
	auto calendarTime = std::tm{};
	localtime_s(&calendarTime, &now);
	m_day = calendarTime.tm_mday;
	m_month = calendarTime.tm_mon + 1;
	m_year = calendarTime.tm_year + 1900;
}
