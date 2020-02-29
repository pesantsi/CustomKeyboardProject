// 
// 
// 

#include "OledDisplay.h"

	// Declaration for an SSD1306 m_display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

void OledDisplay_::setup()
{
	m_display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
	// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
	if (!m_display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
		Serial.println(F("SSD1306 allocation failed"));
		for (;;); // Don't proceed, loop forever
	}

	// Show initial display buffer contents on the screen --
	// the library initializes this with an Adafruit splash screen.
	m_display.display();
	delay(2000); // Pause for 2 seconds

	// Clear the buffer
	m_display.clearDisplay();

	// Draw a single pixel in white
	m_display.drawPixel(10, 10, SSD1306_WHITE);

	// Show the display buffer on the screen. You MUST call display() after
	// drawing commands to make them visible on screen!
	m_display.display();
	delay(2000);
	// display.display() is NOT necessary after every single drawing command,
	// unless that's what you want...rather, you can batch up a bunch of
	// drawing operations and then update the screen all at once by calling
	// display.display(). These examples demonstrate both approaches...

	testdrawline();      // Draw many lines

	testdrawrect();      // Draw rectangles (outlines)

	testfillrect();      // Draw rectangles (filled)

	testdrawcircle();    // Draw circles (outlines)

	testfillcircle();    // Draw circles (filled)

	testdrawroundrect(); // Draw rounded rectangles (outlines)

	testfillroundrect(); // Draw rounded rectangles (filled)

	testdrawtriangle();  // Draw triangles (outlines)

	testfilltriangle();  // Draw triangles (filled)

	testdrawchar();      // Draw characters of the default font

	testdrawstyles();    // Draw 'stylized' characters

	testscrolltext();    // Draw scrolling text

	testdrawbitmap();    // Draw a small bitmap image

	// Invert and restore display, pausing in-between
	m_display.invertDisplay(true);
	delay(1000);
	m_display.invertDisplay(false);
	delay(1000);

	testanimate(logo_bmp, LOGO_WIDTH, LOGO_HEIGHT); // Animate bitmaps

}

void OledDisplay_::testdrawline()
{
	int16_t i;

	m_display.clearDisplay(); // Clear m_display buffer

	for (i = 0; i < m_display.width(); i += 4) {
		m_display.drawLine(0, 0, i, m_display.height() - 1, SSD1306_WHITE);
		m_display.display(); // Update screen with each newly-drawn line
		delay(1);
	}
	for (i = 0; i < m_display.height(); i += 4) {
		m_display.drawLine(0, 0, m_display.width() - 1, i, SSD1306_WHITE);
		m_display.display();
		delay(1);
	}
	delay(250);

	m_display.clearDisplay();

	for (i = 0; i < m_display.width(); i += 4) {
		m_display.drawLine(0, m_display.height() - 1, i, 0, SSD1306_WHITE);
		m_display.display();
		delay(1);
	}
	for (i = m_display.height() - 1; i >= 0; i -= 4) {
		m_display.drawLine(0, m_display.height() - 1, m_display.width() - 1, i, SSD1306_WHITE);
		m_display.display();
		delay(1);
	}
	delay(250);

	m_display.clearDisplay();

	for (i = m_display.width() - 1; i >= 0; i -= 4) {
		m_display.drawLine(m_display.width() - 1, m_display.height() - 1, i, 0, SSD1306_WHITE);
		m_display.display();
		delay(1);
	}
	for (i = m_display.height() - 1; i >= 0; i -= 4) {
		m_display.drawLine(m_display.width() - 1, m_display.height() - 1, 0, i, SSD1306_WHITE);
		m_display.display();
		delay(1);
	}
	delay(250);

	m_display.clearDisplay();

	for (i = 0; i < m_display.height(); i += 4) {
		m_display.drawLine(m_display.width() - 1, 0, 0, i, SSD1306_WHITE);
		m_display.display();
		delay(1);
	}
	for (i = 0; i < m_display.width(); i += 4) {
		m_display.drawLine(m_display.width() - 1, 0, i, m_display.height() - 1, SSD1306_WHITE);
		m_display.display();
		delay(1);
	}

	delay(2000); // Pause for 2 seconds
}

