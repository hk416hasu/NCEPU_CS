#include <stdio.h>

int main() {
    // why int not char?
    int c = 0;

    while (( c = getchar() ) != EOF) {
        putchar(c);
    }

    return 0;

}
