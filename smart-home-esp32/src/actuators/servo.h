#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>

class ServoControl
{
public:
    void begin(uint8_t pin);
    void setAngle(int angle);
    void open();
    void close();
    void sweep(int startAngle, int endAngle, unsigned long stepMs);

private:
    uint8_t _pin;
    int _currentAngle;
    int _targetAngle;
    unsigned long _lastStepTime;
};

#endif // SERVO_H
