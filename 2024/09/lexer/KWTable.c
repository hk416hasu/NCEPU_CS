#include "KWTable.h"

/**
brief: if token is a keyword, return its tokenType ( >= 1)
    else return 0;
    */
int isInKWTable(char *str, int len) {
    char Item[KWlength] = {0};
    strncpy(Item, str, len);

    if ( !strcmp(Item, "main") ) {  // if (Item == "main")
        return 1;
    } else if ( !strcmp(Item, "int") ) {
        return 2;
    } else if ( !strcmp(Item, "float") ) {
        return 3;
    } else if ( !strcmp(Item, "if") ) {
        return 4;
    } else if ( !strcmp(Item, "else") ) {
        return 5;
    } else if ( !strcmp(Item, "while") ) {
        return 6;
    }

    return 0;
}
