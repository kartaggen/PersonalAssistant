#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include <vector>
#include "time.h"

using namespace std;

class Appointment {

public:
	Appointment(char* _date, char* _fromTime, char* _toTime, vector<string> _names, string _notes);

	string getDate();
	vector<string> getNames();
	void addPersonName(string personName);
	void removePersonName(string personName);
	Time getFromTime();
	Time getToTime();
	void print();
	string toString();

private:
	char date[9];
	Time fromTime;
	Time toTime;
	vector <string> names;
	string notes;
};

#endif
