#include "logos.h"
#include "display.h"

Display display;

void setup() {
  // Serial setup
  Serial.begin(115200);

  // Display setup
  display.init(&Serial);
  display.printLogo(LOGO, 1024);
  
  delay(2000);
}

void loop() {
  Serial.println("Starting Node...");
  display.printHeader();
  display.printMessage("Hello World!", 2, 0);
  delay(5000);
}
