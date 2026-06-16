# ZX2D80CE63S-V10

[中文](./readme_ch.md)

## Overview

ZX2D80CE63S-V10 is an ESP-IDF reference project for the ZX2D80CE63S-V10 hardware platform. It provides a ready-to-use software baseline for display, touch, and optional RS485 functionality.

The project is built on the following software stack:

- ESP-IDF v6.0.1
- LVGL 9.x
- ST7789 LCD driver
- FT5x06 touch driver

This project is a practical starting point for:

- validating the LCD and touch hardware bring-up
- bootstrapping an LVGL-based GUI application
- reusing the board-level initialization code for display, touch, and RS485

## Features

- 240 x 320 SPI display support
- FT5x06 capacitive touch integration
- LVGL initialization and demo UI support
- Optional RS485 demo enabled through menuconfig
- Dependency management through ESP-IDF managed components

## Requirements

Recommended environment:

- ESP-IDF v6.0.1
- ESP-IDF toolchain properly installed and exported
- Target chip: esp32c61

The project dependencies are declared in [main/idf_component.yml](main/idf_component.yml), including:

- lvgl/lvgl 9.x
- jbrilha/esp_lcd_st7789
- espressif/esp_lcd_touch_ft5x06

## Quick Start

### 1. Set the target

```bash
idf.py set-target esp32c61
```

### 2. Open the configuration menu

```bash
idf.py menuconfig
```

### 3. Adjust compiler options

The bundled LVGL demo may emit warnings that are treated as build errors under the default compiler settings. If that happens, enable the following option in menuconfig:

```bash
Compiler options -> Disable errors for default warnings
```

<div style="text-align: center;">
	<img src="doc/warn.png" alt="Compiler warning configuration" style="width: 100%; height: auto; border-radius: 5px; margin-bottom: 10px;">
</div>

### 4. Select application features

Application feature switches are available at:

```bash
(Top) -> Application Features
```

Available options:

- Enable RS485 demo: starts the RS485 demo task during boot
- Enable LVGL demo: initializes the LCD, touch controller, and LVGL demo UI

These configuration entries are defined in [main/Kconfig.projbuild](main/Kconfig.projbuild).

<div style="text-align: center;">
	<img src="doc/demo.png" alt="Application feature configuration" style="width: 60%; height: auto; border-radius: 5px; margin-bottom: 10px;">
</div>

### 5. Build, flash, and monitor

```bash
idf.py build
idf.py flash
idf.py monitor
```

## Runtime Behavior

- If RS485 demo is enabled, the RS485 demo logic runs during startup.
- If LVGL demo is enabled, the project initializes the SPI LCD, backlight, touch controller, and LVGL task.
- If both LVGL demo and RS485 demo are disabled, the application only prints logs and exits from the main entry.

The main application entry is implemented in [main/main.c](main/main.c).

## Reuse Guidance

If you plan to use this project as a template for a product or another demo, review these areas first:

- pin definitions in [main/ZX2D80CE63S-V10_pin.h](main/ZX2D80CE63S-V10_pin.h)
- LCD resolution, SPI clock, and display rotation settings
- LVGL draw buffer size and task stack configuration
- whether to keep the demo UI or replace it with your application UI

## Troubleshooting

### Warnings are treated as errors during build

Enable the following option in menuconfig:

```bash
Compiler options -> Disable errors for default warnings
```

### No UI appears after boot

Check the following items first:

- whether LVGL demo is enabled
- whether the backlight and reset pin definitions are correct
- whether the LCD and touch wiring matches the board-level pin configuration

## Note

This repository currently provides a reference project rather than a standalone reusable driver library. If you want to integrate it across multiple products, it is recommended to split the display, touch, and demo logic into separate components for cleaner maintenance and version control.
