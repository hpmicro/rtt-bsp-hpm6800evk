# Change Log

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