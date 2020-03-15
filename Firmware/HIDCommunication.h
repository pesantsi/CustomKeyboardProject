// HIDCommunication.h

#ifndef _HIDCOMMUNICATION_h
#define _HIDCOMMUNICATION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <SPI.h>
#include <Wire.h>
#include <HID-Settings.h>
#include <HID-Project.h>

class HIDCommunication_
{
public:

	void Setup();
	void Loop();

};

extern HIDCommunication_ HIDCommunication;

#endif

