#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>

void execute(int addr) {
    printf("%d\n", addr);
}

int main() {
    std::srand(std::time(0)); // 以当前时间为随机数生成器的种子
    int start = std::rand() % 320;
    


    return 0;
}