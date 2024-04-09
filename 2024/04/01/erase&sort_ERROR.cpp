#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

#define ElemType int

void inputSet(std::set<int> &S, int len) {
    ElemType tmp = 0;
    for (int i = 0; i < len; i++) {
        scanf("%d", &tmp);
        S.insert(tmp);
    }
}

void inputTwoSet(std::set<ElemType> &A, std::set<ElemType> &B) {
    int na = 0, nb = 0;
    scanf("%d", &na);
    inputSet(A, na);
    scanf("%d", &nb);
    inputSet(B, nb);
}

int main() {
    std::set<ElemType> setA, setB;
    inputTwoSet(setA, setB);
    
    std::vector<ElemType> arr(setA.begin(), setA.end());
    std::vector<int>::iterator i;
    for (i = arr.begin(); i != arr.end(); i++) { 
        setB.erase(*i);
        arr.erase(pos);
    }
    for (ElemType elem : setB) {
        arr.push_back(elem);
    }
    std::sort(arr.begin(), arr.end());
    
    for (ElemType elem : arr) {
        printf("%d ", elem);
    }
    printf("\n");
    return 0;
}

/**
 * 
5 5 4 7 9 6
7 3 5 7 2 2 10 1

*/