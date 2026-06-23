#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include <Arduino.h>

enum LedChannel { LED_RED = 0, LED_GREEN = 1, LED_BLUE = 2 };

class LedControl
{
public:
    void begin(uint8_t redPin, uint8_t greenPin, uint8_t bluePin);
    void on(LedChannel channel);
    void off(LedChannel channel);
    void toggle(LedChannel channel);
    void setBrightness(LedChannel channel, uint8_t brightness);
    void allOn();
    void allOff();
    void nightMode();

private:
    uint8_t _pins[3];
    bool _state[3];
    uint8_t _brightness[3];
};

#endif // LED_CONTROL_H
