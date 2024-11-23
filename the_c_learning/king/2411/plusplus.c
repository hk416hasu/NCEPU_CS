#include <stdio.h>

void func(int x) {
    printf("%d\n", x);
}

int main() {
    int i = 10;
    func(i++);
    printf("%d\n", i);
    func(++i);
    printf("%d\n", i);

    i + 1;
    printf("%d\n", i);
    
    return 0;
}
