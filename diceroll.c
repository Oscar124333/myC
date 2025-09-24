#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int diceTotal = 0;
    int diceRoll = 0;
    int diceNum = rand()%4;
    for (int i = 0; i < diceNum; i++)
    {
        diceRoll = rand() % 6;
        diceTotal += diceRoll;
        printf("Roll #%i: %i\n", i+1, diceRoll);
    }
    printf("Dice: %i\n", diceNum);
    printf("Result: %i\n", diceTotal);
    return 0;
}