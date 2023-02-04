//
// Created by pioupia on 04/02/23.
//
#include <stdio.h>
#include <dirent.h>
#include <string.h>

extern char **environ;

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

    struct dirent *de;
  
    DIR *dr = opendir(environ[0]);
  
    if (dr == NULL)
    {
        printf("And error has occured.");
        return (1);
    }
  
    while ((de = readdir(dr)) != NULL) {
        char* name = de->d_name;

        if (has_all != 1 && name[0] == '.') continue;

        printf("%s\n", name);
    }
  
    closedir(dr);    
    
    return (0);
}