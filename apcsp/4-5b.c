#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        sprintf(outputBuffer, "\nExample #%i \n  Max: %i \n  Min: %i", i + 1, maximum(intListArr[i], intListLengths[i]), minimum(intListArr[i], intListLengths[i]));
        printf("%s\n", outputBuffer);
    }


    printf("\n********************\n\n");


    // Problem 2, owls
    char sampleText2[] =
    "I really like owls. Did you know that an owl's eyes are more than "
    "twice as big as the eyes of other birds of comparable weight? And "
    "that when an owl partially closes its eyes during the day, it is "
    "just blocking out light? Sometimes I wish I could be an owl.";
    
    int textSize2 = (int)(strlen(sampleText2));
    int length_of_the_word_owl = 3;
    int owlCount = 0;
    
    for (int i = 0; i < textSize2 - length_of_the_word_owl; i++)
    {
        char owl[] = "owl";
        char currentText[4] = {0};
        
        for (int j = 0; j < length_of_the_word_owl; j++)
        {
            currentText[j] = sampleText2[i + j];
        }
        
        if (strcmp(currentText, owl) == 0)
        {
            owlCount++;
        }
    }
    
    printf("Number of owls: %i\n", owlCount);
    

    printf("\n********************\n\n");


    // Problem 3, edgy I (lowercase i only)
    //  Note: will not do string user input
    char sampleText3[] =
        "Indescribable oppression, which seemed to generate in some " 
        "unfamiliar part of her consciousness, filled her whole being "
        "with a vague anguish. It was like a shadow, like a mist "
        "passing across her soul's summer day. It was strange and "
        "unfamiliar; it was a mood. She did not sit there inwardly "
        "upbraiding her husband, lamenting at Fate, which had directed "
        "her footsteps to the path which they had taken. She was just "
        "having a good cry all to herself. The mosquitoes made merry "
        "over her, biting her firm, round arms and nipping at her bare "
        "insteps. Mississipipipipipissipipiii.";

    int textSize3 = strlen(sampleText3);

    for (int i = 0; i < textSize3; i++)
    {
        if (sampleText3[i] == 'i')
        {
            sampleText3[i] = '!';
        }
    }

    printf("%s\n", sampleText3);



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
