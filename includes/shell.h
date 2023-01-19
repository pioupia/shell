//
// Created by pioupia on 05/12/22.
//

#ifndef C_PROJECT_SHELL_H
#define C_PROJECT_SHELL_H

// Colors : https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
#define COLOR_WHITE_BRIGHT_FG   "\x1b[97m"
#define COLOR_CYAN_BG           "\x1b[46m"
#define COLOR_CYAN_FG           "\x1b[96m"
#define COLOR_BOLD              "\x1b[1m"
#define COLOR_RESET             "\x1b[0m"
#define SPACE_CHAR                 " "


#define MAX_INPUT_LEN 10

void clear(void);
void my_putnchar(const char*);
void my_putchar(char);
int processing_command(char*, char*, char*);
int wait_input(void);

int my_len(const char*);
int my_strcmp(const char*, const char*);
char* my_strcpy(const char*);
char* my_strcat(const char*, ...);
char* my_strcat_freeing(char*, const char*);
char* slice(const char*, int, int);

void parsing_env_variable(char**, char**, char**, char**);

int parse(char*);

#endif //C_PROJECT_SHELL_H
