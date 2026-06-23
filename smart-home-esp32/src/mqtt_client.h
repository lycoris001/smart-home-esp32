#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFiClient.h>

typedef void (*MqttMessageCallback)(const char* topic, const char* payload);

class MqttClient
{
public:
    void begin(const char* broker, uint16_t port, const char* clientId);
    void loop();
    bool publish(const char* topic, const char* payload, bool retained = false);
    void subscribe(const char* topic);
    bool isConnected();
    void onMessage(MqttMessageCallback callback);

private:
    WiFiClient _wifiClient;
    PubSubClient _mqtt;
    const char* _broker;
    uint16_t _port;
    const char* _clientId;
    unsigned long _lastReconnectAttempt;
    static const int MAX_SUBS = 16;
    const char* _subscribedTopics[MAX_SUBS];
    int _subCount;
    static void _mqttCallback(char* topic, byte* payload, unsigned int length);
    static MqttMessageCallback _userCallback;
};

#endif // MQTT_CLIENT_H
