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
    char *cpy = malloc(sizeof(char*) * (len + 1));

    for (int i = 0; (cpy[i] = str[i]); i++);
    return (cpy);
}

char* my_strcat(const char* str1, const char* str2) {
    int first_len = my_len(str1);
    int second_len = my_len(str2);

    char *copy = calloc(first_len + second_len, sizeof(char*));

    for (int i = 0; i < first_len || i < second_len; i++) {
        if (i < first_len) copy[i] = str1[i];
        if (i < second_len) copy[first_len + i] = str2[i];
    }

    copy[first_len + second_len] = '\0';

    return (copy);
}

char* my_strcat_freeing(char* str1, const char* str2) {
    char *str = my_strcat(str1, str2);
    free(str1);

    return (str);
}

int my_strcmp(const char *string, const char *string1) {
    int first_len = my_len(string);
    int second_len = my_len(string1);

    if (first_len != second_len) return 0;


    for (int i = 0; i < first_len; i++) {
        if (string[i] != string1[i]) return 0;
    }

    return 1;
}

char* slice(const char* string, int start, int end) {
    char* str = calloc(end - start + 1, sizeof (char));

    str[end - start] = '\0';
    for (int i = start; i < end && string[i]; i++) {
        str[i - start] = string[i];
    }


    return (str);
}