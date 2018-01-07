#include "LaserSensor.h"



LaserSensor::LaserSensor()
{

}


LaserSensor::~LaserSensor()
{

}

float LaserSensor::getRange(int index)
{
	return 1;
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
	return 0.0;
}