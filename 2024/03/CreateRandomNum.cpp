// 生成唯一随机数的代码，可以设置起点和终点，但是不能设置是否唯一和生成个数
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
#include <fstream>
#include <cstdio>

int main() {

int floor =  0;
int ceiling = 0;
    printf("Every num appears only once [from floor to ceiling].\n");
    do {
        printf("plz input the floor: ");
        scanf("%d", &floor);
        printf("plz input the ceiling: ");
        scanf("%d", &ceiling);
        if (floor > ceiling) {
            printf("Invaild input, plz enter again.\n");
        }
    } while (floor > ceiling);

std::vector<int> vec;
    for (int i = floor; i <= ceiling; i++) {
        vec.push_back(i);
    }

    // 打乱vec的数据
std::random_device rd;
std::mt19937 rng(rd());
    std::shuffle(vec.begin(), vec.end(), rng);

std::ofstream output("RandomNum.txt");
    if (output.is_open()) {
        for (int elem : vec) {
            output << elem << '\n';
        }
        output.close();
        printf("Over~, plz check RandomNum.txt in your file system.\n");
    } else {
        printf("Failed to open file for writing!\n");
    }

    return 0;
}