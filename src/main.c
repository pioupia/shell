#include "../includes/shell.h"

// Declare the environment variable
extern char **environ;


int main()
{
    clear();
    char* username = get_user_name(environ);

    print_user_name(username);
    return (0);
}