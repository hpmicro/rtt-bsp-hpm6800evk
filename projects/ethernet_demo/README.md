# 网络连通性及吞吐性能测试

## 概述

本示例演示了基于RT-Thread 网络连通性测试和吞吐性能测试

## 硬件设置

* 使用USB Type-C线缆连接PC USB端口和PWR DEBUG端口
* 使用以太网线缆连接PC以太网端口和开发板RGMII或RMII端口

## 软件设置

* 使用flash_release编译运行，可以获得更好的网络性能

## 运行示例

* 编译下载程序
* 串口终端显示

```console
 \ | /
- RT -     Thread Operating System
 / | \     5.0.2 build Apr 19 2025 10:18:07
 2006 - 2022 Copyright by RT-Thread team
lwIP-2.1.2 initialized!
[27] I/sal.skt: Socket Abstraction Layer initialize success.
msh />[4067] I/NO_TAG: ENET0
[4070] I/NO_TAG: PHY Status: Link up
[4074] I/NO_TAG: PHY Speed: 1000Mbps
[4078] I/NO_TAG: PHY Duplex: full duplex
```

## 功能验证

### 1. IP分配查询及DHCP状态确认

```console
msh />ifconfig
network interface device: ET (Default)
MTU: 1500
MAC: 98 2c bc b1 9f 17
FLAGS: UP LINK_UP INTERNET_DOWN DHCP_ENABLE ETHARP BROADCAST
ip address: 192.168.100.6
gw address: 192.168.100.1
net mask  : 255.255.255.0
dns server #0: 192.168.100.1
dns server #1: 0.0.0.0

```

**注： 若DHCP开启，则DHCP状态为“DHCP_ENABLE”，需要将网口连接至路由器或具有DHCP服务的PC  **   

### 2. PING测试

  （1）Windows系统中，打开cmd, 运行ping

```console
C:\Users>ping 192.168.100.6

正在 Ping 192.168.100.6 具有 32 字节的数据:
来自 192.168.100.6 的回复: 字节=32 时间<1ms TTL=255
来自 192.168.100.6 的回复: 字节=32 时间<1ms TTL=255
来自 192.168.100.6 的回复: 字节=32 时间<1ms TTL=255
来自 192.168.100.6 的回复: 字节=32 时间<1ms TTL=255

192.168.100.6 的 Ping 统计信息:
    数据包: 已发送 = 4，已接收 = 4，丢失 = 0 (0% 丢失)，
往返行程的估计时间(以毫秒为单位):
    最短 = 0ms，最长 = 0ms，平均 = 0ms
```

  （2）开发板Ping PC

```console
msh />ping 192.168.100.5
ping: not found specified netif, using default netdev ET.
60 bytes from 192.168.100.5 icmp_seq=0 ttl=64 time=0 ms
60 bytes from 192.168.100.5 icmp_seq=1 ttl=64 time=0 ms
60 bytes from 192.168.100.5 icmp_seq=2 ttl=64 time=0 ms
60 bytes from 192.168.100.5 icmp_seq=3 ttl=64 time=0 ms

```

### 3. **iperf测试**

- **TCP服务端模式**

  - MCU端输入命令

    ```console
    msh /> iperf -s
    ```

  -  PC端输入命令

    ```console
    C:\Users>iperf -c 192.168.100.6 -i 1
    ```

  - 观察PC端结果

    ```console
    ------------------------------------------------------------
    Client connecting to 192.168.100.6, TCP port 5001
    TCP window size: 64.0 KByte (default)
    ------------------------------------------------------------
    [368] local 192.168.100.5 port 62515 connected with 192.168.100.6 port 5001
    [ ID] Interval       Transfer     Bandwidth
    [368]  0.0- 1.0 sec  48.6 MBytes   408 Mbits/sec
    [368]  1.0- 2.0 sec  50.1 MBytes   420 Mbits/sec
    [368]  2.0- 3.0 sec  49.7 MBytes   417 Mbits/sec
    [368]  3.0- 4.0 sec  49.9 MBytes   418 Mbits/sec
    [368]  4.0- 5.0 sec  49.2 MBytes   413 Mbits/sec
    [368]  5.0- 6.0 sec  48.0 MBytes   402 Mbits/sec
    [368]  6.0- 7.0 sec  48.2 MBytes   405 Mbits/sec
    [368]  7.0- 8.0 sec  47.4 MBytes   397 Mbits/sec
    [368]  8.0- 9.0 sec  48.4 MBytes   406 Mbits/sec
    [368]  9.0-10.0 sec  48.0 MBytes   402 Mbits/sec
    [368]  0.0-10.0 sec   487 MBytes   409 Mbits/sec
    ```

  - 观察MCU端结果

    ```console
    msh />[14944] I/iperf: new client connected from (192.168.100.5, 62511)
    [19951] I/iperf: iperfd01: 406.9790 Mbps!
    [24944] W/iperf: client disconnected (192.168.100.5, 62511)
    ```

    

