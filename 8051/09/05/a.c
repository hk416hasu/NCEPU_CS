#include <8051.h>   // Include the appropriate header for SDCC

// Manually define P1.0 as LED
__sbit __at (0x90) LED;  

void delay();  // Function prototype for delay

void main(void) {
    while(1) {
        LED = 0;  // Toggle the LED (complement P1.0)
        delay();     // Call delay function
    }
}

void delay() {
    unsigned int i;
    for(i = 0; i < 50000; i++);  // Simple delay loop
}

