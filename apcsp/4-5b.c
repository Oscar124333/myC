#include <stdio.h>
#include <stdlib.h>

int maximum(int integerList[], int integerListLength);
int minimum(int integerList[], int integerListLength);

int main(void)
{
    // Problem 1, min max
    int intList1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int intList2[] = {500, 20, -100, 40, 5, -10, 42, -10};
    int intList3[] = {5, 5, 5, 5, 5};

    int *intListArr[] = {intList1, intList2, intList3};

    int intListLengths[3] =
        {(int)(sizeof(intList1) / sizeof(int)),
        (int)(sizeof(intList2) / sizeof(int)),
        (int)(sizeof(intList3) / sizeof(int))};

    int listAmount = sizeof(intListLengths) / sizeof(int);

    char outputBuffer[40];
    for (int i = 0; i < listAmount; i++)
    {
        sprintf(outputBuffer, "Example #%i \n  Max: %i \n  Min: %i", i + 1, maximum(intListArr[i], intListLengths[i]), minimum(intListArr[i], intListLengths[i]));
        printf("%s\n", outputBuffer);
    }

    // Problem 2, owls
    char *sampleText =
        "I really like owls. Did you know that an owl's eyes are more than "
        "twice as big as the eyes of other birds of comparable weight? And "
        "that when an owl partially closes its eyes during the day, it is "
        "just blocking out light? Sometimes I wish I could be an owl.";

    int textSize = (int)(sizeof(sampleText)/sizeof(char *));
    int length_of_the_word_owl = 3;

    for (int i = 0, char currentText[3]; i < textSize - length_of_the_word_owl; i++)
    {
        for (int j = 0; j < length_of_the_word_owl; j++)
        {
            sprintf(currentText, )
        }
        
    }

    return 0;
}

int maximum(int integerList[], int integerListLength)
{
    int max = integerList[0];

    for (int i = 1; i < integerListLength; i++)
    {
        if (integerList[i] > max)
        {
            max = integerList[i];
        }
    }
    
    return max;
}
int minimum(int integerList[], int integerListLength)
{
    int min = integerList[0];
    
    for (int i = 1; i < integerListLength; i++)
    {
        if (integerList[i] < min)
        {
            min = integerList[i];
        }
    }
    return min;
}