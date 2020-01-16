#include <string>

class Location
{
private:
	std::string loc;

public:
	Location() {
		loc = std::string();
	}
	void setLocation();
	void clearLocation();
	std::string LocationInfo();
};

