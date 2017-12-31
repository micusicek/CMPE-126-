#include "Clock.h"
#include <iomanip>



clockType::clockType(int Hour, int Minutes, int Seconds) {
	this->Hour = Hour;
	this->Minutes = Minutes;
	this->Seconds = Seconds;
}


clockType::~clockType()
{
}

std::ostream& operator << (std::ostream& os, const clockType& c) {
	os
		<< std::setfill('0')
		<< std::setw(2) << c.Hour << ":"
		<< std::setw(2) << c.Minutes << ":"
		<< std::setw(2) << c.Seconds << std::endl;
	return os;
}

clockType operator + (const clockType& one, const clockType& two) {
	clockType result(0, 0, 0);

	int secondsSum = (one.Seconds + two.Seconds);
	int secondsCarryOver = secondsSum / 60;
	result.Seconds = secondsSum % 60;

	int minutesSum = (one.Minutes + two.Minutes + secondsCarryOver);
	int minutesCarryOver = minutesSum / 60;
	result.Minutes = minutesSum % 60;

	result.Hour = (one.Hour + two.Hour + minutesCarryOver) % 24;

	return result;
}