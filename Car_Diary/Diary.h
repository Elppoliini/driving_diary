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
	std::vector<Trip> getTripList() const;


private:
	std::vector<Trip> tripList;
	std::vector<unsigned int> searchOptions;
};

