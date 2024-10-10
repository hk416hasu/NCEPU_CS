#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp = fopen("./token.txt", "r");
    FILE *fp2 = fopen("./syntax.txt", "w");
    int ch = 0;
    while ( (ch = fgetc(fp)) != EOF ) {
        fprintf(fp2, "%c", ch);
    }
    return 0;
}
