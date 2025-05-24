#include <stdio.h>

int main(void)
{
    long number;
    printf("Number: ")
        scanf("%i", &number);
    if (number == NULL)
    {
        return 1;
    }
    printf("%li", number);
    return 0;
}