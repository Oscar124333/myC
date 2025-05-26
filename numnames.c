#include <stdio.h>

// Constants; array identifiers & place values
const int arrONES = 0;
const int arrTEENS = 1;
const int arrTENS = 2;

const int THSND = 1000;
const int MIL = 1000000;

// 2D library of numbers in English
char *numLib[3][10] = {
    {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"},
    {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"},
    {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"},
};

// Prototypes
int digit_counter(int n);
void ones_huns(int n);

int main(void)
{
    // Number grabber
    int num = 0;
    printf("Number: ");
    if (scanf("%i", &num) != 1)
    {
        printf("Input error.\n");
        return 1;
    }

    int digits = digit_counter(num);

    // Prints all millions place-values
    if (digits >= 7)
    {
        ones_huns(num / MIL);
        printf(" million ");
    }

    // Prints all thousands place-values if present
    if (digits >= 4 && (num / THSND) % THSND > 0)
    {
        ones_huns(num / THSND);
        printf(" thousand ");
    }

    // Prints 1-999
    ones_huns(num);

    printf("\n");
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

void ones_huns(int n)
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