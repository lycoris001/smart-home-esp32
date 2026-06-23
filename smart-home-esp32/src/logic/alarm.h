#ifndef ALARM_H
#define ALARM_H

#include <Arduino.h>

enum AlarmType
{
    ALARM_NONE = 0,
    ALARM_INTRUSION,   // 入侵
    ALARM_FIRE,        // 火警
    ALARM_LOW_BATTERY  // 低电量
};

class AlarmManager
{
public:
    void triggerAlarm(AlarmType type, const String& message);
    void clearAlarm();
    bool isAlarming();
    void setArmed(bool armed);
    bool isArmed();
    AlarmType getAlarmType();
    String getAlarmMessage();

private:
    bool _armed;
    bool _alarming;
    AlarmType _alarmType;
    String _alarmMessage;
};

#endif // ALARM_H
