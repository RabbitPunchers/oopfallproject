#pragma once
#include "RobotInterface.h"
#include "PioneerRobotAPI.h"
class PioneerRobotInterface :  public RobotInterface, public PioneerRobotAPI
{
public:
	PioneerRobotInterface();
	void update();
	bool open();
	void move(float speed);
	bool close();
	void turn(RobotInterface::DIRECTION dir);
	void stop();
	void updateRobot();
	~PioneerRobotInterface();
};

