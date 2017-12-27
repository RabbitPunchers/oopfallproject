#include "PioneerRobotInterface.h"



PioneerRobotInterface::PioneerRobotInterface()
{
	
}


PioneerRobotInterface::~PioneerRobotInterface()
{
}

void PioneerRobotInterface::update()
{
	float myX, myY, myTh;
	float sonars[16];
	float laserMin;
	float laserMax;
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
void PioneerRobotInterface::turn(PioneerRobotAPI::DIRECTION dir)
{
	turnRobot(dir);
}
void PioneerRobotInterface::stop() {
	stopRobot();
}
void PioneerRobotInterface::updateRobot()
{
	updateRobot();
}
