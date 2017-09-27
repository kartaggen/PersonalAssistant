#include "app_factory.h"

#include <string>
#include <vector>

Appointment AppFactory::load(const char* temp) {
	char date[9] = { 0 }, fromTime[6] = { 0 }, toTime[6] = { 0 }, note[150] = { 0 };
	vector <string> names;
	int strI = 0;
	for (int i = 0; temp[strI] != ' '; i++, strI++)
	{
		date[i] = temp[strI];
	}
	strI++;
	for (int i = 0; temp[strI] != '-'; i++, strI++)
	{
		fromTime[i] = temp[strI];
	}
	strI++;
	for (int i = 0; temp[strI] != ' '; i++, strI++)
	{
		toTime[i] = temp[strI];
	}
	strI++;
	while (temp[strI] != '\"'&& temp[strI] != ' ')
	{
		char tmpname[20] = { 0 };
		for (int j = 0; temp[strI] != ',' && temp[strI] != ' '; j++, strI++) {
			tmpname[j] = temp[strI];
		}
		names.push_back(tmpname);
		if (temp[strI] == ' ')
			break;
		strI++;
	}
	strI++;
	for (int i = 0; temp[strI] != '\0'; i++, strI++)
	{
		note[i] = temp[strI];
	}
	Appointment a(date, fromTime, toTime, names, note);
	return a;
}
