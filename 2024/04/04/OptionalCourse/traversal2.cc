// 求出给定数组的所有子数组（不包括空集）
#include <iostream>
#include <vector>
#include <numeric>

#define n 4

void Print(std::vector<int> &vec) {
    for (int elem : vec) {
        printf("%d ", elem);
    }
    printf("\n");
}

int main() {
    std::vector<int> vec;
    std::vector<int> data(n);
    std::iota(data.begin(), data.end(), 0);

    int start = 0;
    for (int i = n; i >= 1; i--) {
        vec.resize(0);
        start = n-i;
        for (int j = 0; j < i; j++) {
            vec.push_back(data[start++]);
            Print(vec);
        }
    }
    return 0;
}