#include<8051.h>

#define n 10

void delay();

void main() {
     char num[n] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67 };
     P2 = 0xE3; // select the seg0 to display (74138)

     for (int i = 0; ; i = (i+1)%n) {
         P0 = num[i];
         delay();
     }

 }

void delay() {
    unsigned char i, j, k;
    for (i = 3; i > 0; i--)
        for (j = 200; j > 0; j--)
            for (k=248; k > 0; k--)
                ;
}
