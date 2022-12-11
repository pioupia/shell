//
// Created by pioupia on 11/12/22.
//

#include "../../includes/shell.h"

void parse(char *string) {
    int index = 0;

    for (int i = 0; string[i]; i++) {
        if (string[i] != ';') continue;
        my_putnchar(slice(string, index, i));
        index = i;
    }
}