# 智能家居联动控制系统 — 快速开始

> ESP32-S3 + MQTT + 多传感器联动 | 课程设计项目

## 环境准备

1. 安装 [VS Code](https://code.visualstudio.com/)
2. 安装 **PlatformIO** 扩展
3. 安装 ESP32-S3 USB 驱动（CP210x 或 CH340）

## 编译与烧录

```bash
# 编译
pio run

# 烧录到开发板
pio run --target upload

# 查看串口日志
pio device monitor
```

## 配置 WiFi 与 MQTT

在 `src/config.h` 中修改以下配置：

```c
#define WIFI_SSID     "你的WiFi名称"
#define WIFI_PASSWORD "你的WiFi密码"

#define MQTT_BROKER   "你的EMQX服务器地址"
#define MQTT_PORT     1883
#define MQTT_CLIENT_ID "smart_home_001"
```

> ⚠️ 本地密码配置请写到 `src/config_local.h`（已被 .gitignore 忽略），提交时不会泄露。

## 依赖库

项目使用 PlatformIO 自动管理依赖：

| 库 | 用途 |
|------|------|
| PubSubClient | MQTT 客户端 |
| ArduinoJson | JSON 解析 |
| DHT sensor library | 温湿度传感器 |

## 项目结构

```
smart-home-esp32/
├── platformio.ini            # PlatformIO 配置
├── src/
│   ├── main.cpp              # 主程序入口
│   ├── config.h              # 配置宏
│   ├── wifi_manager.h/.cpp   # WiFi 管理
│   ├── mqtt_client.h/.cpp    # MQTT 客户端
│   ├── sensors/              # 传感器驱动
│   ├── actuators/            # 执行器驱动
│   ├── logic/                # 联动逻辑
│   └── utils/                # 工具类
├── docs/                     # 设计文档
├── app/                      # 移动端 APP
└── test/                     # 单元测试
```
