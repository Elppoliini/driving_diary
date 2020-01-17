#pragma once
#include "Trip.h"
#include <vector>


class Diary
{
public:
	Diary() {
		tripList = {};
	}

	void getAll();
	void findTripByRange();
	void newEntry();
	void removeTrip();
	void clearAllTrips();
	void writeToFile(std::string path);
	bool readFromFile(std::string path);
	double consumption();


private:
	std::vector<Trip> tripList;
};

