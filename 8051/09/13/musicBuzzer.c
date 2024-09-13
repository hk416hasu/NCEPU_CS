#include <8051.h>
#include "timer0.h"
#include "delayxms.h"

unsigned int val[] = {1758, 1758, 1172, 1172, 1044, 1044, 1172, 1172, 1317, 1317, 1395, 1395, 1566, 1566, 1758, 1758, 1172, 1172, 1317, 1317, 1395, 1395, 1566, 1566 };
unsigned char i = 0;

__sbit __at (0xA5) buzzer;

void main() {
    Timer0_Init();
    while (1) {
        i++;    // must update i in main(), but why?
        if (i >= sizeof(val)/sizeof(val[0])) {
            i = 0;
        }
        delayxms(500);
        TR0 = 0;
        delayxms(5);
        TR0 = 1;
    }
}

void ISR() __interrupt 1 {

    TH0 = (65536 - val[i]) >> 8;
    TL0 = (65536 - val[i]) & 0xff;

    TF0 = 0;

    buzzer = !buzzer;
}
