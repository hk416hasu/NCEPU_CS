#include <cstdio>
#include <ctime>

/**
 * @brief:hano(n, A, B, C), 表示 将n个hano塔从A柱运到C柱，B柱中转。
 * 其实hano(n, A, C)就够了
*/
void hano(int n, char A, char B, char C) {
    // 千万别忘了递归退出条件
    if (n == 1) {
        printf("%d->%c\n", n, C);
        return;
    }
    hano(n-1, A, C, B);         // 先将“较大的那n-1个盘子”从A运到B
    printf("%d->%c\n", n, C);   // 再将剩下的“那个最小”的运到C
    hano(n-1, B, A, C);         // 最后将“较大的那n-1个”从B运到C
}

void hano(int n) {
    if (n < 1) {
        printf("wrong value.\n");
        return;
    }
    hano(n, 'A', 'B', 'C');
}

int main() {

int n = 0;
    scanf("%d", &n);

clock_t timestart = clock();
    hano(n);

    // printf("run time cost: %lfs\n", (double)(clock() - timestart)/CLOCKS_PER_SEC); // 可以发现时间复杂度是O(2^n)
double total_t = (double)(clock() - timestart)/(CLOCKS_PER_SEC);
    printf("timecost: %lfs\n", total_t);

    // 清空输入缓冲区
int c;
    while ((c = getchar()) != '\n' && c != EOF);
    getchar(); // 等待用户输入
    
    return 0;
}