#include "appointment.h"


Appointment::Appointment(char* _date, char* _fromTime, char* _toTime, vector<string> _names, string _notes) {
	strcpy_s(date, strlen(_date) + 1, _date);
	fromTime.setTimeString(_fromTime);
	toTime.setTimeString(_toTime);
	names = _names;
	notes = _notes;
}

string Appointment::getDate() {
	return string(date);
}

vector<string> Appointment::getNames() {
	return names;
}

void Appointment::addPersonName(string personName) {
	names.push_back(personName);
}

void Appointment::removePersonName(string personName) {
	for (vector<string>::iterator it = names.begin(); it != names.end(); ++it) {
		if (it->data() == personName) {
			names.erase(it);
			break;
		}
	}
}

Time Appointment::getFromTime() {
	return fromTime;
}

Time Appointment::getToTime() {
	return toTime;
}

void Appointment::print() {
	cout << fromTime << "-" << toTime << " ";
	for (vector<string>::iterator it = names.begin(); it != names.end(); ++it) {
		cout << it->data() << ", ";
	}
	cout << notes;
}

string Appointment::toString() {
	string result = date;
	result += " " + fromTime.toString() + "-" + toTime.toString() + " ";
	for (vector<string>::iterator it = names.begin(); it != names.end(); ++it) {
		result += it->data();
		result += ",";
	}
	int len = result.size();
	result[len - 1] = ' ';
	result += notes;
	return result;
}
