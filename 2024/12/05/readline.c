#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

// gcc a.c -lreadline

int main() {
    char *input;

    printf("welcome to the readline example\n");
    printf("u can exit by\n 1. entering \"exit\"\n 2. entering \"q\"\n 3. pressing C-D\n");

    while (1) {
        // output the prompt message and 
        //  get input by readline lib
        input = readline("> ");

        // want to exit
        if (input == NULL ||
                strcmp(input, "exit") == 0 ||
                strcmp(input, "q") == 0) {
            free(input);
            printf("Exiting...\n");
            break;
        }

        add_history(input);

        printf("you entered: %s\n", input);

        // Free the allocated memory for input
        free(input);
    }

    return 0;
}
