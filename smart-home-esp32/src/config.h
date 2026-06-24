#ifndef CONFIG_H
#define CONFIG_H

// ===================== WiFi 配置 =====================
#define WIFI_SSID     "你的WiFi名称"
#define WIFI_PASSWORD "你的WiFi密码"

// ===================== MQTT 配置 =====================
#define MQTT_BROKER    "你的EMQX服务器地址"
#define MQTT_PORT      1883
#define MQTT_CLIENT_ID "smart_home_001"

// ===================== 引脚分配 =====================
//
// ESP32-S3 约束：
//   禁脚: GPIO 0,3,45,46 (Strapping) + GPIO 26-37 (PSRAM/Flash)
//   ADC: 仅 ADC1 (GPIO 1-10) 可在 WiFi 下使用，ADC2 (GPIO 11-20) 被 WiFi 占用
//   板载: GPIO 48 为 WS2812 NeoPixel，需用 Adafruit_NeoPixel 驱动

// 板载 LED
#define PIN_LED_BUILTIN 48    // WS2812 RGB (NeoPixel), USB-OTG 引脚

// 传感器 (GPIO 1-7, 低位相邻, 光敏独占 ADC1_CH0 确保 WiFi 下可用)
#define PIN_LIGHT_SENSOR 1    // ADC1_CH0, WiFi 安全
#define PIN_DHT11         4   // GPIO 数字
#define PIN_PIR_1         5   // GPIO 数字
#define PIN_PIR_2         6   // GPIO 数字
#define PIN_DOOR          7   // GPIO 数字, 内部上拉

// 执行器 (GPIO 10-16, 连续排列方便面包板接线)
#define PIN_LED_R       10    // PWM
#define PIN_LED_G       11    // PWM
#define PIN_LED_B       12    // PWM
#define PIN_BUZZER      13    // GPIO 数字
#define PIN_RELAY_FAN   14    // GPIO 低电平触发
#define PIN_RELAY_APP   15    // GPIO 低电平触发
#define PIN_SERVO       16    // PWM 50Hz

// ===================== 系统参数 =====================
#define SENSOR_READ_INTERVAL   5000    // 传感器采集间隔(ms)
#define MQTT_REPORT_INTERVAL   5000    // 数据上报间隔(ms)
#define PIR_STABLE_TIMEOUT     30000   // 人体稳定超时(ms)

#endif // CONFIG_H
