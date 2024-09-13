#include <8051.h>

void delayxms(unsigned int xms);

void main() {
    while (1) {
        P2_0 = !P2_0;
        P2_5 = !P2_5;
        delayxms(1000);
    }
}

void delayxms(unsigned int xms) {
    unsigned char i;
    while (xms--) {
        i = 120;
        while (--i);
    }
}
