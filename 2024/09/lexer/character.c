#include "character.h"

bool isLetter(char ch) {
    if ( (ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') )
    {
        return 1;
    }
    return 0;
}

bool isDigit(char ch) {
    if ( ch >= '0' && ch <= '9' ) {
        return 1;
    }
    return 0;
}

bool isLetterOrDigit(char ch) {
    return isLetter(ch) || isDigit(ch);
}

bool isWhiteButNotSpace(int ch) {
    if ( ch == '\n' || ch == '\t' \
            || ch == '\r' || ch == '\f' || ch == '\v' )
    {
        return 1;
    }
    return 0;
}
