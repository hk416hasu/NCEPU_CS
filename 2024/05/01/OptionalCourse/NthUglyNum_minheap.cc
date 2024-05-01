/* 
    1. 如果x是丑数，则 2*x, 3*x, 5*x也是丑数;
    2. 既然要找第n个丑数，所以我们可以从最小的丑数1开始，逐步加入2*x, 3*x, 5*x;
        2.1 每次都取最小的丑数，可以用小根堆
    3. 但是2*x, 3*x, 5*x可能已经存在，所以需要hashset去重;
*/
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <vector>

typedef unsigned long long uLL;

int main() {

    int n = 0;
    scanf("%d", &n);
    int count = 0;
    uLL curr = 0;

    std::vector<uLL> factors = {2, 3, 5};    // 2, 3, 5是丑数因子
    std::priority_queue<uLL, std::vector<uLL>, std::greater<uLL>> MinHeap;
    std::unordered_set<uLL> existed;
    MinHeap.push(1);    // 初始化，第一个丑数是 1
    existed.insert(1);

    while (count < n) {
        curr = MinHeap.top();
        MinHeap.pop();
        for (uLL elem : factors) {
            uLL newUglyNum = elem * curr;
            // 如果newUglyNum没出现过，即不存在于existed集合中，则加入它
            if (existed.find(newUglyNum) == existed.end()) {
                MinHeap.push(newUglyNum);
                existed.insert(newUglyNum);
            }
        }
        count++;
    }
    printf("%llu\n", curr);
    return 0;
}