//
// Created by pioupia on 04/02/23.
//
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;


int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return (S_ISREG(path_stat.st_mode));
}

int cmpstringp(const void *p1, const void *p2)
{
    return strcmp(*(const char **) p1, *(const char **) p2);
}

int main(int argc, char **argv) {
    if (environ[0] == NULL) return (1);

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

    printf("%d\n", has_all);

    struct dirent *de;
  
    DIR *dr = opendir(environ[0]);
  
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

    dr = opendir(environ[0]);

    char **files = calloc(files_len, sizeof(char *));

    int i = 0;
    while ((de = readdir(dr)) != NULL) {
        char* name = de->d_name;
        files[i] = name;
        i++;
    }

    printf("%d\n", i);
    printf("%d\n", files_len);
  
    closedir(dr);
    
    qsort(files, files_len, sizeof(char *), cmpstringp);

    for (; i > 0; i--) {
        printf("%d\n", files_len - i);
        printf("%s\n", files[files_len - i]);
        free(files[files_len - i]);
    }

    free(files);
    

    return (0);
}