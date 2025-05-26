#include <stdio.h>

char *stdNumArr[3][10] = {
    {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"},
    {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"},
    {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"}};
char *bigArr[3] = {"hundred", "thousand", "million"};

int digit_counter(int n);

int main(void)
{

    int num = 0;
    printf("Number: ");
    if (scanf("%i", &num) != 1)
    {
        printf("Input error.\n");
        return 1;
    }
    printf("\n");

    int digits = digit_counter(num);
    printf("Digits: %i\n", digits);

    if (digits == 1)
    {
        printf("%s\n", stdNumArr[0][num - 1]);
    }
    else if (num < 20)
    {
        printf("%s\n", stdNumArr[1][num % 10]);
    }
    else
    {
        if (digits > 2)
        {
            char *big = bigArr[digits - 3];
            printf("%s ", big);
        }

        int tenVal = (num / 10) % 10;
        int oneVal = num % 10;
        char *tens = "";
        if (tenVal > 0)
        {
            tens = stdNumArr[2][(tenVal - 2)];
        }
        char *ones = stdNumArr[0][oneVal - 1];

        printf("%s", tens);
        if (0)
        {
            printf("%s", ones);
        }
        else if (ones != 0)
        {
            printf("-%s", ones);
        }
        printf("\n");
    }

    printf("\n%i\n", num);
    return 0;
}

int digit_counter(int n)
{
    int i = 0;
    while (n != 0)
    {
        n /= 10;
        i++;
    }
    return i;
}