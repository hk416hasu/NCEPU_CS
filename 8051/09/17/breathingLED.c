#include <8051.h>
#include "delayxms.h"

#define cycle 20   // use 20ms as a cycle

__sfr __at (0xa0) led;

void ledMore();
void ledLess();

void main() {
    while (1) {
        ledMore();
        ledLess();
    }
}

void ledMore() {
    for (char i = 0; i < cycle; i++) {
        led = 0x00;
        delayxms(i);
        led = 0xdf;
        delayxms(cycle - i);
    }
}

void ledLess() {
    for (char i = cycle; i > 0; i--) {
        led = 0;
        delayxms(i);
        led = 0xdf;
        delayxms(cycle - i);
    }
}
