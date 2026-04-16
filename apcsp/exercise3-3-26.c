#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


// Prototypes
bool ptrInvalid(void *ptr, char *errorMsg);
int inputHandler(char *variable);
void inputPrompt(char *variable, char *prompt);

// Constants
#define ERRMALLOC 3
const int NULL_TERM_SIZE = 1;

int main(void)
{
    char userInput[100] = {'\0'};
    int userInteger = 0;
    char **songs = malloc(sizeof(char*));
    char **artists = malloc(sizeof(char*));
    int *durations = malloc(sizeof(int));
    
    for (int i = 0; userInput[0] != 'n' && strlen(userInput) == 1; i++)
    {
        inputPrompt(userInput, "Enter a song name: ");
        char **temp = realloc(songs, + 1 + NULL_TERM_SIZE);
        if (ptrInvalid(temp, "incorrent_temp malloc")) {return ERRMALLOC;}
        songs = temp;
        songs[i] = malloc(sizeof(char) * strlen(userInput) + NULL_TERM_SIZE);
        strcpy(songs[i], userInput);
        
        inputPrompt(userInput, "Enter the artist: ");
        temp = realloc(artists, + 1 + NULL_TERM_SIZE);
        if (ptrInvalid(temp, "incorrent_temp malloc")) {return ERRMALLOC;}
        artists = temp;
        artists[i] = malloc(sizeof(char) * strlen(userInput) + NULL_TERM_SIZE);
        strcpy(artists[i], userInput);
        
        inputPrompt(userInput, "Enter the duration: ");
        char *temp1 = realloc(durations, + 1 + NULL_TERM_SIZE);
        if (ptrInvalid(temp, "incorrent_temp malloc")) {return ERRMALLOC;}
        
        durations[i] = atoi(userInput);
    }
    
    
    return 0;
}

/*************/
/*  Utility  */
/*************/

bool ptrInvalid(void *ptr, char *errorMsg)
{
    if (ptr == NULL)
    {
        perror(errorMsg);
        return true;
    }
    return false;
}

int inputHandler(char *variable)
{
    int status = 0;
    int ch;
    status = scanf("%s", variable);
    if (status != 1)
    {
        while ((ch = getchar()) != '\n' && ch != EOF)
            ; // Clear buffer
    }
    return status;
}

void inputPrompt(char *variable, char *prompt)
{
    do
    {
        printf("%s\n==> ", prompt);
    } while (inputHandler(variable) != 1);
    return;
}
