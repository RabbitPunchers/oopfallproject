#include "RobotControl.h"




RobotControl::~RobotControl()
{
	
}

void RobotControl::safeMove(int speed)
{
	
	while (true) {
		robot.update();
		if (sensor[0]->getMin() < 40)
			break;
		robot.move(speed);
		Sleep(1000);
	}
	
}
void RobotControl::turnLeft()
{
	robot.turn(RobotInterface::left);
}
void RobotControl::turnRight()
{
	robot.turn(RobotInterface::right);
}
void RobotControl::forward()
{
	robot.move(50);
}
void RobotControl::print()
{
	cout << "X: " << position->getX() << " Y: " << position->getY() << endl;
	cout << "Facing Direction in Degree: " << position->getTh() << endl;
	cout << "-----------------------------------------" << endl << "Laser Sensor's range to the nearest wall: " << sensor[0]->getMin();
	cout << endl << "Sonar Sensor's ranges by index number: " << endl;
	for (int i = 0; i < 16; i++)
		 {
			cout << "Index: " << i << "// Range: " << sensor[1]->getRange(i) << endl;
		}
}
void RobotControl::moveDistance(float distance)
{
	float t = 0;
	for (t; t = distance / 50;)
		 {
		robot.update();
		if (sensor[0]->getMin() < 40)
			 break;
		robot.move(50);
		Sleep(1000);
		t += 1;
		}

	
}
void RobotControl::closeWall() {
	safeMove(50);
}
