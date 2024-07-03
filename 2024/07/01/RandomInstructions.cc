#include <iostream>
#include <cstdlib>
#include <ctime>

void simulate_instructions(int &sequential_count, int &low_address_count, int &high_address_count) {
    int instructions_executed = 0;
    sequential_count = 0;
    low_address_count = 0;
    high_address_count = 0;

    std::srand(std::time(0)); // 用当前时间作为随机数种子
    int m = std::rand() % 320;
    instructions_executed += 1;
    int current_address = m + 1;

    while (instructions_executed < 320) {
        // 顺序执行
        sequential_count += 1;
        instructions_executed += 1;

        // 随机选择低地址指令
        if (instructions_executed < 320) {
            int m1 = std::rand() % (current_address + 1);
            low_address_count += 1;
            instructions_executed += 1;
            current_address = m1 + 1;
        }

        // 顺序执行
        if (instructions_executed < 320) {
            sequential_count += 1;
            instructions_executed += 1;
        }

        // 随机选择高地址指令
        if (instructions_executed < 320) {
            if (current_address + 1 < 319) {
                current_address = (std::rand() % (319 - (current_address + 1) + 1)) + (current_address + 1);
            } else {
                current_address = 319;
            }
            high_address_count += 1;
            instructions_executed += 1;
        }
    }
}

int main() {
    int sequential_count, low_address_count, high_address_count;
    simulate_instructions(sequential_count, low_address_count, high_address_count);

    // std::cout << "sequential_count: " << sequential_count << std::endl;
    // std::cout << "low_address_count: " << low_address_count << std::endl;
    // std::cout << "high_address_count: " << high_address_count << std::endl;

    return 0;
}
