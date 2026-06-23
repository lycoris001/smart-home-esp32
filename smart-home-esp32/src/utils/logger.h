#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>

enum LogLevel { LOG_DEBUG = 0, LOG_INFO = 1, LOG_WARN = 2, LOG_ERROR = 3 };

class Logger
{
public:
    static void begin(unsigned long baud = 115200);
    static void setLevel(LogLevel level);
    static void debug(const char* format, ...);
    static void info(const char* format, ...);
    static void warn(const char* format, ...);
    static void error(const char* format, ...);

private:
    static LogLevel _level;
    static void log(LogLevel level, const char* tag, const char* format, va_list args);
};

#endif // LOGGER_H
