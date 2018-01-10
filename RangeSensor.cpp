/**
* @file RangeSensor.cpp
* @Author Omer Berkan Calik, Ibrahim Berk Bulgan
* @date January, 2018
* @brief This file is for RangeSensor class' function's definitions.
*/
#include "RangeSensor.h"

RangeSensor::RangeSensor(){}

RangeSensor::~RangeSensor(){}
/*!
	\return Returns current object's sensor type.
*/
string RangeSensor::getType()
{
	return type;
}
/*!
	\param _type is a constant string to set objects type.
*/
void RangeSensor::setType(const string& _type)
{
	type = _type;
}