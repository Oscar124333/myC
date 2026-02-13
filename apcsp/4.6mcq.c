// Write a procedure that accepts three numbers, a, b, and c (you may assume the user always
// enters nonzero values) and displays the two solutions to the quadratic equation ax^2 + bx + c

#include <stdio.h>
#include <math.h>


// Prototypes
float discriminant(float a, float b, float c);
void quadratic_formula(float a, float b, float c);

// Global Constants
const int VARIABLEAMOUNT = 3;
const int VARIABLE_A = 0;
const int VARIABLE_B = 1;
const int VARIABLE_C = 2;

int main(void)
{
    float variableArr[VARIABLEAMOUNT];

    for (int i = 0; i < VARIABLEAMOUNT; i++)
    {
        int scanStatus = 0;
        int ch;

        printf("Enter variable %c: ", 'a' + i);
        scanStatus = scanf("%f", &variableArr[i]);

        if (scanStatus != 1)
        {
            while ((ch = getchar()) != '\n' && ch != EOF); // Clear buffer
        }
    }

    quadratic_formula(variableArr[VARIABLE_A], variableArr[VARIABLE_B], variableArr[VARIABLE_C]);
    
    return 0;
}

float discriminant(float a, float b, float c)
{
    float output = 0;

    output = (b*b) - (4*a*c);
    return output;
}

void quadratic_formula(float a, float b, float c)
{
    float xPos, xNeg, currentDiscriminant;
    xPos = xNeg = currentDiscriminant = 0;

    currentDiscriminant = discriminant(a, b, c);

    // Imaginary solution
    if (currentDiscriminant < 0)
    {
        printf("Solution not found; it is imaginary.\n");
        return;
    }
    
    // First solution
    xNeg = (-b) - sqrt(currentDiscriminant);
    xNeg /= 2 * a;
    printf("x = %.3f", xNeg);
    
    // Second solution
    if (currentDiscriminant != 0)
    {
        xPos = (-b) + sqrt(currentDiscriminant);
        xPos /= 2 * a;
        printf(", %.3f", xPos);
    }
    printf("\n");
    return;
}
