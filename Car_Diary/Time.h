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
	std::string getTime() const;
	int setHours();
	int getHours() const;
	int setMinutes();
	int getMinutes() const;
	void deleteTime();

private:
	int hours;
	int minutes;
	std::string timeDisplayed;
};

