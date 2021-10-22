/*
 * mini_project_1.c
 *
 *  Created on: Sep 10, 2021
 *      Author: Omar Gomaa
 */

#include <stdio.h>
#include<string.h>
#include <stdlib.h>


//Global variables

int vehicle_speed  ;
int room_temperature ;
int engine_temp ;
char AC_state[10]= "OFF" ;
char engine_state[10]="OFF";
char engine_temp_state[10]="OFF" ;

//function declaration

void display () ;
void engine_on () ;
void traffic_light()  ;
void room_temp() ;
void engine_temperature() ;
void dis_current () ;










//function to display the main manu

void display (void) {

	char main_menu ;

	printf(" a.Turn on the vehicle engine \n b.Turn off the vehicle engine \n c. Quit the system \n") ;
	fflush(stdout);
	scanf(" %c",&main_menu);



	if (main_menu == 'c' || main_menu == 'C') {

		printf(" Quit the system \n") ;
		exit(0) ;
	}
	else if (main_menu == 'b' || main_menu == 'B'){
		printf(" Turn off the vehicle engine \n ") ;
		display();

	}
	else if (main_menu == 'a' || main_menu == 'A'){
		printf("Turn on the vehicle engine \n ") ;
		engine_on();
		strcpy(engine_state,"ON") ;



	}
	else {
		printf("Not found!!! ") ;
	}

	printf(" %c",main_menu) ;



}

//function to control the engine

void engine_on (void){

	char sensor_menu ;

	printf("a. Turn off the engine\n "
			"b. Set the traffic light color. \n "
			"c. Set the room temperature (Temperature Sensor) \n ");
	printf("d. Set the engine temperature (Engine Temperature Sensor) \n  ");


	scanf(" %c",&sensor_menu);

	if (sensor_menu == 'a' || sensor_menu == 'A' ) {
		printf("turn off the engine \n") ;
		display() ;

	}
	else if (sensor_menu == 'b' || sensor_menu == 'B' ) {
		printf("Set the traffic light color \n") ;
		traffic_light() ;
		dis_current ();
	}
	else if (sensor_menu == 'c' || sensor_menu == 'C' ) {
		printf("Set the room temperature (Temperature Sensor) \n") ;
		room_temp() ;
		dis_current ();
	}
	else if (sensor_menu == 'd' || sensor_menu == 'D' ) {
		printf("Set the engine temperature (engine Temperature Sensor) \n") ;

		engine_temperature() ;
		dis_current ();
	}

}

//function to control the speed of the vehicle

void traffic_light(void) {

	char light ;

	printf("enter the traffic light \n ( O , G , R)") ;

	scanf(" %c",&light) ;

	if (light == 'G' || light == 'g' ){
		vehicle_speed = 100 ;
	}
	else if (light == 'o' || light == 'O') {
		vehicle_speed = 30 ;
		strcpy(AC_state,"ON") ;
		strcpy(engine_temp_state,"ON") ;
		room_temperature = room_temperature * (5/4) +1 ;
		engine_temp = engine_temp * (5/4) + 1  ;


	}
	else if (light == 'r' || light == 'R') {
		vehicle_speed = 0 ;
	}

	else {
		printf("Not found !!");
	}



}

//function to control the room tempretaure

void room_temp(void) {

	int temp ;

	printf("enter the temperature of the room \n ") ;

	scanf("%d",&temp) ;

	if (temp < 10 || temp > 30) {
		room_temperature  = 20 ;
		strcpy(AC_state,"ON") ;
	}
	else {
		strcpy(AC_state ,"OFF");
	}


}

//function to control the engine temperature

void engine_temperature(void) {

	int temp ;

	printf("enter the temperature of the engine \n") ;

	scanf(" %d",&temp) ;


	if (temp <100 || temp >150 ) {
		engine_temp =125 ;
		strcpy(engine_temp_state,"ON") ;
	}
	else {
		strcpy(engine_temp_state,"OFF") ;
	}

}

//function to display the current state of the engine

void dis_current (void) {

	printf("\nEngine state : %s \n",engine_state) ;
	printf("AC : %s \n",AC_state) ;
	printf("Vehicle speed : %d KM \n" , vehicle_speed) ;
	printf("Room temperature : %d  \n",room_temperature) ;
	printf("Engine Temperature Controller State : %s \n" ,engine_temp_state) ;
	printf("Engine Temperature : %d \n" ,engine_temp) ;


}






int main() {


	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);


	while(1){
	display ();
	printf("\n");
	}

	return 0 ;

}







