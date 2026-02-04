#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *spell_name(char *word);
void greeting(char *unsplitArr);

int charLen = sizeof(char);

int main(void)
{
    char *favoriteMovies[4] = {"Star Wars", "Cars 2", "Cars 3", "Godzilla"};
    
    printf("Favorite Movie #1: %s\n", favoriteMovies[0]);
    
    /*
    for (int i = 0; i < 4; i++)
    {
        printf("Favorite Movie #%i: %s\n", i + 1, favoriteMovies[i]);
        }
        */
        
        printf("%s\n", spell_name("Jessica"));
        printf("%s\n", spell_name("Ariel"));

        char input[] = "wasd wAsd Wasd";
        greeting(input);
        
        return 0;
    }
    
    char *spell_name(char *word)
    {
        int wordLength = strlen(word);
        char *buffer = malloc(sizeof(char) * wordLength * 2 * 1);
        if (buffer == NULL)
        {
            printf("error buffer 2\n");
        }
        
        
        for (int i = 0; i < wordLength - 1; i++)
        {
            sprintf(buffer + i*2, "%c,", word[i]);
        }
        sprintf(buffer + (wordLength - 1) * 2, "%c", word[wordLength - 1]);
        
        return buffer;
    }

    void greeting(char *unsplitArr)
    {
        char splitArr[3][15];
        int arrLength = strlen(unsplitArr);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; unsplitArr[j] != ' '; j++)
            {
                splitArr[i][j] = unsplitArr[j];
            }
        }
        printf("Hello, %s! I love %s too! Age: %s\n", splitArr[0], splitArr[2], splitArr[1]);
        return;
    }
