#include <stdio.h>
#include <stdlib.h>

int maximum(int *integerList);
int minimum(int *integerList);

int main(void)
{
    int listEx1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int listEx2[] = {500, 20, -100, 40, 5, -10, 42, -10}; 
    int listEx3[] = {5, 5, 5 ,5 , 5}; 

    printf("Example #1 \n  Max: %i \n  Min: %i\n", maximum(listEx1), minimum(listEx1));
    return 0;
}

int maximum(int *integerList)
{
    int max = integerList[0];
    // find an alternative; sizeof(integerList) returns 8
    int integerListLength = sizeof(integerList) / sizeof(int);

    for (int i = 1; i < integerListLength; i++)
    {
        if (integerList[i] > max)
        {
            max = integerList[i];
        }
    }
    
    return max;
}
int minimum(int *integerList)
{
    int min = integerList[0];
    int integerListLength = sizeof(integerList) / sizeof(int);
    
    for (int i = 1; i < integerListLength; i++)
    {
        if (integerList[i] < min)
        {
            min = integerList[i];
        }
    }
    return min;
}