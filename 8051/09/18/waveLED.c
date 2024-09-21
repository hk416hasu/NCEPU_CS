#include <8051.h>
#include "delayxms.h"

#define cycle 20   // use 20ms as a cycle

__sfr __at (0xa0) led;

void breathingOne(char sub);

void main() {
    led = 0xff;
    while (1) {
        for (char i = 0; i < 8; i++) {
            led = 0xff;
            breathingOne(i);
            led = 0xff;
        }
    }
}

void breathingOne(char sub) {
    led = 0xff;
    for (char i = 0; i < cycle; i++) {
        led &= (0 << sub);
        delayxms(i);
        led |= (1 << sub);
        delayxms(cycle - i);
    }
    led = 0xff;
    for (char i = cycle; i > 0; i--) {
        led &= (0 << sub);
        delayxms(i);
        led |= (1 << sub);
        delayxms(cycle - i);
    }
    led = 0xff;
}
// why so many led = 0xff, but can not make led off???