- **TCP客户端模式**

  - PC端输入命令

    ```console
    C:\Users>iperf -s -i 1
    ```

  - MCU端输入命令

    ```console
    msh />iperf -c 192.168.100.5
    ```

  - 观察PC端结果

    ```console
    ------------------------------------------------------------
    Server listening on TCP port 5001
    TCP window size: 64.0 KByte (default)
    ------------------------------------------------------------
    [412] local 192.168.100.5 port 5001 connected with 192.168.100.6 port 52432
    [ ID] Interval       Transfer     Bandwidth
    [412]  0.0- 1.0 sec  41.8 MBytes   351 Mbits/sec
    [412]  1.0- 2.0 sec  41.4 MBytes   347 Mbits/sec
    [412]  2.0- 3.0 sec  41.6 MBytes   349 Mbits/sec
    [412]  3.0- 4.0 sec  41.4 MBytes   347 Mbits/sec
    [412]  4.0- 5.0 sec  40.8 MBytes   342 Mbits/sec
    [412]  5.0- 6.0 sec  41.0 MBytes   344 Mbits/sec
    [412]  6.0- 7.0 sec  41.4 MBytes   347 Mbits/sec
    [412]  7.0- 8.0 sec  41.2 MBytes   346 Mbits/sec
    [412]  8.0- 9.0 sec  41.0 MBytes   344 Mbits/sec
    [412]  9.0-10.0 sec  41.4 MBytes   348 Mbits/sec
    [412] 10.0-11.0 sec  41.0 MBytes   344 Mbits/sec
    [412] 11.0-12.0 sec  41.5 MBytes   348 Mbits/sec
    [412] 12.0-13.0 sec  41.1 MBytes   345 Mbits/sec
    [412] 13.0-14.0 sec  41.8 MBytes   351 Mbits/sec
    [412] 14.0-15.0 sec  41.6 MBytes   349 Mbits/sec
    [412] 15.0-16.0 sec  41.8 MBytes   350 Mbits/sec
    [412] 16.0-17.0 sec  41.8 MBytes   350 Mbits/sec
    [412] 17.0-18.0 sec  41.3 MBytes   347 Mbits/sec
    [412] 18.0-19.0 sec  37.0 MBytes   310 Mbits/sec
    [412] 19.0-20.0 sec  40.2 MBytes   338 Mbits/sec
    ```

  - 观察MCU端结果

    ```console
    msh />[100715] I/iperf: Connect to iperf server successful!
    [105721] I/iperf: iperfc01: 347.2940 Mbps!
    [110721] I/iperf: iperfc01: 345.8460 Mbps!
    [115721] I/iperf: iperfc01: 347.6610 Mbps!
    [120721] I/iperf: iperfc01: 339.1610 Mbps!
    ```

- **UDP服务端模式**

  - MCU端输入命令

    ```console
    msh />iperf -u -s
    ```

  - PC端输入命令

    ```console
    C:\Users>iperf -u -c 192.168.100.6 -i 1 -b 1000M -t 20
    ```

  - 观察PC端结果

    ```console
    ------------------------------------------------------------
    Client connecting to 192.168.100.6, UDP port 5001
    Sending 1470 byte datagrams
    UDP buffer size: 64.0 KByte (default)
    ------------------------------------------------------------
    [360] local 192.168.100.5 port 49199 connected with 192.168.100.6 port 5001
    [ ID] Interval       Transfer     Bandwidth
    [360]  0.0- 1.0 sec  64.5 MBytes   541 Mbits/sec
    [360]  1.0- 2.0 sec  81.5 MBytes   683 Mbits/sec
    [360]  2.0- 3.0 sec  78.9 MBytes   662 Mbits/sec
    [360]  3.0- 4.0 sec  82.4 MBytes   692 Mbits/sec
    [360]  4.0- 5.0 sec  82.7 MBytes   694 Mbits/sec
    [360]  5.0- 6.0 sec  83.0 MBytes   696 Mbits/sec
    [360]  6.0- 7.0 sec  83.6 MBytes   702 Mbits/sec
    [360]  7.0- 8.0 sec  82.9 MBytes   696 Mbits/sec
    [360]  8.0- 9.0 sec  83.1 MBytes   697 Mbits/sec
    [360]  9.0-10.0 sec  76.5 MBytes   642 Mbits/sec
    [360] 10.0-11.0 sec  83.0 MBytes   696 Mbits/sec
    [360] 11.0-12.0 sec  82.7 MBytes   693 Mbits/sec
    [360] 12.0-13.0 sec  83.0 MBytes   696 Mbits/sec
    [360] 13.0-14.0 sec  83.3 MBytes   698 Mbits/sec
    [360] 14.0-15.0 sec  82.7 MBytes   694 Mbits/sec
    [360] 15.0-16.0 sec  81.9 MBytes   687 Mbits/sec
    [360] 16.0-17.0 sec  83.0 MBytes   696 Mbits/sec
    [360] 17.0-18.0 sec  82.4 MBytes   691 Mbits/sec
    [360] 18.0-19.0 sec  85.2 MBytes   715 Mbits/sec
    [360] 19.0-20.0 sec  82.2 MBytes   689 Mbits/sec
    [ ID] Interval       Transfer     Bandwidth
    [360]  0.0-20.0 sec  1.59 GBytes   683 Mbits/sec
    [360] WARNING: did not receive ack of last datagram after 10 tries.
    [360] Sent 1161640 datagrams
    ```

  - 观察MCU端结果

    ```console
    sh />[212609] I/iperf: iperfd01: 266.3000 Mbps! lost:46343 total:159565
    
    [217616] I/iperf: iperfd01: 494.4180 Mbps! lost:86063 total:296275
    
    [222623] I/iperf: iperfd01: 484.5870 Mbps! lost:85662 total:291694
    
    [227630] I/iperf: iperfd01: 488.7120 Mbps! lost:87562 total:295348
    
    [233940] I/iperf: iperfd01: 163.2140 Mbps! lost:-2291991 total:-2204522
    
    ```
    
    

