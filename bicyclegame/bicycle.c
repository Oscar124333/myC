#include <stdio.h>
#include <unistd.h>

// Variable Declaratiom
int userInput;

// Functional Prototypes

// Utility Prototypes
void wait(float seconds);
void lines(int num, int space, int newline);

int main(void)
{/*
    printf("Welcome to Oscar's Bicycle Game!\n");
    printf("Please use numbers to indicate your choices.\n");
    printf("1: Start\n2: Options");
    scanf("%i", &userInput);
    printf("\nYou input: %i\n", userInput);
    */
    
    lines(20, 1, 0);
}

void wait(float seconds)
{
    float milliseconds = seconds * 1000.0f;
    usleep(milliseconds * 1000.0f);
}

void lines(int num, int space, int newline)
{
    int total = num + (space * (num - 1)) + newline;
    char str[total + 1];
    for (int i = 0; i < total; i += space)
    {
        str[i] = '*';
        i++;
        for (int j = 0; j < space && i < total; j++)
        {
            str[i + j] = ' ';
        }
    }
    str[total] = '\0';
    printf("%s\n", str);
}
