#pragma once
#include "RangeSensor.h"
class SonarSensor :
	public RangeSensor
{
	float ranges[16];
public:
	float getRange(int index);
	void setRange(float range[]);
	float getMax();
	float getMin();
	void updateSensor(float ranges[]);
	float operator[](int i);

public:
	SonarSensor();
	~SonarSensor();
};

