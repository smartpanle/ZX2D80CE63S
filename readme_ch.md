# ZX2D80CE63S

[English](./readme.md)

## ESP-IDF版本
esp-idf v6.0.1

## 配置

### 设置芯片类型

```bash
idf.py set-target esp32c61
```

### menuconfig

由于lvgl例程存在警告导致编译出错，需要进入menuconfig关闭警告
```bash
Compiler options -> Disable errors for default warnings
```