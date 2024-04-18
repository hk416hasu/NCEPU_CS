#include <stdio.h>
#include <math.h>
#include <limits.h>

#define num 4

int findmin(int arr[]) {
    int min = arr[0];
    for (int i = 1; i < 4; i++) {
        min = (min < arr[i]) ? min : arr[i];
    }
    return min;
}

int findmax(int arr[]) {
    int max = arr[0];
    for (int i = 1; i < 4; i++) {
        max = (max > arr[i]) ? max : arr[i];
    }
    return max;
}

int main() {

    int val[num] = {-7,4,2,5};
    char op[num] = {'+','*','*','+'};
    // int val[num] = {2,3,1,7,4};
    // char op[num] = {'*','+','+','*','*'};

    int dp_max[num][num] = {0};
    int dp_min[num][num] = {0};
    int range[4] = {0};

    for (int i = 0; i < num; i++) {
        dp_max[i][1] = val[i];
        dp_min[i][1] = val[i];
    }
    int a,b,c,d;
    for (int j = 2; j < num; j++) {
        for (int i = 0; i < num; i++) {
            int min = INT_MAX, max = INT_MIN;
            for (int k = 1; k <= j; k++) {
                int ch_i = (i + k - 1) % num;
                int ch = op[ch_i];
                switch (ch)
                {
                case '+':
                    max = fmax( max, (dp_max[i][k] + dp_max[k+1][j-k]) );
                    min = fmin( min, (dp_min[i][k] + dp_min[k+1][j-k]) );
                    break;
                case '*':
                    a = dp_min[i][k];       b = dp_max[i][k];
                    c = dp_min[k+1][j-k];   d = dp_max[k+1][j-k];
                    range[0] = a * c;   range[1] = a * d;
                    range[2] = b * c;   range[3] = b * d;
                    int mul_min = findmin(range);
                    int mul_max = findmax(range);
                    max = fmax( max, mul_max );
                    min = fmin( min, mul_min );
                    break;
                }
            }
            dp_max[i][j] = max;
            dp_min[i][j] = min;
        }
    }
    
    int optimal_i = 0;
    int max = dp_max[0][num-1];
    for (int i = 0; i < num; i++) {
        if (dp_max[i][num-1] > max) {
            optimal_i = i-1;
            max = dp_max[i][num-1];
        }
    }
    printf("you should delete the op[%d].\n", optimal_i);
    // printf("the max score is %d\n", max);
    
    getchar();
    return 0;
}