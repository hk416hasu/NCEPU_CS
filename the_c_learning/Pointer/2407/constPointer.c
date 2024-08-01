#include <stdio.h>

int main() {

    int a = 10;
    int * const cpi = &a; // cpi is const, so cpi can NOT be changed, but (*cpi) can be changed.
    *cpi = 20;
    // cpi = 0x10000; // cpi can NOT be changed

    int b = 100;
    int const * pci = &b;   // pci is a pointer which points to a const
    const int * pci2 = &b;
    pci = 0x10000;  // pci can be changed
    // *pci = 1;   // *pci can NOT be changed

    return 0;
}