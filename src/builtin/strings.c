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

char* my_strcat(const char* str1, const char* str2) {
    int first_len = my_len(str1);
    int second_len = my_len(str2);

    char *copy = malloc(sizeof(char) * (first_len + second_len + 1));

    for (int i = 0; str1[i] || str2[i]; i++) {
        if (i < first_len) copy[i] = str1[i];
        if (i < second_len) copy[first_len + i] = str2[i];
    }

    return (copy);
}

int my_strcmp(char *string, char *string1) {
    string = my_strcpy(string);
    string1 = my_strcpy(string1);

    for (int i = 0; string[i] == string1[i]; i++) {
        if (!string1[i] && !string[i]) return 0;
    }

    return 1;
}

char* slice(const char* string, int start, int end) {
    char* str = malloc(sizeof (char*) * (end - start));

    for (int i = start; i < end && string[i]; i++) {
        str[i - start] = string[i];
    }

    str[end] = '\0';

    return str;
}