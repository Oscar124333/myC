#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

// Constants
#define CASE_EXIT 9
const int RESET = 0;
const int EXIT = 9;

// Global Variables
int userInput = 0;
int userSave = 0;
int inStatus = 0;
int lineBreakLen = 20;

// Gameplay Data
/*  Distance is measured in miles * 10; 100 distance = 10 miles */
typedef struct {
    int type;
    int speed; 
    int HP;
    float accidentRate;
} Bicycle;
Bicycle bike1 = {0, 100, 10, 0.3f};

typedef struct {
    float dBal; // Dollars (standard currency)
    int fBal;   // Favors (premium currency)
    float dollarRate;
    float favorRate;
} PlayerStats;
PlayerStats p1 = {0.0f, 0, 1.0f, 0.11f};

// Gameplay Prototypes
int bike_manual(void);

// Utility Prototypes
void wait(float seconds);
void lineBreak(int astNum);
int inputHandler(int *variable);

// Interface Prototypes
bool user_saves(void);
int main_options(void);
int main_info(void);
int main_credits(void);
int game_overview (void);
void displayStats(PlayerStats player);

int main(void)
{
    int m_Screen = 0;

    enum MenuMain{
        MAIN,
        START,
        OPTIONS,
        INFO_HOW,
        CREDITS
    };
    
    lineBreak(lineBreakLen);
    
    printf("Welcome to Oscar's Bicycle Game!\n");
    printf("Please use numbers to indicate your choices.\n");
    
    do   
    {
        switch (m_Screen)
        {
            case MAIN:
                do
                {
                    lineBreak(lineBreakLen);
                    
                    printf("Main Menu\n");
                    printf("1: Start\n2: Options\n3: Info & How-To\n4: Credits\n\n9: Exit\n\n");
                    printf("==> ");
                    inStatus = inputHandler(&m_Screen);
                } while (inStatus != 1);

                break;
            case START:
                printf("you started the game! wow!\n");
                if (user_saves())
                {
                    printf("Loading save #%d.\n", userSave);
                    m_Screen = game_overview();
                }
                break;
            case OPTIONS:
                m_Screen = main_options();
                break;
            case INFO_HOW:
                m_Screen = main_info();
                break;
            case CREDITS:
                m_Screen = main_credits();
                break;
            case CASE_EXIT:
                lineBreak(lineBreakLen);
                printf("Exiting game.\n");
                break;
            default:
                m_Screen = MAIN;
                break;
        }
    } while (m_Screen != EXIT);

return 0;
}


/******************************************/
//           Gameplay Functions           //
/******************************************/

int bike_manual(void)
{
    lineBreak(lineBreakLen);

    srand(time(NULL));
    float dEarned = (int)((rand() % (300 - 100)) + 100) / 100.0f;
    p1.dBal += dEarned;
    
    wait(0.5);
    printf("biking...\n"); // will make a automagical function that does dot dot dot for me
    wait(0.5);
    printf("earned %.2f dollars!\n", dEarned);
    wait(0.5);

    return RESET;
}

/*******************************************/
//           Interface Functions           //
/*******************************************/

bool user_saves(void) // Currently, '1' is the only correct choice.
{
    lineBreak(lineBreakLen);

    do
    {
        do
        {
            printf("Please choose your save.\n");
            printf("\n==> ");
            inStatus = inputHandler(&userSave);

            lineBreak(lineBreakLen);
        } while (inStatus != 1);
        
        if (userSave == 1)
        {
            printf("Successfully selected save #%d.\n", userSave);
            return true;
        }
        else
        {
            printf("Save not found.\n");
        }
    } while (true);
}


int main_options(void)
{
    int m_opScreen = 0;

    enum Options{
        OPTIONS,
        LINEBREAKLEN,
        PLACEHOLDER
    };

    do
    {
        switch (m_opScreen)
        {
            case OPTIONS:
                do
                {
                    lineBreak(lineBreakLen);

                    printf("Options\n");
                    printf("1: Linebreak Length\n2: Placeholder\n\n9: Exit\n\n");
                    printf("==> ");
                    inStatus = inputHandler(&m_opScreen);
                } while (inStatus != 1);
                break;
                case LINEBREAKLEN:
                do
                {
                    lineBreak(lineBreakLen);
                    
                    printf("Default LineBreak Length: 20\nPlease enter your desired length\n");
                    printf("==> ");
                    inStatus = inputHandler(&lineBreakLen);
                } while (inStatus != 1);

                printf("\nLineBreak Length set to %d.\n", lineBreakLen);

                m_opScreen = OPTIONS;
                break;
            case PLACEHOLDER:
                m_opScreen = OPTIONS;
                break;
            case CASE_EXIT:
                break;
            default:
                m_opScreen = OPTIONS;
                break;
        }
    } while (m_opScreen != EXIT);

    return RESET;
}

