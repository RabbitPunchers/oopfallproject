#include "PioneerRobotInterface.h"




PioneerRobotInterface::PioneerRobotInterface()
{
	setRobot(this);
}



void PioneerRobotInterface::update()
{
		
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
	{
		turnRobot(PioneerRobotAPI::DIRECTION::left);
		Sleep(1000);
		stop();
	}
	else if (dir == 0)
	{
	turnRobot(PioneerRobotAPI::DIRECTION::forward);
	Sleep(1000);
	stop();
	}
	else if (dir == 1)
	{
		turnRobot(PioneerRobotAPI::DIRECTION::right);
		Sleep(1000);
		stop();
	}
}
void PioneerRobotInterface::stop()
{
	stopRobot();
}
void PioneerRobotInterface::updateRobot()
{
//	getLaserRange();
	//getSonarRange();
	PioneerRobotAPI::updateRobot();
	myX = getX();
	myY = getY();
	myTh = getTh();
	getSonarRange(sonars);
	getLaserRange(laserMin, laserMax);
}

PioneerRobotInterface::~PioneerRobotInterface()
{
}
