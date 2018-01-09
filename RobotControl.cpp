#include "RobotControl.h"




RobotControl::~RobotControl()
{
	
}

void RobotControl::safeMove(int speed)
{
	while (true) {
		robot->update();
		if (sensor[1]->getRange(13) < 700 || sensor[1]->getRange(4) < 700)
			break;
		robot->move(300);
		Sleep(100);
		cout << "Laser: "<< sensor[0]->getMin() << endl;
		cout << "Sonar0:" << sensor[1]->getRange(0) << endl;
		cout << "Sonar1:" << sensor[1]->getRange(1) << endl;
		cout << "Sonar2:" << sensor[1]->getRange(2) << endl;
		cout << "Sonar3:" << sensor[1]->getRange(3) << endl;
		cout << "Sonar4:" << sensor[1]->getRange(4) << endl;
		cout << "Sonar5:" << sensor[1]->getRange(5) << endl;
		cout << "Sonar6:" << sensor[1]->getRange(6) << endl;
		
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
		robot->update();
		if (sensor[0]->getMin() < 40)
			 break;
		robot->move(50);
		Sleep(1000);
		t += 1;
		}

	robot->stop();
}
void RobotControl::closeWall() {
	robot->update();
	cout << endl << "Sonar Sensor's ranges by index number: " << endl;
	for (int i = 0; i < 16; i++)
	{
		cout << "Index: " << i << "// Range: " << sensor[1]->getRange(i) << endl;
	}

	cout <<"min: "<< sensor[1]->getMin() << endl;

	while (true) {
		robot->update();
		if (sensor[1]->getMin() < 300)
			break;
		robot->move(100);
		Sleep(100);

	}

	robot->stop();
	
}
