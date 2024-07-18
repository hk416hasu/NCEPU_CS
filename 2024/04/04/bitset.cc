#include <iostream>
#include <bitset>

int main() {
    int num = 10; // 一个示例整数
    std::bitset<sizeof(int) * 8> bits(num); // 将整数转换为位集合

    // 输出01序列
    std::cout << bits << std::endl;

    return 0;
}
