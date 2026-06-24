#ifndef PIR_SENSOR_H
#define PIR_SENSOR_H

#include <Arduino.h>

typedef void (*MotionCallback)();

class PirSensor
{
public:
    void begin(uint8_t pin)
    {
        _pin = pin;
        pinMode(_pin, INPUT);
        _debouncedMotion = false;
        _prevMotion = false;
        _debounceStart = 0;
        _lastTriggerTime = 0;
        _stableTimeout = 30000;
        _onStart = nullptr;
        _onEnd = nullptr;
    }

    void loop()
    {
        unsigned long now = millis();
        bool raw = digitalRead(_pin);

        if (raw)
        {
            if (_debounceStart == 0) _debounceStart = now;
            if (now - _debounceStart >= DEBOUNCE_MS)
            {
                if (!_debouncedMotion)
                {
                    _debouncedMotion = true;
                    _lastTriggerTime = now;
                }
            }
        }
        else
        {
            _debounceStart = 0;
            if (_debouncedMotion) _debouncedMotion = false;
        }

        if (_debouncedMotion && !_prevMotion)
        {
            if (_onStart) _onStart();
        }
        if (!_debouncedMotion && _prevMotion)
        {
            if (_onEnd) _onEnd();
        }
        _prevMotion = _debouncedMotion;
    }

    bool isMotionDetected()
    {
        return _debouncedMotion;
    }

    bool isStable()
    {
        if (_debouncedMotion) return false;
        return (millis() - _lastTriggerTime) >= _stableTimeout;
    }

    void resetStableTimer()
    {
        _lastTriggerTime = millis();
    }

    void setStableTimeout(unsigned long ms)
    {
        _stableTimeout = ms;
    }

    void onMotionStart(MotionCallback cb)
    {
        _onStart = cb;
    }

    void onMotionEnd(MotionCallback cb)
    {
        _onEnd = cb;
    }

private:
    uint8_t _pin;
    bool _debouncedMotion;
    bool _prevMotion;
    unsigned long _debounceStart;
    unsigned long _lastTriggerTime;
    unsigned long _stableTimeout;
    MotionCallback _onStart;
    MotionCallback _onEnd;
    static const unsigned long DEBOUNCE_MS = 200;
};

#endif // PIR_SENSOR_H
