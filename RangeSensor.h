#pragma once
#include <string>
using namespace std;
class RangeSensor
{
	string type;
public:
	RangeSensor();
	~RangeSensor();
	virtual void updateSensor(float ranges[]) = 0;
	virtual float getMin() = 0;
	virtual float getMax() = 0;
	virtual float getRange(int index) = 0;
	virtual string getType();
	void setType(const string&);
	virtual float operator[](int) = 0;
};

