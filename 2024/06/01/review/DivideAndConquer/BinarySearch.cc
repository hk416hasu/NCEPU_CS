#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> arr {8,5,10,1,4,7,2,3,6,9};

int main() {

    int low = 0, high = arr.size() - 1;

    int target = 0;
    scanf("%d", &target);
    // assert(target >= 0 && target <= 9);

    std::sort(arr.begin(), arr.end());
    int mid = 0;
    bool found = false;
    while(low <= high) {    // 为什么是low <= high? 想想只有一个元素的时候。
        mid = (low + high) / 2;
        if (arr[mid] == target) {
            found = true;
            break;
        } else if (target < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (found) {
        printf("%d\n", mid);
    } else {
        printf("not found\n");
    }

    return 0;
}