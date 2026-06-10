idf_component_register(
    SRCS "main.c" "lvgl_demo_ui.c"
    INCLUDE_DIRS "."
    REQUIRES driver esp_lcd esp_timer
)