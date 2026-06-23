#ifndef DOOR_SENSOR_H
#define DOOR_SENSOR_H

#include <Arduino.h>

typedef void (*DoorCallback)(bool isOpen);

class DoorSensor
{
public:
    void begin(uint8_t pin);
    bool isOpen();
    bool isClosed();
    void onStateChange(DoorCallback cb);

private:
    uint8_t _pin;
    bool _doorOpen;
    unsigned long _lastChangeTime;
    DoorCallback _callback;
};

#endif // DOOR_SENSOR_H
