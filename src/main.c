#include <malloc.h>
#include "../includes/shell.h"

// Declare the environment variable
extern char **environ;


int main()
{
    clear();
    char* username = get_user_name(environ);

    while (print_user_name(username) == 0);

    free(username);
    return (0);
}