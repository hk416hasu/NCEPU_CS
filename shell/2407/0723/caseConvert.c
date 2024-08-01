// bugs
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

// #define pattern abc
// #define replacement ABC

int main(int argc, char *argv[]) {
    assert(argc > 1);
    system("echo program start.");
   
    size_t cmd_size = strlen("var=") + strlen("argc[1]") + strlen("; echo ${var//abc/ABC}") + 1;
    char *cmd = (char *)malloc(cmd_size);
    assert(cmd != NULL);
    
    snprintf(cmd, cmd_size, "var=%s; echo ${var//abc/ABC}", argv[1]);
    
    system(cmd);

    free(cmd);
    cmd = NULL;

    // system("var=argv[1]; echo ${var//abc/ABC}"); // bugs

    system("echo program end.");
	
    return 0;
}
