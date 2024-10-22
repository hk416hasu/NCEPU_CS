#include <8051.h>

void serial_init(void);
void serial_transmit(unsigned char);

void main() {
    serial_init();  // Initialize serial communication
    while (1) {
        serial_transmit('H');
        serial_transmit('\r');
        serial_transmit('\n');
        for (int i = 0; i < 30000; i++);  // Simple delay loop
    }
}

// Initialize serial communication (9600 baud, 8N1)
void serial_init(void) {
    TMOD = 0x20;  // Timer1 mode 2 (8-bit auto-reload)
    TH1 = 0xFD;   // Load value for 9600 baud rate (11.0592 MHz)
    SCON = 0x50;  // Mode 1 (8-bit UART), enable receiver
    TR1 = 1;      // Start Timer1
}

// Transmit a single character via UART
void serial_transmit(unsigned char ch) {
    SBUF = ch;    // Load the character into the buffer
    while (TI == 0);  // Wait for transmission to complete
    TI = 0;       // Clear the transmit interrupt flag
}

