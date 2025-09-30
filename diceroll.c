#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize dice values
int dNum = 0;
int dSides = 0;
int dRollVal = 0;
int dSum = 0;

// userInput values
int uRandom = 1;
int uManual = 2;
int uExit = 9;

// Prototypes
void lineBreak(void);
void randomDice(void);
void manualDice(void);

int main(void)
{
    // Seed rand
    srand(time(NULL));

    // Figure out user's desired function
    int userInput = 0;
    lineBreak();
    printf("Welcome to Oscar's Dice Roller!\n");
    while (userInput != uRandom && userInput != uManual && userInput != uExit)  // Loop until valid input given
    {
        printf("\nWould you like a completely random dice roll or to manually control and roll your dice?\n1: Random\n2: Manual\n9: Exit the Program\n--> ");
        scanf("%d", &userInput);
    }

    // Function call based on userInput
    if (userInput == uExit)
    {
        return 1;
    }
    else if (userInput == uRandom)
    {
        lineBreak();
        randomDice();
        return 0;
    }
    else if (userInput == uManual)
    {   // Ask what the user wants with dice
        lineBreak();
        printf("How many dice would you like to roll?\n--> ");
        scanf("%d", &dNum);
        printf("\nHow many sides would you like on your dice?\n--> ");
        scanf("%d", &dSides);
        manualDice();
        return 0;
    }
    else
    {
        lineBreak();
        printf("Error encountered! Please try again!\n");
        return 2;
    }
}

void lineBreak(void)
{
    printf("\n\n* * * * * * * * * *\n");
}

void randomDice(void)
{
    // Random # of dice (<=25), then roll each dice (D6) and total
    dNum = rand() % 25 + 1;
    dSides = 6;
    for (int i = 0; i < dNum; i++)
    {
        dRollVal = rand() % dSides + 1;
        dSum += dRollVal;
        printf("Roll #%i: %i\n", i+1, dRollVal);
    }
    printf("\nDice: %i\n", dNum);
    printf("Result: %i\n", dSum);
}

void manualDice(void)
{
    for (int i = 0; i < dNum; i++)
    {
        dRollVal = rand() % dSides + 1;
        dSum += dRollVal;
        printf("Roll #%i: %i\n", i+1, dRollVal);
    }
    printf("\nDice: %i\n", dNum);
    printf("Result: %i\n", dSum);
}