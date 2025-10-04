#include <stdio.h>
#include <math.h>
#include <unistd.h>

// Variable Declaratiom
int userInput;

// Functional Prototypes

// Utility Prototypes
void wait(float seconds);
void lines(int num, int strAmnt, int newline);

int main(void)
{/*
    printf("Welcome to Oscar's Bicycle Game!\n");
    printf("Please use numbers to indicate your choices.\n");
    printf("1: Start\n2: Options");
    scanf("%i", &userInput);
    printf("\nYou input: %i\n", userInput);
    */
    
    lines(2, 1, 2);
}

void wait(float seconds)
{
    float milliseconds = seconds * 1000.0f;
    usleep(milliseconds * 1000.0f);
}

void lines(int num, int space, int newline)
{
    int strEnd = 1;
    int strAmnt = num + (space * (num - 1)) + newline + strEnd; // Amount of memory to allocate to str
    char str[strAmnt];
    
    newlineIncr = ceil(newline/2.0); // For the following loop; tells # of extra space at start.
    for (int i = 0; i < strAmnt; i += space + newlineIncr)
    {
        str[i] = '*';
        i++;
        for (int j = 0; j < space && i < strAmnt; j++)
        {
            str[i + j] = ' ';
        }
    }

    f(0) = xxx
    f(1) = []xxx
    f(2) = []xxx[]
    f(3) = [][]xxx[]
    f(4) = [][]xxx[][]
                 2         4
    for (int i = 0, j = 0; i < newline; i++)
    {
        if (i % 2 = 0)
        {
            str[i - (++j)] = '\n'
        }
        else
        {
            str[strAmnt - i] = '\n'
        }
    }

    str[strAmnt] = '\0';
    printf("%s\n", str);
}
