#include "wifi_manager.h"

void WiFiManager::begin(const char* ssid, const char* password)
{
    _ssid = ssid;
    _password = password;
    _lastReconnectAttempt = 0;
    _retryCount = 0;
    connect();
}

bool WiFiManager::isConnected()
{
    return WiFi.status() == WL_CONNECTED;
}

void WiFiManager::loop()
{
    if (!isConnected())
    {
        unsigned long now = millis();
        unsigned long interval = min(1000UL << min(_retryCount, 6), 60000UL);
        if (now - _lastReconnectAttempt >= interval)
        {
            _lastReconnectAttempt = now;
            _retryCount++;
            Serial.printf("[WiFi] 重连中... (第%d次)\n", _retryCount);
            connect();
        }
    }
    else
    {
        _retryCount = 0;
    }
}

void WiFiManager::connect()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(_ssid, _password);
    if (WiFi.waitForConnectResult(10000) == WL_CONNECTED)
    {
        Serial.printf("[WiFi] 连接成功, IP: %s, RSSI: %d\n",
                      WiFi.localIP().toString().c_str(), WiFi.RSSI());
    }
    else
    {
        Serial.println("[WiFi] 连接失败");
    }
}
