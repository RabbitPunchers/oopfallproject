#pragma once
#include "RobotInterface.h"
class PioneerRobotInterface : public PioneerRobotAPI, public RobotInterface
{
public:
	PioneerRobotInterface();
	void update();
	bool open();
	void move(float speed);
	bool close();
	void turn(PioneerRobotAPI::DIRECTION dir);
	void stop();
	void updateRobot();
	~PioneerRobotInterface();
};

