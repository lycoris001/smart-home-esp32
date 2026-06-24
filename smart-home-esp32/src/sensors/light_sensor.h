#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include <Arduino.h>

class LightSensor
{
public:
    void begin(uint8_t pin)
    {
        _pin = pin;
        analogReadResolution(12);
        analogSetAttenuation(ADC_11db);
        pinMode(_pin, INPUT);
        _rawValue = 0;
        _filterIndex = 0;
        _filterCount = 0;
        for (int i = 0; i < FILTER_SIZE; i++) _filterBuf[i] = 0;
        for (int i = 0; i < 5; i++) readRaw();
    }

    int readRaw()
    {
        _rawValue = analogRead(_pin);
        _filterBuf[_filterIndex] = _rawValue;
        _filterIndex = (_filterIndex + 1) % FILTER_SIZE;
        if (_filterCount < FILTER_SIZE) _filterCount++;
        return _rawValue;
    }

    int readFiltered()
    {
        long sum = 0;
        for (int i = 0; i < _filterCount; i++) sum += _filterBuf[i];
        return (int)(sum / _filterCount);
    }

    int readPercent()
    {
        return map(readFiltered(), 0, 4095, 0, 100);
    }

    bool isDark(int threshold)
    {
        return readFiltered() < threshold;
    }

private:
    uint8_t _pin;
    int _rawValue;
    static const int FILTER_SIZE = 10;
    int _filterBuf[10];
    int _filterIndex;
    int _filterCount;
};

#endif // LIGHT_SENSOR_H
