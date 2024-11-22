#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int i, k;
    float j;

    scanf("%d%f%d", &i, &j, &k); // 10.3 5 6
    printf("i = %d\nj = %f\nk = %d\n", i, j, k);

    char str[10] = "514893";
    int arr[5] = {0};
    sscanf(str, "%1d%2d%3d%1d%1d", &arr[0], &arr[1], &arr[2],
            &arr[3], &arr[4]);
    for (int i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
