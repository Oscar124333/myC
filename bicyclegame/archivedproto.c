#include <stdio.h>
#include <math.h>
#include <unistd.h>

// Archived Prototypes
void lines(int astNum, int space, int newline); // Draws lines with simple auto '\n' formatting.

int main(void)
{
    lines(100, 0, 3);
}

void lines(int astNum, int space, int newline)
{
    int arrEnd = 1;
    
    int arrSize = astNum + (space *(astNum - 1));
    int arrSizeTotal = arrSize + newline + arrEnd;
    char arr[arrSizeTotal];
    
    float newlineIncr = ceil(newline/2.0f); // Amount to compensate for '\n's at start.

    for (int i = newlineIncr; i < arrSize + newlineIncr; i += space)
    {
        arr[i] = '*';
        i++;
        for (int j = 0; j < space && i < arrSize + newlineIncr; j++) // Prevent spaces after final '*'
        {
            arr[i + j] = ' ';
        }
    }
    
    for (int i = 0, j = 0; i < newline; i++) // Easy formatting with '\n' insertion before and after
    {
        if (i % 2 == 0)
        {
            arr[i - (j++)] = '\n';
        }
        else
        {
            arr[arrSizeTotal - arrEnd - j] = '\n';
        }
    }
    
    arr[arrSizeTotal - arrEnd] = '\0';
    printf("%s\n", arr);
}