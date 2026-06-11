I (48) boot: Partition Table:
I (50) boot: ## Label            Usage          Type ST Offset   Length
I (56) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (63) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (69) boot:  2 factory          factory app      00 00 00010000 00100000
I (76) boot: End of partition table
I (80) esp_image: segment 0: paddr=00010020 vaddr=42060020 size=39488h (234632) map
I (145) esp_image: segment 1: paddr=000494b0 vaddr=40800000 size=06b68h ( 27496) load
I (154) esp_image: segment 2: paddr=00050020 vaddr=42000020 size=5f094h (389268) map
I (249) esp_image: segment 3: paddr=000af0bc vaddr=40806b68 size=0492ch ( 18732) load
I (256) esp_image: segment 4: paddr=000b39f0 vaddr=4080b500 size=01c7ch (  7292) load
I (265) boot: Loaded app from partition at offset 0x10000
I (266) boot: Disabling RNG early entropy source...
W (276) pmu_init: blk_version is less than 2, pvt function not supported in efuse.
I (277) cpu_start: Unicore app
W (286) clk: esp_perip_clk_init() has not been implemented yet
I (291) cpu_start: GPIO 10 and 11 are used as console UART I/O pins
I (292) cpu_start: Pro cpu start user code
I (292) cpu_start: cpu freq: 160000000 Hz
I (294) app_init: Application information:
I (297) app_init: Project name:     hello_world
I (302) app_init: App version:      6f52aae-dirty
I (306) app_init: Compile time:     Jun 10 2026 18:17:18
I (311) app_init: ELF file SHA256:  514dfffbb...
I (316) app_init: ESP-IDF:          v6.0.1-dirty
I (320) efuse_init: Min chip rev:     v1.0
I (324) efuse_init: Max chip rev:     v1.99 
I (328) efuse_init: Chip rev:         v1.0
I (332) heap_init: Initializing. RAM available for dynamic allocation:
I (338) heap_init: At 4081E410 len 0002E260 (184 KiB): RAM
I (343) heap_init: At 4084C670 len 00002F58 (11 KiB): RAM
I (349) spi_flash: detected chip: generic
I (352) spi_flash: flash io: dio
W (355) spi_flash: Detected size(8192k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (367) sleep_gpio: Configure to isolate all GPIO pins in sleep state
I (373) sleep_gpio: Enable automatic switching of GPIO sleep configuration
I (380) main_task: Started on CPU0
I (380) main_task: Calling app_main()
I (380) example: Turn off LCD backlight
I (380) example: Initialize SPI bus
I (390) example: Install panel IO
I (390) example: Install ST7789 panel driver
I (390) st7789: LCD panel create success, version: 0.0.1
--- 0x40807ab0: esp_restart_noos at /home/qmsd/esp/esp6.0.1/esp-idf/components/esp_system/port/soc/esp32c61/system_internal.c:154
--- 0x4083b970: esp_bootloader_get_description at /home/qmsd/esp/esp6.0.1/esp-idf/components/esp_bootloader_format/esp_bootloader_desc.c:40
--- 0x4083e670: is_xmc_chip_strict at /home/qmsd/esp/esp6.0.1/esp-idf/components/bootloader_support/bootloader_flash/src/bootloader_flash.c:925
--- 0x4083b97a: call_start_cpu0 at /home/qmsd/esp/esp6.0.1/esp-idf/components/bootloader/subproject/main/bootloader_start.c:27
I (710) example: Turn on LCD backlight
I (710) example: Initialize LVGL library
I (710) example: Install LVGL tick timer
I (710) example: Register io panel event callback for LVGL flush ready notification
I (710) example: Create LVGL task
I (720) example: Starting LVGL task
I (780) example: Display LVGL Meter Widget
I (1150) main_task: Returned from app_main()
Guru Meditation Error: Core  0 panic'ed (Stack protection fault). 

Detected in task "LVGL" at 0x42014e94
--- 0x42014e94: block_next at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/stdlib/builtin/lv_tlsf.c:454
Stack pointer: 0x4084d100
Stack bounds: 0x4084d110 - 0x4084e100


Core  0 register dump:
--- Stack dump detected
MEPC    : 0x42014eb0  RA      : 0x42014eaa  SP      : 0x4084d100  GP      : 0x4080bd04  
--- 0x42014eb0: block_next at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/stdlib/builtin/lv_tlsf.c:455
--- 0x42014eaa: block_next at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/stdlib/builtin/lv_tlsf.c:455
TP      : 0x4084e0f0  T0      : 0x4084c870  T1      : 0x00000000  T2      : 0x00000001  
S0/FP   : 0x40818418  S1      : 0x40818420  A0      : 0x40818420  A1      : 0x00000018  
A2      : 0x00000024  A3      : 0x00000011  A4      : 0x00000028  A5      : 0x00000025  
A6      : 0x0000003a  A7      : 0x00000000  S2      : 0x00000044  S3      : 0x40818420  
S4      : 0x0000001c  S5      : 0x408183f0  S6      : 0x000000d6  S7      : 0x000000ff  
S8      : 0x4084d284  S9      : 0x00000005  S10     : 0x00000000  S11     : 0x000000ff  
T3      : 0x00000000  T4      : 0x40810874  T5      : 0x00000001  T6      : 0x00000001  
MSTATUS : 0x00001881  MTVEC   : 0x40800003  MCAUSE  : 0x0000001b  MTVAL   : 0x00000000  
--- 0x40800003: _vector_table at ??:?
MHARTID : 0x00000000  


--- Backtrace:


add symbol table from file "/home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/build/bootloader/bootloader.elf"
0x42014eb0 in block_next (block=block@entry=0x40818418 <work_mem_int+42152>) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/stdlib/builtin/lv_tlsf.c:455
455         block_header_t * next = offset_to_block(block_to_ptr(block),
#0  0x42014eb0 in block_next (block=block@entry=0x40818418 <work_mem_int+42152>) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/stdlib/builtin/lv_tlsf.c:455
#1  0x42014ed8 in block_link_next (block=block@entry=0x40818418 <work_mem_int+42152>) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/stdlib/builtin/lv_tlsf.c:464
#2  0x42014eee in block_mark_as_free (block=block@entry=0x40818418 <work_mem_int+42152>) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/stdlib/builtin/lv_tlsf.c:472
#3  0x420150fc in block_split (block=block@entry=0x408183f0 <work_mem_int+42112>, size=size@entry=36) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/stdlib/builtin/lv_tlsf.c:669
#4  0x42015254 in block_trim_free (control=0x4080df70 <work_mem_int>, block=0x408183f0 <work_mem_int+42112>, size=36) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/stdlib/builtin/lv_tlsf.c:718
#5  0x4201527e in block_prepare_used (control=control@entry=0x4080df70 <work_mem_int>, block=0x408183f0 <work_mem_int+42112>, size=size@entry=36) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/stdlib/builtin/lv_tlsf.c:786
#6  0x4201560e in lv_tlsf_malloc (tlsf=0x4080df70 <work_mem_int>, size=<optimized out>) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/stdlib/builtin/lv_tlsf.c:1102
#7  0x42013f0a in lv_malloc_core (size=<optimized out>) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/stdlib/builtin/lv_mem_core_builtin.c:144
#8  0x42015774 in lv_malloc (size=size@entry=36) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/stdlib/lv_mem.c:70
#9  0x4203dfa6 in circ_calc_aa4 (c=0x4080deec <lv_global+372>, radius=radius@entry=5) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/draw/sw/lv_draw_sw_mask.c:1079
#10 0x4203e8d4 in lv_draw_sw_mask_radius_init (param=param@entry=0x4084d284, rect=rect@entry=0x4084d330, radius=radius@entry=5, inv=inv@entry=true) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/draw/sw/lv_draw_sw_mask.c:352
#11 0x42039928 in draw_border_complex (t=t@entry=0x408194cc <work_mem_int+46428>, outer_area=outer_area@entry=0x408194d4 <work_mem_int+46436>, inner_area=inner_area@entry=0x4084d330, rout=7, rin=5, color=..., opa=<optimized out>) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/draw/sw/lv_draw_sw_border.c:109
#12 0x42039d9c in lv_draw_sw_border (t=t@entry=0x408194cc <work_mem_int+46428>, dsc=0x4081952c <work_mem_int+46524>, coords=coords@entry=0x408194d4 <work_mem_int+46436>) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/draw/sw/lv_draw_sw_border.c:81
#13 0x420385a2 in execute_drawing (t=t@entry=0x408194cc <work_mem_int+46428>) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/draw/sw/lv_draw_sw.c:393
#14 0x4203863c in dispatch (draw_unit=0x4080ec18 <work_mem_int+3240>, layer=0x4080f028 <work_mem_int+4280>) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/draw/sw/lv_draw_sw.c:332
#15 0x4200c84a in lv_draw_dispatch_layer (disp=disp@entry=0x4080ecf0 <work_mem_int+3456>, layer=layer@entry=0x4080f028 <work_mem_int+4280>) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/draw/lv_draw.c:284
#16 0x4200c87a in lv_draw_dispatch () at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/draw/lv_draw.c:222
#17 0x4200c926 in lv_draw_finalize_task_creation (layer=layer@entry=0x4080f028 <work_mem_int+4280>, t=0x408194cc <work_mem_int+46428>) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/draw/lv_draw.c:173
#18 0x4200efea in lv_draw_rect (layer=layer@entry=0x4080f028 <work_mem_int+4280>, dsc=dsc@entry=0x4084d510, coords=coords@entry=0x4084d4dc) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/draw/lv_draw_rect.c:348
#19 0x4202e204 in lv_obj_draw (e=<optimized out>) at /home/qmsd/esp_project/work_project/ZX2D80CE63S-V10/ZX2D80CE63S-V10/managed_components/lvgl__lvgl/src/core/lv_obj.c:776
#20 0x00000000 in ?? ()
Backtrace stopped: frame did not save the PC



ELF file SHA256: 514dfffbb