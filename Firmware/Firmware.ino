/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x32 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include "HIDCommunication.h"
#include "OledDisplay.h"

void setup()
{
	Serial.begin(9600);

	HIDCommunication.Setup();
	OledDisplay.Setup();
}

void loop()
{
	//// Send data to the host
	//if (!digitalRead(pinButton)) 
	//{
	//	digitalWrite(pinLed, HIGH);

	//	// Create buffer with numbers and send it
	//	uint8_t megabuff[100];
	//	for (uint8_t i = 0; i < sizeof(megabuff); i++) {
	//		megabuff[i] = i;
	//	}
	//	RawHID.write(megabuff, sizeof(megabuff));

	//	// Simple debounce
	//	delay(300);
	//	digitalWrite(pinLed, LOW);
	//}


}

