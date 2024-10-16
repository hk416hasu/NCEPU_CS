#include <8051.h>
#include "timer0.h"
#include "delayxms.h"

char num[10] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };
char seg[4] = { 0xe3, 0xe7, 0xeb, 0xef }; // the right LED-Seg
char digits[4] = { 0, 1, 2, 3 };

void segCon(char location, char n) {
    P2 = seg[location];
    P0 = num[n];
}

void print4Digits() {
    segCon(0, digits[3]); delayxms(1);
    segCon(1, digits[2]); delayxms(1);
    segCon(2, digits[1]); delayxms(1);
    segCon(3, digits[0]); delayxms(1);
}
void updateDigits() {
    for ( char i = 0; i < 4; i++ ) {
        digits[i] = (digits[i] + 1) % 10;
    }
}

char flag = 0;
void main() {

    Timer0_Init();

    while (1) {
        while ( flag == 0 ) {
            print4Digits();
        }
        flag = 0;
        updateDigits();
    }

}

char times = 0;
void ISR() __interrupt 1 {
    TH0 = ( 65535 - 50000 ) >> 8;
    TL0 = ( 65535 - 50000 ) & 0xff;
    times++;
    if ( times == 20 ) {
        flag = 1;
        times = 0;
    }
}
