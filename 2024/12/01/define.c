int printf(const char *format, ...);

#define PRINT_INT(x) \
    printf(#x " = %d; ", x); \
    printf(#x "1 = %d; ", x##1); \
    NEWLINE()
#define NEWLINE() printf("\n");
#define GEN(x) static int x, x##1;
#define FORALL(_) _(x) _(y) _(z) _(x2)

int main() {
    FORALL(GEN)
    FORALL(PRINT_INT)
    return 0;
}
