//
// Created by pioupia on 06/12/22.
//

#include <malloc.h>
#include "../../includes/shell.h"

char* get_user_name (char **environment) {
    char *arg = malloc(sizeof(char*) * 5);
    char *value = "";

    arg[4] = '\0';

    for (char **current = environment; *current; current++) {
        int step = 0;
        int len = my_len(*current);
        int start_index = 0;

        for (int i = 0; current[0][i]; i++) {
            if (step == 0) {
                if (current[0][i] == '=' && my_strcmp(arg, "USER") == 0) {
                    step = 1;
                    value = calloc(len, sizeof(char*));
                    start_index = i + 1;
                    continue;
                } else if (i == 4) {
                    break;
                }
                arg[i] = current[0][i];
                continue;
            }

            value[i - start_index] = current[0][i];
        }

        if (step == 1)
            break;
    }

    // Free the memory of the argument.
    free(arg);

    return value;
}