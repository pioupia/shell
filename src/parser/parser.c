//
// Created by pioupia on 11/12/22.
//

#include <malloc.h>
#include "../../includes/shell.h"


char** parse_args(char* string) {
    my_putnchar(string);
    free(string);

    // int args_count = 0;
    // int max_length_argument = 0;
    // int actual_length_argument = 0;

    // for (int i = 0; string[i]; i++) {
        // crâne
    // }

    char *arr[] = {"ab"};

    char **strings = arr;
    return strings;
}


void parse_commands(char* string)
{
    char* command = "";
    char* args;
    int step = 0;
    int first_char = 0;


    for (int i = 0; string[i]; i++) {
        if (step == 0) {
            if (string[i] == ' ' && first_char != 0) {
                command = slice(string, first_char-1, i);
                args = slice(string, i + 1, my_len(string));
                step = 1;
            } else if (first_char == 0 && string[i] != ' ' && string[i] != ';') {
                first_char = i + 1;
            }
        }
    }

    if (step == 0) {
        my_putnchar(string);
        return;
    }
    //test; coucou --help --test; ton beau crâne bien lisse et luisant

    parse_args(
            args
        );

    my_putnchar(command);
    free(command);
}

void parse(char *string)
{
    int index = 0;

    for (int i = 0; string[i]; i++) {
        if (string[i] != ';' && string[i + 1] != '\0') continue;

        if (string[i + 1] == '\0') {
            index++;
        }

        char* sliced = slice(string, index, i);
        parse_commands(sliced);

        free(sliced);

        index = i;
    }

    free(string);
}