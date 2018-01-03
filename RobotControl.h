#pragma once
#include "RobotInterface.h"
#include <iostream>
#include <vector>
#define FOREVER while(true);
using namespace std;
class RobotControl
{
	RobotInterface* robot;
	vector <RangeSensor*> sensor;
	Position* position;
public:
	RobotControl(RobotInterface *_robot, LaserSensor* _laser, SonarSensor* _sonar) :robot(_robot){
		sensor.reserve(2);
		sensor[0] = _laser;
		sensor[1] = _sonar;
	};
	~RobotControl();
	void safeMove(int speed);
	void turnLeft();
	void turnRight();
	void forward();
	void print();
	void moveDistance(float distance);
	void closeWall();
};

