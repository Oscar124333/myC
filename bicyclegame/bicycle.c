#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

// Variable Declarations
int userInput = 0;
int lineDefault = 20;

// Gameplay Prototypes

// Utility Prototypes
void wait(float seconds);
void lineBreak(int astNum, int astSpace, int nlBefore, int nlAfter);

// Interface Prototypes
void menuOptions(void);
void menuInfo(void);
void menuCredits(void);
bool menuSaves(int saveNum);

int main(void)
{
    lineBreak(lineDefault,1,3,0);
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
        
        lineBreak(lineDefault, 1, 1, 0);
        if (userInput == MS_OPTIONS)
        {
            menuOptions();
        }
        else if (userInput == MS_INFO_HOW)
        {
            menuInfo();
        }
        else if (userInput == MS_CREDITS)
        {
            menuCredits();
        }
        else if (userInput == MS_EXIT)
        {
            return 1;
        }
        lineBreak(lineDefault, 1, 1, 0);
    }
    while (userInput != MS_START);
    
    printf("you started the game!\nwow!\n");

    lineBreak(lineDefault, 1, 1, 0);
    printf("please choose your save: ");
    scanf("%i", &userInput);
    if (menuSaves(userInput))
    {
        int userSave = userInput;
    }
    
    lineBreak(lineDefault, 1, 0, 0);
}

/***********************/
// Gameplay Prototypes //
/***********************/


/************************/
// Interface Prototypes //
/************************/

void menuOptions(void)
{
    printf("options WIP");
}

void menuInfo(void)
{
    printf("info WIP");
}

void menuCredits(void)
{
    printf("credits WIP");
}

bool menuSaves(int saveNum)
{
    // If save exists, spit out true
    if (saveNum == 1)
    {
        printf("\nyou successfully chose save %i\n", saveNum);
        return true;
    }
    else
    {
        printf("\ndoes not compute\n");
        return false;
    }
}

/**********************/
// Utility Prototypes //
/**********************/

void wait(float seconds)
{
    float milliseconds = seconds * 1000.0f;
    usleep(milliseconds * 1000.0f);
}

void lineBreak(int astNum, int astSpace, int nlBefore, int nlAfter)
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
