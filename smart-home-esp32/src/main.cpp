#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "config.h"
#include "sensors/dht_sensor.h"

#define NUMPIXELS 1

Adafruit_NeoPixel rgbLed(NUMPIXELS, PIN_LED_BUILTIN, NEO_GRB + NEO_KHZ800);
DhtSensor dht;

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

    rgbLed.setPixelColor(0, rgbLed.Color(0, 255, 0));
    rgbLed.show();
    Serial.println("Smart Home System Boot OK");
    Serial.println("--- DHT11 测试开始 ---");
}

void loop()
{
    if (dht.read())
    {
        Serial.printf("温度: %.1f ℃  湿度: %.1f %%\n",
                      dht.getTemperature(), dht.getHumidity());
    }

    delay(2000);
}
