/*
    bool数组模拟二进制+1
    flag 是进位标志位, 也可以理解成+1标志位，初始为 1
    while (flag == 1)
        if bin[i] = 0 then bin[i] = 1, flag = 0
        else bin[i] = 1 then bin[i] = 0, flag = 1

    综上，仅当进位标志位为true时，flag = bin[i], bin[i]取反

    结束条件可以是最高位为 1 (需要多一位标志位)
            也可以是所有位均为 1，但多了一些判断时间
*/
#include <vector>
#include <iostream>
#include <cmath>
#include <cassert>

// 打印数组
void Print(std::vector<bool> &vec) {
    for (bool elem : vec) {
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

#define n 4

int main() {
    assert(n > 0);
    std::vector<bool> bin(n+1);

    // 从0000 加到 1111
    while (!bin.back()) {
    // while (!bin.front()) {
        Print(bin);
        bool flag = 1;  // 进位标志位
        for (int i = 0; flag; i++) {    // 小端
        // for (int i = bin.size()-1; flag; i--) {  // 大端
            flag = bin[i];
            bin[i] = !bin[i];
        }
    }

    return 0;
}