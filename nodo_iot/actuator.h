#ifndef ACTUATOR_H
#define ACTUATOR_H

class Actuator {
    public:
        Actuator(int ledPin);
        void turnOn();
        void turnOff();
    private:
        int ledPin;
};

#endif