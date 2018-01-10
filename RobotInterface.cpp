/**
* @file RobotInterface.cpp
* @Author Ömer Berkan Çalýk, Ibrahim Berk Bulgan
* @date January, 2018
* @brief This file is for RobotInterface class' function's definitions.
*/
#include "RobotInterface.h"
#include <vector>


RobotInterface::RobotInterface(){}

RobotInterface::~RobotInterface(){}

/*!
	\param pos is a Position pointer. Which represents Position created back before.
*/
void RobotInterface::setPosition(Position* pos)
{
	position = pos;
}

/*!
	\param las is a RangeSensor pointer. Which represents laserSensor created back before.
	\param son is a RangeSensor pointer. Which represents sonarSensor created back before.
*/
void RobotInterface::setSensor(RangeSensor* las, RangeSensor* son)
{
	rangeSensor.push_back(las);
	rangeSensor.push_back(son);
}


