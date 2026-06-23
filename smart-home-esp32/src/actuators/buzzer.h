#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class Buzzer
{
public:
    void begin(uint8_t pin);
    void beepOn();
    void beepOff();
    void beep(unsigned long durationMs);
    void alarmPattern(int times, unsigned long onMs, unsigned long offMs);
    void setMute(bool mute);

private:
    uint8_t _pin;
    bool _muted;
    unsigned long _beepEndTime;
    int _alarmTimes;
    unsigned long _alarmOnMs;
    unsigned long _alarmOffMs;
    bool _alarmActive;
    bool _alarmState;
    unsigned long _alarmPhaseTime;
    int _alarmCount;
};

#endif // BUZZER_H
