I (23) boot: ESP-IDF v6.0.1-dirty 2nd stage bootloader
I (23) boot: compile time Jun  9 2026 16:50:57
I (24) boot: chip revision: v1.0
I (24) boot: efuse block revision: v0.1
I (27) boot.esp32c61: SPI Speed      : 80MHz
I (31) boot.esp32c61: SPI Mode       : DIO
I (35) boot.esp32c61: SPI Flash Size : 2MB
I (39) boot: Enabling RNG early entropy source...
I (43) boot: Partition Table:
I (46) boot: ## Label            Usage          Type ST Offset   Length
I (52) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (59) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (65) boot:  2 factory          factory app      00 00 00010000 00100000
I (72) boot: End of partition table
I (75) esp_image: segment 0: paddr=00010020 vaddr=42018020 size=06a18h ( 27160) map
I (88) esp_image: segment 1: paddr=00016a40 vaddr=40800000 size=015d8h (  5592) load
I (91) esp_image: segment 2: paddr=00018020 vaddr=42000020 size=10010h ( 65552) map
I (109) esp_image: segment 3: paddr=00028038 vaddr=408015d8 size=08a1ch ( 35356) load
I (117) esp_image: segment 4: paddr=00030a5c vaddr=4080a000 size=016dch (  5852) load
I (121) boot: Loaded app from partition at offset 0x10000
I (122) boot: Disabling RNG early entropy source...
W (135) pmu_init: blk_version is less than 2, pvt function not supported in efuse.
I (135) cpu_start: Unicore app
W (145) clk: esp_perip_clk_init() has not been implemented yet
I (150) cpu_start: GPIO 10 and 11 are used as console UART I/O pins
I (150) cpu_start: Pro cpu start user code
I (151) cpu_start: cpu freq: 160000000 Hz
I (153) app_init: Application information:
I (156) app_init: Project name:     hello_world
I (161) app_init: App version:      a1952e1-dirty
I (165) app_init: Compile time:     Jun  9 2026 16:50:54
I (170) app_init: ELF file SHA256:  dc093ab15...
I (174) app_init: ESP-IDF:          v6.0.1-dirty
I (179) efuse_init: Min chip rev:     v1.0
I (183) efuse_init: Max chip rev:     v1.99 
I (187) efuse_init: Chip rev:         v1.0
I (190) heap_init: Initializing. RAM available for dynamic allocation:
I (197) heap_init: At 4080E640 len 0003E030 (248 KiB): RAM
I (202) heap_init: At 4084C670 len 00002F58 (11 KiB): RAM
I (207) spi_flash: detected chip: generic
I (211) spi_flash: flash io: dio
W (214) spi_flash: Detected size(8192k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (226) main_task: Started on CPU0
I (226) main_task: Calling app_main()
I (226) lcd_probe: ============================================
I (236) lcd_probe: ST7789P3 BITBANG-ONLY PROBE (4-line 8bit serial)
I (236) lcd_probe: Pins: SCLK=3 SDA=24 DC=5 RST=25 CS=9 BL=22 TE=23
I (246) lcd_probe: Only bitbang probes are enabled to avoid panel state interference.
I (256) lcd_probe: 
I (256) lcd_probe: ========== PROBE E_bitbang_4wire_mode0 ==========
I (256) lcd_probe: bitbang on GPIO directly (bypass SPI peripheral), timing=mode0
I (1506) lcd_probe: bitbang wrote 64x64 RED block at top-left (mode0), full init + continuous cmd/data transactions
I (3006) lcd_probe: 
I (3006) lcd_probe: ========== PROBE F_bitbang_4wire_mode3 ==========
I (3006) lcd_probe: bitbang on GPIO directly (bypass SPI peripheral), timing=mode3
I (4246) lcd_probe: bitbang wrote 64x64 RED block at top-left (mode3), full init + continuous cmd/data transactions
I (5746) lcd_probe: ============================================
I (5746) lcd_probe: BITBANG-ONLY PROBE END
I (5746) lcd_probe: ============================================