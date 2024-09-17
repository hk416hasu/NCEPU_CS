#include <8051.h>
#include "delayxms.h"

#define cycle 20   // use 20ms as a cycle

__sfr __at (0xa0) led;

void breathingOne(char sub);

void main() {
    while (1) {
        for (char i = 0; i < 8; i++) {
            breathingOne(i);
            delayxms(20);
        }
    }
}

void breathingOne(char sub) {
    sub = 0;
    for (char i = 0; i < cycle; i++) {
        led = 0;
        delayxms(i);
        led = 1;
        delayxms(cycle - i);
    }
    for (char i = cycle; i > 0; i--) {
        led = 0;
        delayxms(i);
        led = 1;
        delayxms(cycle - i);
    }
}
