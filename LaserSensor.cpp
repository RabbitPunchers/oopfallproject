/**
* @file LaserSensor.cpp
* @Author Ömer Berkan Çalýk, Ibrahim Berk Bulgan
* @date January, 2018
* @brief This file is for LaserSensor class' function's definitions.
*/
#include "LaserSensor.h"
LaserSensor::LaserSensor()
{
min = 0;
max = 0;
}
LaserSensor::~LaserSensor()
{
}
/*!
	\param index is an integer that agrees 0 as min 1 as max within function.
	\return Minimum or maximim value according to index value.
*/
float LaserSensor::getRange(int index)
{
	if (index == 0)
		return min;
	if (index == 1)
		return max;
}
/*!
	\param range[] is an array that includes min and max values.
*/
void LaserSensor::setRange(float range[])
{
	min = range[0];
	max = range[1];
}
/*!
	\param range[] is an array that includes min and max values.
*/
void LaserSensor::updateSensor(float ranges[])
{
	min = ranges[0];
	max = ranges[1];
}
/*!
	\return The max variable of laser sensor.
*/
float LaserSensor::getMax()
{
	return max;
}
/*!
	\return The min variable of laser sensor.
*/
float LaserSensor::getMin()
{
	return min;
}
/*!
	\param index is an integer that agrees 0 as min 1 as max within function.
	\return Minimum or maximim value according to index value.
*/
float LaserSensor::operator[](int i)
{
	return getRange(i);
}