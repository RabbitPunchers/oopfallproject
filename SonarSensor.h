#pragma once
#include "RangeSensor.h"
class SonarSensor :
	public RangeSensor
{
	float ranges[16];
public:
	SonarSensor();
	~SonarSensor();
	float getRange(int);
	void setRange(float[]);
	float getMax();
	float getMin();
	void updateSensor(float[]);
	float operator[](int);
};

