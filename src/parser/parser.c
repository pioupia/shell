//
// Created by pioupia on 11/12/22.
//

#include <malloc.h>
#include "../../includes/shell.h"

char **parse_args(char *string) {
    int args_count = 1;
    int actual_length_argument = 0;

    for (int i = 0; string[i]; i++) {
        if (string[i] != ' ') {
            actual_length_argument++;
            continue;
        }

        if (string[i] == ' ' && actual_length_argument != 0) {
            actual_length_argument = 0;
            args_count++;
        }
    }

    char** args = malloc((args_count + 1) * sizeof(char*));
    actual_length_argument = 0;

    args[args_count] = NULL;

    for (int i = 0; string[i]; i++) {
        if (string[i] != ' ') {
            actual_length_argument++;
            continue;
        }

        if (string[i] == ' ' && actual_length_argument != 0) {
            args[i] = slice(string,  i - actual_length_argument, i);
            my_putnchar(args[i]);
            actual_length_argument = 0;
        }
    }


    free(string);
    return (args);
}


void parse_commands(char *string) {
    char *command = "";
    char *args;
    int step = 0;
    int first_char = 0;


    for (int i = 0; string[i]; i++) {
        if (string[i] == ' ' && first_char != 0) {
            command = slice(string, first_char - 1, i);
            args = slice(string, i + 1, my_len(string));
            step = 1;
            break;
        }

        if (first_char == 0 && string[i] != ' ' && string[i] != ';') {
            first_char = i + 1;
        }
    }

    if (step == 0) {
        my_putnchar(string);
        return;
    }

    char** arguments = parse_args(
            args
    );

    for (int i = 0; arguments[i];) {
        my_putnchar(arguments[i]);
        free(arguments[i++]);
    }

    free(arguments);

    my_putnchar(command);
    free(command);
}

void parse(char *string) {
    int index = 0;

    for (int i = 0; string[i]; i++) {
        if (string[i] != ';' && string[i + 1] != '\0') continue;

        if (string[i + 1] == '\0') {
            index++;
        }

        char *sliced = slice(string, index, i);
        parse_commands(sliced);

        free(sliced);

        index = i;
    }

    free(string);
}