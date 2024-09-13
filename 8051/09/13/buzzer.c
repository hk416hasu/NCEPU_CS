#include <8051.h>
#include "delayxms.h"

void main() {
    while (1) {
        P2_0 = !P2_0;
        P2_5 = !P2_5;
        delayxms(1);
    }
}
