#include "mqtt_client.h"

MqttMessageCallback MqttClient::_userCallback = nullptr;

void MqttClient::begin(const char* broker, uint16_t port, const char* clientId)
{
    _broker = broker;
    _port = port;
    _clientId = clientId;
    _lastReconnectAttempt = 0;
    _subCount = 0;
    _mqtt.setClient(_wifiClient);
    _mqtt.setServer(_broker, _port);
    _mqtt.setCallback(_mqttCallback);
}

void MqttClient::loop()
{
    if (!_mqtt.connected())
    {
        unsigned long now = millis();
        if (now - _lastReconnectAttempt >= 5000)
        {
            _lastReconnectAttempt = now;
            Serial.printf("[MQTT] 连接 %s:%d ...\n", _broker, _port);
            if (_mqtt.connect(_clientId))
            {
                Serial.println("[MQTT] 连接成功");
                for (int i = 0; i < _subCount; i++)
                {
                    _mqtt.subscribe(_subscribedTopics[i]);
                    Serial.printf("[MQTT] 订阅: %s\n", _subscribedTopics[i]);
                }
            }
            else
            {
                Serial.printf("[MQTT] 连接失败, rc=%d\n", _mqtt.state());
            }
        }
    }
    _mqtt.loop();
}

bool MqttClient::publish(const char* topic, const char* payload, bool retained)
{
    return _mqtt.publish(topic, payload, retained);
}

void MqttClient::subscribe(const char* topic)
{
    if (_subCount < MAX_SUBS)
    {
        _subscribedTopics[_subCount++] = topic;
    }
    if (_mqtt.connected())
    {
        _mqtt.subscribe(topic);
    }
}

bool MqttClient::isConnected()
{
    return _mqtt.connected();
}

void MqttClient::onMessage(MqttMessageCallback callback)
{
    _userCallback = callback;
}

void MqttClient::_mqttCallback(char* topic, byte* payload, unsigned int length)
{
    char buf[256];
    unsigned int len = length < 255 ? length : 255;
    memcpy(buf, payload, len);
    buf[len] = '\0';
    Serial.printf("[MQTT] 收到: %s -> %s\n", topic, buf);
    if (_userCallback) _userCallback(topic, buf);
}
