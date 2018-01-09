#include "SonarSensor.h"

SonarSensor::SonarSensor(){}

SonarSensor::~SonarSensor(){}

float SonarSensor::getRange(int index)
{
	return ranges[index];
}
void SonarSensor::setRange(float range[])
{
	for (int i = 0; i < 16; i++)
		ranges[i] = range[i];
}
float SonarSensor::getMax()
{
	float max = ranges[0];
	for (int i = 0; i < 16; i++)
	{
		if (ranges[i] > max)
			max = ranges[i];
	}
	return max;
}
float SonarSensor::getMin()
{
	float min = ranges[0];
	for (int i = 0; i < 16; i++)
	{
		if (ranges[i] < min)
			min = ranges[i];
	}
	return min;
}
void SonarSensor::updateSensor(float range[])
{
	for (int i = 0; i < 16; i++)
	{
		ranges[i] = range[i];
	}
}
float SonarSensor::operator[](int i)
{
	return ranges[i];
}
