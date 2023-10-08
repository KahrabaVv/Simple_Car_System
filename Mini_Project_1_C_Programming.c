/*
 * Mini_Project_1_C_Programming.c
 *
 *  Created on: Aug 10, 2023
 *      Author: Kerolossamehel-shaip
 */
#include <stdio.h>
int main()
{
	setbuf(stdout, NULL);
	int engineOn = 0;
	int Etemperature=90;
	int Rtemperature=35;
	int tempControllerOn=0;
	int acOn=0;
	int speed = 0;
	while(1){
		char input;
		printf("please enter your choise from the follwing\n");
		printf("a. Turn on the vehicle engine\n");
		printf("b. Turn off the vehicle engine\n");
		printf("c. Quit the system\n\n");
		scanf(" %c",&input);
		if(input=='c'){
			break;
		}
		switch(input){

		case'a':
			char input2;
			printf("Vehicle engine turned on.\n");
			engineOn = 1;

			while( engineOn == 1){
				printf("please enter your choise from the follwing\n");
				printf("a. Turn off the engine\n");
				printf("b. Set the traffic light color.\n");
				printf("c. Set the room temperature (Temperature Sensor)\n");
				printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
				scanf(" %c",&input2);
				if(input2=='a'){
					engineOn = 0;
					printf("Vehicle engine turned off.\n");
				}
				switch(input2){
				case 'b':
					char trafficLight;

					printf("Enter the traffic light reading (G/O/R): ");
					scanf(" %c", &trafficLight);

					switch (trafficLight) {
					case 'G':
						printf("Vehicle speed set to 100 km/hr.\n");
						speed=100;
						break;
					case 'O':
						printf("Vehicle speed set to 30 km/hr.\n");
						speed=30;
						acOn=1;
						Rtemperature=Rtemperature*(5/4)+1;
						tempControllerOn=1;
						Etemperature=Etemperature*(5/4)+1;
						break;
					case 'R':
						printf("Vehicle speed set to 0 km/hr.\n");
						speed=0;
						break;
					default:
						printf("Invalid traffic light reading.\n");
						break;

					}break;
				case 'c':


						printf("Enter the room temperature: ");
						scanf("%d", &Rtemperature);

						if (Rtemperature < 10 || Rtemperature > 30) {
							acOn = 1;
							Rtemperature = 20;
							printf("AC turned on. Temperature set to 20°C.\n");
						}
						if(speed==30){
							acOn=1;
							Rtemperature=Rtemperature*(5/4)+1;
						}
						else {
							acOn = 0;
							printf("AC turned off.\n");
						}
						break;
					case 'd':
						printf("Enter the engine temperature: ");
						scanf("%d", &Etemperature);

						if (Etemperature < 100 || Etemperature > 150) {
							tempControllerOn = 1;
							Etemperature = 125;

						}
						else {
							tempControllerOn = 0;

						}
						if(speed==30){
							tempControllerOn=1;
							Etemperature=Etemperature*(5/4)+1;


						}

						break;
				}
				printf("Current Vehicle State:\n");
				printf("Engine state: %s\n", engineOn ? "ON" : "OFF");
				printf("AC: %s\n", acOn ? "ON" : "OFF");
				printf("Vehicle Speed: %d km/hr\n", speed);
				printf("Room Temperature: %d\n", Rtemperature);
				printf("Engine Temperature Controller State: %s\n", tempControllerOn ? "ON" : "OFF");
				printf("Engine Temperature: %d\n", Etemperature);
				printf("\n");}

			break;

		case'b':
			engineOn = 0;
			printf("Vehicle engine turned off.\n");
			printf("What do you want to do next?\n");
			break;

		default:
			printf("Invalid choice. Please try again.\n");
			break;
		}

	}printf("program ended");

	return 0;
}
