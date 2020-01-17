#include <string>

class Location
{
private:
	std::string loc;

public:
	Location() {
		loc = std::string();
	}
	Location(std::string location) {
		loc = location;
	}
	void setLocation();
	void clearLocation();
	std::string LocationInfo() const;
};

