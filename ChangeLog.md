# Change Log

## v1.6.0

- Integrated hpm_sdk v1.6.0
- Updated:
    - Optimized the control of `BRS` bit in CANFD frame
    - Upgraded the `cherryUSB` stack to v1.3.1
    - Added USB descriptor for Full-speed mode to USB examples
    - Upgraded the SoC Datasheet
    - Optimized SDIO driver, added new configuration options such as `BUS_WDITH`，Added eMMC HS400 support, Added SD UHS-I speed mode support
- Fixed:
    - Macro definition errors related to  TX DMA for UART7 & UART7 
    - Memory leakage issue in uart_v2 driver
- Added:
    - SPI CS pin control option
    - Adapted RT-Thread Cache API
    - Added performance test command to `sdcard_demo`
- New Examples:
    - airoc_wifi_demo (Infinieon AIROC WiFi series)

## v1.5.0

- Integrated hpm_sdk v1.5.0
- Updated:
    - usb stack switched to cherryUSB for usb samples
    - ETH PHY abstraction layer multi-instance support and optimization
- Fixed:
    - MCAN sample read data error when enable RT_CAN_USING_HDR
- Added:
    - added interrupt vector mode and preemptive mode
    - systemView component
    - rtt lcd driver

## 1.4.1
- Fixed:
  - Transmission error while enabling DMA in I2C driver
  - Failed to create template project

## v1.4.0

- Integrated hpm_sdk v1.4.0
- Upgraded RT-Thread to v1.4.0
- New samples:
    - audio_i2s_demo
    - audio_pdm_dao_demo
    - blink_led
    - can_example
    - ethernet_demo
    - ethernet_ptp_master_demo
    - ethernet_ptp_slave_demo
    - flashdb_demo
    - i2c_demo
    - lv_demo_widgets
    - sdcard_demo
    - uart_dma_demo
    - usb_device_generic_hid
    - usb_host_msc_udisk
    - web_camera_demo
    - webnet_demo