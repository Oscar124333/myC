#include <stdio.h>

// Constants; array identifiers & place values
const int arrONES = 0;
const int arrTEENS = 1;
const int arrTENS = 2;
const int THSND = 1000;

// 2D library of numbers in English
char *numLib[3][10] = {
    {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"},
    {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"},
    {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"},
};
char *bigLib[] = {"thousand", "million", "billion", "trillion"};

// Prototypes
int digit_counter(long long n);
void ones_huns(long long n);

int main(void)
{
    // Number grabber
    long long num = 0;
    printf("Number: ");
    if (scanf("%lli", &num) != 1)
    {
        printf("Input error.\n");
        return 1;
    }

    int digits = digit_counter(num);
    // Iterates through num from left to right
    while (digits > 0)
    {
        int bigFactor = (digits - 4) / 3;
        if (digits < 4)
        {
            ones_huns(num);
        }
        else
        {
            long long tempFACTOR = THSND;
            for (int j = 0; j < bigFactor; j++)
            {
                tempFACTOR *= THSND;
            }
            ones_huns(num / tempFACTOR);
            printf(" %s ", bigLib[bigFactor]);
        }
        digits -= 3;
    }

    printf("\n");
    return 0;
}

int digit_counter(long long n)
{
    int i = 0;
    while (n != 0)
    {
        n /= 10;
        i++;
    }
    return i;
}

void ones_huns(long long n)
{
    int hunVal = (n / 100) % 10;
    int tenVal = (n / 10) % 10;
    int oneVal = n % 10;

    // Prints hundreds place
    if (hunVal > 0)
    {
        char *huns = numLib[arrONES][hunVal];
        printf("%s hundred ", huns);
    }

    // Prints teens & terminates, or tens, or nothing if only ones
    if (tenVal > 0)
    {
        char *tens = "";
        if (tenVal == arrTEENS)
        {
            tens = numLib[arrTEENS][oneVal];
            printf("%s", tens);
            return;
        }
        else
        {
            tens = numLib[arrTENS][(tenVal - arrTENS)];
            printf("%s", tens);
        }
    }

    // Prints ones; dash if tens present
    if (oneVal > 0)
    {
        char *ones = numLib[arrONES][oneVal];
        if (tenVal > 0)
        {
            printf("-%s", ones);
        }
        else
        {
            printf("%s", ones);
        }
    }
}