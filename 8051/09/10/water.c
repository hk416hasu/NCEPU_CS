#include<8051.h>

#define true  1
#define false 0
__sfr __at (0xA0) LED;

void delay();

void main() {
   int arr[8] = {0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F};
   for (int i=0;;i=(i+1)%8) {
       LED = arr[i];
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
