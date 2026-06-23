# 从零开始：AI 辅助智能家居项目开发全流程

> 基于 ESP32-S3 的小户型智能家居联动控制系统 — 一步步手把手开发指南

---

## 目录

- [前置说明：与 AI 高效协作的原则](#前置说明与-ai-高效协作的原则)
- [阶段 0：项目预备](#阶段-0项目预备)
- [阶段 1：环境搭建 + ESP32-S3 点灯（预计 1 天）](#阶段-1环境搭建--esp32-s3-点灯预计-1-天)
- [阶段 2：传感器驱动开发（预计 2 天）](#阶段-2传感器驱动开发预计-2-天)
- [阶段 3：执行器驱动开发（预计 2 天）](#阶段-3执行器驱动开发预计-2-天)
- [阶段 4：WiFi + MQTT 通信模块（预计 2 天）](#阶段-4wifi--mqtt-通信模块预计-2-天)
- [阶段 5：联动规则引擎 + 场景模式（预计 2 天）](#阶段-5联动规则引擎--场景模式预计-2-天)
- [阶段 6：手机 APP 基础界面 + MQTT 对接（预计 2 天）](#阶段-6手机-app-基础界面--mqtt-对接预计-2-天)
- [阶段 7：系统联调 + 端到端测试（预计 2 天）](#阶段-7系统联调--端到端测试预计-2-天)
- [阶段 8：文档撰写 + 答辩准备（预计 2 天）](#阶段-8文档撰写--答辩准备预计-2-天)
- [附录：AI Prompt 速查表](#附录ai-prompt-速查表)

---

## 前置说明：与 AI 高效协作的原则

### 每次对话前准备好三样东西

| 准备项 | 说明 | 示例 |
|--------|------|------|
| **当前阶段目标** | 要说清楚这轮对话要完成什么 | "我要给 ESP32-S3 写一个 DHT11 温湿度传感器驱动" |
| **上下文文件** | 把相关代码文件直接粘贴给 AI | 粘贴 `config.h`、参考驱动代码 |
| **验证标准** | 告诉 AI 怎样算"完成" | "串口每 2 秒打印一次温度和湿度值" |

### 一次只做一个模块

```
❌ "帮我写全部传感器驱动和执行器驱动"
✅ "帮我写 DHT11 温湿度传感器驱动，打印到串口"
```

### 代码必须能编译并烧录验证

每完成一个 `.h/.cpp` 文件，立刻让 AI 生成对应的测试代码写入 `main.cpp`，编译烧录看结果，有问题马上反馈。

---

## 阶段 0：项目预备

### 0.1 硬件开箱验证

在写任何代码之前，先把所有硬件检查一遍：

```
你的任务：逐项检查以下硬件是否齐全，拍照存档

□ ESP32-S3-DevKitC-1 开发板 ×1
□ DHT11/DHT22 温湿度传感器 ×1
□ LM393 光敏传感器模块 ×1
□ HC-SR501 PIR 人体红外传感器 ×1~2
□ MC-38 干簧管门磁模块 ×1~2
□ 5mm LED + 220Ω电阻 ×2~3
□ 3.3V/5V 有源蜂鸣器模块 ×1
□ 5V 低电平触发继电器模块 ×2
□ 5V 微型排风扇 ×1
□ SG90 舵机 ×1
□ 面包板 + 杜邦线套件 ×1
□ 5V/2A 独立电源适配器 ×1
□ USB Type-C 数据线 ×1
```

### 0.2 创建项目骨架

用 AI 一次性生成项目骨架：

```
AI Prompt：

请为 ESP32-S3 智能家居项目创建以下文件结构（PlatformIO 项目）：

smart-home-esp32/
├── README.md                 # 项目说明
├── platformio.ini            # PlatformIO 配置
├── .gitignore                # Git 忽略规则
├── docs/
│   ├── architecture.md       # 系统架构说明
│   ├── hardware.md           # 硬件接线图（含引脚分配表）
│   └── mqtt-topics.md        # MQTT 主题定义
├── src/
│   ├── main.cpp              # 主程序入口
│   ├── config.h              # WiFi / MQTT / 引脚 配置宏
│   ├── wifi_manager.h/.cpp   # WiFi 连接管理
│   ├── mqtt_client.h/.cpp    # MQTT 客户端封装
│   ├── sensors/
│   │   ├── dht_sensor.h      # 温湿度驱动
│   │   ├── light_sensor.h    # 光敏电阻驱动
│   │   ├── pir_sensor.h      # PIR 红外驱动
│   │   └── door_sensor.h     # 门磁驱动
│   ├── actuators/
│   │   ├── led_control.h     # LED 控制
│   │   ├── buzzer.h          # 蜂鸣器控制
│   │   ├── relay.h           # 继电器控制
│   │   └── servo.h           # 舵机控制
│   ├── logic/
│   │   ├── scene_manager.h   # 场景模式管理
│   │   ├── linkage_engine.h  # 联动规则引擎
│   │   └── alarm.h           # 告警管理
│   └── utils/
│       ├── timer.h           # 定时器工具
│       └── logger.h          # 日志输出
├── app/                      # 移动端 APP 源码（后续）
└── test/                     # 单元测试（后续）

要求：
1. platformio.ini 配置 ESP32-S3，使用 Arduino 框架
2. config.h 中定义 WiFi SSID/PASSWORD、MQTT Broker 地址占位符
3. 每个 .h 文件包含头文件保护和基本结构
4. README.md 写入项目简介和快速开始说明
5. .gitignore 忽略 .pio/ build/ *.o *.bin *.elf .vscode/ .idea/
```

**验证**：`pio run` 能编译通过（`main.cpp` 只需 `#include <Arduino.h>` + 空的 `setup()`/`loop()`）。

### 0.3 Git 初始化 + 首次提交

```bash
cd smart-home-esp32
git init
git add .
git commit -m "init: 项目骨架搭建，PlatformIO + ESP32-S3"
git branch -M main
git remote add origin <你的仓库地址>
git push -u origin main
```

---

## 阶段 1：环境搭建 + ESP32-S3 点灯（预计 1 天）

### 目标
- VS Code + PlatformIO 环境就绪
- ESP32-S3 能烧录程序
- 板载 LED 闪烁 = 环境验证通过

### 1.1 安装开发环境

| 工具 | 下载地址 | 说明 |
|------|---------|------|
| VS Code | https://code.visualstudio.com/ | 主编辑器 |
| PlatformIO 扩展 | VS Code 扩展市场搜索 "PlatformIO" | 嵌入式开发框架 |
| USB 驱动 | CP210x 或 CH340 | 串口驱动 |

### 1.2 点灯验证

```
AI Prompt：

请为 ESP32-S3 写一个 Arduino 框架的点灯程序，功能如下：
1. 使用板载 LED（GPIO 48，ESP32-S3-DevKitC-1 默认）
2. 在 setup() 中通过串口打印 "Smart Home System Boot OK"
3. LED 以 500ms 间隔闪烁
4. 每次状态变化时在串口打印 "LED ON" / "LED OFF"
```

**验证**：编译 → 烧录 → 看串口输出 → LED 在闪。

### 1.3 硬件接线准备 — 引脚分配表

```
AI Prompt：

请根据以下硬件清单，为 ESP32-S3-DevKitC-1 生成一份引脚分配表。
要求：
1. 避开 ESP32-S3 的 Strapping 引脚（GPIO 0, 3, 45, 46）
2. 避开用于 PSRAM/Flash 的 GPIO 26-37
3. 尽量同类传感器放在相邻引脚方便接线
4. 用 Markdown 表格输出，包含：功能、品名、GPIO、备注

硬件清单：
- 板载 LED：GPIO 48
- DHT11 温湿度传感器 ×1
- LM393 光敏传感器模块 ×1（模拟输出用 ADC）
- HC-SR501 PIR 人体红外传感器 ×2
- MC-38 门磁传感器 ×1
- LED 灯 ×3（红/绿/蓝）
- 有源蜂鸣器 ×1
- 继电器 ×2（分别控制风扇和模拟家电）
- SG90 舵机 ×1（PWM 引脚）
```

将输出结果保存到 `docs/hardware.md`。

---

## 阶段 2：传感器驱动开发（预计 2 天）

### 核心原则

> **一个传感器一个驱动 + 一个测试，验证通过再写下一个。**

顺序建议：

```
DHT11 温湿度 → 光敏电阻 → PIR 红外 → 门磁
```

### 2.1 DHT11 温湿度驱动

```
AI Prompt：

请为 DHT11 温湿度传感器写一个 ESP32-S3 Arduino 驱动（单文件 .h），要求：

1. 使用 DHT sensor library（Adafruit 或 DHT11 原生库）
2. 封装为类 DhtSensor，包含：
   - begin(pin)：初始化
   - read() → bool：读取数据
   - getTemperature() → float：返回温度（℃）
   - getHumidity() → float：返回湿度（%）
   - isOK() → bool：读取是否成功
3. 内置非阻塞定时读取，调用 read() 时自动处理 DHT11 的 ≥2s 采样间隔
4. 读取失败时通过串口打印错误信息（不要 crash）

同时写一个 main.cpp 测试用例：
- 每 2 秒读取一次并打印 "温度: XX.X ℃  湿度: XX.X %"
```

### 2.2 光敏电阻驱动

```
AI Prompt：

请为 LM393 光敏传感器模块写一个 ESP32-S3 Arduino 驱动（单文件 .h），要求：

1. 使用 ESP32-S3 的 ADC 读取模拟值（12 位分辨率，0-4095）
2. 封装为类 LightSensor，包含：
   - begin(pin)：初始化 ADC
   - readRaw() → int：返回原始 ADC 值（0-4095）
   - readPercent() → int：返回 0-100 百分比（100=最亮）
   - isDark(threshold)：返回是否低于阈值
3. 内置移动平均滤波（取最近 N 次平均值）

同时写测试用例，每 500ms 打印原始值和百分比。
```

### 2.3 PIR 人体红外传感器驱动

```
AI Prompt：

请为 HC-SR501 PIR 人体红外传感器写一个 ESP32-S3 Arduino 驱动（单文件 .h），要求：

1. 封装为类 PirSensor，包含：
   - begin(pin)：初始化
   - isMotionDetected() → bool：是否检测到人体
   - isStable() → bool：是否持续无人体（默认 30 秒）
   - resetStableTimer()：重置稳定计时
2. 内置防抖处理（高电平需持续 ≥200ms 才算有效触发）
3. 内置稳定计时器：连续无触发 N 秒后返回 true
4. 支持回调函数 onMotionStart / onMotionEnd

同时写测试用例，检测到人体时打印 "有人进入"，稳定后打印 "无人"。
```

### 2.4 门磁传感器驱动

```
AI Prompt：

请为 MC-38 干簧管门磁传感器写一个 ESP32-S3 Arduino 驱动（单文件 .h），要求：

1. 封装为类 DoorSensor，包含：
   - begin(pin)：初始化（内部上拉）
   - isOpen() → bool：门是否打开
   - isClosed() → bool：门是否关闭
   - onStateChange(callback)：状态变化回调
2. 内置防抖处理（50ms 去抖）
3. 记录最近一次状态变化的时间戳

同时写测试用例，门状态变化时打印 "门已打开" / "门已关闭"。
```

### 阶段 2 验收标准

```
- [ ] DHT11 温湿度值在串口正常打印，数值合理
- [ ] 光敏传感器能区分亮暗环境
- [ ] PIR 能准确检测人体进出
- [ ] 门磁开关状态变化正确响应
- [ ] pio run 编译零错误
- [ ] 所有代码已 commit
```

---

## 阶段 3：执行器驱动开发（预计 2 天）

### 顺序建议

```
LED 控制 → 蜂鸣器 → 继电器 → 舵机
```

### 3.1 LED 控制驱动

```
AI Prompt：

请为 3 路 LED 写一个 ESP32-S3 Arduino 驱动（单文件 .h），要求：

1. 封装为类 LedControl，支持多路 LED：
   - begin(redPin, greenPin, bluePin)：初始化三路
   - on(channel)：开启指定通道
   - off(channel)：关闭指定通道
   - toggle(channel)：翻转
   - setBrightness(channel, 0-255)：设置亮度（PWM）
2. 支持预定义场景：allOn() / allOff() / nightMode()
3. 使用 ledc 实现平滑呼吸灯效果

同时写测试用例：三路 LED 依次闪烁 + 呼吸灯演示。
```

### 3.2 蜂鸣器驱动

```
AI Prompt：

请为有源蜂鸣器写一个 ESP32-S3 Arduino 驱动（单文件 .h），要求：

1. 封装为类 Buzzer，包含：
   - begin(pin)：初始化
   - beepOn()：持续响
   - beepOff()：关闭
   - beep(duration_ms)：响指定时长
   - alarmPattern(times, onMs, offMs)：报警模式（嘀-嘀-嘀）
2. 非阻塞实现（不阻塞 loop）
3. 支持静音模式（全局开关）

同时写测试用例：短鸣 → 长鸣 → 报警模式演示。
```

### 3.3 继电器驱动

```
AI Prompt：

请为 2 路 5V 低电平触发继电器写一个 ESP32-S3 Arduino 驱动（单文件 .h），要求：

1. 封装为类 Relay，支持多路：
   - begin(fanPin, appliancePin)：初始化
   - on(channel)：闭合（注意低电平触发逻辑）
   - off(channel)：断开
   - isOn(channel) → bool：状态查询
2. 上电时确保继电器处于断开状态
3. 记录每路继电器动作次数（寿命统计）

同时写测试用例：两路继电器交替开关，串口打印状态。
```

### 3.4 舵机驱动

```
AI Prompt：

请为 SG90 舵机写一个 ESP32-S3 Arduino 驱动（单文件 .h），要求：

1. 使用 ESP32-S3 的 ledc 实现 PWM（50Hz）
2. 封装为类 ServoControl，包含：
   - begin(pin)：初始化
   - setAngle(0-180)：设置角度
   - open()：转至 90°（模拟开门）
   - close()：转至 0°（模拟关门）
   - sweep(start, end, step_ms)：来回扫描
3. 非阻塞角度渐变（防抖）

同时写测试用例：开门 → 延时 → 关门 → 往复扫描。
```

### 阶段 3 验收标准

```
- [ ] LED 三色可控、支持 PWM 调光
- [ ] 蜂鸣器报警模式正常工作
- [ ] 继电器正确控制负载
- [ ] 舵机 0°-180° 精确可调
- [ ] pio run 编译零错误
- [ ] 所有代码已 commit
```

---

## 阶段 4：WiFi + MQTT 通信模块（预计 2 天）

### 4.1 WiFi 连接管理

```
AI Prompt：

请为 ESP32-S3 写一个 WiFi 连接管理模块（wifi_manager.h + wifi_manager.cpp），要求：

1. 封装为类 WiFiManager，包含：
   - begin(ssid, password)：连接 WiFi
   - isConnected() → bool：检查连接状态
   - loop()：须在主循环中调用，处理自动重连
2. 断线自动重连（指数退避：1s → 2s → 4s → ... → 最大 60s）
3. 连接成功/断开时通过串口打印状态
4. 连接成功时打印 IP 地址和信号强度（RSSI）
5. 非阻塞，所有操作不卡主循环

config.h 中定义宏：
#define WIFI_SSID     "你的WiFi名"
#define WIFI_PASSWORD "你的WiFi密码"
```

### 4.2 MQTT 客户端封装

```
AI Prompt：

请为 ESP32-S3 写一个 MQTT 客户端封装（mqtt_client.h + mqtt_client.cpp），要求：

1. 使用 PubSubClient 库
2. 封装为类 MqttClient，包含：
   - begin(broker, port, clientId)：连接 Broker
   - loop()：须在主循环调用（处理心跳/收消息）
   - publish(topic, payload)：发布消息
   - subscribe(topic, callback)：订阅主题
   - isConnected() → bool
3. 断线自动重连 + 自动重新订阅
4. 支持 QoS 0/1
5. 内置 JSON 消息构建/解析（ArduinoJson）
6. 统一 MQTT 主题命名：home/{room}/{device}/{action}

config.h 中定义宏：
#define MQTT_BROKER    "你的EMQX地址"
#define MQTT_PORT      1883
#define MQTT_CLIENT_ID "smart_home_001"
```

### 4.3 MQTT 主题定义

创建 `docs/mqtt-topics.md`，统一主题命名：

```
home/livingroom/temperature   → 发布温度数据
home/livingroom/humidity      → 发布湿度数据
home/livingroom/light         → 发布光照数据
home/livingroom/pir           → 发布人体检测
home/livingroom/door          → 发布门磁状态
home/livingroom/led/command   → 订阅 LED 控制指令
home/livingroom/fan/command   → 订阅风扇控制指令
home/livingroom/buzzer/command→ 订阅蜂鸣器指令
home/livingroom/scene         → 订阅场景切换指令
home/livingroom/alarm         → 发布告警信息
```

### 4.4 联调：传感器数据上云

```
AI Prompt：

请修改 main.cpp，实现以下功能：
1. WiFiManager 连接 WiFi（状态通过串口打印）
2. MqttClient 连接 EMQX Broker
3. 将 DHT11 温湿度、光敏值每 5 秒发布到对应 MQTT 主题
4. 将 PIR 人体检测和门磁状态变化时立即发布
5. 接收 LED 控制指令（JSON: {"channel":1,"state":1,"brightness":128}）
6. 串口打印每条收发的消息

完整的 setup() 和 loop()，调用之前写好的所有驱动模块。
```

### 阶段 4 验收标准

```
- [ ] WiFi 连接成功，断线自动重连
- [ ] MQTT 连接 Broker 成功
- [ ] 使用 MQTTX 等工具能看到传感器数据实时上报
- [ ] 能通过 MQTT 下发指令控制 LED
- [ ] 所有代码已 commit
```

---

## 阶段 5：联动规则引擎 + 场景模式（预计 2 天）

### 5.1 联动规则引擎

```
AI Prompt：

请为智能家居系统写一个联动规则引擎（linkage_engine.h），要求：

1. 封装为类 LinkageEngine，管理多條联动规则
2. 规则数据结构：
   struct Rule {
     string name;           // 规则名称
     function<bool()> condition;  // 触发条件（返回 true 即触发）
     function<void()> action;     // 联动动作
     bool enabled;          // 是否启用
   };
3. 支持：
   - addRule(rule)：添加规则
   - removeRule(name)：移除规则
   - enableRule(name) / disableRule(name)：开关规则
   - loop()：每轮检查所有规则（非阻塞）
4. 内置默认规则（基于 README 中的需求）：

   | 规则名 | 触发条件 | 联动动作 |
   |--------|---------|---------|
   | auto_light_on | PIR 有人 && 光照不足 | 开 LED |
   | auto_light_off | PIR 30s 无人 | 关 LED |
   | high_temp_fan | 温度 > 30℃ | 开风扇 |
   | high_humidity_fan | 湿度 > 75% | 开风扇 |
   | temp_normal | 温度 < 26℃ | 关风扇 |
   | door_alarm | 设防 && 门开 | 蜂鸣器报警 |

5. 规则执行日志通过串口打印 "联动触发: [规则名]"
```

### 5.2 场景模式管理

```
AI Prompt：

请写一个场景模式管理器（scene_manager.h），要求：

1. 定义三种场景模式：
   - HOME_MODE（回家模式）：解除安防、开灯、温控就绪
   - AWAY_MODE（离家模式）：关灯、断电、启用安防
   - NIGHT_MODE（睡眠模式）：关灯、静音蜂鸣器、安防保持

2. 封装为类 SceneManager，包含：
   - setScene(mode)：切换场景
   - getCurrentScene() → SceneMode
   - 切换场景时自动执行进入动作（关灯/开灯/设防/撤防等）
3. 记录上一次场景，支持 undo() 回到上一个场景
4. 支持 MQTT 远程切换：订阅 home/livingroom/scene，收到 {"scene":"away"} 即切换
5. 场景切换时通过 MQTT 发布状态更新

同时修改 main.cpp：
- 初始化 LinkageEngine 并注册默认规则
- 初始化 SceneManager
- loop() 中调用两者的 loop()
- 通过 MQTT 下发场景切换指令验证
```

### 5.3 告警管理

```
AI Prompt：

请写告警管理模块（alarm.h），要求：

1. 封装为类 AlarmManager，包含：
   - triggerAlarm(type, message)：触发告警
   - clearAlarm()：清除告警
   - isAlarming() → bool
   - setArmed(bool)：设防/撤防
2. 告警类型：INTRUSION（入侵）/ FIRE（火警）/ LOW_BATTERY（低电量）
3. 告警时自动执行：
   - 蜂鸣器报警模式
   - MQTT 发布告警消息到 home/livingroom/alarm
4. 仅在设防状态下才触发入侵告警

修改 main.cpp，集成告警管理并接入联动规则。
```

### 阶段 5 验收标准

```
- [ ] 联动规则全部触发正确
- [ ] 场景切换后设备状态符合预期
- [ ] MQTT 能远程切换场景
- [ ] 告警模式下门磁触发蜂鸣器 + MQTT 推送
- [ ] 所有代码已 commit
```

---

## 阶段 6：手机 APP 基础界面 + MQTT 对接（预计 2 天）

### 开发方式

> 如果你熟悉鸿蒙开发：
> 用 DevEco Studio + ArkTS 开发 APP。

> 如果不想从零学APP开发，推荐方案：
> 使用 **Qt for Android** 或 **Flutter** 快速搭建跨平台控制面板。

> 最简方案（课程演示足够）：
> 直接用 **HTML + MQTT.js** 做一个 Web 控制面板，手机浏览器打开就能用。

### 6.1 Web 控制面板（推荐最简方案）

```
AI Prompt：

请帮我写一个智能家居 Web 控制面板（纯前端），要求：

功能需求：
1. 实时显示：温度、湿度、光照、门磁状态、人体检测
2. 控制面板：LED 开关/亮度滑块、风扇开关、蜂鸣器测试
3. 场景切换按钮：回家 / 离家 / 睡眠
4. 告警消息列表（最近 10 条）

技术约束：
- 使用 MQTT.js 通过 WebSocket 连接 EMQX Broker
- 单 HTML 文件，内联 CSS/JS，无需构建工具
- 响应式布局，手机端友好
- 深色主题科技感 UI

MQTT 连接信息（在代码中用占位符）：
- Broker: wss://你的EMQX地址:8084/mqtt
- 用户名/密码：占位

订阅主题：
- home/livingroom/temperature
- home/livingroom/humidity
- home/livingroom/light
- home/livingroom/pir
- home/livingroom/door
- home/livingroom/alarm

发布主题：
- home/livingroom/led/command
- home/livingroom/fan/command
- home/livingroom/buzzer/command
- home/livingroom/scene
```

### 6.2 鸿蒙 APP（如需原生）

```
AI Prompt：

请帮我写一个鸿蒙（HarmonyOS）智能家居控制 APP，要求：

1. 使用 ArkTS 语言 + ArkUI 框架
2. 三个页面：
   - 首页：仪表盘（温湿度表盘 + 光照条 + 人体/门磁图标）
   - 控制页：LED 开关+亮度 / 风扇 / 蜂鸣器
   - 场景页：回家/离家/睡眠 模式切换大按钮
3. 使用 @ohos/paho-mqtt 或 MQTT.js 连接 EMQX
4. MQTT 主题与 ESP32 端对齐
5. 收到告警时顶部弹出通知栏

项目文件结构：
├── entry/src/main/ets/
│   ├── pages/
│   │   ├── Index.ets          # 首页仪表盘
│   │   ├── ControlPage.ets    # 设备控制
│   │   └── ScenePage.ets      # 场景切换
│   ├── mqtt/
│   │   └── MqttManager.ets    # MQTT 客户端封装
│   └── common/
│       └── Constants.ets      # 常量定义
```

### 阶段 6 验收标准

```
- [ ] APP 能连接 EMQX 并显示实时传感器数据
- [ ] 能通过 APP 控制 ESP32 端 LED/风扇/蜂鸣器
- [ ] 场景切换按钮生效，ESP32 端响应正确
- [ ] 告警消息能推送到 APP
- [ ] 所有代码已 commit
```

---

## 阶段 7：系统联调 + 端到端测试（预计 2 天）

### 7.1 联调清单

```
AI Prompt：

请帮我生成一份端到端测试清单（Markdown 表格格式），逐个测试以下场景：

1. 人来灯亮：遮挡光敏 + 在 PIR 前挥手 → LED 自动亮
2. 人走灯灭：PIR 前无人 30 秒 → LED 自动灭
3. 高温风扇：用吹风机加热 DHT11 → 风扇自动开 → 降温后自动关
4. 门磁报警：设防 → 开门 → 蜂鸣器响 + APP 收到告警
5. 离家模式：APP 点"离家" → LED 灭 + 风扇停 + 设防
6. 回家模式：APP 点"回家" → 撤防 + LED 亮 + 蜂鸣器静音
7. 远程控制：APP 控制每个设备 → ESP32 响应正确
8. WiFi 断线重连：拔路由器电源 → ESP32 自动重连

每条包含：测试步骤、预期结果、实测结果、是否通过
```

### 7.2 常见联调问题速查

```
AI Prompt：

ESP32-S3 智能家居项目常见联调问题排查：

1. MQTT 连接失败 → 检查 WiFi 是否连接、Broker 地址是否正确
2. DHT11 读数全是 0 → 检查接线、上拉电阻、采样间隔
3. PIR 误触发频繁 → 调整 delayTime 电位器、检查是否有热源干扰
4. 继电器不动作 → 确认低电平触发逻辑、检查供电
5. LED 亮度不对 → 确认是 PWM 引脚（ESP32-S3 部分引脚不支持）
6. 内存不足重启 → 减少 String 使用、增大 ArduinoJson buffer
```

### 7.3 稳定性测试

写一个压测脚本，连续运行 2 小时，记录：

- MQTT 断线次数
- ESP32 重启次数
- 平均内存使用
- 传感器数据丢包率

```
AI Prompt：

请修改 main.cpp，增加以下监控功能：
1. 每 10 分钟打印一次堆内存剩余量（ESP.getFreeHeap()）
2. 统计 MQTT 发布/订阅成功/失败次数
3. 记录系统运行时间（millis() 转 时:分:秒）
4. 看门狗（若 loop() 超过 5 秒未返回，自动重启）
```

### 阶段 7 验收标准

```
- [ ] 8 项端到端测试全部通过
- [ ] 连续运行 30 分钟无重启
- [ ] MQTT 消息不丢包
- [ ] 所有代码已 commit
```

---

## 阶段 8：文档撰写 + 答辩准备（预计 2 天）

### 8.1 技术文档

```
AI Prompt：

请基于本项目代码和 README，帮我撰写以下文档：

1. 技术报告（5000 字左右）：
   - 项目背景与意义
   - 系统总体设计（含架构图文字描述）
   - 硬件选型与接线
   - 软件模块设计（传感器/执行器/通信/联动引擎/场景管理）
   - 测试方法与结果
   - 总结与展望

2. 用户手册：
   - 硬件接线图示
   - 首次使用配置步骤
   - APP 操作说明（截图标注）
   - 常见故障排查

3. 演示脚本（5 分钟）：
   - 每个功能演示的台词和时间分配
   - 重点突出联动逻辑和远程控制
```

### 8.2 PPT 大纲

```
AI Prompt：

请为智能家居项目答辩生成 PPT 大纲（15 页），每页要点如下：

1. 封面（项目名 + 成员）
2. 项目背景与痛点
3. 系统功能总览
4. 系统架构图
5. 硬件清单
6. 关键技术一：传感器数据采集
7. 关键技术二：MQTT 通信
8. 关键技术三：联动规则引擎
9. 关键技术四：场景模式管理
10. APP 界面截图
11. 测试结果（表格 + 截图）
12. 项目难点与解决方案
13. 创新点总结
14. 演示视频 / 现场演示
15. 致谢 + Q&A
```

### 阶段 8 验收标准

```
- [ ] 技术报告完成并导出 PDF
- [ ] PPT 制作完成
- [ ] 演示脚本排练 ≥3 遍
- [ ] 现场演示设备调试完成
- [ ] 最终代码 commit + tag
```

---

## 附录：AI Prompt 速查表

### 通用调试指令

```
# 编译报错
"我的代码编译报错，错误信息如下：[粘贴错误]，请帮我修复"

# 硬件不工作
"我的 [传感器/执行器] 没有反应，当前接线：[描述]，代码：[粘贴]，请帮我排查"

# 代码审查
"请审查以下代码，指出潜在的 bug、内存泄漏和性能问题：[粘贴代码]"

# 优化建议
"以下代码能正常运行但响应较慢，请给出优化建议：[粘贴代码]"
```

### 项目推进节奏

```
每天开始 → 告诉 AI 今天要完成哪个模块
每完成一个 .h → 立刻写测试 → 烧录验证 → commit
遇到 bug → 粘贴错误信息 + 代码 → AI 排查 → 修复 → commit
每天结束 → git push，记录到 CHANGELOG
```

### Git 提交节奏

```bash
# 每个阶段做个 tag
git tag -a v0.1 -m "阶段1：环境搭建+点灯"
git tag -a v0.2 -m "阶段2：传感器驱动全部完成"
git tag -a v0.3 -m "阶段3：执行器驱动全部完成"
git tag -a v0.4 -m "阶段4：WiFi+MQTT通信"
git tag -a v0.5 -m "阶段5：联动引擎+场景模式"
git tag -a v0.6 -m "阶段6：APP对接"
git tag -a v0.7 -m "阶段7：联调测试通过"
git tag -a v1.0 -m "v1.0 发布"
git push --tags
```
