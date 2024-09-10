#include<8051.h>

 void main() {
// when u put 0x01 into a sfr, the Px0 is 1, and others are 0.
    // the zero is the lowest bit.
     
     P2 = 0xE3; // select the seg0 to display (74138)
     P0 = 0x4f; // display 3

 }
