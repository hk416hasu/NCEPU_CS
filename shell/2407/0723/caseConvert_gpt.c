#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(int argc, char *argv[]) {
    assert(argc > 1);
    system("echo program start.");

    // Allocate enough space for the command
    size_t cmd_size = strlen("echo ") + strlen(argv[1]) + strlen(" | sed 's/abc/ABC/g'") + 1;
    char *cmd = (char *)malloc(cmd_size);
    if (cmd == NULL) {
        perror("malloc");
        return 1;
    }

    // Construct the command
    snprintf(cmd, cmd_size, "echo %s | sed 's/abc/ABC/g'", argv[1]);

    // Execute the command
    system(cmd);

    // Clean up
    free(cmd);

    system("echo program end.");

    return 0;
}

