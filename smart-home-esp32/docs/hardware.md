# 硬件接线图

## 主控

| 品名 | 型号 | Flash | PSRAM | USB-OTG |
|------|------|:---:|:---:|:---:|
| 开发板 | ESP32-S3-DevKitC-1 **N16R8** | 16MB | 8MB Octal | GPIO 47/48 原生 USB |

---

## ESP32-S3 关键注意事项

### 1. 引脚限制

| 限制类型 | 涉及引脚 | 说明 |
|----------|----------|------|
| **PSRAM/Flash 专用** | GPIO 26-37 | 板载 Flash/PSRAM 占用，**禁止用作普通 IO** |
| **Strapping 引脚** | GPIO 0, 3, 45, 46 | 启动配置引脚，GPIO 0 拉低进入下载模式 |
| **USB-OTG** | GPIO 47, 48 | 原生 USB 引脚，可直接做 USB 主机/设备 |
| **ADC2 限制** | GPIO 11-20 | WiFi 开启时 ADC2 不可用，仅 ADC1 可做模拟输入 |

### 2. ADC 选型规则

```
WiFi + analogRead 共存时:
  ✅ ADC1 (GPIO 1-10)  — 可用
  ❌ ADC2 (GPIO 11-20) — WiFi 占用，不可用
```

本项目光敏传感器接 **GPIO 1 (ADC1_CH0)**，不受 WiFi 影响。

### 3. PSRAM 启用

N16R8 自带 8MB Octal PSRAM，`platformio.ini` 已配置：
```ini
board_build.psram_type = opi
board_build.arduino.memory_type = qio_opi
```

编译后 `ESP.getPsramSize()` 应返回 `8388608`（8MB）。

---

## 引脚分配表

### 板载

| 功能 | 品名 | GPIO | 接口类型 | 备注 |
|------|------|:---:|------|------|
| 板载 LED | WS2812 RGB | 48 | NeoPixel | USB-OTG 引脚，不可用 digitalWrite |

### 传感器（GPIO 1-7，ADC1 安全区）

| 功能 | 品名 | GPIO | 接口类型 | 备注 |
|------|------|:---:|------|------|
| 温湿度 | DHT11/DHT22 | 4 | GPIO | 需外接 4.7kΩ 上拉到 3.3V |
| 光照 | LM393 光敏模块 | 1 | ADC1_CH0 | WiFi 下可用，模拟 0-4095 |
| 人体红外 1 | HC-SR501 | 5 | GPIO | 数字输入，高电平 = 有人 |
| 人体红外 2 | HC-SR501 | 6 | GPIO | 数字输入（可选） |
| 门磁 | MC-38 干簧管 | 7 | GPIO | 内部上拉，低电平 = 门开 |

### 执行器（GPIO 10-16，连续排列）

| 功能 | 品名 | GPIO | 接口类型 | 备注 |
|------|------|:---:|------|------|
| LED 红 | 5mm LED | 10 | GPIO (PWM) | 串 220Ω 限流电阻 |
| LED 绿 | 5mm LED | 11 | GPIO (PWM) | 串 220Ω 限流电阻 |
| LED 蓝 | 5mm LED | 12 | GPIO (PWM) | 串 220Ω 限流电阻 |
| 蜂鸣器 | 有源蜂鸣器模块 | 13 | GPIO | 3.3V/5V 均可 |
| 风扇继电器 | 5V 低电平触发继电器 | 14 | GPIO | 低电平吸合 |
| 家电继电器 | 5V 低电平触发继电器 | 15 | GPIO | 低电平吸合 |
| 舵机 | SG90 | 16 | GPIO (PWM) | 50Hz，500-2500μs |

### 保留引脚（禁止使用）

| GPIO | 原因 | 说明 |
|:---:|------|------|
| 0 | Strapping | 下载模式引脚 |
| 3 | Strapping | JTAG 控制 |
| 26-37 | 硬件占用 | Flash / PSRAM 专用 |
| 45 | Strapping | VDD_SPI 电压选择 |
| 46 | Strapping | VDD_SPI 电压选择 |

---

## 接线注意事项

1. **DHT11** 数据线需 **4.7kΩ 上拉电阻** 到 3.3V
2. **继电器** 使用 **5V 独立电源**，控制信号 3.3V 经三极管驱动
3. **所有传感器 VCC 接 3.3V**，GND 共地
4. **执行器大电流设备**（风扇/继电器线圈）单独从 5V 供电
5. **上电前** 先用万用表测 VCC-GND 短路
6. **ADC 输入** 电压范围 0-3.3V，超过会损坏引脚
