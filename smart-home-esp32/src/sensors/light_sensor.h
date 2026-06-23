#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include <Arduino.h>

class LightSensor
{
public:
    void begin(uint8_t pin);
    int readRaw();
    int readPercent();
    bool isDark(int threshold);

private:
    uint8_t _pin;
    static const int _filterSize = 10;
    int _buffer[_filterSize];
    int _bufferIndex;
    int _filteredValue;
};

#endif // LIGHT_SENSOR_H
