// copy input to output, but remove m  u  l  t  i  -  s  p  a  c  e

#include <stdio.h>

int main() {

    int c = 0, old_c = 0;

    while ((c = getchar()) != EOF) {
        if (old_c != ' ' || c != ' ')
            putchar(c);
        old_c = c;
    }


    return 0;
}
