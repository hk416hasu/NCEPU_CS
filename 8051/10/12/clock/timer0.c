#include "timer0.h"

void Timer0_Init() {
    TMOD &= 0xf0;   // clear Timer0 configure
    TMOD |= 0x01;   // set timer0 to 16-bit mode
    TH0 = (65536 - 50000) >> 8;  // set the High 8 bits of timer0
    TL0 = (65536 - 50000) & 0xff; // set the Low 8 bits of timer0
    // IE = 0x82 等效于 EA = ET0 = 1
    ET0 = 1;    // enable interrupt of timer0
    EA = 1;     // enable global interrupts
    TR0 = 1;    // enable timer0
}
