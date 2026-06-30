set(app_srcs "main.c" "st7789_vendor.c")

if(CONFIG_APP_ENABLE_RS485)
    list(APPEND app_srcs "rs485_demo.c")
endif()

if(CONFIG_APP_ENABLE_LVGL)
    list(APPEND app_srcs "lvgl_demo_ui.c")
endif()

idf_component_register(
    SRCS ${app_srcs}
    INCLUDE_DIRS "."
    REQUIRES driver esp_lcd esp_timer esp_driver_uart esp_driver_gpio
)
