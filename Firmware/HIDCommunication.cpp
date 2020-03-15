// 
// 
// 
#include "HIDCommunication.h"
#include "OledDisplay.h"

uint8_t m_rawhidData[255];

void HIDCommunication_::Setup()
{
	RawHID.begin(m_rawhidData, sizeof(m_rawhidData));
}

void HIDCommunication_::Loop()
{

	// Check if there is new data from the RawHID device
	auto bytesAvailable = RawHID.available();
	if (bytesAvailable)
	{
		//digitalWrite(pinLed, HIGH);

		// Mirror data via Serial
		while (bytesAvailable--)
		{
			//OledDisplay.ShowText(RawHID.read())
			Serial.println(RawHID.read());
		}

		//digitalWrite(pinLed, LOW);
	}
}