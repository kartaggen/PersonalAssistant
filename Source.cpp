#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "personal_assistant.h"

using namespace std;

int main() {
	PersonalAssistant mainA;
	string keyAction;
	do{
		string crrP;
		ifstream cp("crrPerson.txt");
		getline(cp, crrP);
		cp.close();
		mainA.setCrrPerson(crrP.c_str());
		cout << "This is " << mainA.getCrrPerson() << "'s personal assistant." << endl;
		cout << "To change the person, type: changePA <name>" << endl << endl;

		cout << "To create a meeting, write: create meeting <date> <time> <person[s]> [<notes>]" << endl;
		cout << "Example: create meeting 12.06.16 12:00-13:00 Lee \"Lunch with Lee\" " << endl << endl;

		cout << "To remove a meeting, write: remove meeting <date> <time>" << endl;
		cout << "Example: remove meeting 12.06.16 12:00 " << endl << endl;

		//cout << "To create regular meeting, write: create regular meeting <time> <interval> [daily, weekly, monthly] <day> <person[s]> [<notes>]" << endl;
		//cout << "Example: create regular meeting 15:00-16:00 daily[daily, weekly, monthly] <day> <person[s]> [<notes>] " << endl << endl;
		

		cout << "To show meetings, write: show meetings <date>" << endl;
		cout << "Example: show meetings 12.06.16" << endl << endl;

		cout << "To suggest meetings, write: suggest meeting time <date> <duration> <person>" << endl;
		cout << "Example: suggest meeting time 12.06.16 1 Dragan" << endl << endl;

		cout << "To exit(save new information), write: exit" << endl;
		getline(cin, keyAction);
		if (!strncmp(keyAction.c_str(), "changePA", 8)) {
			keyAction.erase(0, 9);
			mainA.setCrrPerson(keyAction.c_str());
			ofstream cp("crrPerson.txt");
			cp << keyAction;
			cp.close();
			cout << "Currently logged as " << keyAction << endl;
			getline(cin, keyAction);
		}
		else if (!strncmp(keyAction.c_str(), "create meeting", 14)) {
			keyAction.erase(0, 15);
			mainA.createMeeting(keyAction);
			getline(cin, keyAction);
		}
		else if (!strncmp(keyAction.c_str(), "remove meeting", 14)) {
			keyAction.erase(0, 15);
			mainA.removeMeeting(keyAction);
			getline(cin, keyAction);
		}
		//else if (!strncmp(keyAction.c_str(), "create regular meeting", 22)) {
		//	keyAction.erase(0, 23);
		//	mainA.createRegularMeeting(keyAction);
		//	getline(cin, keyAction);
		//}
		else if (!strncmp(keyAction.c_str(), "show meeting", 12)) {
			keyAction.erase(0, 14);
			mainA.showMeetings(keyAction);
			getline(cin, keyAction);

		}
		else if (!strncmp(keyAction.c_str(), "suggest meeting time", 20)) {
			keyAction.erase(0, 21);
			mainA.suggestMeetingTime(keyAction);
			getline(cin, keyAction);
		}
	} while (strcmp(keyAction.c_str(), "exit"));
	mainA.save();
	return 0;
}