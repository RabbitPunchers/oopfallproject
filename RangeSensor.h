/**
* @file RangeSensor.h
* @Author Ömer Berkan Çalýk,Berk Bulgan
* @date January, 2018
* @brief This file is for RangeSensor class definition.
*/

#pragma once
#include <string>
using namespace std;

//! RangeSensor Class.
/*!
 This is an abstract class for providing an interface to the SonarSensor and LaserSensor.
*/
class RangeSensor
{
	//! This stores the sensor type value.
	string type;
public:
	//! Constructor.
	RangeSensor();
	//! Destructor.
	~RangeSensor();
	//! Pure virtual function for updating sensor ranges. SonarSensor uses this function.
	virtual void updateSensor(float ranges[]) = 0;
	//! Pure virtual function for getting minimum sensor range. LaserSensor uses this function.
	virtual float getMin() = 0;
	//! Pure virtual function for getting maximum sensor range. LaserSensor uses this function.
	virtual float getMax() = 0;
	//! Pure virtual function for getting the given sensor range. SonarSensor uses this function.
	virtual float getRange(int index) = 0;
	//! This returns type value.
	virtual string getType();
	//! This changes type value with the given string.
	void setType(const string&);
	//! Operator[] overloading.SonarSensor uses this function.
	virtual float operator[](int) = 0;
};