void OledDisplay_::testdrawrect()
{
	m_display.clearDisplay();

	for (int16_t i = 0; i < m_display.height() / 2; i += 2) {
		m_display.drawRect(i, i, m_display.width() - 2 * i, m_display.height() - 2 * i, SSD1306_WHITE);
		m_display.display(); // Update screen with each newly-drawn rectangle
		delay(1);
	}

	delay(2000);
}

void OledDisplay_::testfillrect()
{
	m_display.clearDisplay();

	for (int16_t i = 0; i < m_display.height() / 2; i += 3) {
		// The INVERSE color is used so rectangles alternate white/black
		m_display.fillRect(i, i, m_display.width() - i * 2, m_display.height() - i * 2, SSD1306_INVERSE);
		m_display.display(); // Update screen with each newly-drawn rectangle
		delay(1);
	}

	delay(2000);
}

void OledDisplay_::testdrawcircle()
{
	m_display.clearDisplay();

	for (int16_t i = 0; i < max(m_display.width(), m_display.height()) / 2; i += 2) {
		m_display.drawCircle(m_display.width() / 2, m_display.height() / 2, i, SSD1306_WHITE);
		m_display.display();
		delay(1);
	}

	delay(2000);
}

void OledDisplay_::testfillcircle()
{
	m_display.clearDisplay();

	for (int16_t i = max(m_display.width(), m_display.height()) / 2; i > 0; i -= 3) {
		// The INVERSE color is used so circles alternate white/black
		m_display.fillCircle(m_display.width() / 2, m_display.height() / 2, i, SSD1306_INVERSE);
		m_display.display(); // Update screen with each newly-drawn circle
		delay(1);
	}

	delay(2000);
}

void OledDisplay_::testdrawroundrect()
{
	m_display.clearDisplay();

	for (int16_t i = 0; i < m_display.height() / 2 - 2; i += 2) {
		m_display.drawRoundRect(i, i, m_display.width() - 2 * i, m_display.height() - 2 * i,
			m_display.height() / 4, SSD1306_WHITE);
		m_display.display();
		delay(1);
	}

	delay(2000);
}

void OledDisplay_::testfillroundrect()
{
	m_display.clearDisplay();

	for (int16_t i = 0; i < m_display.height() / 2 - 2; i += 2) {
		// The INVERSE color is used so round-rects alternate white/black
		m_display.fillRoundRect(i, i, m_display.width() - 2 * i, m_display.height() - 2 * i,
			m_display.height() / 4, SSD1306_INVERSE);
		m_display.display();
		delay(1);
	}

	delay(2000);
}

void OledDisplay_::testdrawtriangle()
{
	m_display.clearDisplay();

	for (int16_t i = 0; i < max(m_display.width(), m_display.height()) / 2; i += 5) {
		m_display.drawTriangle(
			m_display.width() / 2, m_display.height() / 2 - i,
			m_display.width() / 2 - i, m_display.height() / 2 + i,
			m_display.width() / 2 + i, m_display.height() / 2 + i, SSD1306_WHITE);
		m_display.display();
		delay(1);
	}

	delay(2000);
}

void OledDisplay_::testfilltriangle()
{
	m_display.clearDisplay();

	for (int16_t i = max(m_display.width(), m_display.height()) / 2; i > 0; i -= 5) {
		// The INVERSE color is used so triangles alternate white/black
		m_display.fillTriangle(
			m_display.width() / 2, m_display.height() / 2 - i,
			m_display.width() / 2 - i, m_display.height() / 2 + i,
			m_display.width() / 2 + i, m_display.height() / 2 + i, SSD1306_INVERSE);
		m_display.display();
		delay(1);
	}

	delay(2000);
}

