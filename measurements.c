/* Exercise 2-1 from Ivor Horton's Beginning C, personally extended.
 *   "Write a program that prompts the user to enter a distance in inches and then outputs that distance in yards, feet and inches.""
 *   Will also do miles, kilometers, millimeters, centimeters, meters, kilometers, and everything in between
 */

#include <stdio.h>

// Globals
long double MetersFactors[][8] = {
    {1000.0, 1609.34, 1.0, 0.3048, 0.0254, 0.01},
    {4828.03, 1852, 0.9144, 201.1684, 5.0292, 20.1168, 0.201, 2.54e-5},
    {100.0, 10.0, 0.1, 0.001, 1e-6}};

typedef struct
{
    int system;
    int unit;
} Units;
Units userUnits = {0, 0};

const int OTHER = 7;

// Prototypes
void print_common_measurements(void);
void print_other_measurements(int userChoice);
void print_suffix(Units unit);

long double measurement_convert_to_meters(long double measurement, Units unit);
long double measurement_meters_to_user(long double measurement, Units unit);

int inputHandler(int *variable);

int main(void)
{
    int userInput = 0;
    long double userMeasure = 0.0l;

    printf("Welcome to Oscar's Measurement Converter!\n\nPlease enter a number corresponding to the unit of measure your measurement is in.\n");
    print_common_measurements();
    printf("==> ");
    scanf("%d", &userInput);

    if (userInput == OTHER)
    {
        printf("\nWhich system do you wish to use?\n1. Imperial\n2. Metric\n");
        printf("==> ");
        scanf("%d", &userInput);
        userUnits.system = userInput;

        print_other_measurements(userInput);
        printf("==> ");
        scanf("%d", &userInput);
        userUnits.unit = userInput;
    }
    else
    {
        userUnits.system = 0;
        userUnits.unit = userInput;
    }

    printf("\nPlease enter only the number of your measurement. Decimals are allowed.\n");
    printf("==> ");
    scanf("%Lf", &userMeasure);
    long double userMeters = measurement_convert_to_meters(userMeasure, userUnits);
    Units origUnits = userUnits;

    printf("\n* * * * * * * * * * * * * * *\n");
    printf("\nWhat would you like to convert this measurement to?\n");
    print_common_measurements();
    printf("==> ");
    scanf("%d", &userInput);

    if (userInput == OTHER)
    {
        printf("\nWhich system do you wish to convert to?\n1. Imperial\n2. Metric\n");
        printf("==> ");
        scanf("%d", &userInput);
        userUnits.system = userInput;

        print_other_measurements(userInput);
        printf("==> ");
        scanf("%d", &userInput);
        userUnits.unit = userInput;
    }
    else
    {
        userUnits.system = 0;
        userUnits.unit = userInput;
    }

    long double userConverted = measurement_meters_to_user(userMeters, userUnits);
    printf("\n%0.2Lf ", userMeasure);
    print_suffix(origUnits);
    printf(", converted to ");
    printf("%Lf ", userConverted);
    print_suffix(userUnits);
    printf("\n");
}

void print_common_measurements(void)
{
    printf("1. Kilometers\n2. Miles\n3. Meters\n4. Feet\n5. Inches\n6. Centimeters\n7. Other\n");
    return;
}

void print_other_measurements(int userChoice)
{
    enum Systems
    {
        IMPERIAL = 1,
        METRIC
    };

    if (userChoice == IMPERIAL)
    {
        printf("\nImperial Measurements\n");
        printf("1. Leagues\n2. Nautical Miles\n3. Yards\n4. Furlongs\n5. Rods\n6. Chains\n7. Links\n8. Mils\n");
    }
    else if (userChoice == METRIC)
    {
        printf("\nMetric Measurements\n");
        printf("1. Hectometers\n2. Decameters\n3. Decimeters\n4. Millimeters\n5. Micrometers\n");
    }
}

void print_suffix(Units unit)
{
    char *suffixArr[][8] = {
        {"kilometers", "miles", "meters", "feet", "inches", "centimeters"},
        {"leagues", "nautical miles", "yards", "furlongs", "rods", "chains", "links", "mils"},
        {"hectometers", "decameters", "decimeters", "millimeters", "micrometers"}};

    printf("%s", suffixArr[unit.system][unit.unit - 1]);
    return;
}

long double measurement_convert_to_meters(long double measurement, Units unit)
{
    long double factor = 1.0l;
    long double meters = 1.0l;

    factor = MetersFactors[unit.system][unit.unit - 1];
    meters = measurement * factor;
    return meters;
}

long double measurement_meters_to_user(long double measurement, Units unit)
{
    long double factor = 1.0l;
    long double measureOut = 1.0l;

    factor = 1 / MetersFactors[unit.system][unit.unit - 1];
    measureOut = measurement * factor;
    return measureOut;
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