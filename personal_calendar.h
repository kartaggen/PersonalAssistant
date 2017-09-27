#ifndef PERSONAL_CALENDAR_H
#define PERSONAL_CALENDAR_H

#include <string>
#include <vector>
#include "Appointment.h"
#include "time.h"

using namespace std;

class PersonalCalendar {
public:
	PersonalCalendar();
	PersonalCalendar(const char* _name);
	
	void displayMeetingByDate(string date);
	bool isAvailable(Appointment _curApp);
	void addAppointment(Appointment _newApp);
	string getName();
	vector<string> removeAppointment(string date, Time fromTime);
	void showAvailableTime(string date, string duration);
	string toString();

private:
	string name;
	vector<Appointment> appointments;

};
#endif
