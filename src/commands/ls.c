//
// Created by pioupia on 04/02/23.
//
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

#define IS_FILE         1
#define IS_EXECUTABLE   2

#define FILE_COLOR                  "\x1b[97m"
#define EXECUTABLE_FILE_COLOR       "\x1b[93m"
#define DIRECTORY_COLOR             "\x1b[96m"
#define COLOR_BOLD                  "\x1b[1m"
#define COLOR_RESET                 "\x1b[0m"

extern char **environ;


int is_regular_file(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);

    int res = S_ISREG(path_stat.st_mode);

    if (res == 1 && path_stat.st_mode & S_IXUSR) {
        return (2);
    }

    return (res);
}

int main(int argc, char **argv) {
    char *pwd = environ[0];
    if (pwd == NULL) return (1);

    int has_all = 0;

    if (argc != 0) {
        for (int i = 0; i < argc; i++) {
            char *argument = argv[i];

            if (argument[0] != '-') continue;

            for (int j = 0; argument[++j];) {
                if (argument[j] != 'a') continue;

                has_all = 1;
                break;
            }
        }
    }

    struct dirent *de;

    DIR *dr = opendir(pwd);

    if (!dr) {
        if (errno = ENOENT) {
            perror("Directory doesn't exist");
        } else {
            printf("An error has occured.");
        }
        return (1);
    }

    while ((de = readdir(dr)) != NULL) {
        char *name = de->d_name;

        if (has_all != 1 && name[0] == '.') continue;

        int type = is_regular_file(name);
        if (type == IS_FILE) {
            printf(FILE_COLOR "%s\n" COLOR_RESET, name);
        } else if (type == IS_EXECUTABLE) {
            printf(EXECUTABLE_FILE_COLOR COLOR_BOLD "%s%s*\n", name, COLOR_RESET);
        } else {
            printf(COLOR_BOLD DIRECTORY_COLOR "%s%s/\n", name, COLOR_RESET);
        }
    }
    closedir(dr);

    return (0);
}