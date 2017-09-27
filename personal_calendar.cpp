#include "personal_calendar.h"
#include <fstream>
#include "app_factory.h"

PersonalCalendar::PersonalCalendar() {
}

PersonalCalendar::PersonalCalendar(const char* _name) {
	name = _name;
	string currentLine;
	AppFactory appFactory;

	ifstream cp(name + ".txt");
	while (getline(cp, currentLine)) {
		appointments.push_back(appFactory.load(currentLine.c_str()));
	}
}

void PersonalCalendar::displayMeetingByDate(string date) {
	bool hasMeetings = false;
	cout << "Meetings for: " << date << endl;
	for (vector<Appointment>::iterator it = appointments.begin(); it != appointments.end(); ++it) {
		if (date == it->getDate()) {
			hasMeetings = true;
			it->print();
			cout << endl;
		}
	}
	if (!hasMeetings) {
		cout << "No meetings!" << endl;
	}
}

bool PersonalCalendar::isAvailable(Appointment _curApp) {
	bool isAvail = true;
	for (vector<Appointment>::iterator it = appointments.begin(); it != appointments.end(); ++it) {
		if (_curApp.getDate() == it->getDate() &&
			!(_curApp.getFromTime() < it->getFromTime() && _curApp.getToTime() < it->getFromTime() ||
				_curApp.getFromTime() > it->getToTime() && _curApp.getToTime() > it->getToTime())) {
			isAvail = false;
		}
	}
	return isAvail;
}

void PersonalCalendar::addAppointment(Appointment _newApp) {
	_newApp.removePersonName(name);
	appointments.push_back(_newApp);
}
string PersonalCalendar::getName() {
	return name;
}

vector<string> PersonalCalendar::removeAppointment(string date, Time fromTime) {
	vector<string> participants;
	bool exists = false;
	for (vector<Appointment>::iterator it = appointments.begin(); it != appointments.end(); ++it) {
		if (date == it->getDate() && fromTime == it->getFromTime()) {
			participants = it->getNames();
			appointments.erase(it);
			exists = true;
			break;
		}
	}
	if (!exists) {
		cout << "Meeting doesn't exist!" << endl;
	}
	return participants;
}

void PersonalCalendar::showAvailableTime(string date, string duration) {
	bool first = true;
	int dur = stoi(duration);
	bool freeSlots[10] = { true, true, true, true, true, true, true, true, true, true };
	for (vector<Appointment>::iterator it = appointments.begin(); it != appointments.end(); ++it) {
		if (date == it->getDate()) {
			for (int i = 0; i + dur <= 10; i++) {
				Time slotFromTime(i + 8, 0);
				Time slotToTime(i + 8 + dur, 0);
				if (slotFromTime <= it->getFromTime() && slotToTime > it->getFromTime() ||
					slotFromTime < it->getToTime() && slotToTime >= it->getToTime() ||
					slotFromTime >= it->getFromTime() && slotToTime <= it->getToTime() ||
					slotFromTime <= it->getFromTime() && slotToTime >= it->getToTime()) {
					freeSlots[i] = false;
				}
			}
		}
	}
	for (int i = 0; i + dur <= 10; i++) {
		Time slotFromTime(i + 8, 0);
		Time slotToTime(i + 8 + dur, 0);
		if (freeSlots[i]) {
			if (first) {
				cout << "Available slots: ";
				first = false;
			}
			cout << slotFromTime.toString() << "-" << slotToTime.toString() << " ";
		}
		if (first) {
			cout << "No available slots!" << endl;
		}

	}
}

string PersonalCalendar::toString() {
	string result;
	for (vector<Appointment>::iterator it = appointments.begin(); it != appointments.end(); ++it) {
		result += it->toString() + "\n";
	}
	return result;
}