//
// Created by pioupia on 06/12/22.
//

#include <unistd.h>
#include <malloc.h>
#include "../../includes/shell.h"

void my_putchar(char str) {
    write(STDOUT_FILENO, &str, 1);
}

void my_putnchar(const char *str) {
    int len = my_len(str);

    char *string = my_strcpy(str);
    string[len] = '\n';

    write(STDOUT_FILENO, string, len + 1);

    free(string);
}

void print_wobl(char *str) {
    int len = my_len(str);
    write(STDOUT_FILENO, str, len + 1);
}

char* get_relative_path(const char* pwd, const char* home) {
    int i = 0;

    while (pwd[i] == home[i])
        i++;

    if (i <= 1) {
        return my_strcpy(pwd);
    }

    char* path = slice(pwd, i, my_len(pwd));
    char* result = my_strcat("~", path);

    free(path);
    return result;
}

int processing_command(char *username, char* pwd, char* home) {
    char* relative_path = get_relative_path(pwd, home);
    char *start = my_strcat(COLOR_BOLD COLOR_CYAN_BG COLOR_WHITE_BRIGHT_FG SPACE_CHAR,
                            username);
    char *end_style = my_strcat(start, SPACE_CHAR COLOR_RESET);
    char *points = my_strcat(end_style, ":");
    char *with_path_style = my_strcat(points, COLOR_CYAN_FG);
    char *with_path = my_strcat(with_path_style, relative_path);
    char *with_path_style_end = my_strcat(with_path, COLOR_RESET);
    char* end = my_strcat(with_path_style_end, "$ ");

    print_wobl(end);

    free(start);
    free(end_style);
    free(points);
    free(with_path_style);
    free(with_path);
    free(with_path_style_end);
    free(end);
    free(relative_path);

    return wait_input();
}

int wait_input (void)
{
    char* string = malloc(sizeof(char*) * 1);
    string[0] = '\0';

    char buff[MAX_INPUT_LEN + 1];


    while (1) {
        ssize_t bytesRead = read(STDIN_FILENO, buff, MAX_INPUT_LEN);

        if (0 > bytesRead) {
            my_putnchar("read failed");
            continue;
        }

        buff[bytesRead] = '\0';

        if (buff[bytesRead - 1] == '\n') {
            int status = parse(
                    my_strcat(string, buff)
            );

            free(string);

            return status;
        }

        string = my_strcat_freeing(string, buff);
    }

    return 0;
}

void clear(void) {
    // printing escape sentence to clear the console
    // https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
    char *str = "\033[H\033[2J";
    int len = my_len(str);

    write(STDOUT_FILENO, str, len);
}