//
// Created by pioupia on 02/02/23.
//
#include <stdio.h>

extern char **environ;

int main(void) {
    if (environ[0] == NULL) return (1);

    printf("%s\n", environ[0]);

    return (0);
}