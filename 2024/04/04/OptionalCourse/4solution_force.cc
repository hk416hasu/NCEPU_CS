// 暴力
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

// 利用位运算，生成num的0/1序列
void Access_Init(std::vector<bool> &vec, int num) {
    vec.clear();
    for (int i = 0; i < sizeof(int) * 8; i++) {
        bool bit = (num >> i) & 1;
        vec.push_back(bit);
    }
}

void Print(std::vector<int> &vec) {
    for (int elem : vec) {
        printf("%d ", elem);
    }
    printf("\n");
}

int main() {
    int n = 0, target = 0, count = 0;
    scanf("%d %d", &n, &target);

    // 初始化data序列为 1 ~ n。初始化题目没给，我就随便定了个
    std::vector<int> data(n);
    std::iota(data.begin(), data.end(), 1);

    // 暴力枚举所有情况求符合题意的解，时间复杂度 O(2^n)
    int ceiling = (int)pow(2, n), mask = 0;
    std::vector<bool> access(ceiling);
    std::vector<int> sub;
    for (int i = 1; i < ceiling; i++) {
        Access_Init(access, i);
        for (int j = 0; j < n; j++) {
            if (access[j]) {
                sub.push_back(data[j]);
            }
        }
        if (std::accumulate(sub.begin(), sub.end(), 0) == target) {
            Print(sub);
            count++;
        }
        sub.clear();
    }

    printf("Here are %d solutions.\n", count);

    return 0;
}