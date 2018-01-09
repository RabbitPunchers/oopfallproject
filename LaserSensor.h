/**
 * @file LaserSensor.h
 * @Author Ömer Berkan Çalýk, Berk Bulgan
 * @date January, 2018
 * @brief LaserSensor Class definition.
*/

#pragma once
#include "RangeSensor.h"

//! LaserSensor Class
/*!
  This is a class for calculating the minimum and maximum range between
  LaserSensor and the walls.It inherits from the RangeSensor class.
*/
	
class LaserSensor :
	public RangeSensor
{
	//! This is for storing the minimum range.
	float min;
	//! This is for storing the maximum range.
	float max;
public:
	//! Overloaded RangeSensor::getRange().
	float getRange(int index);
	//! Overloaded RangeSensor::setRange().
	void setRange(float range[]);
	//! Overloaded RangeSensor::updateSensor().
	void updateSensor(float ranges[]);
	//! This function returns the max attribute.
	float getMax();
	//! This function returns the min attribute.
	float getMin();
	//! operator[] overloading.
	float operator[](int i);
	//! Constructor.
	LaserSensor();
	//! Destructor.
	~LaserSensor();
};
