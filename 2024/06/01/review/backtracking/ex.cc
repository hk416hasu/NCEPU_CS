#include <iostream>
#include <vector>

#define len 3

using std::vector;

vector<int> vec;

void output(vector<int> &vec) {
    for (int elem : vec) {
        printf("%d ", elem);
    }
    printf("\n");
}

void SubSet(int t) {
    if (t == len) {
        output(vec);
    } else {
        for (int i = 0; i <= 1; i++) {
            vec.push_back(i);
            SubSet(t+1);
            vec.pop_back();
        }
    }
}

vector<int> arr = {1, 2, 3};    // arr.size() == len

void Permutation(int t) {
    if (t == len) {
        output(arr);
    } else {
        for (int i = t; i < len; i++) {
            std::swap(arr[t], arr[i]);
            Permutation(t + 1);
            std::swap(arr[t], arr[i]);
        }
    }
}

int main() {

    SubSet(0);
    
    vec.clear();
    printf("\n");

    Permutation(0);

    return 0;
}