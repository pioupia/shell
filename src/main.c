#include <unistd.h>
#include <stdlib.h>
#include "../includes/shell.h"

// Declare the environment variable
extern char **environ;

int main(void) {
    clear();
    char *username = NULL;
    char *home = NULL;
    char *pwd = NULL;

    char hostname[1024];
    hostname[1023] = '\0';
    gethostname(hostname, 1023);

    parsing_env_variable(environ, &username, &home, &pwd);

    while (processing_command(username, pwd, home, hostname) == 0);

    free(username);
    free(home);
    free(pwd);
    return (0);
}