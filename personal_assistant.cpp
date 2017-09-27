#include "personal_assistant.h"
#include <fstream>
#include "app_factory.h"

PersonalAssistant::PersonalAssistant() {
	string currentName;
	ifstream cp("people.txt");
	while (getline(cp, currentName)) {
		calendarList.insert(pair <string, PersonalCalendar>(currentName, PersonalCalendar(currentName.c_str())));
	}
	cp.close();
}

void PersonalAssistant::setCrrPerson(const char * _crrPerson) {
	int nameLen = strlen(_crrPerson) + 1;
	crrPerson = new char[nameLen];
	strcpy_s(crrPerson, nameLen, _crrPerson);
}
char * PersonalAssistant::getCrrPerson() {
	return crrPerson;
}
PersonalAssistant::~PersonalAssistant() {
	delete[] crrPerson;
}

void PersonalAssistant::showMeetings(string date) {
	PersonalCalendar cal = calendarList[crrPerson];
	cal.displayMeetingByDate(date);
}

void PersonalAssistant::createMeeting(string newMeet) {
	bool isPossible = true;
	AppFactory factory;
	Appointment curApp = factory.load(newMeet.c_str());
	vector<string> curPeople = curApp.getNames();
	curPeople.push_back(crrPerson);
	for (vector<string>::iterator it = curPeople.begin(); it != curPeople.end(); ++it) {
		if (calendarList.find(it->data()) == calendarList.end()) {
			PersonalCalendar newCal(it->data());
			calendarList.insert(pair<string, PersonalCalendar>(it->data(), newCal));
		}
		if (!calendarList[it->data()].isAvailable(curApp)) {
			isPossible = false;
			cout << it->data() << " is not available." << endl;
			break;
		}
	}
	if (isPossible)
	{
		curApp.addPersonName(crrPerson);
		for (vector<string>::iterator it = curPeople.begin(); it != curPeople.end(); ++it) {

			calendarList[it->data()].addAppointment(curApp);
		}
		cout << "Meeting created" << endl;
	}
}

void PersonalAssistant::removeMeeting(string removeMeet) {
	string date = removeMeet.substr(0, 8);
	string fromTimeStr = removeMeet.substr(9, 5);
	Time fromTime;
	fromTime.setTimeString(fromTimeStr.c_str());
	vector<string> participants = calendarList[crrPerson].removeAppointment(date, fromTime);
	for (vector<string>::iterator it = participants.begin(); it != participants.end(); ++it) {
		calendarList[it->data()].removeAppointment(date, fromTime);
	}
	cout << "Meeting removed!";
}

void PersonalAssistant::suggestMeetingTime(string suggestMeet) {
	size_t pos1 = suggestMeet.find(" ");
	string date = suggestMeet.substr(0, 8);
	string tempdurper = suggestMeet.substr(pos1 + 1);  // "2 Pesho"
	size_t pos2 = tempdurper.find(" ");
	string duration = tempdurper.substr(0, pos2);
	string person = tempdurper.substr(pos2 + 1);
	calendarList[person].showAvailableTime(date, duration);
}

//TODO

////create regular meeting <time> <interval> [daily, weekly, monthly] <day> <person[s]> [<notes>]
//void PersonalAssistant::createRegularMeeting(string regularMeet) {
//	string fromTimeStr = regularMeet.substr(0, 4);
//	string toTimeStr = regularMeet.substr(6, 4);
//	string restStr = regularMeet.substr(12);
//	size_t pos1 = restStr.find(" ");
//	string intervalStr = restStr.substr(0, pos1);
//	if(intervalStr== "daily") {
//
//	}
//	else if (intervalStr == "daily") {
//
//	}
//	else if (intervalStr == "monthly") {
//
//	}
//	else {
//		cout << "Wrong interval!" << endl;
//	}
//}

void PersonalAssistant::save() {
	ofstream pp("people.txt");
	for (map<string, PersonalCalendar>::iterator it = calendarList.begin(); it != calendarList.end(); ++it) {
		pp << it->first << endl;
		ofstream cp(it->first + ".txt");
		cp << it->second.toString();
		cp.close();
	}
	pp.close();
}