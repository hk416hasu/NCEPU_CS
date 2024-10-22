#include <8051.h>
#include "delayxms.h"

void serial_init(void);
void serial_transmit(unsigned char);

void main() {
    serial_init();
    while (1) {
        serial_transmit('H');
        serial_transmit('e');
        serial_transmit('l');
        serial_transmit('l');
        serial_transmit('o');
        serial_transmit('!');
        serial_transmit('\r');
        serial_transmit('\n');
        delayxms(1000);
    }
}

void serial_init(void) {
    SCON = 0x50;  // 8-bit UART
    TMOD = 0x20;  // Timer1 8-bit auto-reload mode
    TH1 = 0xFD;   // 9600 baudrate for 11.0592 MHz
    TR1 = 1;      // Start Timer1
}

void serial_transmit(unsigned char ch) {
    SBUF = ch;
    while (TI == 0); // wait for the end of sending
    TI = 0;          // Clear the transmit interrupt flag
}

