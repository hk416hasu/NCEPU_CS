#include <stdio.h>
#include <math.h>
int main() {
    int num = 0;
    scanf("%d", &num);
    int arr[num];
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    int lastsum = 0, maxsum = arr[num - 1];
    for (int i = num - 2; i >= 0; i--) {
        if (lastsum > 0) {
            lastsum += arr[i];
        } else {
            lastsum = arr[i];
        }
        maxsum = fmax(maxsum, lastsum);
    }

    printf("%d\n", maxsum);

    return 0;
}

// 7 -5 4 1 -4 1 0 -3