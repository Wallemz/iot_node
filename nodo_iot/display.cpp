#include "display.h"

Display::Display() : serial(nullptr) {}

void Display::init(HardwareSerial* serial) {
    this->serial = serial;
    Wire.begin();
    oled.init();
    oled.clearDisplay();
}

void Display::printLogo(unsigned char *logo, int size) {
    oled.drawBitmap(logo, size);
}

void Display::printHeader() {
    oled.clearDisplay();
    oled.setTextXY(0,0);
    oled.putString("  WalleM's Node");

    oled.setTextXY(1,0);
    oled.putString("    MKR 1300");
}

void Display::printErrorHeader() {
    oled.clearDisplay();
    oled.setTextXY(0,0);
    oled.putString("  WalleM's Node");

    oled.setTextXY(1,0);
    oled.putString("      ERROR");
}

bool Display::printMessage(String message, unsigned int row, unsigned int column) {
    if (row > 7 || column > 127 || row <= 1)
    {
        return false;
    }
    
    oled.setTextXY(row,column);
    oled.putString(message.c_str());
    return true;
}

void Display::printError(String message) {
    Display::printErrorHeader();
    int messageLength = message.length();
    int numLines = (messageLength + 15) / 16;

    if (numLines > 5) {
        numLines = 5; // limit the number of lines to 5 if the message is too long
    }

    for (int i = 0; i < numLines; i++) {
        String line = message.substring(i * 16, (i + 1) * 16); // extract 16 characters for each line
        oled.setTextXY(i + 2, 0); // start displaying the lines from the third row
        oled.putString(line);
    }
}