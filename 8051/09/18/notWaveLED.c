#include <8051.h>
#include "delayxms.h"

#define cycle 20   // use 20ms as a cycle

__sfr __at (0xa0) led;

void breathingOne(char sub);

void main() {
    while (1) {
        for (char i = 0; i < 8; i++) {
            breathingOne(i);
            delayxms(5);
        }
    }
}

// at least i learned how to control each sbit by sfr
void breathingOne(char sub) {
    for (char i = 0; i < cycle; i++) {
        led &= (0 << sub);
        delayxms(i);
        led |= (1 << sub);
        delayxms(cycle - i);
    }
    for (char i = cycle; i > 0; i--) {
        led &= (0 << sub);
        delayxms(i);
        led |= (1 << sub);
        delayxms(cycle - i);
    }
}
