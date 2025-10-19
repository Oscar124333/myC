#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

// Constants
#define CASEEXIT 9
const int EXIT = 9;

// Global Variables
int userInput = 0;
int userState = 0;
int userSave = 0;

// Gameplay Prototypes
void gameOverview (void);

// Utility Prototypes
void wait(float seconds);
void lineBreak(void);

// Interface Prototypes
int menuMain_options(void);
int menuMain_info(void);
int menuMain_credits(void);
bool userSaves(void);

int main(void)
{
    lineBreak();
    
    printf("Welcome to Oscar's Bicycle Game!\n");
    printf("Please use numbers to indicate your choices.\n");
    
    enum MenuMain{
        MAIN,
        START,
        OPTIONS,
        INFO_HOW,
        CREDITS
    };
    
    do   
    {
        
        switch (userState)
        {
            case MAIN:
                lineBreak();

                printf("Main Menu");
                printf("\n1: Start\n2: Options\n3: Info & How-To\n4: Credits\n9: Exit\n");
                printf("==> ");
                scanf("%i", &userState);
                break;
            case START:
                printf("you started the game! wow!\n");
                gameOverview();
                break;
            case OPTIONS:
                userState = menuMain_options();
                break;
            case INFO_HOW:
                userState = menuMain_info();
                break;
            case CREDITS:
                userState = menuMain_credits();
                break;
            case CASEEXIT:
                lineBreak();
                printf("Exiting game.\n");
                break;
            default:
                printf("Pleae try again.\n");
                userState = MAIN;
                break;
        }
    } while (userState != EXIT);

/*
*   if (userInput == EXIT)
*   {
*       return 1;
*   }
*   else if (userSaves())
*   {
*       printf("Loading save #%i.\n", userSave);
*       gameOverview();
*   }
*   return 0;
*/
}

/******************************************/
//           Gameplay Functions           //
/******************************************/

void gameOverview(void)
{
    lineBreak();
    
    char *day[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    printf("You wake up. It's day %i. %s.\n", 1, day[1]);

    do
    {
        printf("Y\n");
        scanf("%i", &userInput);

    } while (userInput != EXIT);

    if (userInput == EXIT)
    {
        // some auto save functionality here
    }
}

/*******************************************/
//           Interface Functions           //
/*******************************************/

bool userSaves(void) // Currently, '1' is the only correct choice.
{
    do
    {
        lineBreak();
    
        printf("Please choose your save.\n");
        printf("==> ");
        scanf("%i", &userSave);
        
        if (userSave == 1)
        {
            lineBreak();
            printf("Successfully selected save #%i.\n", userSave);
            return true;
        }
        else
        {
            printf("Save not found.\n");
        }
    } while (true);

}

int menuMain_options(void)
{
    enum Options{
        OPTIONS,
        PLACEHOLDER
    };

    do
    {
        switch (userInput)
        {
            case OPTIONS:
                lineBreak();

                printf("Options\n");
                printf("9: Exit\n");
                printf("==> ");
                scanf("%i", &userInput);
                break;
            case PLACEHOLDER:
                userInput = OPTIONS;
                break;
            case CASEEXIT:
                break;
            default:
                printf("Please try again.\n");
                userInput = OPTIONS;
                break;
        }
    } while (userInput != EXIT);
    return 0;
}

int menuMain_info(void)
{
    enum Info{
        INFO,
        H2P,
        LORE
    };

    do
    {
        lineBreak();
        printf("Information\n");
        printf("1: How to Play\n2: Lore\n9: Exit\n");
        printf("==> ");
        scanf("%i", &userInput);
    } while ((userInput < 1 || userInput > 2) && userInput != EXIT);
    
    if (userInput == H2P)
    {
        do
        {
            lineBreak();
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
            lineBreak();
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
        return 0;
    }
}

int menuMain_credits(void)
{
    enum Credits{
        CREDITS,
        PLACEHOLDER
    };

    do
    {
        lineBreak();
        printf("Credits WIP\n");
        printf("9: Exit\n");
        printf("==> ");
        scanf("%i", &userInput);
    } while (userInput != EXIT);
    
    if (userInput == EXIT)
    {
        return 0;
    }
}

/*****************************************/
//           Utility Functions           //
/*****************************************/

void wait(float seconds)
{
    float milliseconds = seconds * 1000.0f;
    usleep(milliseconds * 1000.0f);
}

void lineBreak(void)
{
    int astNum = 20;
    int astSpace = 1;
    int nlBefore = 1;
    int nlAfter  = 1;
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
