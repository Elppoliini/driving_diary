#include "Odometer.h"
#include <iostream>
#include <string>
using namespace std;

void Odometer::setStart() {
	string input = string();

	while (true) {
		cin >> input;
		try {
			start = std::stoi(input);
			if (start < 0) {
				cout << "The value must be a non-negative number." << endl;
				continue;
			}
			break;
		}
		catch (invalid_argument) {
			cout << "The value must be an integer." << endl;
		}
		catch (out_of_range) {
			cout << "Input is too long." << endl;
		}
		cin.clear();
		cin.ignore(numeric_limits <std::streamsize>::max(), '\n');

	}
}

int Odometer::distance() {
	return end - start;
}

void Odometer::setEnd() {
	string input = string();

	while (true) {
		cin >> input;
		try {
			end = std::stoi(input);
			if (end < 0) {
				cout << "The value must be a non-negative number." << endl;
				continue;
			}
			if (end < start) {
				cout << "The value can not be less than the value when the trip started. Please insert the new odometer value:" << endl;
				continue;
			}
			break;
		}
		catch (invalid_argument) {
			cout << "The value must be an integer." << endl;
		}
		catch (out_of_range) {
			cout << "Input is too long." << endl;
		}
		cin.clear();
		cin.ignore(numeric_limits <std::streamsize>::max(), '\n');

	}
}

int Odometer::getStart() const {
	return start;
}

int Odometer::getEnd() const {
	return end;
}
