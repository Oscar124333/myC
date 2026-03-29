#include <stdio.h>

// Constants
#define EXIT 9
const int SCHOOLS = 0;
const int SCORES = 1;

// Prototypes
void printSingleRecap(int index, char *school, float score);
int inputHandler(int *variable);
void inputPrompt(int *variable, char *prompt);

int main(void)
{
    char *schoolsR1[] = {
        "Arcadia HS",
        "Mira Costa HS",
        "Glen A. Wilson HS",
        "Palisades CHS",
        "Canyon HS",
        "Troy HS",
        "Bolsa Grande HS",
        "Chaffey HS",
        "Serrano HS",
        "Claremont HS",
        "Lakewood HS",
        "Oak Park HS",
        "Glendora HS",
        "Burbank HS"
    };

    float scoresR1[] = {
        92.450f,
        90.000f,
        84.600f,
        83.300f,
        83.150f,
        82.450f,
        80.900f,
        80.100f,
        79.880f,
        76.350f,
        75.645f,
        73.300f,
        71.200f,
        69.895f
    };

    int lengthR1 = sizeof(schoolsR1)/sizeof(schoolsR1[0]);

    char *schoolsR2[] = {
        "Cypress HS",
        "South Hills HS",
        "Helix CHS",
        "Thousand Oaks HS",
        "St. Genevieve HS",
        "Aliso Niguel HS",
        "Warren HS",
        "Alta Loma HS",
        "Katella HS",
        "Camarillo HS",
        "Laguna Hills HS",
        "Don Lugo HS",
        "Simi Valley HS",
        "Downey HS"
    };

    float scoresR2[] = {
        92.300f,
        91.000f,
        90.600f,
        86.300f,
        85.600f,
        85.000f,
        84.950f,
        83.275f,
        82.350f,
        79.995f,
        78.950f,
        76.850f,
        73.520f,
        72.660f
    };

    int lengthR2 = sizeof(schoolsR2)/sizeof(schoolsR2[0]);


    char *schoolsR3[] = {
        "Upland HS",
        "Scripps Ranch HS",
        "Bonita HS",
        "Trabuco Hills HS",
        "Vista HS",
        "Buena Park HS",
        "Westminster HS",
        "Torrance HS",
        "La Quinta HS",
        "Crescenta Valley HS",
        "Del Norte HS",
        "Monrovia HS",
        "Grossmont HS"
    };

    float scoresR3[] = {
        91.925f,
        90.850f,
        89.875f,
        89.550f,
        88.375f,
        86.275f,
        83.350f,
        82.525f,
        82.450f,
        80.700f,
        80.640f,
        79.490f,
        70.950f
    };
    
    int lengthR3 = sizeof(schoolsR3)/sizeof(schoolsR3[0]);

    char *schoolsR4[] = {
        "Temple City HS",
        "North HS",
        "Rancho Alamitos HS",
        "Westlake HS",
        "Golden Valley HS",
        "Patriot HS",
        "Los Alamitos HS",
        "Temescal Canyon HS",
        "Millikan HS",
        "Santa Monica HS",
        "Orange Vista HS",
        "John Burroughs HS",
        "Valley View HS"
    };

    float scoresR4[] = {
        91.850f,
        89.150f,
        86.600f,
        85.375f,
        84.350f,
        83.800f,
        82.950f,
        81.500f,
        79.550f,
        79.525f,
        78.575f,
        77.500f,
        76.400f
    };

    int lengthR4 = sizeof(schoolsR4)/sizeof(schoolsR4[0]);

    // 4x2 2D array; 4 rounds, school name and score
    typedef struct
    {
        char **schools;
        float *scores;
        int length;
    } RecapTrio;

    RecapTrio recap[] = {
        {schoolsR1, scoresR1, lengthR1},
        {schoolsR2, scoresR2, lengthR2},
        {schoolsR3, scoresR3, lengthR3},
        {schoolsR4, scoresR4, lengthR4}
    };

    // Actual Code
    
    int userInput = 0;

    char *menuPrompt =
        "What would you like to do?\n"
        "1: Print a round\n"
        "2: Sort a pair of rounds\n"
        "3: Sort the competition\n"
        "9: Exit\n";
    // end char*

    
    do
    {
        switch (userInput)
        {
            case 0:
                inputPrompt(&userInput, menuPrompt);
                break;
            case 1:
            {
                inputPrompt(&userInput, "Which round?\n1 through 4\n");
                if (userInput == EXIT || (userInput < 1 || userInput > 4))
                {
                    userInput = 0;
                    break;
                }

                int round = userInput-1;
                printf("=====\n");
                for (int i = 0; i < recap[round].length; i++)
                {
                    printf("#%i. %s\n%0.3f\n\n", i+1, recap[round].schools[i], recap[round].scores[i]);
                }
                printf("=====\n");
            }   
                userInput = 0;
                break;
            case 2:
            {
                inputPrompt(&userInput, "Which pair?\n1: 1 & 3\n2: 2 & 4\n");
                if (userInput == EXIT || (userInput < 1 || userInput > 2))
                {
                    userInput = 0;
                    break;
                }
                
                int firstRound = userInput-1;
                int secondRound = userInput+1;
                int roundsLengthTotal = recap[firstRound].length + recap[secondRound].length;
                printf("=====\n");
                for (int firstIndex = 0, secondIndex = 0, i = 0; i < roundsLengthTotal; i++)
                {
                    float currentScoreFirst = recap[firstRound].scores[firstIndex];
                    float currentScoreSecond = recap[secondRound].scores[secondIndex];

                    if (currentScoreFirst > currentScoreSecond)
                    {
                        printSingleRecap(i+1, recap[firstRound].schools[firstIndex], recap[firstRound].scores[firstIndex]);
                        firstIndex++;
                    }
                    else
                    {
                        printSingleRecap(i+1, recap[secondRound].schools[secondIndex], recap[secondRound].scores[secondIndex]);
                        secondIndex++;
                    }
                }
                printf("%i schools competed.\n\n", roundsLengthTotal);
            }
                userInput = 0;
                break;
            case 3:            
            {    
                int firstRound = 0;
                int roundsLengthTotal = recap[0].length + recap[1].length + recap[2].length + recap[3].length;
                int indices[4] = {0};

                printf("=====\n");
                for (int i = 0; i < roundsLengthTotal; i++)
                {
                    
                    float currentScore = recap[firstRound].scores[indices[firstRound]];
                    int currentRound = firstRound;
                    for (int j = 0; j < 4; j++)
                    {
                        float currentScoreNext = recap[j].scores[indices[j]];
                        if (currentScore < currentScoreNext)
                        {
                            currentScore = currentScoreNext;
                            currentRound = j;
                        }
                    }
                    printSingleRecap(i+1, recap[currentRound].schools[indices[currentRound]], recap[currentRound].scores[indices[currentRound]]);

                    indices[currentRound]++;
                }
                printf("%i schools competed.\n\n", roundsLengthTotal);
            }
                userInput = 0;
                break;
            case EXIT:
                break;
            default:
                userInput = 0;
                break;
        }
    } while (userInput != EXIT);

    return 1;
}

void printSingleRecap(int index, char *school, float score)
{
    printf("#%i. %s\n%0.3f\n\n", index, school, score);
    return;
}

int inputHandler(int *variable)
{
    int status = 0;
    int ch;
    status = scanf("%d", variable);
    if (status != 1)
    {
        while ((ch = getchar()) != '\n' && ch != EOF)
            ; // Clear buffer
    }
    printf("\n");
    return status;
}

void inputPrompt(int *variable, char *prompt)
{
    do
    {
        printf("%s\n==> ", prompt);
    } while (inputHandler(variable) != 1);
    return;
}