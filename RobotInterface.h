#pragma once
#include "Position.h"
#include "SonarSensor.h"
#include "LaserSensor.h"
#include "PioneerRobotAPI.h"
using namespace std;
class RobotInterface
{
public:
	enum DIRECTION {
		LEFT = -1, FORWARD = 0, RIGHT = 1
	};
	RobotInterface();
	void setPosition(Position* pos);
	void setSensor(RangeSensor* sen);
	virtual void update() = 0;
	virtual bool open() = 0;
	virtual bool close() = 0;
	virtual void move(float speed) = 0;
	virtual void turn(DIRECTION dir) = 0;
	virtual void stop() = 0;
	virtual ~RobotInterface();

private:
	Position* position;
	RangeSensor* rangeSensor;
};

