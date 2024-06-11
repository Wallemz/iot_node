#ifndef DISPLAY_H
#define DISPLAY_H

#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>

class Display {
	public:
		Display();
		void init(HardwareSerial* serial);
		void printLogo(unsigned char *logo, int size);
		void printHeader();
		bool printMessage(String message, unsigned int row, unsigned int column);
		void printError(String message);
	private:
		ACROBOTIC_SSD1306 oled;
		HardwareSerial* serial;
		void printErrorHeader();
};

#endif