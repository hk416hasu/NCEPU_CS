#include <queue>
#include <vector>
#include <algorithm>

int main() {
    std::priority_queue<int> Heap;

    for (int i = 0; i < 10; i++) {
        Heap.push(i);
    }

    Heap.empty();

    return 0;
}