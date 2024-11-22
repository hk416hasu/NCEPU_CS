#include <unistd.h>
#include <sys/types.h>

int main() {
    
    write(STDOUT_FILENO, "hello world\n", 12);

    return 0;
}
