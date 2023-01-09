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

    my_putnchar(username);
    my_putnchar(home);
    my_putnchar(pwd);

    while (print_user_name(username) == 0);

    free(username);
    free(home);
    free(pwd);
    return (0);
}