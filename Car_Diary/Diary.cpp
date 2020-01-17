#include "Diary.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Diary:: getAll() {

	for (Trip& t: tripList) {
		t.summary();
	}
}
void Diary::findTripByRange() {
	int min, max;
	cout << "Enter the minimum range of trips you want to look:" << endl;
	while (!(cin >> min) || min < 0) {
		cout << "The value needs to be positive." << endl;
		cin.clear();
		cin.ignore(numeric_limits <std::streamsize>::max(), '\n');

	}
	cout << "Enter the maximum range of trips you want to look:" << endl;
	while (!(cin >> max) || max < 0) {
		cout << "The value needs to be positive." << endl;
		cin.clear();
		cin.ignore(numeric_limits <std::streamsize>::max(), '\n');

	}
	cout << "Trips in diary inside this range \n" << endl;
	for (unsigned int i = 0; i < tripList.size(); i++) {
		if (tripList[i].getDistance() >= min && tripList[i].getDistance() <= max) {
			cout << i + 1 << ". " << endl;
			tripList[i].summary();
		}
	}
}
void Diary:: newEntry() {
	Trip t;
	t.initTrip();
	tripList.push_back(t); 
}
void Diary::removeTrip() {
	int choice;
	int i = 1;
	cout << "You have selected to remove a trip from the diary. Write the minimum and maximum range values to choose the trip you want to remove." << endl;
	findTripByRange();
	cout << "Choose the number of the trip you wish to remove. 0 exits without removing a trip" << endl;
	while (!(cin >> choice) || choice < 0) {
		cout << "The value needs to be positive." << endl;
		cin.clear();
		cin.ignore(numeric_limits <std::streamsize>::max(), '\n');

	}
	if (choice == 0) return;
	choice--;
	tripList[choice].clearTrip();
	tripList.erase(tripList.begin() + choice);
}

void Diary::clearAllTrips() {
	tripList.clear();
	cout << "The Diary have been initialized and the saved trips have been removed. " << endl;
}

void Diary::writeToFile(string path) {
	ofstream file;
	file.open(path, ios_base::out | ios_base::trunc);
	for (Trip& t : tripList) {
		file << t;
		file << endl;
	}
}

bool Diary::readFromFile(std::string path) {
	ifstream file;
	file.open(path, ios_base::in);
	if (!file.is_open()) {
		return false;
	}
	while (!file.eof()) {
		Trip t;
		file >> t;
		tripList.push_back(t);
	}

	return true;
}

double Diary::consumption() {
	int bought = 0, distance = 0;
	for (Trip& t : tripList) {
		distance += t.getDistance();
		bought += t.getBoughtFuel();
	}

	return (double)bought / ((double)distance / 100);
}