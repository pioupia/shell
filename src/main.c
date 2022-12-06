#include "../includes/shell.h"

// Declare the environment variable
extern char **environ;


int main()
{
    clear();
    char* username = get_user_name(environ);
    my_putnchar(username);

    return (0);
}