#pragma once
#include <string>
class Time
{
public:
	Time() {
		hours = -1;
		minutes = -1;
	}
	void setTime();
	std::string getTime();
	int setHours();
	int getHours();
	int setMinutes();
	int getMinutes();
	void deleteTime();

private:
	int hours;
	int minutes;
	std::string timeDisplayed;
};

