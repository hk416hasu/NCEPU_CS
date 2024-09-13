#include <8051.h>
#include "timer0.h"

__sbit __at (0xA5) buzzer;

void main() {
    Timer0_Init();
    while (1);
}

void ISR() __interrupt 1 {
    TH0 = (65536 - 300) >> 8;
    TL0 = (65536 - 300) & 0xff;

    TF0 = 0;

    buzzer = !buzzer;
}
