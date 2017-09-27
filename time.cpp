#include "time.h"

Time::Time() {
	hour = 0;
	minute = 0;
}

Time::Time(int _hour, int _minute) {
	hour = _hour;
	minute = _minute;
}

void Time::setTimeString(const char* timeStr) {
	if (timeStr[1] == ':') {
		hour = ((int)timeStr[0]) - 48;
		minute = (((int)timeStr[2]) - 48) * 10 + ((int)timeStr[3]) - 48;
	}
	else {
		hour = (((int)timeStr[0]) - 48) * 10 + ((int)timeStr[1]) - 48;
		minute = (((int)timeStr[3]) - 48) * 10 + ((int)timeStr[4]) - 48;
	}
}

bool Time::operator <= (const Time& other) {
	return  (this->hour * 60 + this->minute) <= (other.hour * 60 + other.minute);
}

bool Time::operator >= (const Time& other) {
	return  (this->hour * 60 + this->minute) >= (other.hour * 60 + other.minute);
}

bool Time::operator < (const Time& other) {
	return  (this->hour * 60 + this->minute) < (other.hour * 60 + other.minute);
}

bool Time::operator > (const Time& other) {
	return  (this->hour * 60 + this->minute) > (other.hour * 60 + other.minute);
}

bool Time::operator == (const Time& other) {
	return  (this->hour * 60 + this->minute) == (other.hour * 60 + other.minute);
}

string Time::toString() {
	char buffer[10];
	sprintf_s(buffer, "%02d:%02d", hour, minute);
	return buffer;
}

ostream& operator<<(ostream& out, const Time& time)
{
	char buffer[10];
	sprintf_s(buffer, "%02d:%02d", time.hour, time.minute);
	out << buffer;
	return out;
}
