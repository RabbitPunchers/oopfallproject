#pragma once
#include <vector>
#include "PioneerRobotInterface.h"
#include <iostream>
#include "LaserSensor.h"
#include "SonarSensor.h"
#define FOREVER while(true);
using namespace std;

class RobotControl
{
	PioneerRobotInterface* robot;
	vector <RangeSensor*>sensor;
	Position* position;
public:
	RobotControl(PioneerRobotInterface* _robot, LaserSensor * _laser, SonarSensor*  _sonar) :robot(_robot) {
		sensor.push_back(_laser);
		sensor.push_back(_sonar);
	}
	~RobotControl();
	void safeMove(int speed);
	void turnLeft();
	void turnRight();
	void forward();
	void print();
	void moveDistance(float distance);
	void closeWall();
};

