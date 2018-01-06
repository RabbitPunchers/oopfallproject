#include <iostream>
#include <string>
#include "PioneerRobotInterface.h"
#include "RobotControl.h"
#include "SonarSensor.h"
#include "LaserSensor.h"
#define FOREVER while(true)
using namespace std;

int main()
{
	int sw1, sw2, sw3, swm;
	PioneerRobotInterface robot;
	SonarSensor* sonar = new SonarSensor;
	LaserSensor* laser = new LaserSensor;
	RobotControl controller(robot, laser, sonar);

	FOREVER{
		cout << "Main Menu" << endl << "1. Connection" << endl << "2. Motion" << endl << "3. Sensor" << endl << "4. Quit" << endl << "Choose one : ";
	cin >> swm;
	system("cls");
	switch (swm)
	{
	case 1: // Connection Menu	
		FOREVER{
			cout << "Connection Menu" << endl << "1. Connect Robot" << endl << "2. Disconnect Robot" << endl << "3. Back" << endl << "Choose one : ";
		cin >> sw1;
		if (sw1 == 1) //ROBOT CONNECTION
		{
			system("cls");
			if (robot.open() == false) {
				cout << "Robot connection failed." << endl << endl;
				
			}
			else if (robot.open()) {
				cout << "Robot is connected succesfully." << endl << endl;
			}
		}
		else if (sw1 == 2) //ROBOT DISCONNECTION
		{
			system("cls");
			if (robot.close()==false) {
				cout << "Robot disconnection failed." << endl << endl;
			}
			if (robot.close()) {
				cout << "Robot is disconnected succesfully." << endl << endl;
			}
		}
		else if (sw1 == 3)
			{
				system("cls");
				break;
			}
		}
		break;
	case 2: // Motion Menu
		FOREVER{
			cout << "Motion Menu" << endl << "1. Move Robot" << endl << "2. Safe Move Robot" << endl << "3. Turn Left" << endl << "4. Turn Right" << endl;
		cout << "5. Forward" << endl << "6. Move Distance" << endl << "7. Close Wall" << endl << "8. Back" << endl << "Choose One : ";
		cin >> sw2;
		if (sw2 == 1)
			robot.move(50);
		else if (sw2 == 2)
			controller.safeMove(50);
		else if (sw2 == 3)
			controller.turnLeft();
		else if (sw2 == 4)
			controller.turnRight();
		else if (sw2 == 5)
			controller.forward();
		else if (sw2 == 6)
			controller.moveDistance(50);
		else if (sw2 == 7)
			controller.closeWall();
		else if (sw2 == 8)
		{
			system("cls");
			break;
		}
	}
		break;
	case 3: // Sensor Menu
		FOREVER{
			cout << "Select Sensor: " << endl << "1. Laser Sensor" << endl << "2. Sonar Sensor" << endl;
		cin >> sw3;
		if (sw3 == 1)
			{
			
	
			}
		}
		break;
	case 4: // Quit Selection
		return 0;
	default: // Default Menu
		cout << "Please type numbers between 1-4.";
		break;

	}
	}
}