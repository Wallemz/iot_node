#include "sensor.h"

Sensor::Sensor() : serial(nullptr) {}

bool Sensor::init(HardwareSerial* serial) {
    this->serial = serial;
    
    if (!sensor.begin()) {
        serial->println("Could not find a valid sensor, check wiring!");
        return false;
    }

    return true;
}

float Sensor::readTemperature() {
    return sensor.readTemperature();
}

float Sensor::readHumidity() {
    return sensor.readHumidity();
}