#include "display.h"

// Constructor
Display::Display() : serial(nullptr) {}

// Inicializa la pantalla OLED y configura el objeto Serial
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

bool Display::printMessage(String message, unsigned int row, unsigned int column) {
    if (row > 7 || column > 127 || row <= 1)
    {
        return false;
    }
    
    oled.setTextXY(row,column);
    oled.putString(message.c_str());
    return true;
}