/**
 * @file PioneerRobotInterface.h
 * @Author Ömer Berkan Çalýk, Berk Bulgan
 * @date January, 2018
 * @brief This is an interface for controlling the robot.
*/

#pragma once
#include "RobotInterface.h"

//! PioneerRobotInterface Class
/*!
	This class inherits from the given PioneerRobotAPI Class.
	The purpose of PioneerRobotInterface is using the PioneerRobotAPI's functions.
*/
class PioneerRobotInterface : public RobotInterface, public PioneerRobotAPI
{
public:
	//! Constructor. 
	PioneerRobotInterface();
	//! Overloaded RobotInterface::update().
	void update();
	//! This function calls PioneerRobotAPI::connect().This is for connecting to the robot.
	bool open();
	//! This function calls PioneerRobotAPI::moveRobot().It moves the robot at given speed.
	void move(float speed);
	//! This function calls PioneerRobotAPI::disconnect().This for for disconnecting from the robot.
	bool close();
	//! This function turns the robot to the given direction using PioneerRobotAPI::turnRobot().
	void turn(RobotInterface::DIRECTION dir);
	//! This function calls PioneerRobotAPI::stopRobot().It stops the robot's movement.
	void stop();
	//! This function updates the robot's attributes.
	void updateRobot();
	//! Destructor.
	~PioneerRobotInterface();
protected:
	//! These are for storing coordinates and the orientation angle.
	float myX, myY, myTh;
	//! These array stores Sonar Sensors ranges.
	float sonars[16];
	//! This stores minimum range of Laser Sensor.
	float laserMin;
	//! This stores maximum range of Laser Sensor.
	float laserMax;
};

