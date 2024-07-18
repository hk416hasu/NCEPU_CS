#include <stdio.h>
#include <stdint.h>  // 包含 uintptr_t 类型

int main() {

    int num = 0xFFFFFF;
    int *p = &num;

    printf("%p\n", p);
    printf("%p\n", *p);

    p = (int *)((uintptr_t)num);
    printf("%p\n", p);
    printf("%p\n", *p); // 这句访问了未声明的内存, 段错误, 可能是由OS发出


    return 0;
}