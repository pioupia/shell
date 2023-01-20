//
// Created by pioupia on 06/12/22.
//

#include <malloc.h>
#include "../../includes/shell.h"


void parsing_env_variable(char **environment, char **username, char **home, char **pwd) {
    char *arg = malloc(sizeof(char *) * 5);
    char *arg_pwd = calloc(3, sizeof(char *));

    arg[4] = '\0';
    arg_pwd[3] = '\0';

    for (char **current = environment; *current; current++) {
        int step = 0;
        int len = my_len(*current);

        for (int i = 0; current[0][i]; i++) {
            if (step == 4) break;

            if (current[0][i] == '=') {
                if (my_strcmp(arg, "USER") == 0) {
                    step++;
                    *username = slice(*current, 5, len);
                } else if (my_strcmp(arg, "HOME") == 0) {
                    step++;
                    *home = slice(*current, 5, len);
                } else if (my_strcmp(arg_pwd, "PWD") == 0) {
                    step++;
                    *pwd = slice(*current, 4, len);
                }
                continue;
            } else if (i == 4) {
                break;
            }

            if (i < 4)
                arg[i] = current[0][i];
            if (i < 3)
                arg_pwd[i] = current[0][i];
        }

        if (step == 3)
            break;
    }

    // Free the memory of the argument.
    free(arg);
    free(arg_pwd);
}