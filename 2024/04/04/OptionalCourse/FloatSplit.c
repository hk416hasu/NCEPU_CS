// 通过观察可得：k+1 <= y <= 2*k, 然后我们就可以通过四则运算得到潜在的x, 再判断x是否是正整数即可
#include <stdio.h>

int main() {

    double k = 0.0;
    scanf("%lf", &k);
    double x = 0.0, y = 0.0;
    for (y = k+1; y <= 2*k; y++) {
        x = (k * y) / (y - k);  // 计算得到潜在的 x
        if ((int)(x) == x) {    // 判断x是否符合条件 (是正整数), 注意((int)x)会被隐式转换为double型再进行判断
            printf("1/%d = 1/%d + 1/%d\n", (int)k, (int)x, (int)y);
        }
    }

    return 0;
}