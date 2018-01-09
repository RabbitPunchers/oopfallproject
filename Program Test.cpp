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
	bool onoff = false;
	SonarSensor* sonar = new SonarSensor;
	LaserSensor* laser = new LaserSensor;
	PioneerRobotInterface* robot = new PioneerRobotInterface;
	Position* posis = new Position;
	RobotControl controller(robot, laser, sonar, posis);
	robot->setPosition(posis);
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
			if (robot->open())
			{
				cout << "Robot is connected succesfully." << endl << endl;
				onoff = true;
			}
			else
				cout << "Robot connection is unsuccessful." << endl << endl;
		}
		else if (sw1 == 2) //ROBOT DISCONNECTION
		{
			system("cls");
			if (robot->close())
			{
				cout << "Robot is disconnected succesfully." << endl << endl;
				onoff = false;
			}
			else
				cout << "Robot disconnecion is unsuccessful" << endl << endl;
		}
		else if (sw1 == 3)
			{
				system("cls");
				break;
			}
		}
		break;
	case 2: // Motion Menu
		if (!onoff)
		{
			system("cls");
			cout << "**************************" << endl;
			cout << "*  Please connect robot  *" << endl;
			cout << "* before accessing menus *" << endl;
			cout << "**************************" << endl << endl << endl;
			break;
		}
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
			cout << "Robot is moving with speed 300. It will stop when it get closes the wall." << endl;
			controller.safeMove(300);
		}
		else if (sw2 == 3)
		{
			system("cls");
			cout << "Robot is turning left." << endl << endl;
			controller.turnLeft();

		}
		else if (sw2 == 4)
		{
			system("cls");
			cout << "Robot is turning left." << endl << endl;
			controller.turnRight();
		}
		else if (sw2 == 5)
		{
			system("cls");
			cout << "Robot is moving with speed 50." << endl << endl;
			controller.forward();

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
			cout << "Robot is moving with speed 50. It will stop when it get closes the wall." << endl << endl;
			controller.closeWall();
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
		if (!onoff)
		{
			system("cls");
			cout << "**************************" << endl;
			cout << "*  Please connect robot  *" << endl;
			cout << "* before accessing menus *" << endl;
			cout << "**************************" << endl << endl << endl;
			break;
		}
		FOREVER{
			cout << "Select Sensor: " << endl << "1. Laser Sensor" << endl << "2. Sonar Sensor" << endl << "3. Print all" << endl << "4. Back" << endl << "Choose One: ";
		cin >> sw3;
		if (sw3 == 1)
			{
				system("cls");
				cout << "Min: " << laser->getMin() << " Max: " << laser->getMax() << endl << endl;
			}
		else if (sw3 == 2)
			{
				robot->update();
				system("cls");
				int sonar_index;
				cout << "Enter the index(Enter -1 to see them all.): ";
				cin >> sonar_index;
			if (sonar_index == -1)
			{
				system("cls");
				cout << "Robot's solar sensor's ranges are:" << endl;
				for (int _index = 0; _index < 16; _index++)
					cout << "Sensor[" << _index << "] :" << sonar->getRange(_index) << endl;
			}
			else if (sonar_index > -1 && sonar_index < 16)
				cout << "Sensor number " << sonar_index << ": " << sonar->getRange(sonar_index) << endl << endl;
			else
				cout << "**Error**" << endl << "Please specify a number between -1 and 15" << endl;
			}
		else if (sw3 == 3)
		{
			robot->update();
			system("cls");
			controller.print();

		}

		else if (sw3 == 4)
			{
			system("cls");
			break;
			}
		}
		break;
	case 4: // Quit Selection
		return 0;
	default: // Default Menu
		system("cls");
		cout << "Please type numbers between 1-4.";
		break;

		}
	}
}