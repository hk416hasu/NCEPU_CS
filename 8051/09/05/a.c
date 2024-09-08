#include <8051.h>   // Include the appropriate header for SDCC

// P2 is connectted to LED
__sfr __at (0xA0) LED;  

void delay();  // Function prototype for delay

void main(void) {
    while(1) {
        LED = ~LED;  // Toggle the LED 
        delay();     // Call delay function
    }
}

void delay() {
    unsigned char i, j, k;
    for (i = 10; i > 0; i--)
        for (j = 200; j > 0; j--)
            for (k=248; k > 0; k--)
                ;
}
