//
// Created by pioupia on 11/12/22.
//

#include <malloc.h>
#include "../../includes/shell.h"

char** parse_args(const char* string) {
    // Allouer un tableau de chaînes de caractères assez grande pour accueillir tous les arguments
    const int max_arguments = 10;
    char **args = calloc(max_arguments, sizeof(char *));

    // Allouer une chaîne de caractères pour stocker temporairement un argument en cours de traitement
    const int max_argument_length = 256;
    char *argument = calloc(max_argument_length, sizeof(char));

    int argument_index = 0;
    int argument_length = 0;
    for (int i = 0; string[i]; i++) {
        if (string[i] != ' ') {
            // Ajouter le caractère au argument en cours de traitement
            argument[argument_length] = string[i];
            argument_length++;

            // Si le argument en cours de traitement est trop long, libérer la mémoire et retourner un message d'erreur
            if (argument_length >= max_argument_length) {
                free(argument);
                for (int j = 0; j < argument_index; j++) {
                    free(args[j]);
                }
                free(args);
                return NULL;
            }
        } else {
            // Ajouter le argument au tableau d'arguments
            argument[argument_length] = '\0';
            args[argument_index] = my_strcpy(argument);
            argument_index++;

            // Si le tableau d'arguments est plein, libérer la mémoire et retourner un message d'erreur
            if (argument_index >= max_arguments) {
                free(argument);
                for (int j = 0; j < argument_index; j++) {
                    free(args[j]);
                }
                free(args);
                return NULL;
            }

            // Réinitialiser la chaîne de caractères pour stocker le prochain argument
            argument_length = 0;
        }
    }

    // Ajouter le dernier argument au tableau d'arguments (si la chaîne de caractères ne se termine pas par un espace)
    if (argument_length > 0) {
        argument[argument_length] = '\0';
        args[argument_index] = my_strcpy(argument);
        argument_index++;
    }

    free(argument);

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
    free(args);

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