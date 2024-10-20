#include <8051.h>
#include "delayxms.h"
#include "LCD1602.h"

#define xptCommand_XP 0b10011100
#define xptCommand_VBAT 0b10101100

__sbit __at (0xB4) xpt_DIN;
__sbit __at (0xB5) xpt_CS;
__sbit __at (0xB6) xpt_DCLK;
__sbit __at (0xB7) xpt_DOUT;

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

void main() {
    LCD_Init();
    unsigned int xptVal = 0;
    while(1) {
        xptVal = xpt2046_read(xptCommand_VBAT);
        LCD_ShowNum(1,1,xptVal,3);
        delayxms(10);
    }
}
