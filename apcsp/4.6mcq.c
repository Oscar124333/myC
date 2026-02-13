// Write a procedure that accepts three numbers, a, b, and c (you may assume the user always
// enters nonzero values) and displays the two solutions to the quadratic equation ax^2 + bx + c

#include <stdio.h>
#include <math.h>


// Prototypes
int discriminant(int a, int b, int c);
void quadratic_formula(int a, int b, int c);

// Global Constants
int VARIABLEAMOUNT = 3;
int VARIABLE_A = 0;
int VARIABLE_B = 1;
int VARIABLE_C = 2;

int main(void)
{
    int variableArr[VARIABLEAMOUNT];

    for (int i = 0; i < VARIABLEAMOUNT; i++)
    {
        int scanStatus = 0;
        int ch;

        printf("Enter variable %c: ", 'a' + i);
        scanStatus = scanf("%i", &variableArr[i]);
        
        if (scanStatus != 1)
        {
            while ((ch = getchar()) != '\n' && ch != EOF); // Clear buffer
        }
    }

    quadratic_formula(variableArr[VARIABLE_A], variableArr[VARIABLE_B], variableArr[VARIABLE_C]);
    
    return 0;
}

int discriminant(int a, int b, int c)
{
    int output = 0;

    output = (b*b) - (4*a*c);
    return output;
}

void quadratic_formula(int a, int b, int c)
{
    int xPos = 0;
    int xNeg = 0;

    int currentDiscriminant = discriminant(a, b, c);
    if (currentDiscriminant < 0)
    {
        printf("Solution not found; it is imaginary.\n");
        return;
    }
    
    xPos = (-b) + sqrt(currentDiscriminant);
    xPos /= 2 * a;

    printf("x = %i", xPos);
    
    if (currentDiscriminant != 0)
    {
        xNeg = (-b) - sqrt(currentDiscriminant);
        xNeg /= 2 * a;
        printf(", %i", xNeg);
    }
    printf("\n");
    return;
}
