unsigned int sleep(unsigned int seconds);
#include <stdio.h>

#define FORALL_REGS(_) _(x) _(y) _(z)
#define GEN(x) static int x, x##1;
#define PRINT(x) printf(#x " = %d; ", x);
#define LOGIC() x1 = (!x&&y&&z) || (x&&!y) || (x&&y&&!z); \
                y1 = (!y&&z) || (y&&!z); \
                z1 = !z;
#define UPDATE(x) x = x##1;


int main() {
    FORALL_REGS(GEN);
    while (1) {
        FORALL_REGS(PRINT);
        sleep(1);
        putchar('\n');
        fflush(stdout);
        LOGIC();
        FORALL_REGS(UPDATE);
    }
}
