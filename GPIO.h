/******************************************************************
 *  Filename: GPIO.h
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
 *  (Fill in a detailed description of the source code file).
 *****************************************************************/

#ifndef GPIO_H_
#define GPIO_H_

#include <string>
#include <fstream>

using std::string;
using std::ofstream;

//int myVariable;

#define GPIO_PATH "/sys/class/gpio/"

namespace GPIO_RPi{

	typedef int (*CallbackType)(int);

	enum GPIO_DIRECTION {
		INPUT,
		OUTPUT
	};

	enum GPIO_VALUE {
		LOW = 0,
		HIGH = 1
	};

	enum GPIO_EDGE {
		NONE,
		RISING,
		FALLING,
		BOTH
	};

	class GPIO {

	private:
		int number, debounceTime;
		string name, path;
		//char name[], path[];

	public:
		GPIO(int number);

		virtual int getNumber() {
			return number;
		}

		// General I/O Settings
		virtual int setDirection(GPIO_DIRECTION);
		virtual GPIO_DIRECTION getDirection();
		virtual int setValue(GPIO_VALUE);
		virtual int toggleOutput();
		virtual GPIO_VALUE getValue();
		virtual int setActiveLow(bool isLow = true);	// low=1, high=0
		virtual int setActiveHigh();					// This is the default state
		virtual void setDebounceTime(int time) {
			this->debounceTime = time;
		}

		virtual ~GPIO();


	private:
		int write(string path, string filename, string value);
		int write(string path, string filename, int value);
		string read(string path, string filename);
		int exportGPIO();
		int unexportGPIO();
		ofstream stream;
		pthread_t thread;
		CallbackType callbackFunction;
		bool threadRunning;
		int togglePeriod;  // default 100ms
		int toggleNumber;  // default -1 (infinite)
		//friend void* threadedPoll(void *value);
		//friend void* threadedToggle(void *value);

	};

	//void* threadedPoll(void *value);
	//void* threadedToggle(void *value);
}


#endif /* End of file */
