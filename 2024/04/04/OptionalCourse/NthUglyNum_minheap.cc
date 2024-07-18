// 如果x是丑数，则 2*x, 3*x, 5*x也是丑数
// 我们可以利用小根堆来得到
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <vector>
#include "NthUglyNumAnswer.h"

typedef long long LL;

int main() {

    int n = 0;
    scanf("%d", &n);
    int count = 0;
    LL target = 0;

    std::vector<LL> factors = {2, 3, 5};
    std::priority_queue<LL, std::vector<LL>, std::greater<LL>> MinHeap;
    std::unordered_set<LL> existed;
    MinHeap.push(1);
    existed.insert(1);

    while (count < n) {
        target = MinHeap.top();
        MinHeap.pop();
        for (LL elem : factors) {
            if (existed.find(elem * target) == existed.end()) {
                MinHeap.push(elem * target);
                existed.insert(elem * target);
            }
        }
        count++;
    }
    // printf("%ld\n", UglyNum_all[n-1]);
    printf("%ld\n", target);

    return 0;
}