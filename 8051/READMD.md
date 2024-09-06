First, using SDCC as compiler
    u can install it with " sudo apt-get install sdcc " , then
```bash
    sdcc c51.c
```

Second, change .ihx to .hex
```bash
    packihx a.ihx > a.hex
```

Next, burn the .hex with stcgal
    u can install it by following steps
```bash
    sudo apt install python3-pip
    pip install stcgal  # no need sudo?
```
