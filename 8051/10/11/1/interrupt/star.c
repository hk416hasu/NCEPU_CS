#include <8051.h>
#include "timer0.h"

__sbit __at (0xA3) LED;
int times = 0;

int main() {
    Timer0_Init();
    while (1);
}

void ISR() __interrupt 1 {
    TH0 = (65536 - 50000) >> 8;
    TL0 = (65536 - 50000) & 0xff;
    times++;
    if ( times == 20 ) {
        LED = !LED;
        times = 0;
    }
}
