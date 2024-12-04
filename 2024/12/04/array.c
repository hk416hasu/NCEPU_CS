int printf(const char *format, ...);
int puts(const char *s);
#define NULL ((void *)0)

#define LEN(array) (sizeof(array) / sizeof(array[0]))

int main(void) {

    int array[10] = {0};

    printf("%p\n", array + 1);
    printf("%p\n", &array[0]);
    printf("%p\n", &array[0] + 1);
    puts("");

    printf("%ld\n", sizeof(array));
    printf("%ld\n", sizeof array );
    printf("%ld\n", sizeof(array[0]));
    puts("");

    void *p = NULL;
    p = array;
    printf("%ld\n", sizeof(p)); // sizeof(void *)
    printf("%ld\n", sizeof(p[0])); // ??? bahaviour?
    printf("%d\n", ((int*)p)[0]);
    printf("%ld\n", sizeof((int*)p)[0]);
    puts("");

    printf("%ld\n", LEN(array));
    puts("");

    printf("%p\n", "abc"); // "abc" is a pointer to a char-arr
    puts("");

    printf("%p\n", main);

    return 0;
}
