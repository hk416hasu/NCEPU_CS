#include <stdio.h>

volatile int counter = 0;

void func() {
    counter++;
}

int main() {
    printf("%d\n", counter);

    func();

    printf("%d\n", counter);

    return 0;
}
