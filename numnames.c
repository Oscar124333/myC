#include <stdio.h>

char *onesArr[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char *teensArr[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *tensArr[] = {"ten, twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety"};
char *bigArr[] = {"hundred", "thousand", "million"};

int main(void)
{
    int num = 0;
    printf("Number: ");
    if (scanf("%i", &num) != 1)
    {
        printf("Input error.\n");
        return 1;
    }
    printf("%i\n", num);

        return 0;
}