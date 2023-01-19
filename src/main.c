#include <malloc.h>
#include "../includes/shell.h"

// Declare the environment variable
extern char **environ;


int main()
{
    clear();
    char* username = NULL;
    char* home = NULL;
    char* pwd = NULL;
    parsing_env_variable(environ, &username, &home, &pwd);

    while (processing_command(username, pwd, home) == 0);

    free(username);
    free(home);
    free(pwd);
    return (0);
}