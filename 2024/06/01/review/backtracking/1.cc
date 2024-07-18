// 子集
#include <iostream>
#include <vector>

using std::vector;
#define n 3

vector<int> elems {7,8,9};
vector<int> vec;

void output() {
    for (int i = 0; i < vec.size(); i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

void backtracking(int t) {
    if (t == n) {
        output();
    } else {
        // 必须先push, 否则可能会对空vector进行pop
        // for (int i = 0; i < 2; i++) {
        //     if (i == 0) {
        //         vec.push_back(elems[t]);
        //     } else {
        //         vec.pop_back();
        //     }
        //     backtracking(t + 1);
        // }
        vec.push_back(elems[t]);
        backtracking(t + 1);
        vec.pop_back();
        backtracking(t + 1);
    }
}

int main() {
    backtracking(0);

    return 0;
}