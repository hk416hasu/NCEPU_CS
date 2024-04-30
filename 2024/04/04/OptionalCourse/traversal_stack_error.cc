#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

#define n 4

void Print(std::vector<int> &vec) {
    for (int elem : vec) {
        printf("%d ", elem);
    }
    printf("\n");
}

int main() {
    int m = 3, count = 0;
    std::vector<int> stack;
    std::vector<int> data(n);
    std::iota(data.begin(), data.end(), 0);

    for (int k = 1; k <= n; k++) {
        for (int i = 0; i <= n-k; i++) {
            stack.resize(0);
            for (int j = i; j < i+k; j++) {
                if (stack.size() == k) {
                    stack.pop_back();
                }
                stack.push_back(data[j]);
                // if (std::accumulate(stack.begin(), stack.end(), 0) == m) {
                //     count++;
                // }
                Print(stack);
            }
        }
    }

    getchar();
    return 0;
}