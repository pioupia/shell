//
// Created by pioupia on 11/12/22.
//

#include <malloc.h>
#include "../../includes/shell.h"

void parse(char *string) {
    int index = 0;

    for (int i = 0; string[i]; i++) {
        if (string[i] != ';') continue;
        char* sliced = slice(string, index, i);
        my_putnchar(sliced);
        free(sliced);
        index = i;
    }

    free(string);
}