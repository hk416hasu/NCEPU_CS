#include <8051.h>
#include "xpt2046.h"

unsigned int xpt2046_read(unsigned char command) {
    // initialization
    unsigned int xptVal = 0;
    xpt_DCLK = 0;
    xpt_CS = 0;

    // emit command to xpt2046
    for ( int i = 0; i < 8; i++ ) {
        xpt_DIN = command & (0x80 >> i);
        xpt_DCLK = 1;
        xpt_DCLK = 0;
    }

    // get val from xpt2046
    for ( int i = 15; i >= 0; i-- ) {
        xpt_DCLK = 1;
        xpt_DCLK = 0;
        xptVal |= xpt_DOUT << i;
    }

    return (xptVal >> 8);
}
