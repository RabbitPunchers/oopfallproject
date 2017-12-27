#include "RangeSensor.h"



RangeSensor::RangeSensor()
{
}


RangeSensor::~RangeSensor()
{
}

string RangeSensor::getType()
{
	return type;
}

void RangeSensor::setType(const string& _type)
{
	type = _type;
}