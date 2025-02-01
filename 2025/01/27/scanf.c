#include <stdio.h>

int main() {
    char arr[9] = {0};  // 预留一个字节存储 '\0'
    int ret = scanf("%8c", arr);
    if (ret == 1) {
        printf("成功读取: %s\n", arr);
    } else {
        printf("读取失败或输入不足！\n");
    }
    return 0;
}

