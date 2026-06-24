#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "config.h"
#include "sensors/dht_sensor.h"
#include "sensors/light_sensor.h"
#include "sensors/pir_sensor.h"
#include "sensors/door_sensor.h"

#define NUMPIXELS 1

Adafruit_NeoPixel rgbLed(NUMPIXELS, PIN_LED_BUILTIN, NEO_GRB + NEO_KHZ800);
DhtSensor dht;
LightSensor light;
PirSensor pir1;
DoorSensor door;

unsigned long lastDhtTime = 0;
unsigned long lastLightTime = 0;
unsigned long lastPirTime = 0;
unsigned long lastDoorTime = 0;

void onMotionStart()
{
    Serial.println("[PIR1] 有人进入");
    rgbLed.setPixelColor(0, rgbLed.Color(255, 0, 0));
    rgbLed.show();
}

void onMotionEnd()
{
    Serial.println("[PIR1] 无人");
    rgbLed.setPixelColor(0, rgbLed.Color(0, 255, 0));
    rgbLed.show();
}

void onDoorChange(bool isOpen)
{
    if (isOpen) Serial.println("[门磁] 门已打开");
    else        Serial.println("[门磁] 门已关闭");
}

void setup()
{
    rgbLed.begin();
    rgbLed.setBrightness(20);
    rgbLed.clear();
    rgbLed.show();

    Serial.begin(115200);
    delay(2000);
    Serial.println();

    dht.begin(PIN_DHT11);
    light.begin(PIN_LIGHT_SENSOR);
    pir1.begin(PIN_PIR_1);
    pir1.onMotionStart(onMotionStart);
    pir1.onMotionEnd(onMotionEnd);
    door.begin(PIN_DOOR);
    door.onStateChange(onDoorChange);

    rgbLed.setPixelColor(0, rgbLed.Color(0, 255, 0));
    rgbLed.show();
    Serial.println("Smart Home System Boot OK");
    Serial.println("--- 传感器测试开始 ---");
}

void loop()
{
    unsigned long now = millis();

    pir1.loop();
    door.loop();

    if (now - lastDhtTime >= 2000)
    {
        lastDhtTime = now;
        if (dht.read())
        {
            Serial.printf("[DHT11] 温度: %.1f ℃  湿度: %.1f %%\n",
                          dht.getTemperature(), dht.getHumidity());
        }
    }

    if (now - lastLightTime >= 500)
    {
        lastLightTime = now;
        int raw = light.readRaw();
        int pct = light.readPercent();
        Serial.printf("[光敏] 原始值: %d  百分比: %d %%\n", raw, pct);
    }

    if (now - lastPirTime >= 2000)
    {
        lastPirTime = now;
        Serial.printf("[PIR1] 状态: %s  稳定: %s\n",
                      pir1.isMotionDetected() ? "有人" : "无人",
                      pir1.isStable() ? "是" : "否");
    }

    if (now - lastDoorTime >= 2000)
    {
        lastDoorTime = now;
        Serial.printf("[门磁] 状态: %s\n", door.isOpen() ? "打开" : "关闭");
    }
}
