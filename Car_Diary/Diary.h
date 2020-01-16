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


private:
	std::vector<Trip> tripList;
};

