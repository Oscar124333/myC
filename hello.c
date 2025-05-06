#include <stdio.h>

int main(void)
{
    int num = 0;
    printf("Hello?\n");
    scanf("%i", &num);
    if (num > 0) {
        printf("Hello, World\n");
    }
    return 0;
}