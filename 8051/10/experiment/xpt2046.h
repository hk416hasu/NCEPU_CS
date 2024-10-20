#ifndef XPT2046_H
#define XPT2046_H

#define xptCommand_XP 0b10011100
#define xptCommand_VBAT 0b10101100

__sbit __at (0xB4) xpt_DIN;
__sbit __at (0xB5) xpt_CS;
__sbit __at (0xB6) xpt_DCLK;
__sbit __at (0xB7) xpt_DOUT;

unsigned int xpt2046_read(unsigned char command);

#endif
