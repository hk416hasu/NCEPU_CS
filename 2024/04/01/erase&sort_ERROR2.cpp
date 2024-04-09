#include <cstdio>
#include <vector>

int main() {

    std::vector<int> arr;
    int na = 0, nb = 0, tmp = 0;
    scanf("%d", na);
    for (int i = 0; i < na; i++) {
        scanf("%d", tmp);
        if (tmp > (arr.size() - 1)) {
            arr.resize(2 * tmp);
        }
        arr[tmp] = 1;
    }

    scanf("%d", nb);
    for (int i = 0; i < nb; i++) {
        scanf("%d", tmp);
        if (tmp > (arr.size() - 1)) {
            arr.resize(2 * tmp);
        }
        arr[tmp] = 0;
    }

    return 0;
}