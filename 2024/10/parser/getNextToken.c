#include <stdio.h>
#include <stdlib.h>

FILE *fp = NULL;

_Bool getNextToken() {
    char buf[5];
    if (fgets(buf, sizeof(buf), fp) != NULL) {
        printf("%s", buf);
    } else {
        return 0;
    }
    return 1;
}


void InitTokens() {
    // use awk helping me format token.txt ( unix makes life eaiser. )
    system("awk '{ print $1 }' ./token.txt > formattedTokens");
    // open the file containing formatted tokens
    fp = fopen("./formattedTokens", "r");
        // error handle
}

void CloseTokens() {
    fclose(fp);
}

int main() {
    InitTokens();
    while (getNextToken());
    CloseTokens();

    return 0;
}
