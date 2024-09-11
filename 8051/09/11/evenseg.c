#include<8051.h>

#define n 10

void delay();

char num[n] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };
char seg[8] = { 0xe3, 0xe7, 0xeb, 0xef, 0xf3, 0xf7, 0xfb, 0xff };

void main() {

    int i = 0, j = 0;
    while (1) {
        P0 = num[i];    i = (i+1) % n;
        delay();
    }

 }

void delay() {
    unsigned char i, j, k;
    int m = 0;
    for (i = 1; i > 0; i--)
        for (j = 50; j > 0; j--)
            for (k=248; k > 0; k--) {
                P2 = seg[m];    
                m = (m+1) % 8;
            }

}
