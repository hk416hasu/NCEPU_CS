This is a flow of how to build an development env and how to use them,

#### 1.build your env ####

First, every source file need a compiler, it's **sdcc** for C51(8051).
```bash
    # install
    sudo apt install sdcc

    # how to use it?
    sdcc C51.c  # don't forget to include <8051.h>
```

Second, u need to burn the output file to your STC MCUs,
an open source ISP flash tool for STC MCUs called **stcgal**
can help with u.
```bash
    # install
    sudo apt install python3-pip
    pip install stcgal  # may need sudo?

    # how to use it?
    sudo stcgal a.ihx    
                    # plz ensure /dev/ttyUSB0 exists before burning and
                    # it's indeed your development board.
                    # Don't forget to restart your 8051 board when buring. 
```

Additionally, maybe u need a .hex file, **packihx** can help u.
```bash
    # install
    # the packihx will be installed with sdcc, so u needn't install again

    # how to use it?
    packihx a.ihx > a.hex
```

#### 2.some problems u may meet ####

##### a) My ubuntu 22.04.04 has CH340 driver, so i don't need to install again, #####
    u can use this command to check if your computer can detect the CH340 devices:
```bash
    lsusb   # this command can show the list of all your USB device
```
    If u are lucky enough, u can find your CH340 device, which means u have a CH340 driver.

##### b) Stcgal prints error that it can not find /dev/ttyUSB0, i solved it by this, i wish it's also useful for u: #####
```bash
    # check the brltty status
    sudo dmesg | grep brltty

    # if u get the message like this:
    [ 1766.123165] usb 1-2: usbfs: interface 0 claimed by ch341 while 'brltty' sets config #1
    # which means brltty claimed the CH340 USB-to-serial converter.
    # What is brltty? It's designed for the blind, and u can remove it.

    # how to remove brltty, which claims the CH340 device.
    sudo systemctl stop brltty
    sudo systemctl disable brltty
    sudo apt remove brltty

    # then u need to re-plug your usb
    ls /dev/ttyUSB* # to check the usb device status
```

---

addtional notes:
char                1 byte      -128~127
unsigned char       1 byte      0~255
int                 2 bytes     -32768~32767
unsigned int        2 bytes     0~65535
long int            4 bytes     -2147483648~2147483647
unsigned long int   4 bytes     0~0xFFFFh
