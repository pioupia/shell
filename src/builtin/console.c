//
// Created by pioupia on 06/12/22.
//

#include <unistd.h>
#include <malloc.h>
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

void print_wobl(char *str) {
    int len = my_len(str);
    write(STDOUT_FILENO, str, len + 1);
}

void print_user_name(char* username)
{
    char* start = my_strcat(COLOR_BOLD COLOR_CYAN_BG COLOR_WHITE_BRIGHT_FG SPACE_CHAR, username);
    char* end_style = my_strcat(start, SPACE_CHAR COLOR_RESET);
    char* end = my_strcat(end_style, ":$ ");

    print_wobl(end);

    free(start);
    free(end_style);
    free(end);

    wait_input();
}

char* wait_input (void)
{
    char* string = "";
    char buff[MAX_INPUT_LEN + 1];
    int partNum = 0;

    while(1)
    {
        ssize_t bytesRead = read(STDIN_FILENO, buff, MAX_INPUT_LEN);

        if(0 > bytesRead)
        {
            my_putnchar("read failed");
            continue;
        }

        buff[bytesRead] = '\0';
        partNum++;

        if (buff[bytesRead - 1] == '\n') return string;

        my_strcat(string, buff);
    }
}

void clear (void)
{
    // printing escape sentence to clear the console
    // https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
    char* str = "\033[H\033[2J";
    int len = my_len(str);

    write(STDOUT_FILENO, str, len);
}