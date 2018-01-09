/**
* @file RobotControl.h
* @Author Omer Berkan Calik, Berk Bulgan
* @date January, 2018
* @brief This file is for RobotControl class definition.
*/

#pragma once
#include <vector>
#include "PioneerRobotInterface.h"
#include <iostream>
#include "LaserSensor.h"
#include "SonarSensor.h"
#define FOREVER while(true);
using namespace std;

//! RobotControl Class.
/*!
  This is a class for controlling the robot's movements.
*/
class RobotControl
{
	//! This is for accessing to the RobotInterface.
	RobotInterface* robot;
	//! This vector stores the sensors.
	vector <RangeSensor*>sensor;
	//! This is for accessing t the Position.
	Position* position;
public:
	//! Constructor.
	RobotControl(RobotInterface* _robot, LaserSensor * _laser, SonarSensor*  _sonar, Position* _pos) :robot(_robot), position(_pos) {
		sensor.push_back(_laser);
		sensor.push_back(_sonar);
	}
	//! Destructor.
	~RobotControl();
	//! This function moves the robot at the given speed and stops it when robot gets close to a wall.
	void safeMove(int speed);
	//! This function turns robot to the left.
	void turnLeft();
	//! This function turns robot to the right.
	void turnRight();
	//! This function moves robot forward.
	void forward();
	//! This function prints the Position and Sensor values.
	void print();
	//! This function moves the robot for given distance.
	void moveDistance(float distance);
	//! This function moves robot forward and stops it when robot gets close to a wall.
	void closeWall();
};

