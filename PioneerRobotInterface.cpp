/**
* @file PioneerRobotInterface.cpp
* @Author Omer Berkan Calik, Ibrahim Berk Bulgan
* @date January, 2018
* @brief This file is for PioneerRobotInterface class' function's definitions.
*/
#include "PioneerRobotInterface.h"
PioneerRobotInterface::PioneerRobotInterface()
{
	setRobot(this);
}

void PioneerRobotInterface::update()
{
	this->updateRobot();
	myX = getX();
	myY = getY();
	myTh = getTh();
	position->setTh(myTh);
	position->setY(myY);
	position->setX(myX);
	getSonarRange(sonars);
	rangeSensor[1]->updateSensor(sonars);
	getLaserRange(laserMin, laserMax);
	float laserRanges[2];
	laserRanges[0] = laserMin;
	laserRanges[1] = laserMax;
	rangeSensor[0]->updateSensor(laserRanges);
}

/*!
    \return is Robot connected?
*/
bool PioneerRobotInterface::open()
{
	return connect();
}

/*!
  \param speed is a float argument. Which represents the robot's movement speed.
*/
void PioneerRobotInterface::move(float speed)
{
	moveRobot(speed);

}

/*!
   \return is Robot disconnected?
*/
bool PioneerRobotInterface::close()
{
	return disconnect();
}

/*!
  \param dir is an enum. Which represent the turning direction.
*/
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
	PioneerRobotAPI::updateRobot();
	/*myX = getX();
	myY = getY();
	myTh = getTh();
	getSonarRange(sonars);
	rangeSensor[1]->updateSensor(sonars);
	getLaserRange(laserMin, laserMax);
	float laserRanges[2];
	laserRanges[0] = laserMin;
	laserRanges[1] = laserMax;
	rangeSensor[0]->updateSensor(laserRanges);*/
}

PioneerRobotInterface::~PioneerRobotInterface(){}
