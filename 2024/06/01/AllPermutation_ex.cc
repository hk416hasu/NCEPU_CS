#include <iostream>

#define n 3

int arr[n] = {1,2,3};

void output() {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void allPermutation(int t) {
    if (t == n) {
        output();
    } else {
        for (int i = t; i < n; i++) {   // 递归地处理t层之下的元素们
            std::swap(arr[t], arr[i]);
            allPermutation(t + 1);
            std::swap(arr[t], arr[i]);
        }
    }
}

int main() {
    allPermutation(0);
    return 0;
}