- UDP客户端模式

  - PC端输入命令

    ```console
    C:\Users>iperf -u -s -i 1
    ```

  - MCU端输入命令

    ```console
    msh />iperf -u -c 192.168.100.5
    ```

  - 观察MCU端结果

    ```console
    ------------------------------------------------------------
    Server listening on UDP port 5001
    Receiving 1470 byte datagrams
    UDP buffer size: 64.0 KByte (default)
    ------------------------------------------------------------
    [352] local 192.168.100.5 port 5001 connected with 192.168.100.6 port 62510
    [ ID] Interval       Transfer     Bandwidth       Jitter   Lost/Total Datagrams
    [352]  0.0- 1.0 sec  97.7 MBytes   819 Mbits/sec  0.020 ms 13051/82710 (16%)
    [352]  1.0- 2.0 sec  98.5 MBytes   826 Mbits/sec  0.010 ms 1076/71327 (1.5%)
    [352]  2.0- 3.0 sec  98.9 MBytes   829 Mbits/sec  0.001 ms  415/70950 (0.58%)
    [352]  3.0- 4.0 sec  99.1 MBytes   831 Mbits/sec  0.005 ms    0/70703 (0%)
    [352]  4.0- 5.0 sec  98.4 MBytes   825 Mbits/sec  0.040 ms    0/70169 (0%)
    [352]  5.0- 6.0 sec  97.7 MBytes   820 Mbits/sec  0.051 ms  492/70209 (0.7%)
    [352]  6.0- 7.0 sec  98.6 MBytes   827 Mbits/sec  0.032 ms    0/70298 (0%)
    [352]  7.0- 8.0 sec   100 MBytes   842 Mbits/sec  0.003 ms    0/71558 (0%)
    [352]  8.0- 9.0 sec   100 MBytes   841 Mbits/sec  0.002 ms    0/71482 (0%)
    [352]  9.0-10.0 sec  99.3 MBytes   833 Mbits/sec  0.001 ms  317/71149 (0.45%)
    [352] 10.0-11.0 sec  97.1 MBytes   815 Mbits/sec  0.015 ms  401/69687 (0.58%)
    [352] 11.0-12.0 sec  96.9 MBytes   812 Mbits/sec  0.001 ms  378/69463 (0.54%)
    [352] 12.0-13.0 sec  98.3 MBytes   825 Mbits/sec  0.002 ms  396/70526 (0.56%)
    [352] 13.0-14.0 sec   100 MBytes   840 Mbits/sec  0.015 ms    0/71418 (0%)
    [352] 14.0-15.0 sec  99.3 MBytes   833 Mbits/sec  0.007 ms  654/71496 (0.91%)
    [352] 15.0-16.0 sec   100 MBytes   840 Mbits/sec  0.046 ms    0/71459 (0%)
    [352] 16.0-17.0 sec   100 MBytes   840 Mbits/sec  0.005 ms    0/71443 (0%)
    [352] 17.0-18.0 sec   100 MBytes   841 Mbits/sec  0.011 ms    0/71498 (0%)
    [352] 18.0-19.0 sec   100 MBytes   843 Mbits/sec  0.041 ms    0/71652 (0%)
    [352] 19.0-20.0 sec  99.9 MBytes   838 Mbits/sec  0.004 ms  401/71688 (0.56%)
    ```

    

  - 观察MCU端结果

    ```console
    [66131] I/iperf: iperf udp mode run...
    ```

    **注：此模式下，MCU端无统计信息输出，且无退出机制，需要按reset键重启MCU。**

  

  

