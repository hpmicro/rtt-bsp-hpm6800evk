# 更新

## v1.5.0

- 整合了hpm_sdk v1.5.0
- 更新:
    - USB相关sample协议栈切换为cherryUSB
    - ETH PHY 抽象层多实例支持和优化
- 修复:
    - MCAN sample开启硬件过滤器读取数据错误的问题
- 新增:
    - 增加中断向量模式和可抢占模式
    - systemView组件
    - rtt lcd driver驱动

## v1.4.1
- 修复：
  - I2C开启DMA后传输出错的问题
  - 默认模板工程创建出错的问题

## v1.4.0

- 整合了 hpm_sdk v1.4.0
- 升级 RT-Thread 到 v5.0.2
- 新增示例:
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