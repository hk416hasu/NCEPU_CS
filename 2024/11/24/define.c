#include <stdio.h>

#define A "aaaaaaaaaa"
#define Ten(A) A A A A A A A A A A
#define B Ten(A)
#define C Ten(B)
#define D Ten(C)
#define E Ten(D)
#define F Ten(E)
#define G Ten(F)

int main() { puts(G); }
