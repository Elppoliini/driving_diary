#include <iostream>
#include <iomanip>
#include "Time.h"

using namespace std;

void Time::setTime() {
	setHours();
	setMinutes();
}
string Time::getTime() const {
	if (hours == -1 || minutes == -1) {
		return "The time have not been set yet or it have been deleted.";
	}

	string displayHours;
	string displayMinutes;

	if (getHours() < 10) {
		displayHours = '0' + to_string(getHours());
	}
	else {
		displayHours = to_string(getHours());
	}
	if (getMinutes() < 10) {
		displayMinutes = '0' + to_string(getMinutes());
	}
	else {
		displayMinutes = to_string(getMinutes());
	}

	return displayHours + ":" + displayMinutes;

}
int Time::setHours() {
	cout << "Enter hours:" << endl;

	string input = string();
	while (true) {
		cin >> input;
		try {
			hours = std::stoi(input);
			if (hours < 0 || hours >= 24) {
				cout << "Hours must be between 00 and 23." << endl;
				continue;
			}
			break;
		}
		catch (invalid_argument) {
			cout << "Time must be an integer." << endl;
		}
		catch (out_of_range) {
			cout << "Input is too long." << endl;
		}
		cin.clear();
		cin.ignore(numeric_limits <std::streamsize>::max(), '\n');

	}
	return hours;
}
int Time::getHours() const {
	return hours;
}
int Time::setMinutes() {
	cout << "Enter minutes:" << endl;

	string input = string();
	while (true) {
		cin >> input;
		try {
			minutes = std::stoi(input);
			if (minutes < 0 || minutes >=60) {
				cout << "Minutes must be between 00 and 59." << endl;
				continue;
			}
			break;
		}
		catch (invalid_argument) {
			cout << "Time must be an integer." << endl;
		}
		catch (out_of_range) {
			cout << "Input is too long." << endl;
		}
		cin.clear();
		cin.ignore(numeric_limits <std::streamsize>::max(), '\n');

	}
	return minutes;
}
int Time::getMinutes() const {
	return minutes;
}

void Time::deleteTime() {
	timeDisplayed = "The time have not been set yet or it have been deleted.";
	hours = -1;
	minutes = -1;
}