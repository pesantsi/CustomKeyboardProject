// OledDisplay.h

#ifndef _OLEDDISPLAY_h
#define _OLEDDISPLAY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define XPOS   0 // Indexes into the 'icons' array in function below
#define YPOS   1
#define DELTAY 2

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

static const unsigned char PROGMEM logo_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000
};

class OledDisplay_
{
public:
	void testdrawline();
	void testdrawrect();
	void testfillrect();
	void testdrawcircle();
	void testfillcircle();
	void testdrawroundrect();
	void testfillroundrect();
	void testdrawtriangle();
	void testfilltriangle();
	void testdrawchar();
	void testdrawstyles();
	void testscrolltext();
	void testdrawbitmap();
	void testanimate(uint8_t w, uint8_t h);

	void Setup();
	void ShowText(char text[]);

private:
	Adafruit_SSD1306 m_display;

};

extern OledDisplay_ OledDisplay;
#endif

