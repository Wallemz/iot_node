#ifndef SENSOR_H
#define SENSOR_H

#include <Wire.h>
#include "Adafruit_Si7021.h"

class Sensor {
	public:
		Sensor();
		bool init(HardwareSerial* serial);
		float readTemperature();
		float readHumidity();
	private:
		Adafruit_Si7021 sensor = Adafruit_Si7021();
		HardwareSerial* serial;
};

#endif