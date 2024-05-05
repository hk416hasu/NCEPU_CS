#include <stdio.h>

// char *argv[]是个字符串，然后argv[0]存储了程序名  // 当时啥也不懂 没用过linux & shell

/*
240505补充：
    int argc: arg count, 参数数量;
    char *argv[]: arg value 是字符串数组, 存的是shell传进来的参数。
    argv[0] 是 ./xxx(程序名)，arg[1]开始存的是具体参数
*/
int main(int argc, char *argv[]) {
    
    for (int i=0; i < argc; i++) {
        printf("%s ", argv[1]);
    }

    return 0;
}