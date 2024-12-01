int printf(const char *format, ...);

#define PRINT_INT(x, x1) \
    printf(#x " = %d; ", x); \
    printf(#x1 " = %d; ", x1); \
    NEWLINE()
#define NEWLINE() printf("\n");
#define GEN(x) static int x, x##1;
#define FORALL(_) _(x, x1) _(y, y1) _(z, z1)

int main() {
    GEN(x)
    GEN(y)
    GEN(z)
    FORALL(PRINT_INT)
    return 0;
}
