//
// Created by pioupia on 06/12/22.
//
#include <malloc.h>

int my_len(const char *str)
{
    int len = 0;

    while(str[len])
        len++;

    return (len);
}

char* my_strcpy(const char *str)
{
    int len = my_len(str);
    char *cpy = malloc(sizeof(char) * (len + 1));

    for (int i = 0; (cpy[i] = str[i]); i++);
    return (cpy);
}

int my_strcmp(char *string, char *string1) {
    string = my_strcpy(string);
    string1 = my_strcpy(string1);

    for (int i = 0; string[i] == string1[i]; i++) {
        if (!string1[i] && !string[i]) return 0;
    }

    return 1;
}