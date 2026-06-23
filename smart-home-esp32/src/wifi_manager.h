#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <Arduino.h>
#include <WiFi.h>

class WiFiManager
{
public:
    void begin(const char* ssid, const char* password);
    bool isConnected();
    void loop();

private:
    const char* _ssid;
    const char* _password;
    unsigned long _lastReconnectAttempt;
    int _retryCount;
    void connect();
};

#endif // WIFI_MANAGER_H
