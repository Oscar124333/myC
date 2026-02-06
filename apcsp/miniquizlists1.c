#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randSeeded(int a, int b);

int main(void)
{
    srand(time(NULL));

    
    // 50 random numbers from 1-50
    int randNumList[50] = {0};
    int randNumList_size = sizeof(randNumList) / sizeof(int);
    
    for (int i = 0; i < randNumList_size; i++)
    {
        int randomNumber = randSeeded(1, 50);
        randNumList[i] = randomNumber;
    }

    // DEBUGGING
    for (int i = 0; i < randNumList_size; i++)
    {
        printf("Integer #%i: %i\n", i+1, randNumList[i]);
    }
    
    
    // odd number counter
    int oddCounter = 0;
    for (int i = 0; i < randNumList_size; i++)
    {
        if ((randNumList[i] % 2) == 1)
        {
            oddCounter++;
        }
    }
    printf("\nNumber of Odd Integers: %i\n", oddCounter);
    
    
    // even integer remover + printer
    int *oddNumList = malloc(sizeof(int) * oddCounter);
    for (int i = 0, j = 0; i < randNumList_size; i++)
    {
        int currentInteger = randNumList[i];
        if ((currentInteger % 2) == 1)
        {
            oddNumList[j] = currentInteger;
            j++;
        }        
    }
    
    for (int i = 0; i < oddCounter; i++)
    {
        printf("Odd Integer #%i: %i\n", i + 1, oddNumList[i]);
    }

    
    free(oddNumList);
    return 0;
}

int randSeeded(int a, int b)
{
    int randomInteger = (rand() % (b - a)) + a;
    return randomInteger;
}