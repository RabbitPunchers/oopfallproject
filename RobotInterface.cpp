#include "RobotInterface.h"
#include <vector>


RobotInterface::RobotInterface(){}

RobotInterface::~RobotInterface(){}

void RobotInterface::setPosition(Position* pos)
{
	position = pos;
}
void RobotInterface::setSensor(RangeSensor* las, RangeSensor* son)
{
	rangeSensor.push_back(las);
	rangeSensor.push_back(son);
}


