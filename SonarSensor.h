/**
* @file SonarSensor.h
* @Author Omer Berkan Calik,Berk Bulgan
* @date January, 2018
* @brief This file is for SonarSensor class definition.
*/

#pragma once
#include "RangeSensor.h"

//! SonarSensor Class
/*!
  This is a class for calculating the ranges of Sonar Sensors
  to the walls.It inherits from the RangeSensor class.
*/
class SonarSensor :
	public RangeSensor
{
	//! This stores the Sonar Sensors' ranges.
	float ranges[16];
public:
	//! This returns the range of the given SonarSensor.
	float getRange(int index);
	//! This changes the ranges with the given array.
	void setRange(float range[]);
	//! Overloaded function.
	float getMax();
	//! Overloaded function.
	float getMin();
	//! This changes the ranges with the given array.
	void updateSensor(float ranges[]);
	//! Operator[] overloading. It works like getRange().
	float operator[](int i);

public:
	SonarSensor();
	~SonarSensor();
};

