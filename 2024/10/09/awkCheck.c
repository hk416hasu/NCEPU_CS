#include <stdio.h>
#include <stdlib.h>

int main() {
    // system() does not work on XiJi platform, maybe it isn't implemented...
//    system("awk '{print $1}' ./token.txt > ./syntax.txt");
//    system("echo hello > syntax.txt");
//    system("echo Exp >> syntax.txt");
//    system("echo AssSta >> syntax.txt");
//    system("echo Program >> syntax.txt");

    FILE *fp = fopen("./syntax.txt", "w");
    fprintf(fp, "Exp\n");
    fprintf(fp, "AssSta\n");
    fprintf(fp, "Program\n");
    system("echo hello >> syntax.txt"); // this doesn't work

    fclose(fp);

    return 0;
}
