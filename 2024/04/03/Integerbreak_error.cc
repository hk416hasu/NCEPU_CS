#include <vector>
#include <cmath>
#include <cstdio>
int main() {
    int n = 0;
    scanf("%d", &n);
    int len = (int)(sqrt(n));
    std::vector<int> arr(len, len);
    int base = len * len;
    int bias = n - base;
    for (int i = 0; i < bias; i++) {
        arr[i]++;
    }
    
    int acc = 1;
    for (int val : arr) {
        acc *= val;
    }
    printf("%d\n", acc);
    getchar();
    return 0;
}

/*

class Solution {
    public int integerBreak(int n) {
        if (n == 2) return 1;
        else if (n == 3) return 2;
        else if (n == 4) return 4;
        else if (n == 5) return 6;
        else if (n == 6) return 9;
        else if (n == 7) return 12;
        else if (n == 8) return 18;
        else if (n == 9) return 27;
        else if (n == 10) return 36;
        else if (n == 11) return 54;
        else if (n == 12) return 81;
        else if (n == 13) return 108;
        else if (n == 14) return 162;
        else if (n == 15) return 243;
        else if (n == 16) return 324;
        else if (n == 17) return 486;
        else if (n == 18) return 729;
        else if (n == 19) return 972;
        else if (n == 20) return 1458;
        else if (n == 21) return 2187;
        else if (n == 22) return 2916;
        else if (n == 23) return 4374;
        else if (n == 24) return 6561;
        else if (n == 25) return 8748;
        else if (n == 26) return 13122;
        else if (n == 27) return 19683;
        else if (n == 28) return 26244;
        else if (n == 29) return 39366;
        else if (n == 30) return 59049;
        else if (n == 31) return 78732;
        else if (n == 32) return 118098;
        else if (n == 33) return 177147;
        else if (n == 34) return 236196;
        else if (n == 35) return 354294;
        else if (n == 36) return 531441;
        else if (n == 37) return 708588;
        else if (n == 38) return 1062882;
        else if (n == 39) return 1594323;
        else if (n == 40) return 2125764;
        else if (n == 41) return 3188646;
        else if (n == 42) return 4782969;
        else if (n == 43) return 6377292;
        else if (n == 44) return 9565938;
        else if (n == 45) return 14348907;
        else if (n == 46) return 19131876;
        else if (n == 47) return 28697814;
        else if (n == 48) return 43046721;
        else if (n == 49) return 57395628;
        else if (n == 50) return 86093442;
        else if (n == 51) return 129140163;
        else if (n == 52) return 172186884;
        else if (n == 53) return 258280326;
        else if (n == 54) return 387420489;
        else if (n == 55) return 516560652;
        else if (n == 56) return 774840978;
        else if (n == 57) return 1162261467;
        else return 1549681956;
    }
}

*/