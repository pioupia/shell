#include <malloc.h>
#include <unistd.h>

extern char **environ;

int my_len(const char *str)
{
    int len = 0;

    while(str[len])
        len++;

    return (len);
}

char* my_strcpy(const char *str)
{
    int len = my_len(str);
    char *cpy = malloc(sizeof(char*) * (len + 1));

    for (int i = 0; (cpy[i] = str[i]); i++);
    return (cpy);
}

void my_putnchar(const char *str) {
    int len = my_len(str);

    char *string = my_strcpy(str);
    string[len] = '\n';

    write(STDOUT_FILENO, string, len + 1);

    free(string);
}

int main(void) {
    char *pwd = environ[0];

    my_putnchar(pwd);

    return 0;
}