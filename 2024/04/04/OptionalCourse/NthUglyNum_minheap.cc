#include <algorithm>
#include <queue>
#include <unordered_set>
#include <vector>

int main() {

    int N = 0;
    scanf("%d", &N);
    int count = 0;
    long target = 0;

    std::vector<int> factors = {2, 3, 5};
    std::priority_queue<long, std::vector<long>, std::greater<long>> MinHeap;
    std::unordered_set<long> existed;
    MinHeap.push(1);
    existed.insert(1);

    while (count < N) {
        target = MinHeap.top();
        MinHeap.pop();
        for (int elem : factors) {
            if (existed.find(elem * target) == existed.end()) {
                MinHeap.push(elem * target);
                existed.insert(elem * target);
            }
        }
        count++;
    }
    printf("%ld\n", target);

    return 0;
}