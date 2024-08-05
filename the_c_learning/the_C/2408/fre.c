// count different chars frequency, and draw picture.

#include <stdio.h>

void func (int num) {
    num /= 10;
    for (int i = 0; i < num; i++) {
        printf("#");
    }
    printf("\n");
} 

int main() {

    int ndigit[10], nwhite = 0, nother = 0;
    for (int i = 0; i < 10; i++) { ndigit[i] = 0; }

    int c = 0;
    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ndigit[c - '0']++;
        }
        else if (c == ' ' || c == '\t' || c == '\n') {
            nwhite++;
        }
        else {
            nother++;
        }   
    }

    printf("digits:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d(%d)\t:", i, ndigit[i]); func(ndigit[i]);
    }
    printf("wh(%d)\t:", nwhite); func(nwhite);
   
    printf("ot(%d)\t:", nother); func(nother);

    return 0;
}
