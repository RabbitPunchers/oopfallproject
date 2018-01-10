/**
 * @file LaserSensor.h
 * @Author Omer Berkan Calik, Ibrahim Berk Bulgan
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
	//! This function returns min value if index is 0, returns max value if index is 1.
	float getRange(int index);
	//! This function sets the min and max values according to given array.
	void setRange(float range[]);
	//! This function updates the min and max values according to given array.
	void updateSensor(float ranges[]);
	//! This function returns the max attribute.
	float getMax();
	//! This function returns the min attribute.
	float getMin();
	//! This function returns min value if index is 0, returns max value if index is 1.
	float operator[](int i);
	//! Constructor.
	LaserSensor();
	//! Destructor.
	~LaserSensor();
};
