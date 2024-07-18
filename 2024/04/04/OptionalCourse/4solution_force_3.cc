// 暴力算法, 借助它来理解题意
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

// 对布尔数组+1
void Add1(std::vector<bool> &vec) {
    bool flag = 1;  // +1标志位 ; 进位标志位
    /*
    加 1 操作：
    while (flag == 1)
        if bin[i] = 0 then bin[i] = 1, flag = 0
        if bin[i] = 1 then bin[i] = 0, flag = 1
    综上，仅当进位标志位为true时，flag = bin[i], bin[i]取反即可
    */
    for (int i = 0; flag; i++) {    // 小端加一操作
        flag = vec[i];
        vec[i] = !vec[i];
    }
}

// 打印数组
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

    // 暴力枚举所有情况，时间复杂度 O(2^n)
    std::vector<bool> access(n+1);  // 多申请一位
    std::vector<int> sub;   // 保存中间结果，以便打印
    int i = 0;
    // 当且仅当access数组全为true时终止
    while (!access.back()) {
        sub.clear();
        for (int j = 0; j < n; j++) {
            if (access[j]) {
                sub.push_back(data[j]);
            }
        }
        if (std::accumulate(sub.begin(), sub.end(), 0) == target) {
            Print(sub);
            count++;
        }
        Add1(access);
    }

    printf("Here are %d solutions.\n", count);

    return 0;
}