/* Exercise 2-1 from Ivor Horton's Beginning C, personally extended.
 *   "Write a program that prompts the user to enter a distance in inches and then outputs that distance in yards, feet and inches.""
 *   Will also do miles, kilometers, millimeters, centimeters, meters, kilometers, and everything in between
 */

#include <stdio.h>

// Prototypes
int measurement_choice(int userChoice);
int measurement_choose(int userMsrmnt);
int inputHandler(int *variable);

int main(void)
{
    int userInput = 0;

    printf("Welcome to Oscar's Measurement Converter!\n\nPlease enter the number corresponding to the unit of measure used.\n");
    printf("1. Kilometers\n2. Miles\n3. Meters\n4. Feet\n5. Inches\n6. Centimeters\n7. Other");
    printf("==> ");
    scanf("%d", &userInput);

    int unit = measurement_choie(userInput);
    if (1)
    {
    }

    printf("\n* * * * * * * * * * * * * * *\n");
    printf("\nWhat would you like to convert this measurement to?\n");

    printf("==> ");
    scanf("%d", &userInput);
    measurement_choice(userInput);

    measurement_choose(userInput);
}

int measurement_choice(int userChoice)
{
    enum Systems
    {
        COMMON = 1,
        IMPERIAL,
        METRIC
    };

    enum Common
    {
        cMILES = 1,
        cKILO,
        cFEET,
        cINCHES,
        cCENTI,
        cMILL,
        EXTRA,
        ALL
    };

    if (userChoice == 1)
    {
        printf("\n1. Feet\n2. Yards\n3. Miles");
    }
}

int measurement_choose(int userMsrmnt)
{
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
        while ((ch = getchar()) != '\n' && ch != EOF)
            ; // Clear buffer
    }
}