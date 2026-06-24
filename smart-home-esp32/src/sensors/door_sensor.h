#ifndef DOOR_SENSOR_H
#define DOOR_SENSOR_H

#include <Arduino.h>

typedef void (*DoorCallback)(bool isOpen);

class DoorSensor
{
public:
    void begin(uint8_t pin)
    {
        _pin = pin;
        pinMode(_pin, INPUT_PULLUP);
        _state = digitalRead(_pin);
        _prevState = _state;
        _lastChangeTime = 0;
        _debounceStart = 0;
        _pendingState = _state;
        _callback = nullptr;
    }

    void loop()
    {
        unsigned long now = millis();
        bool raw = digitalRead(_pin);

        if (raw != _pendingState)
        {
            _pendingState = raw;
            _debounceStart = now;
        }

        if (_debounceStart > 0 && now - _debounceStart >= DEBOUNCE_MS)
        {
            if (_pendingState != _state)
            {
                _prevState = _state;
                _state = _pendingState;
                _lastChangeTime = now;
                if (_callback) _callback(_state);
            }
            _debounceStart = 0;
        }
    }

    bool isOpen()
    {
        return _state == HIGH;
    }

    bool isClosed()
    {
        return _state == LOW;
    }

    unsigned long getLastChangeTime()
    {
        return _lastChangeTime;
    }

    bool justChanged()
    {
        return _state != _prevState;
    }

    void onStateChange(DoorCallback cb)
    {
        _callback = cb;
    }

private:
    uint8_t _pin;
    bool _state;
    bool _prevState;
    bool _pendingState;
    unsigned long _lastChangeTime;
    unsigned long _debounceStart;
    DoorCallback _callback;
    static const unsigned long DEBOUNCE_MS = 50;
};

#endif // DOOR_SENSOR_H
