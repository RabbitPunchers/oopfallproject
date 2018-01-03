#include "PioneerRobotInterface.h"



PioneerRobotInterface::PioneerRobotInterface()
{
	
}


PioneerRobotInterface::~PioneerRobotInterface()
{
}

void PioneerRobotInterface::update()
{

	myX = getX();
	myY = getY();
	myTh = getTh();
	getSonarRange(sonars);
	getLaserRange(laserMin, laserMax);
}
bool PioneerRobotInterface::open()
{
	return connect();
}
void PioneerRobotInterface::move(float speed)
{
	moveRobot(speed);
}
bool PioneerRobotInterface::close()
{
	return disconnect();
}
void PioneerRobotInterface::turn(RobotInterface::DIRECTION dir)
{
	if (dir == -1)
		turnRobot(PioneerRobotAPI::DIRECTION::left);
	else if (dir == 0)
		turnRobot(PioneerRobotAPI::DIRECTION::forward);
	else if (dir == 1)
		turnRobot(PioneerRobotAPI::DIRECTION::right);
}
void PioneerRobotInterface::stop() 
{
	stopRobot();
}
void PioneerRobotInterface::updateRobot()
{
	updateRobot();
}
