#include "LaserSensor.h"




LaserSensor::LaserSensor()
{
min = 0;
max = 0;
}

LaserSensor::~LaserSensor()
{
}

float LaserSensor::getRange(int index)
{
	if (index == 0)
		return min;
	if (index == 1)
		return max;
}
void LaserSensor::setRange(float range[])
{

}
void LaserSensor::updateSensor(float ranges[])
{
	min = ranges[0];
	max = ranges[1];
}
float LaserSensor::getMax()
{
	return max;
}
float LaserSensor::getMin()
{
	return min;
}
float LaserSensor::operator[](int i)
{
	return getRange(i);
}