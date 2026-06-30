#include "driver/gpio.h"
#include "esp_check.h"
#include "esp_lcd_panel_commands.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdlib.h>
#include <sys/cdefs.h>
#include "esp_lcd_panel_st7789.h"

#include "st7789_vendor.h"

static const char *TAG = "st7789_vendor";

static const st7789_lcd_init_cmd_t vendor_specific_init_default[] = {
    {0x11, 0, 0, 120},
    {0x36, (uint8_t[]){0x00}, 1, 0},
    {0x3A, (uint8_t[]){0x05}, 1, 0},
    {0xB2, (uint8_t[]){0x0C, 0x0C, 0x00, 0x33, 0x33}, 5, 0},
    {0xB7, (uint8_t[]){0x46}, 1, 0},
    {0xBB, (uint8_t[]){0x1B}, 1, 0},
    {0xC0, (uint8_t[]){0x2C}, 1, 0},
    {0xC2, (uint8_t[]){0x01}, 1, 0},
    {0xC3, (uint8_t[]){0x0F}, 1, 0},
    {0xC4, (uint8_t[]){0x20}, 1, 0},
    {0xC6, (uint8_t[]){0x0F}, 1, 0},
    {0xD0, (uint8_t[]){0xA7, 0xA1}, 2, 0},
    {0xD0, (uint8_t[]){0xA4, 0xA1}, 2, 0},
    {0xD6, (uint8_t[]){0xA1}, 1, 0},
    {0xE0, (uint8_t[]){
        0xF0, 0x00, 0x06, 0x04, 0x05, 0x05,
        0x31, 0x44, 0x48, 0x36, 0x12, 0x12,
        0x2B, 0x34
    }, 14, 0},
    {0xE1, (uint8_t[]){
        0xF0, 0x0B, 0x0F, 0x0F, 0x0D, 0x26,
        0x31, 0x43, 0x47, 0x38, 0x14, 0x14,
        0x2C, 0x32
    }, 14, 0},
    {0x21, 0, 0, 0},
    {0x29, 0, 0, 0},
    {0x2C, 0, 0, 0},
};

esp_err_t panel_st7789_init(esp_lcd_panel_io_handle_t io, const st7789_vendor_config_t *vendor_config)
{
    ESP_RETURN_ON_FALSE(io, ESP_ERR_INVALID_ARG, TAG, "invalid io handle");

    // LCD goes into sleep mode and display will be turned off after power on
    // reset, exit sleep mode first
    ESP_RETURN_ON_ERROR(esp_lcd_panel_io_tx_param(io, LCD_CMD_SLPOUT, NULL, 0),
                        TAG, "send SLPOUT failed");
    vTaskDelay(pdMS_TO_TICKS(100));

    ESP_RETURN_ON_ERROR(esp_lcd_panel_io_tx_param(io, LCD_CMD_MADCTL,
                                                  (uint8_t[]){0x00}, 1),
                        TAG, "send MADCTL failed");
    ESP_RETURN_ON_ERROR(esp_lcd_panel_io_tx_param(io, LCD_CMD_COLMOD,
                                                  (uint8_t[]){0x55}, 1),
                        TAG, "send COLMOD failed");

    // Select init commands: use vendor_config if provided, otherwise use defaults
    const st7789_lcd_init_cmd_t *init_cmds = NULL;
    uint16_t init_cmds_size = 0;
    if (vendor_config && vendor_config->init_cmds) {
        init_cmds = vendor_config->init_cmds;
        init_cmds_size = vendor_config->init_cmds_size;
    } else {
        init_cmds = vendor_specific_init_default;
        init_cmds_size = sizeof(vendor_specific_init_default) /
                         sizeof(st7789_lcd_init_cmd_t);
    }

    // Check if MADCTL or COLMOD will be overwritten by the init sequence
    for (int i = 0; i < init_cmds_size; i++) {
        switch (init_cmds[i].cmd) {
        case LCD_CMD_MADCTL:
            ESP_LOGW(TAG,
                     "The %02Xh command has been used and will be overwritten "
                     "by external initialization sequence",
                     init_cmds[i].cmd);
            break;
        case LCD_CMD_COLMOD:
            ESP_LOGW(TAG,
                     "The %02Xh command has been used and will be overwritten "
                     "by external initialization sequence",
                     init_cmds[i].cmd);
            break;
        default:
            break;
        }
    }

    // Send all init commands
    for (int i = 0; i < init_cmds_size; i++) {
        ESP_RETURN_ON_ERROR(esp_lcd_panel_io_tx_param(io, init_cmds[i].cmd,
                                                      init_cmds[i].data,
                                                      init_cmds[i].data_bytes),
                            TAG, "send init command failed");
        vTaskDelay(pdMS_TO_TICKS(init_cmds[i].delay_ms));
    }
    ESP_LOGD(TAG, "send init commands success");

    return ESP_OK;
}
