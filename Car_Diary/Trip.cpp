#include "Trip.h"
#include "Diary.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


void Trip::initTrip() {
	cout << "Enter start location:" << endl;
	startLocation.setLocation();
	cout << "Enter starting time" << endl;
	startingTime.setTime();
	cout << "Odometer value when the trip started:" << endl;
	ometer.setStart();
	cout << "Enter end location:" << endl;
	endLocation.setLocation();
	cout << "Enter ending time" << endl;
	endingTime.setTime();
	cout << "Odometer value when the trip ended:" << endl;
	ometer.setEnd();
	buyingFuel();
}

void Trip::clearTrip() {
	startLocation.clearLocation();
	endLocation.clearLocation();
	startingTime.deleteTime();
	endingTime.deleteTime();
	boughtFuel = 0;
}

void Trip::summary() {
	cout << "Start location: " << startLocation.LocationInfo() << endl;
	cout << "Starting time: " << startingTime.getTime() << endl;
	cout << "Odometer value when the trip started: " << ometer.getStart() << endl;
	cout << "End location: " << endLocation.LocationInfo() << endl;
	cout << "Trip ending time: " << endingTime.getTime() << endl;
	cout << "Odometer value when trip ended: " << ometer.getEnd() << endl;
	cout << "Traveled distance: " << ometer.distance() << endl;
	cout << "Fuel bought among the trip: " << boughtFuel << endl;
	cout << endl;
}

void Trip::buyingFuel() {
	
	int fuelAmount;
	cout << "How many units of fuel did you buy? (enter 0 if you did not buy any fuel)" << endl;
	string input = string();

	while (true) {
		cin >> input;
		try {
			fuelAmount = std::stoi(input);
			if (fuelAmount < 0) {
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
	boughtFuel = fuelAmount;
}


int Trip::getDistance() {
	return ometer.distance();
}

ostream& operator<<(ostream& os, const Trip& t) {
	os << t.startLocation.LocationInfo() << endl;
	os << t.endLocation.LocationInfo() << endl;
	os << t.startingTime.getHours() << endl;
	os << t.startingTime.getMinutes() << endl;
	os << t.endingTime.getHours() << endl;
	os << t.endingTime.getMinutes() << endl;
	os << t.ometer.getStart() << endl;
	os << t.ometer.getEnd() << endl;
	os << t.boughtFuel << endl;
	return os;
}
