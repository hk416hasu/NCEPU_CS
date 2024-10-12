#include <stdio.h>

int main() {

    int num = 0;
    scanf("%d", &num);

    int arr[3] = {0};

    for ( int i = 0; i < 3; i++ ) {
        arr[i] = num % 10;
        num /= 10;
    }

    for ( int i = 0; i < 3; i++ ) {
        printf("%d", arr[i]);
    }

    return 0;
}
