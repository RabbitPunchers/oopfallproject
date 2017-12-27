#include <iostream>
#include <string>
#include "PioneerRobotInterface.h"
#define FOREVER while(true)
using namespace std;

int main()
{
	int sw1, sw2, sw3, swm;
	PioneerRobotInterface robot;
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
						if (!robot.open()) {
							cout << "Robot connection failed." << endl << endl;
						}
						else if (robot.open()) {
							cout << "Robot is connected succesfully." << endl << endl;
						}
					}
					else if (sw1 == 2) //ROBOT DISCONNECTION
					{
						system("cls");
						if (!robot.close()) {
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
				}
				break;
			case 3: // Sensor Menu
				FOREVER{

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