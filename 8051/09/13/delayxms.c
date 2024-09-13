#include "delayxms.h"

void delayxms(unsigned int xms) {
    unsigned char i;
    while (xms--) {
        i = 120;
        while (--i);
    }
}
