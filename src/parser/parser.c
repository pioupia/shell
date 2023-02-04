//
// Created by pioupia on 11/12/22.
//

#include <malloc.h>
#include "../../includes/shell.h"

char** parse_args(const char* string)
{
    // Allouer un tableau de chaînes de caractères assez grande pour accueillir tous les arguments
    const int max_arguments = 11;
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
            if (argument_length >= max_argument_length - 1) {
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

    args[argument_index] = NULL;

    free(argument);

    return (args);
}


int parse_commands(char *string, char *pwd)
{
    char *command = "";
    char** arguments;
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
        command = my_strcpy(string);
        arguments = calloc(1, sizeof(char *));
        arguments[0] = NULL;

        args = NULL;
    } else {
        arguments = parse_args(
                args
        );
    }

    if (my_strcmp(command, "exit") == 0) {
        if (args != NULL) free(args);
        free(command);

        for (int i = 0; arguments[i];) {
            free(arguments[i++]);
        }

        free(arguments);


        my_putnchar("Good bye !");
        return 1;
    }

    char *environ[] = { pwd, NULL };

    char *file_name = my_strcat("./src/commands/", command, ".o", NULL);

    my_exec(file_name, arguments, environ);

    for (int i = 0; arguments[i];) {
        free(arguments[i++]);
    }

    if (args != NULL) free(args);
    free(file_name);
    free(arguments);
    free(command);
    return (0);
}

int parse(char *string, char *pwd)
{
    int index = 0;

    for (int i = 0; string[i]; i++) {
        if (string[i] != ';' && string[i + 1] != '\0') continue;

        char *sliced = slice(string, index, i);
        int status = parse_commands(sliced, pwd);

        if (status == 1) {
            free(sliced);
            free(string);
            return 1;
        }

        free(sliced);

        index = i;
    }

    free(string);

    return 0;
}