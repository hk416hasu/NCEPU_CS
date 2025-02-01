#include <stdio.h>

int main() {

    int buffer[128] = {0};
    char ch;
    while (scanf("%c", &ch) && ch != '\n') {
        buffer[ch]++;
    }

    scanf("%c", &ch);
    printf("%d", buffer[ch]);

    return 0;
}
