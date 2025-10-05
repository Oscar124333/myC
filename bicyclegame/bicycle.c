#include <stdio.h>
#include <unistd.h>

// Variable Declarations
int userInput;

// Gameplay Prototypes

// Utility Prototypes
void wait(float seconds);
void line(int astNum, int astSpace, int nlBefore, int nlAfter);

// Interface Prototypes
void options(void);
void info(void);
void credits(void);

int main(void)
{
    line(20,1,3,0);
    printf("Welcome to Oscar's Bicycle Game!\n");
    printf("Please use numbers to indicate your choices.\n");
    enum MenuStart{
        MS_START = 1,
        MS_OPTIONS,
        MS_INFO_HOW,
        MS_CREDITS,
        MS_EXIT
    };

    do   
    {
        printf("\n1: Start\n2: Options\n3: Info & How-To\n4: Credits\n5: Exit\n");
        printf("==> ");
        scanf("%i", &userInput);
        printf("\nYou input: %i\n", userInput);
      
        line(15, 1, 1, 0);
        if (userInput == MS_OPTIONS)
        {
            options();
        }
        else if (userInput == MS_INFO_HOW)
        {
            info();
        }
        else if (userInput == MS_CREDITS)
        {
            credits();
        }
        else if (userInput == MS_EXIT)
        {
            return 1;
        }
        line(15, 1, 1, 0);
    }
    while (userInput != MS_START);

    printf("you started the game!\nwow!");
    line(15, 1, 1, 0);
}

/***********************/
// Gameplay Prototypes //
/***********************/


/************************/
// Interface Prototypes //
/************************/

void options(void)
{
    printf("options WIP");
}
void info(void)
{
    printf("info WIP");
}
void credits(void)
{
    printf("credits WIP");
}

/**********************/
// Utility Prototypes //
/**********************/

void wait(float seconds)
{
    float milliseconds = seconds * 1000.0f;
    usleep(milliseconds * 1000.0f);
}

void line(int astNum, int astSpace, int nlBefore, int nlAfter)
{
    int arrEnd = 1;
    
    int arrSize = astNum + (astSpace *(astNum - 1));
    int arrSizeTotal = arrSize + nlBefore + nlAfter + arrEnd;
    char arr[arrSizeTotal];
    
    for (int i = nlBefore; i < arrSize + nlBefore; i += astSpace)
    {
        arr[i] = '*';
        i++;
        for (int j = 0; j < astSpace && i < arrSize + nlBefore; j++) // Prevent spaces after final '*'
        {
            arr[i + j] = ' ';
        }
    }
    
    for (int i = 0; i < nlBefore; i++)
    {
        arr[i] = '\n';
    }
    for (int i = 0; i < nlAfter; i++)
    {
        arr[arrSize + nlBefore + i] = '\n';
    }
    
    arr[arrSizeTotal - arrEnd] = '\0';
    printf("%s\n", arr);
}
