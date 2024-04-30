/* 利用vector的实现，主要思路是

时间耗费大，主要消耗在
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include "NthUglyNumAnswer.h"

typedef long long LL;

// Only if vec doesn't contain num, then push num into vec.
void AddOnly(std::vector<LL> &vec, const LL &num) {
    std::vector<LL>::iterator it = std::find(vec.begin(), vec.end(), num);
    if (it == vec.end()) {
        vec.push_back(num);
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    std::vector<LL> UglyNum;
    UglyNum.push_back(1);

    int count = 0;
    LL target = 1;

    while (count < n) {
        target = UglyNum.front();
        UglyNum.erase(UglyNum.begin());
        AddOnly(UglyNum, target * 2);
        AddOnly(UglyNum, target * 3);
        AddOnly(UglyNum, target * 5);
        std::make_heap(UglyNum.begin(), UglyNum.end(), std::greater<LL>());
        count++;
    }

    // printf("%ld\n", UglyNum_all[n-1]);
    printf("%ld\n", target);

    return 0;
}