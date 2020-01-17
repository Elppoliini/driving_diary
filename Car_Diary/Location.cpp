#include "Location.h"
#include <iostream>
using namespace std;
void Location:: setLocation() {
	cin.clear();
	getline(cin, loc);
	while (loc.empty()) {
		cout << "Location must be set. Please insert the location" << endl;
		getline(cin, loc);
	}
}

void Location::clearLocation() {
	loc.clear();
}

string Location::LocationInfo() const {
	return loc;
}
