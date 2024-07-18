#include <stdio.h>
#include <assert.h>
#include <math.h>

// 牛顿迭代法 : https://en.wikipedia.org/wiki/Newton%27s_method
double NewTon_sqrt(double n) {
    double x1 = (n >= 1) ? n : 1.0; // 根据n的值，赋予不同的初始值
    double x0 = 0.0;    // 保存上次的结果
    while (x0 != x1 && x1 * x1 > n) {   // 当精度仍在更新 且 满足平方根定义 时循环
        x0 = x1;    // 保存上次的精度
        x1 = (x1 + n/x1) / 2.0; // 牛顿迭代，更新精度
    }
    return x1;
}

int main() {
    double x = 0.0;
    do {
        scanf("%lf", &x);
        assert(x >= 0);
        double y = NewTon_sqrt(x);
        printf("NewTon  : %.16lf\n", y);
        printf("std_Sqrt: %.16lf\n", sqrt(x));
    } while (getchar() != EOF);
    return 0;
}