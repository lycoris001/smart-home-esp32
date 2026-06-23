#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H

#include <Arduino.h>

class DhtSensor
{
public:
    void begin(uint8_t pin);
    bool read();
    float getTemperature();
    float getHumidity();
    bool isOK();

private:
    uint8_t _pin;
    float _temperature;
    float _humidity;
    bool _ok;
    unsigned long _lastReadTime;
};

#endif // DHT_SENSOR_H
