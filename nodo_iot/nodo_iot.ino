#include "actuator.h"
#include "display.h"
#include "logos.h"
#include "sensor.h"

Actuator actuator1(LED_BUILTIN);
Actuator actuator2(7);
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

    delay(1000);
    actuator1.turnOff();
    actuator2.turnOn();
    delay(1000);
    actuator1.turnOn();
    actuator2.turnOff();
  }
}
