#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>

enum RelayChannel { RELAY_FAN = 0, RELAY_APPLIANCE = 1 };

class Relay
{
public:
    void begin(uint8_t fanPin, uint8_t appliancePin);
    void on(RelayChannel channel);
    void off(RelayChannel channel);
    bool isOn(RelayChannel channel);

private:
    uint8_t _pins[2];
    bool _state[2];
    unsigned long _switchCount[2];
};

#endif // RELAY_H
