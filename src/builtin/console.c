//
// Created by pioupia on 06/12/22.
//

#include <unistd.h>
#include "../../includes/shell.h"

void my_putchar(char str)
{
    write(STDOUT_FILENO, &str, 1);
}

void my_putnchar(char *str)
{
    int len = my_len(str);


    str = my_strcpy(str);
    str[len] = '\n';

    write(STDOUT_FILENO, str, len + 1);
}

void clear (void)
{
    // printing escape sentence to clear the console
    // https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
    char* str = "\033[H\033[2J";
    int len = my_len(str);

    write(STDOUT_FILENO, str, len);
}