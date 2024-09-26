#include <8051.h>
#include "timer0.h"
#include "delayxms.h"

#define speed 210

__code unsigned int val[36] = { 3508,3318,3126,2955,2785,2633,2484,2344,2214,2089,1972,1860, 1758,1659,1566,1478,1395,1317,1242,1172,1106,1045,986,930, 878,828,782,738,697,657,621,586,553,522,492,465 };
__code unsigned char Music[] = { 9,11,12,14,16,21,19, 16,9,16,14,12,11, 9,11,12,14,16,14,12, 11,9,11,12,11,9,8,11, 9,11,12,14,16,21,19, 16,9,16,14,12,11, 9,11,12,14,16,14,12, 11,12,14,16, 19,21,16,14,16,14,16, 19,21,16,14,16,14,16, 14,12,11,7,9,7,9, 11,12,14,16,9,16,19, 19,21,16,14,16,14,16, 19,21,16,14,16,14,16, 14,12,11,7,9,7,9, 11,12,14,16,9,16,19, 19,21,16,14,16,14,16, 19,21,16,14,16,14,16, 14,12,11,7,9,7,9, 11,12,14,16,9,16,19, 19,21,16,14,16,14,16, 19,21,16,14,16,21,23, 24,23,21,19,16,14,16, 14,12,11,7,9,16,19 };
__code unsigned char length[] ={ 1,1,1,1,2,1,1, 2,2,1,1,1,1, 1,1,1,1,2,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,2,1,1, 2,2,1,1,1,1, 1,1,1,1,2,1,1, 2,2,2,2, 1,1,1,1,2,1,1, 1,1,1,1,2,1,1, 1,1,1,1,2,1,1, 1,1,1,1,2,1,1, 1,1,1,1,2,1,1, 1,1,1,1,2,1,1, 1,1,1,1,2,1,1, 1,1,1,1,2,1,1, 1,1,1,1,2,1,1, 1,1,1,1,2,1,1, 1,1,1,1,2,1,1, 1,1,1,1,2,1,1, 1,1,1,1,2,1,1, 1,1,1,1,2,1,1, 1,1,1,1,2,1,1, 1,1,1,1,2,1,1 };
unsigned char i = 0;

__sbit __at (0xA5) buzzer;

void main() {

    Timer0_Init();
    while (1) {
        i++;    // must update i in main(), but why?
        if (i >= sizeof(Music)/sizeof(Music[0])) {
            i = 0;
        }
        delayxms(speed * length[i]);

        // gap
        TR0 = 0;
        delayxms(5);
        TR0 = 1;
    }
}

void ISR() __interrupt 1 {

    TH0 = (65536 - val[Music[i]]) >> 8;
    TL0 = (65536 - val[Music[i]]) & 0xff;

    TF0 = 0;

    buzzer = !buzzer;
}