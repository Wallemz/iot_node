#include "logos.h"
#include "display.h"
#include "sensor.h"

Display display;
Sensor sensor;

void setup() {
  // Serial setup
  Serial.begin(115200);

  // Display setup
  display.init(&Serial);
  display.printLogo(LOGO, 1024);

  // Sensor setup
  if (!sensor.init(&Serial)) {
    Serial.println("Error initializing sensor");
    display.printError("Error initializing sensor");
    while (1);
  }
  
  delay(2000);
}

void loop() {
  Serial.println("Starting Node...");
  display.printHeader();

  while (true)
  {
    float temperature = sensor.readTemperature();
    float humidity = sensor.readHumidity();

    display.printMessage("T: " + String(temperature) + " C", 3, 0);
    display.printMessage("H: " + String(humidity) + " %", 4, 0);
    delay(500);
  }
}
