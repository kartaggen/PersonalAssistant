#ifndef TIME_H
#define TIME_H

#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

class Time {
public:
	Time();
	Time(int _hour, int _minute);

	void setTimeString(const char* timeStr);
	bool operator <= (const Time& other);
	bool operator >= (const Time& other);
	bool operator < (const Time& other);
	bool operator > (const Time& other);
	bool operator == (const Time& other);
	string toString();
	friend ostream& operator<<(ostream& out, const Time& time);

private:
	int hour;
	int minute;
};

ostream& operator<<(ostream& out, const Time& time);

#endif
