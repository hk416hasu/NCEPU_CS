// count the num of ' ', '\t' and '\n'

#include <stdio.h>

int main() {

    int c = 0;

    int ns = 0, nt = 0, nl = 0; // num_space, num_tab, num_line

    while ((c = getchar()) != EOF) {
        if (c == ' ')  { ns++; }
        if (c == '\t') { nt++; }
        if (c == '\n') { nl++; }
    }
        
    printf("ns:%d, nt:%d, nl:%d\n", ns, nt, nl); 
    return 0;
}
