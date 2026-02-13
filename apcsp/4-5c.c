#include <stdio.h>

int integerInputHandler(int *variable);

int main(void)
{
    // Problem 1, Append and Extend with names
    int nameAmount = 0;
    integerInputHandler(&nameAmount);
    char **nameArr = malloc(sizeof(char) * nameAmount);
    
    char buffer[25] = {'\0'};
    if (stringInputHandler(&buffer) != 1)
    {

    }

    return 0;
}

int integerInputHandler(int *variable)
{
    int status = 0;
    int ch;
    status = scanf("%d", variable);
    if (status != 1)
    {
        while ((ch = getchar()) != '\n' && ch != EOF); // Clear buffer
    }
    return status;
}
int stringInputHandler(char *variable)
{
    int status = 0;
    int ch;
    status = scanf("%s", variable);
    if (status != 1)
    {
        while ((ch = getchar()) != '\n' && ch != EOF); // Clear buffer
    }
    return status;
}