/**
* @file RobotControl.cpp
* @Author Omer Berkan Calik, Ibrahim Berk Bulgan
* @date January, 2018
* @brief This file is for RobotControl class' function's definitions.
*/
#include "RobotControl.h"
#include <ctime>

RobotControl::~RobotControl()
{
	
}


/*!
	\param speed is an int argument. Which represents the robot's movement speed.
*/
void RobotControl::safeMove(int speed)
{
	while (true) {
		robot->update();
		if (sensor[1]->getRange(3) < 700 || sensor[1]->getRange(4) < 700)
			break;
		robot->move(300);
		Sleep(100);
		system("cls");
		cout << "Sonar Sensor's ranges by index number: " << endl;
		for (int i = 0; i < 6; i++)
		{
			cout << "Index: " << i << " // Range: " << sensor[1]->getRange(i) << endl;
		}
		cout << "min: " << sensor[1]->getMin() << endl << endl << "Robot will stop when it get close to a wall.";
	}
	robot->stop();
}
void RobotControl::turnLeft()
{
	robot->turn(RobotInterface::left);
}
void RobotControl::turnRight()
{
	robot->turn(RobotInterface::right);
}
void RobotControl::forward()
{
	robot->move(50);
}
void RobotControl::print()
{
	robot->update();
	cout << "X: " << position->getX() << " Y: " << position->getY() << endl;
	cout << "Facing Direction in Degree: " << position->getTh() << endl;
	cout << "-----------------------------------------" << endl << "Laser Sensor's range to the nearest wall: " << sensor[0]->getMin();
	cout << endl << "Sonar Sensor's ranges by index number: " << endl;
	for (int i = 0; i < 16; i++)
		 {
			cout << "Sonar Sensor[" << i << "] :" << sensor[1]->getRange(i) << endl;
		}
	cout << endl << endl;
}

/*!
	\param distance is a float argument. Which represents how many milimetres the robot will go.
*/
void RobotControl::moveDistance(float distance)
{
	int t = 0;
	for (t; t<=distance / 50;t = t + 1)
		 {
		robot->update();
		//if (sensor[1]->getMin() < 800)
			// break;
		robot->move(50);
		Sleep(1000);
		cout << "time: " << t << endl;
		cout << "distance: " << distance << endl;
		}

	robot->stop();
}
void RobotControl::closeWall() {
	robot->update();
	while (true)
	{
		robot->update();
		if (sensor[1]->getMin() < 700)
			break;
		robot->move(50);
		Sleep(100);
		system("cls");
		cout << "Sonar Sensor's ranges by index number: " << endl;
		for (int i = 0; i < 16; i++)
		{
			cout << "Index: " << i << " // Range: " << sensor[1]->getRange(i) << endl;
		}
		cout << "min: " << sensor[1]->getMin() << endl << endl << "Robot will stop when it get close to a wall.";
	}
	robot->stop();
	
}