int main_info(void)
{
    int m_inScreen = 0;
    
    enum Info{
        INFO,
        H2P,
        LORE
    };

    do
    {
        switch (m_inScreen)
        {
            case INFO: 
                do
                {
                    lineBreak(lineBreakLen);
                    
                    printf("Information\n");
                    printf("1: How to Play\n2: Lore\n\n9: Exit\n\n");
                    printf("==> ");
                    inStatus = inputHandler(&m_inScreen);
                } while (inStatus != 1);

                break;
            case H2P:
                do
                {
                    do
                    {
                        lineBreak(lineBreakLen);

                        printf("How to Play WIP\n");
                        printf("\n9: Exit\n\n");
                        printf("==> ");
                        inStatus = inputHandler(&m_inScreen);
                    } while (inStatus != 1);
                } while (m_inScreen != EXIT);

                m_inScreen = INFO;
                break;
            case LORE:
            do
                {
                    do
                    {
                        lineBreak(lineBreakLen);
                        printf("Lore WIP\n");
                        printf("\n9: Exit\n\n");
                        printf("==> ");
                        inStatus = inputHandler(&m_inScreen);
                    } while (inStatus != 1);
                } while (m_inScreen != EXIT);

                m_inScreen = INFO;
                break;
            default:
                m_inScreen = INFO;
                break;
        }
    } while (m_inScreen != EXIT);
    
    return RESET;
}

int main_credits(void)
{
    int m_crScreen = 0;

    enum Credits{
        CREDITS,
        PLACEHOLDER
    };
    
    do
    {
        switch (m_crScreen)
        {
            case CREDITS:
                do
                {
                    lineBreak(lineBreakLen);
                    
                    printf("Credits WIP\n");
                    printf("\n9: Exit\n\n");
                    printf("==> ");
                    inStatus = inputHandler(&m_crScreen);
                } while (inStatus != 1);
                break;
            case PLACEHOLDER:
                m_crScreen = CREDITS;
                break;
            case CASE_EXIT:
                break;
            default:
                m_crScreen = CREDITS;
                break;
        }
    } while (m_crScreen != EXIT);
    
    return RESET;
}

int game_overview(void)
{
    int g_ovScreen = 0;

    enum game_options{
        OVERVIEW,
        GO2SCHOOL,
        SHOP,
        SKILLS,
        ITERATE
    };

    lineBreak(lineBreakLen);

    printf("You wake up. It's day %d.\n", 1);

    do
    {
        switch (g_ovScreen)
        {
            case OVERVIEW:
                do
                {
                    lineBreak(lineBreakLen);

                    if (true)
                    {
                        displayStats(p1);
                    }

                    printf("Day %d.\n", 0);
                    printf("1: Bike to School\n2: Shop\n3: Skills\n4: Iterate\n\n9: Exit\n\n");
                    printf("==> ");
                    inStatus = inputHandler(&g_ovScreen);
                } while (inStatus != 1);
                break;
            case GO2SCHOOL:
                g_ovScreen = bike_manual();
                break;
            case SHOP:
            case SKILLS:
            case ITERATE:
                g_ovScreen = OVERVIEW;
                break;
            default:
                g_ovScreen = OVERVIEW;
                break;
        }
    } while (g_ovScreen != EXIT);

    return RESET;
}

void displayStats(PlayerStats player)
{
    printf("Balance: $%.2lf\n", player.dBal);
    printf("Favors:  %d\n", player.fBal);
    printf("$ Mult:  %.2fx\n", player.dollarRate);
    printf("F Mult:  %.2fx\n\n", player.favorRate);
}

/*****************************************/
//           Utility Functions           //
/*****************************************/

void wait(float seconds)
{
    float milliseconds = seconds * 1000.0f;
    usleep(milliseconds * 1000.0f);
}

void lineBreak(int astNum)
{
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

int inputHandler(int *variable)
{
    int status = 0;
    int ch;
    status = scanf("%d", variable);
    if (status == 1)
    {
        return status;
    }
    else
    {
        while ((ch = getchar()) != '\n' && ch != EOF); // Clear buffer
    }
}