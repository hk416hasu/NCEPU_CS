#include "global.h"

int main() {
    InitTokens();

    while (getNextToken());

    CloseTokens();

    return 0;
}
