#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

// Constants
const int EXIT = 9;

// Global Variables
int lineDefault = 20;
int userInput = 0;
int userSave = 0;

// Gameplay Prototypes
void gameLoop(void);

// Utility Prototypes
void wait(float seconds);
void lineBreak(int astNum, int astSpace, int nlBefore, int nlAfter);

// Interface Prototypes
void menuMain(void);
void menuMain_options(void);
void menuMain_info(void);
void menuMain_credits(void);
bool userSaves(void);

int main(void)
{
    lineBreak(lineDefault, 1, 1, 1);
    printf("Welcome to Oscar's Bicycle Game!\n");
    printf("Please use numbers to indicate your choices.\n");
    
    menuMain();

    if (userInput == EXIT)
    {
        return 1;
    }
    else if (userSaves())
    {
        printf("Loading save #%i.\n", userSave);
    }
    return 0;
}


/**********************/
// Gameplay Functions //
/**********************/

void gameLoop(void)
{

}

/***********************/
// Interface Functions //
/***********************/

void menuMain(void)
{
    lineBreak(lineDefault, 1, 1, 1);

    printf("Main Menu");
    enum MenuMain{
        START = 1,
        OPTIONS,
        INFO_HOW,
        CREDITS
    };

    do   
    {
        printf("\n1: Start\n2: Options\n3: Info & How-To\n4: Credits\n9: Exit\n");
        printf("==> ");
        scanf("%i", &userInput);
        
        if (userInput == START)
        {
            printf("you started the game! wow!\n");
            return;
        }
        else if (userInput == OPTIONS)
        {
            menuMain_options();
        }
        else if (userInput == INFO_HOW)
        {
            menuMain_info();
        }
        else if (userInput == CREDITS)
        {
            menuMain_credits();
        }
        else if (userInput == EXIT)
        {
            lineBreak(lineDefault, 1, 1, 1);
            printf("Exiting game.\n");
            return;
        }
    } while ((userInput < START || userInput > CREDITS) && userInput != EXIT);

}

bool userSaves(void) // Currently, '1' is the only correct choice.
{
    do
    {
        lineBreak(lineDefault, 1, 1, 1);
    
        printf("Please choose your save.\n");
        printf("==> ");
        scanf("%i", &userSave);
        
        if (userSave == 1)
        {
            lineBreak(lineDefault, 1, 1, 1);
            printf("Successfully selected save #%i.\n", userSave);
            return true;
        }
        else
        {
            printf("Save not found.\n");
        }
    } while (true);

}

void menuMain_options(void)
{
    do
    {
        lineBreak(lineDefault, 1, 1, 1);
        printf("Options\n");
        printf("9: Exit\n");
        printf("==> ");
        scanf("%i", &userInput);
    } while (userInput != EXIT);

    if (userInput == EXIT)
    {
        menuMain();
        return;
    }
}

void menuMain_info(void)
{
    enum MenuMainInfo{
        H2P = 1,
        LORE
    };
    do
    {
        lineBreak(lineDefault, 1, 1, 1);
        printf("Information\n");
        printf("1: How to Play\n2: Lore\n9: Exit\n");
        printf("==> ");
        scanf("%i", &userInput);
    } while ((userInput < 1 || userInput > 2) && userInput != EXIT);
    
    if (userInput == H2P)
    {
        do
        {
            lineBreak(lineDefault, 1, 1, 1);
            printf("How to Play WIP\n");
            printf("9: Exit\n");
            printf("==> ");
            scanf("%i", &userInput);
        } while (userInput != EXIT);

        if (userInput == EXIT)
        {
            menuMain_info();
        }
    }
    else if (userInput == LORE)
    {
        do
        {
            lineBreak(lineDefault, 1, 1, 1);
            printf("Lore WIP\n");
            printf("9: Exit\n");
            printf("==> ");
            scanf("%i", &userInput);
        } while (userInput != EXIT);
        
        if (userInput == EXIT)
        {
            menuMain_info();
        }
    }
    else if (userInput == EXIT)
    {
        menuMain();
        return;
    }
}

void menuMain_credits(void)
{
    do
    {
        lineBreak(lineDefault, 1, 1, 1);
        printf("Credits WIP\n");
        printf("9: Exit\n");
        printf("==> ");
        scanf("%i", &userInput);
    } while (userInput != EXIT);
    
    if (userInput == EXIT)
    {
        menuMain();
        return;
    }
}

/*********************/
// Utility Functions //
/*********************/

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
