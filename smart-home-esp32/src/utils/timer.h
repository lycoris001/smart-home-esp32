#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer
{
public:
    void start(unsigned long intervalMs, bool repeat = true);
    void stop();
    bool isReady();
    void reset();
    bool isRunning();

private:
    unsigned long _interval;
    unsigned long _lastTick;
    bool _running;
    bool _repeat;
};

#endif // TIMER_H
