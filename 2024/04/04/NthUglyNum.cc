#include <iostream>
#include <vector>
#include <algorithm>
#include "NthUglyNumAnswer.h"

#define N 500

// Only if vec doesn't contain num, then push num into vec.
void AddOnly(std::vector<int> &vec, const int &num) {
    std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), num);
    if (it == vec.end()) {
        vec.push_back(num);
    }
}

int main() {
    std::vector<int> UglyNum;
    UglyNum.push_back(1);

    int count = 0;
    int target = 1;

    while (count < N) {
        target = UglyNum.front();
        UglyNum.erase(UglyNum.begin());
        AddOnly(UglyNum, target * 2);
        AddOnly(UglyNum, target * 3);
        AddOnly(UglyNum, target * 5);
        std::make_heap(UglyNum.begin(), UglyNum.end(), std::greater<int>());
        count++;
    }

    printf("%d\n", UglyNum_all[N-1]);
    printf("%d\n", target);

    getchar();
    return 0;
}