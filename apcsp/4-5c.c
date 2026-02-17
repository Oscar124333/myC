#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Globals
const int STATUS_OKAY = 1;
const int NULL_SIZE = 1;
const int NAME_CHAR_LIMIT = 25;

// Prototypes
void problem1(void);
void problem2(void);
int integerInputHandler(int *variable);
int stringInputHandler(char *variable);

int main(void)
{
    int inputStatus = 0;

    enum
    {
        PROBLEM1 = 1,
        PROBLEM2,
        PROBLEM3,
        PROBLEM4,
        PROBLEM5,
        PROBLEM6,
        PROBLEM7
    } Problems;
    int userInput = 0;

    do
    {
        printf("Which problem do you want to see? Enter the corresponding number.\n==> ");
        inputStatus = integerInputHandler(&userInput);
    } while (inputStatus != STATUS_OKAY);

    switch (userInput)
    {
        case PROBLEM1:
            printf("\nProblem 1 loaded.\n\n");
            problem1();
            break;
            case PROBLEM2:
            printf("\nProblem 2 loaded.\n\n");
            problem2();
            break;
        // case PROBLEM3:
        //     printf("Problem 3 loaded.\n\n");
        //     problem3();
        //     break;
        // case PROBLEM4:
        //     printf("Problem 4 loaded.\n\n");
        //     problem4();
        //     break;
        // case PROBLEM5:
        //     printf("Problem 5 loaded.\n\n");
        //     problem5();
        //     break;
        // case PROBLEM6:
        //     printf("Problem 6 loaded.\n\n");
        //     problem6();
        //     break;
        // case PROBLEM7:
        //     printf("Problem 7 loaded.\n\n");
        //     problem7();
        //     break;
        default:
            printf("\nThat's not my problem.\n(get it? lololol)\n\n");
            return 1;
    }

    return 0;
}

/***********************/
/*  Problem Functions  */
/***********************/

void problem1(void)
{
    int inputStatus = 0;
    
    // Problem 1, Append and Extend with names
    int nameAmount = 0;
    do
    {
        printf("How many names does your name have? Enter a number\n==> ");
        inputStatus = integerInputHandler(&nameAmount);
    } while (inputStatus != STATUS_OKAY);
    
    // Allocate array of strings
    char **nameArr = malloc(nameAmount * sizeof(char *));  
    if (nameArr == NULL)
    {
        perror("malloc() Error, char **nameArr");
        return;
    }
    
    // Allocate buffer (and collect garbage)
    char *buffer = calloc(NAME_CHAR_LIMIT + NULL_SIZE, sizeof(char));
    if (buffer == NULL)
    {
        perror("malloc() Error, char *buffer");
        return;
    }
    printf("There is a maximum of %i characters per name.\n", NAME_CHAR_LIMIT);

    for (int i = 0; i < nameAmount; i++)
    {
        do
        {
            printf("Enter name #%i: ", i+1);
            inputStatus = stringInputHandler(buffer);
        } while (inputStatus != STATUS_OKAY);

        // Allocate and paste each string of the array
        int currentBufferLen = strlen(buffer) + NULL_SIZE;
        nameArr[i] = malloc(currentBufferLen * sizeof(char));
        if (nameArr[i] == NULL)
        {
            perror("malloc() Error, char nameArr[]");
            return;
        }
        else
        {
            strncpy(nameArr[i], buffer, currentBufferLen);
        }

    }


    // Print formatted results
    for (int i = 0, j = 0; i < nameAmount; i++)
    {
        char *nameTypeArr[] = {"First", "Middle", "Last"};
        int middleNameStart = 1;
        int lastName = nameAmount - 1;

        if (i == middleNameStart)
        {
            j++;
        }
        if (i == lastName && middleNameStart < nameAmount)
        {
            j++;
        }

        printf("%s Name: %s\n", nameTypeArr[j], nameArr[i]);
    }

    // I am NOT programming it so that it prints all the middle names in a single list/line. >:(
    
    // Memory Freeing
    for (int i = 0; i < nameAmount; i++)
    {
        free(nameArr[i]);
    }
    free(nameArr);
    free(buffer);

    return;
}

void problem2(void)
{
    int inputStatus = 0;

    /* Problem 2
        Using a loop, ask the user for five numbers. Store those numbers in a list. Each time you add a new number to your list, print the list. (Your list will initially be empty.)
        You should report the sum of the numbers in the list at the end. */

    const int FIVE = 5;   // just for problem 2
    int userNumList[FIVE];
    printf("** Enter %i numbers. **\n", FIVE);

    for (int i = 0; i < FIVE; i++)
    {
        do
        {
            printf("Enter a number\n==> ");
            inputStatus = integerInputHandler(&userNumList[i]);    
        } while (inputStatus != STATUS_OKAY);

        // i'll do it just this one time
        printf("Current list: {");
        for (int j = 0; j <= i; j++)
        {
            if (i != j)
            {
                printf("%i, ", userNumList[j]);
            }
            else
            {
                printf("%i}\n", userNumList[j]);
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < FIVE; i ++)
    {
        sum += userNumList[i];
    }

    printf("\nProblem 2's Sum: %i\n", sum);

    return;
}

void problem3(void)
{
    return;
}


/*********************/
/*  Input Functions  */
/*********************/

int integerInputHandler(int *variable)
{
    int status = 0;
    int ch;
    status = scanf("%d", variable);
    if (status != 1)
    {
        while ((ch = getchar()) != '\n' && ch != EOF); // Clear buffer
    }
    return status;
}
int stringInputHandler(char *variable)
{
    int status = 0;
    int ch;
    status = scanf("%24s", variable);
    while ((ch = getchar()) != '\n' && ch != EOF); // Clear buffer

    return status;
}