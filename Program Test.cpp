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
	
	SonarSensor* sonar = new SonarSensor;
	LaserSensor* laser = new LaserSensor;
	PioneerRobotInterface* robot = new PioneerRobotInterface;
	RobotControl controller(robot, laser, sonar);
	robot->setSensor(laser, sonar);

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
			if (robot->open()) {
				cout << "Robot is connected succesfully." << endl << endl;
			}
			else
			{
				cout << "Robot connection is unsuccessful." << endl << endl;
			}
		}
		else if (sw1 == 2) //ROBOT DISCONNECTION
		{
			system("cls");
			if (robot->close()) {
				cout << "Robot is disconnected succesfully." << endl << endl;
			}
			else 
			{
				cout << "Robot disconnecion is unsuccessful" << endl << endl;
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
		cout << "5. Forward" << endl << "6. Move Distance" << endl << "7. Close Wall" << endl << "8. Stop Robot" << endl << "9. Back" << endl << "Choose One : ";
		cin >> sw2;
		if (sw2 == 1)
		{
			system("cls");
			robot->move(50);
			cout << "Robot is moving with speed 50." << endl << endl;
			cout << "Min: " << laser->getMin() << " max: " << laser->getMax() << endl;;
		}			
		else if (sw2 == 2)
		{
			system("cls");
			controller.safeMove(1000);
			cout << "Robot is moving with speed 80. It will stop when it get closes the wall." << endl << endl;
		}
		else if (sw2 == 3)
		{
			system("cls");
			controller.turnLeft();
			cout << "Robot is turning left." << endl << endl;
		}
		else if (sw2 == 4)
		{
			system("cls");
			controller.turnRight();
			cout << "Robot is turning left." << endl << endl;
		}
		else if (sw2 == 5)
		{
			system("cls");
			controller.forward();
			cout << "Robot is moving with speed 50." << endl << endl;
		}
		else if (sw2 == 6)
		{
			float dist;
			cout << "Please enter desired distance: ";
			cin >> dist;
			controller.moveDistance(dist);
		}
		else if (sw2 == 7)
		{
			system("cls");
			controller.closeWall();
			cout << "Robot is moving with speed 50. It will stop when it get closes the wall." << endl << endl;
		}
		else if (sw2 == 8)
		{
			system("cls");
			robot->stop();
			cout << "Robot has stopped." << endl << endl;
		}
		else if (sw2 == 9)
		{
			system("cls");
			break;
		}
	}
		break;
	case 3: // Sensor Menu
		FOREVER{
			cout << "Select Sensor: " << endl << "1. Laser Sensor" << endl << "2. Sonar Sensor" << "3.Back"<<endl;
		cin >> sw3;
		if (sw3 == 1)
			{
				cout << "Min: " << laser->getMin() << " max: " << laser->getMax() << endl;;
			}
		else if(sw3 == 2)
		{
			int sonar_index;
			cout << "Enter the index: " << endl;
			cin >> sonar_index;
			sonar->getRange(sonar_index);
		}

		else if (sw3 == 3)
		{
			system("cls");
			break;
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