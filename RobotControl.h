/**
* @file RobotControl.h
* @Author Omer Berkan Calik, Ibrahim Berk Bulgan
* @date January, 2018
* @brief This file is for RobotControl class definition.
*/

#pragma once
#include <vector>
#include <iostream>
<<<<<<< HEAD
#include "PioneerRobotInterface.h" 
=======
#include "PioneerRobotInterface.h" 						
>>>>>>> 479c4233875f80b6bc3c33d6f93140ff025d2684
#include "RangeSensor.h"
using namespace std;

//! RobotControl Class.
/*!
  This is a class for controlling the robot's movements.
*/
class RobotControl
{
	//! This is for accessing to the RobotInterface.
	RobotInterface* robot;
	//! This vector stores the sensors' adresses.
	vector <RangeSensor*>sensor;
	//! This is for accessing to the Position.
	Position* position;
public:
	//! Constructor.
	/*
		\param _robot previously created robot's adress to be able to control it.
		\param _laser previously created laser sensor's adress to access it within controller.
		\param _sonar previously created sonar sensor's adress to access it within controller.
		\param _pos previously created position object's adress to access it within controller.	
	*/
	RobotControl(RobotInterface* _robot, RangeSensor* _laser, RangeSensor*  _sonar, Position* _pos) :robot(_robot), position(_pos) {
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
