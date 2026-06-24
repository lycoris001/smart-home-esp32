#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H

#include <Arduino.h>
#include <DHT.h>

class DhtSensor
{
public:
    void begin(uint8_t pin)
    {
        _pin = pin;
        _dht = new DHT(_pin, DHT11);
        _dht->begin();
        _temperature = 0.0f;
        _humidity = 0.0f;
        _ok = false;
        _lastReadTime = 0;
        delay(100);
    }

    bool read()
    {
        unsigned long now = millis();
        if (now - _lastReadTime < 2000) return _ok;
        _lastReadTime = now;

        float t = _dht->readTemperature();
        float h = _dht->readHumidity();

        if (isnan(t) || isnan(h))
        {
            _ok = false;
            Serial.println("[DHT11] 读取失败，请检查接线");
            return false;
        }

        _temperature = t;
        _humidity = h;
        _ok = true;
        return true;
    }

    float getTemperature()
    {
        return _temperature;
    }

    float getHumidity()
    {
        return _humidity;
    }

    bool isOK()
    {
        return _ok;
    }

private:
    uint8_t _pin;
    DHT* _dht;
    float _temperature;
    float _humidity;
    bool _ok;
    unsigned long _lastReadTime;
};

#endif // DHT_SENSOR_H
