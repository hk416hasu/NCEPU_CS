// 暴力算法, 借助它来理解题意
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

// 利用位运算，生成num的0/1序列
void Access_Init(std::vector<bool> &vec, int num) {
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = (num >> i) & 1;
    }
}

// 打印数组
void Print(std::vector<int> &vec) {
    for (int elem : vec) {
        printf("%d ", elem);
    }
    printf("\n");
}

// 若布尔数组中全为true返回true，否则返回false
bool isAllTrue(std::vector<bool> vec) {
    for (bool elem : vec) {
        if (!elem) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 0, target = 0, count = 0;
    scanf("%d %d", &n, &target);

    // 初始化data序列为 1 ~ n。初始化题目没给，我就随便定了个
    std::vector<int> data(n);
    std::iota(data.begin(), data.end(), 1);

    // 暴力枚举所有情况，时间复杂度 O(2^n)
    std::vector<bool> access(n);
    std::vector<int> sub;   // 保存中间结果，以便打印
    int i = 0;
    // 当且仅当access数组全为true时终止
    while (!isAllTrue(access)) {
        Access_Init(access, i++);
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