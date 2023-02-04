//
// Created by pioupia on 04/02/23.
//
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define IS_FILE         1
#define IS_EXECUTABLE   2

extern char **environ;


int is_regular_file(const char *path)
{
    struct stat path_stat;
    int res = stat(path, &path_stat);

    if (res == 0 && access(path, X_OK)) {
        return (2);
    }

    return (S_ISREG(path_stat.st_mode));
}

int cmpstringp(const void *p1, const void *p2)
{
    return strcmp(*(const char **) p1, *(const char **) p2);
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
  
    if (dr == NULL)
    {
        printf("And error has occured.");
        return (1);
    }
  
    int files_len = 0;
    while ((de = readdir(dr)) != NULL) {
        files_len++;
    }

    closedir(dr);

    dr = opendir(pwd);

    char **files = calloc(files_len, sizeof(char *));

    int i = 0;
    while ((de = readdir(dr)) != NULL) {
        files[i] = de -> d_name;
        printf("%s\n", files[i]);
        i++;
    }

    closedir(dr);
    
    qsort(files, files_len, sizeof(char *), cmpstringp);

    strcat(pwd, "/");

    for (; i > 0; i--) {
        char *value = files[files_len - i];

        if (has_all != 1 && value[0] == '.') continue;

        char *temp_pwd = malloc(strlen(pwd));
        strcpy(temp_pwd, pwd);

        char *file_path = strcat(temp_pwd, value);

        int type = is_regular_file(file_path);
        if (type == IS_FILE) {
            printf("%s\n", value);
        } else if (type == IS_EXECUTABLE) {
            printf("* %s\n", value);
        } else {
            printf("%s/\n", value);
        }

        free(file_path);
    }

    free(files);
    return (0);
}