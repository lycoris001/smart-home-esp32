# MQTT 主题定义

> 统一命名规范：`home/{room}/{device}/{action}`

## 数据上报主题（ESP32 → APP 订阅）

| 主题 | 说明 | QoS |
|------|------|:---:|
| `home/livingroom/temperature` | 温度数据（℃） | 0 |
| `home/livingroom/humidity` | 湿度数据（%） | 0 |
| `home/livingroom/light` | 光照数据（0-100） | 0 |
| `home/livingroom/pir` | 人体检测（0/1） | 1 |
| `home/livingroom/door` | 门磁状态（open/closed） | 1 |
| `home/livingroom/alarm` | 告警信息（JSON） | 1 |

## 控制指令主题（APP → ESP32 订阅）

| 主题 | 说明 | 载荷格式 |
|------|------|---------|
| `home/livingroom/led/command` | LED 控制 | `{"channel":0,"state":1,"brightness":128}` |
| `home/livingroom/fan/command` | 风扇控制 | `{"state":1}` |
| `home/livingroom/buzzer/command` | 蜂鸣器控制 | `{"action":"beep","duration":500}` |
| `home/livingroom/scene` | 场景切换 | `{"scene":"away"}` |

## 场景模式值

| 值 | 含义 |
|------|------|
| `home` | 回家模式 |
| `away` | 离家模式 |
| `night` | 睡眠模式 |

## 告警消息格式

```json
{
  "type": "intrusion",
  "message": "门磁异常开启",
  "timestamp": 1700000000
}
```

告警类型：`intrusion`（入侵）/ `fire`（火警）/ `low_battery`（低电量）
