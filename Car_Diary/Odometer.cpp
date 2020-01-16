#include "Odometer.h"
#include <iostream>
using namespace std;

void Odometer::setStart() {
	while(start < 0) cin >> start;
	end = start;
}

int Odometer::distance() {
	return end - start;
}

void Odometer::setEnd() {
	cin >> end;
	while (end < start) {
		cout << "The value can not be less than the value when the trip started. Please insert the new odometer value:";
		cin >> end;
	}
}

int Odometer::getStart() {
	return start;
}

int Odometer::getEnd() {
	return end;
}