void OledDisplay_::testdrawchar()
{
	m_display.clearDisplay();

	m_display.setTextSize(1);      // Normal 1:1 pixel scale
	m_display.setTextColor(SSD1306_WHITE); // Draw white text
	m_display.setCursor(0, 0);     // Start at top-left corner
	m_display.cp437(true);         // Use full 256 char 'Code Page 437' font

	// Not all the characters will fit on the m_display. This is normal.
	// Library will draw what it can and the rest will be clipped.
	for (int16_t i = 0; i < 256; i++) {
		if (i == '\n') m_display.write(' ');
		else          m_display.write(i);
	}

	m_display.display();
	delay(2000);
}

void OledDisplay_::testdrawstyles()
{
	m_display.clearDisplay();

	m_display.setTextSize(1);             // Normal 1:1 pixel scale
	m_display.setTextColor(SSD1306_WHITE);        // Draw white text
	m_display.setCursor(0, 0);             // Start at top-left corner
	m_display.println(F("Hello, world!"));

	m_display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
	m_display.println(3.141592);

	m_display.setTextSize(2);             // Draw 2X-scale text
	m_display.setTextColor(SSD1306_WHITE);
	m_display.print(F("0x")); m_display.println(0xDEADBEEF, HEX);

	m_display.display();
	delay(2000);
}

void OledDisplay_::testscrolltext()
{
	m_display.clearDisplay();

	m_display.setTextSize(2); // Draw 2X-scale text
	m_display.setTextColor(SSD1306_WHITE);
	m_display.setCursor(10, 0);
	m_display.println(F("scroll"));
	m_display.display();      // Show initial text
	delay(100);

	// Scroll in various directions, pausing in-between:
	m_display.startscrollright(0x00, 0x0F);
	delay(2000);
	m_display.stopscroll();
	delay(1000);
	m_display.startscrollleft(0x00, 0x0F);
	delay(2000);
	m_display.stopscroll();
	delay(1000);
	m_display.startscrolldiagright(0x00, 0x07);
	delay(2000);
	m_display.startscrolldiagleft(0x00, 0x07);
	delay(2000);
	m_display.stopscroll();
	delay(1000);
}

void OledDisplay_::testdrawbitmap()
{
	m_display.clearDisplay();

	m_display.drawBitmap(
		(m_display.width() - LOGO_WIDTH) / 2,
		(m_display.height() - LOGO_HEIGHT) / 2,
		logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
	m_display.display();
	delay(1000);
}

#define XPOS   0 // Indexes into the 'icons' array in function below
#define YPOS   1
#define DELTAY 2

void OledDisplay_::testanimate(const uint8_t* bitmap, uint8_t w, uint8_t h)
{
	int8_t f, icons[NUMFLAKES][3];

	// Initialize 'snowflake' positions
	for (f = 0; f < NUMFLAKES; f++) {
		icons[f][XPOS] = random(1 - LOGO_WIDTH, m_display.width());
		icons[f][YPOS] = -LOGO_HEIGHT;
		icons[f][DELTAY] = random(1, 6);
		Serial.print(F("x: "));
		Serial.print(icons[f][XPOS], DEC);
		Serial.print(F(" y: "));
		Serial.print(icons[f][YPOS], DEC);
		Serial.print(F(" dy: "));
		Serial.println(icons[f][DELTAY], DEC);
	}

	for (;;) { // Loop forever...
		m_display.clearDisplay(); // Clear the m_display buffer

		// Draw each snowflake:
		for (f = 0; f < NUMFLAKES; f++) {
			m_display.drawBitmap(icons[f][XPOS], icons[f][YPOS], bitmap, w, h, SSD1306_WHITE);
		}

		m_display.display(); // Show the m_display buffer on the screen
		delay(200);        // Pause for 1/10 second

		// Then update coordinates of each flake...
		for (f = 0; f < NUMFLAKES; f++) {
			icons[f][YPOS] += icons[f][DELTAY];
			// If snowflake is off the bottom of the screen...
			if (icons[f][YPOS] >= m_display.height()) {
				// Reinitialize to a random position, just off the top
				icons[f][XPOS] = random(1 - LOGO_WIDTH, m_display.width());
				icons[f][YPOS] = -LOGO_HEIGHT;
				icons[f][DELTAY] = random(1, 6);
			}
		}
	}
}

OledDisplay_ OledDisplay;