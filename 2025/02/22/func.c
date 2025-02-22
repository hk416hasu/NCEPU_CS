#include <stdio.h>

int main() {
    // Declaring the function prototype inside main
    int add(int, int);

    // Calling the function
    int result = add(3, 4);
    printf("Result: %d\n", result);


    int mul(int, int); // Declaring
    int (*funcPointer)(int, int) = mul; // define a function pointer
    printf("%d\n", funcPointer(6, 7));

    return 0;
}

// Defining the function outside main
int add(int a, int b) {
    return a + b;
}

int mul(int a, int b) {
   return a * b;
}
