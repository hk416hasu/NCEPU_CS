#include <8051.h>
#include "delayxms.h"

int main() {
    while (1) {
        P2_2 = !P2_2;
        delayxms(1000);
    }
}
