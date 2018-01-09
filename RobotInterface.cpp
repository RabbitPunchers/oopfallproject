#include "RobotInterface.h"
#include <vector>


RobotInterface::RobotInterface(){}

RobotInterface::~RobotInterface(){}

/*!
	\param pos is a Position.
*/
void RobotInterface::setPosition(Position* pos)
{
	position = pos;
}

/*!
	\param las is a RangeSensor pointer. Which represents laserSensor.
	\param son is a RangeSensor pointer. Which represents RangeSensor.
*/
void RobotInterface::setSensor(RangeSensor* las, RangeSensor* son)
{
	rangeSensor.push_back(las);
	rangeSensor.push_back(son);
}


