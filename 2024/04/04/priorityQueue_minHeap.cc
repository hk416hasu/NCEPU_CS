#include <iostream>
#include <vector>
#include <queue>

int main() {
    // 最小优先队列
    // std::greater<int> 使得最大优先队列的行为变成最小优先队列的行为
    std::priority_queue<long, std::vector<long>, std::greater<long>> min_heap;
    min_heap.push(5);
    min_heap.push(3);
    min_heap.push(2);
    min_heap.push(0);


    getchar();
    return 0;
}