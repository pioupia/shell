//
// Created by pioupia on 05/12/22.
//

#ifndef C_PROJECT_SHELL_H
#define C_PROJECT_SHELL_H

// Colors : https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
#define COLOR_WHITE_BRIGHT_FG   "\x1b[97m"
#define COLOR_CYAN_BG   "\x1b[46m"
#define COLOR_BOLD "\x1b[1m"
#define COLOR_RESET   "\x1b[0m"
#define SPACE_CHAR " "


#define MAX_INPUT_LEN 10

void clear(void);
void my_putnchar(const char*);
void my_putchar(char);
int print_user_name(char*);
int wait_input(void);

int my_len(const char*);
int my_strcmp(const char*, const char*);
char* my_strcpy(const char*);
char* my_strcat(const char*, const char*);
char* my_strcat_freeing(char*, const char*);
char* slice(const char*, int, int);

char* get_user_name(char**);

int parse(char*);

#endif //C_PROJECT_SHELL_H
