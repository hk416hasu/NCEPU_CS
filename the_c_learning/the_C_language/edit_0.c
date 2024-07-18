#include <stdio.h>

int main() {
    int Num_space = 0, Num_tab = 0, Num_newline = 0;
    int c = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') ++Num_newline;
        if (c == ' ') ++Num_space;
        if (c == '\t') ++Num_tab;
    }
    printf("the Num of enter : %d\n", Num_newline);
    printf("the Num of space : %d\n", Num_space);
    printf("the Num of tab : %d\n", Num_tab);

    return 0;
}