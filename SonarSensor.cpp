/**
* @file SonarSensor.cpp
* @Author Omer Berkan Calik, Ibrahim Berk Bulgan
* @date January, 2018
* @brief This file is for SonarSensor class' function's definitions.
*/

#include "SonarSensor.h"
SonarSensor::SonarSensor(){}
SonarSensor::~SonarSensor(){}
/*!
	\param index is an integer to select which sensor will be readen.
	\return The desired sensor's range.
*/
float SonarSensor::getRange(int index)
{
	return ranges[index];
}
/*!
	\param range[] is an array to update sonar sensor's ranges.
*/
void SonarSensor::setRange(float range[])
{
	for (int i = 0; i < 16; i++)
		ranges[i] = range[i];
}
/*!
	\return Returns the furthest sensor to wall's range value.
*/
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
/*!
	\return Returns the nearest sensor to wall's range value.
*/
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
/*!
	\param range[] is an array to update sonar sensor's ranges.
*/
void SonarSensor::updateSensor(float range[])
{
	for (int i = 0; i < 16; i++)
	{
		ranges[i] = range[i];
	}
}
/*!
	\param index is an integer to select which sensor will be readen.
	\return The desired sensor's range.
*/
float SonarSensor::operator[](int i)
{
	return ranges[i];
}
