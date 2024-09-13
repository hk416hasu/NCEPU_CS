#include <8051.h>

void delay10ms();

void main() {
    while (1) {
        if ( P3_1 == 0 ) {
            delay10ms();    // To solve the wave jitter of butter.
            while ( P3_1 == 0 );    // When the key is pressed, just in 
                                    // this while. Only when the key re-
                                    // bound, the signal will be sent.
                                    // To avoid multiple transmission of
                                    // signals.
            // Key1 is pressed
            P2_0 = !P2_0;
        }
    }   
}


void delay10ms() {
    unsigned char j, k;
    for (j = 30; j > 0; j--)
        for (k = 248; k > 0; k--)
            ;
}
