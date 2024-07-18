#include <iostream>
#include <map>
#include <vector>

int main() {
    // 定义一个map，键类型为int，值类型为std::vector<int>
    std::map<int, std::vector<int>> myMap;

    // 创建一些数组（使用std::vector）
    std::vector<int> array1 = {1, 2, 3};
    std::vector<int> array2 = {4, 5, 6};
    std::vector<int> array3 = {7, 8, 9};

    // 使用insert方法将数组插入到map中
    myMap.insert({1, array1});
    myMap.insert({2, array2});
    myMap.insert({1, array3}); // 这个操作将不会替换原来的值，因为insert不会覆盖已存在的键

    // 打印map中的元素
    for (const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: ";
        for (int val : pair.second) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
