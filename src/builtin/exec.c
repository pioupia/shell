#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include "../../includes/shell.h"

//
// Created by pioupia on 31/01/23.
//
int my_exec(char *command, char **args, char **environ)
{
    int status;
    pid_t pid;
    int errcode = 0;

    pid = fork();
    if (!pid) {
        if (execve(command, args, environ) == -1) {
            errcode = errno;
            my_putnchar("Error ! The command doesn't exist.");
            exit(errcode);
        } else {
            free(command);
            exit(errcode);
        }
    } else
        wait(&status);

    errcode = 0;
    return (errcode);
}