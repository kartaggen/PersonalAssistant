#ifndef PERSONAL_ASSISTANT_H
#define PERSONAL_ASSISTANT_H

#include <string>
#include <map>
#include "personal_calendar.h"

using namespace std;

class PersonalAssistant {
public:
	PersonalAssistant();
	~PersonalAssistant();
	
	void setCrrPerson(const char * _crrPerson);
	char * getCrrPerson();
	void showMeetings(string date);
	void createMeeting(string newMeet);
	void removeMeeting(string removeMeet);
	void suggestMeetingTime(string suggestMeet);
	//TODO
	//void createRegularMeeting(string regularMeet);
	void save();

private:
	char* crrPerson;
	map<string, PersonalCalendar> calendarList;
};
#endif
