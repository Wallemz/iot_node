#include "actuator.h"
#include <Arduino.h>

Actuator::Actuator(int ledPin) {
    this->ledPin = ledPin;
    pinMode(this->ledPin, OUTPUT);
}

void Actuator::turnOn() {
    digitalWrite(this->ledPin, HIGH);
}

void Actuator::turnOff() {
    digitalWrite(this->ledPin, LOW);
}