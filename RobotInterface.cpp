#include "RobotInterface.h"



RobotInterface::RobotInterface()
{

}


RobotInterface::~RobotInterface()
{
}


void RobotInterface::setPosition(Position* pos)
{
	position = pos;
}
void RobotInterface::setSensor(RangeSensor* sen)
{
	rangeSensor = sen;
}


