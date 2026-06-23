#ifndef PIR_SENSOR_H
#define PIR_SENSOR_H

#include <Arduino.h>

typedef void (*MotionCallback)();

class PirSensor
{
public:
    void begin(uint8_t pin);
    bool isMotionDetected();
    bool isStable();
    void resetStableTimer();
    void onMotionStart(MotionCallback cb);
    void onMotionEnd(MotionCallback cb);

private:
    uint8_t _pin;
    bool _motionState;
    unsigned long _lastTriggerTime;
    unsigned long _stableTimeout;
    MotionCallback _onStart;
    MotionCallback _onEnd;
};

#endif // PIR_SENSOR_H
