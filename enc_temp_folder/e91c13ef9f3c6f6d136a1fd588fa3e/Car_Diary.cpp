// Car_Diary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "Trip.h"
#include "Diary.h"
using namespace std;

/* COMMANDS

	Initialize(clear all trips)
	Save trip to disk
	Read trip from the disk
	Add new Trip
	Remove a trip
		Print a report. 
		Program asks user to enter upper and lower limit of driven distance 
		and prints trips where the driven distance is in the specified range
	Calculate average fuel consumption based on the driven distance and bought fuel.

*/



int main()
{
	Diary diar = Diary();
	diar.readFromFile("driving_diary.txt");
	bool keepGoing = true;
	string input;
	while (keepGoing) {
		cout << "Here is a list of the commands to use: Choose the number of the command to continue.\n" << endl;
		cout << "1: Add a new trip" << endl;
		cout << "2: List trips" << endl;
		cout << "3: Find trips from a specific range" << endl;
		cout << "4: Remove a trip" << endl;
		cout << "5: Clear diary" << endl;
		cout << "6:Count average fuel consumption" << endl;
		cout << "7: Save and exit" << endl;
		cin >> input;
		int command = 0;
		try {
			command = std::stoi(input);
			if (command < 1 || command > 6) {
				cout << "The input must be between 1-6." << endl;
				continue;
			}
		}
		catch (invalid_argument) {
			cout << "The input must be an integer." << endl;
		}
		catch (out_of_range) {
			cout << "Input is too long." << endl;
		}
		switch (command) {
			case 1:
				cout << "You chose to add a new entry to the driving diary." << endl;
				diar.newEntry();
				break;
			case 2:
				cout << "Here is a list of all the trips in the diary: \n" << endl;
				diar.getAll();
				break;
			case 3:
				cout << "Find trips by range." << endl;
				diar.findTripByRange();
				break;
			case 4:
				cout << "You chose to remove  trip." << endl;
				diar.removeTrip();
				break;
			case 5:
			{
				cout << "You chose to clear the diary from all trips. Are you sure you want to do it?" << endl;
				string answer = string();
				cin >> answer;
				transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
				while (answer.compare("yes") != 0 && answer.compare("no") != 0) {
					cout << "The answer needs to be yes or no" << endl;
					cin >> answer;
					transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
				}
				if (answer.compare("yes") == 0) {
					diar.clearAllTrips();
				}
				break;
			}
			case 6:
				cout << "Here is your average fuel consumption:\n" << endl;
				cout << diar.consumption() << "liters/100km" << endl;
				break;
			case 7:
				cout << "You chose to save and exit." << endl;
				keepGoing = false;
				diar.writeToFile("driving_diary.txt");
				break;
			default:
				cout << "Oops. Something went wrong." << endl;
		}
	}
}
