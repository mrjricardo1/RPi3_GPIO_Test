/******************************************************************
 *  Filename: myGPIO.cpp
 *  Project name: Roboticos-UPB Reto
 *
 *  Copyright 2020 Meech International Ltd as an unpublished work.
 *  All Rights Reserved.
 *
 *  The information contained herein is confidential property of ....
 *  The use, copying, transfer or disclosure of such information is
 *  prohibited expect by express written agreement with ....
 *
 *  First written on 28/01/2020 by RM
 *
 *  File History:
 *
 *  Rev     Date     	Description
 *  1.0		01.2020		Initial File
 *
 *  Description:
 *  Simple program to switch on/off an LED on pin-36 (GPIO16) of the RPi-3.
 *****************************************************************/

/******************************************************************
 * System Includes Files
 *****************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <ctype.h>
#include <sys/mman.h>
#include <time.h>


/*****************************************************************
 * User Includes Files
 *****************************************************************/
#include "GPIO.h"


using namespace GPIO_RPi;
using namespace std;

int poll_ms;

int main( int argc, char** argv ) {

	printf( ">>>>>>>>>>>>>>>> ROBOTICOS UPB - RETO 1 <<<<<<<<<<<<<<<\n");
	printf( "28-Ene-2020\n");

	if( argc == 2 ) {
		poll_ms = atoi( argv[ 1 ] );

		if( poll_ms < 500 || poll_ms > 30000 ){
			printf( "El valor en %dms entrado es invalido. El valor debe ser entre 500mS y 30000 mS\n" , poll_ms );
			poll_ms = 1000;
			printf( "El valor cargado por default es: %dmS\n" , poll_ms );
		}
	}
	else {
		poll_ms = 1000;
		printf( "No valor fue entrado. Se usara por default: %dmS\n" , poll_ms );
	}
	printf( "Empieza la sequencia On/Off del LED usando: %dmS\n" , poll_ms );
	poll_ms *= 1000;

	GPIO myOutGPIO(16);					// Using Pin36 (GPIO16)

	myOutGPIO.setDirection(OUTPUT);		// Set IO as Output

	for (int i=0; i<10; i++) {
		myOutGPIO.setValue(HIGH);
		usleep(poll_ms);
		//usleep(500000);
		myOutGPIO.setValue(LOW);
		usleep(poll_ms);
		//usleep(500000);
	}
}
