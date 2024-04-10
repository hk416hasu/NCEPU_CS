#include <stdio.h>
#include <math.h>
#include <mem.h>

int main() {
    int num = 5, capacity = 10;
    num = num + 1;
    capacity = capacity + 1;
    int weight[num] = {0,3,2,4,1,6};
    int price[num] = {0,10,7,12,4,20};
    int dp[capacity][num];
    memset(dp, 0, capacity * num * sizeof(int));

    int w = 0, p = 0;
    for (int i = 1; i < capacity; i++) {
        for (int j = 1; j < num; j++) {
            w = weight[j];
            p = price[j];
            if (w > i) {
                dp[i][j] = dp[i][j-1];
            } else {
                dp[i][j] = fmax(dp[i-w][j-1] + p, dp[i][j-1]);
            }
        }
    }

    for (int i = 0; i < capacity; i++) {
        for (int j = 0; j < num; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    getchar();
    return 0;
}