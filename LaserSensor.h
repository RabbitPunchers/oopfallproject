#pragma once
#include "RangeSensor.h"
class LaserSensor :
	public RangeSensor
{
	float min;
	float max;
public:
	float getRange(int index);
	void setRange(float range[]);
	void updateSensor(float ranges[]);
	float getMax();
	float getMin();
	float operator[](int i);
	LaserSensor();
	~LaserSensor();
};
