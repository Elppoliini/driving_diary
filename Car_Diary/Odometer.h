#pragma once
class Odometer
{

public:
	Odometer() {
		start = -1;
		end = -1;
	}
	Odometer(int s, int e) {
		start = s;
		end = e;
	}
	int distance();
	void setEnd();
	void setStart();
	int getStart() const;
	int getEnd() const;
	
private:
	int start;
	int end;
};

