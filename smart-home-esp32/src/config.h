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
// 板载 LED
#define PIN_LED_BUILTIN 48

// 传感器
#define PIN_DHT11       4
#define PIN_LIGHT_SENSOR 1    // ADC1_CH0
#define PIN_PIR_1       5
#define PIN_PIR_2       6
#define PIN_DOOR        7

// 执行器
#define PIN_LED_R       10
#define PIN_LED_G       11
#define PIN_LED_B       12
#define PIN_BUZZER      13
#define PIN_RELAY_FAN   14
#define PIN_RELAY_APP   15
#define PIN_SERVO       16    // PWM

// ===================== 系统参数 =====================
#define SENSOR_READ_INTERVAL   5000    // 传感器采集间隔(ms)
#define MQTT_REPORT_INTERVAL   5000    // 数据上报间隔(ms)
#define PIR_STABLE_TIMEOUT     30000   // 人体稳定超时(ms)

#endif // CONFIG_H
