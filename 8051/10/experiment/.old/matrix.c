#include <8051.h>
#include "delayxms.h"

char num[10] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };
char seg[4] = { 0xe3, 0xe7, 0xeb, 0xef }; // the right LED-Seg
int gotNum = 0;

void segCon(char location, char n) {
    P2 = seg[location];
    P0 = num[n];
}

void getNextNum() {

    P1_7 = 0;
    if ( P1_3 == 0 ) { delayxms(5); if ( P1_3 == 0 ) gotNum = 1; }
    if ( P1_2 == 0 ) { delayxms(5); if ( P1_2 == 0 ) gotNum = 2; }
    if ( P1_1 == 0 ) { delayxms(5); if ( P1_1 == 0 ) gotNum = 3; }
    if ( P1_0 == 0 ) { delayxms(5); if ( P1_0 == 0 ) gotNum = 4; }
    P1_7 = 1;

    P1_6 = 0;
    if ( P1_3 == 0 ) { delayxms(5); if ( P1_3 == 0 ) gotNum = 5; }
    if ( P1_2 == 0 ) { delayxms(5); if ( P1_2 == 0 ) gotNum = 6; }
    if ( P1_1 == 0 ) { delayxms(5); if ( P1_1 == 0 ) gotNum = 7; }
    if ( P1_0 == 0 ) { delayxms(5); if ( P1_0 == 0 ) gotNum = 8; }
    P1_6 = 1;

    P1_5 = 0;
    if ( P1_3 == 0 ) { delayxms(5); if ( P1_3 == 0 ) gotNum = 9; }
    if ( P1_2 == 0 ) { delayxms(5); if ( P1_2 == 0 ) gotNum = 0; }
    P1_5 = 1;

}

void main() {
    while (1) {
        segCon(0, gotNum);
        getNextNum();
    }
}
