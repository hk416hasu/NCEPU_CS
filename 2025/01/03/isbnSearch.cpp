#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void isbn_search(const char *isbn) {
    char command[100];
    snprintf(command, sizeof(command), "nodejs ./isbn2.js %s > ./info.json", isbn);
    assert(system(command) != -1);
}

int main(void) {
    const char isbn[] = "9787559646224";
    isbn_search(isbn);
    return 0;
}

