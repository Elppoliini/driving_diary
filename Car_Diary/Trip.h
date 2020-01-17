#pragma once
#include "Location.h"
#include "Odometer.h"
#include "Time.h"
class Trip
{

public:
	Trip() {
		startLocation = Location();
		endLocation = Location();
		ometer = Odometer();
		startingTime = Time();
		endingTime = Time();
		boughtFuel = 0;
	}
	

	void initTrip();
	void clearTrip();
	void summary();
	void buyingFuel();
	int getDistance();
	friend std::ostream& operator<<(std::ostream& os, const Trip& t);
	friend std::istream& operator>>(std::istream& is, Trip& t);
	int getBoughtFuel();
	void setValues(
		Location startLocation,
		Location endLocation,
		Odometer ometer,
		Time startTime,
		Time endTime,
		int fuel
	) {
		this->startLocation = startLocation;
		this->endLocation = endLocation;
		this->ometer = ometer;
		this->startingTime = startTime;
		this->endingTime = endTime;
		this->boughtFuel = fuel;
	}

private:

	Location startLocation = Location();
	Location endLocation = Location();
	Odometer ometer;
	Time startingTime;
	Time endingTime;
	int boughtFuel;
};

