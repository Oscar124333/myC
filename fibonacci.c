#include <stdio.h>

void fibonacci(int i);

int main(void){
    // Grab input from user
    int input = 0;
    printf("How many fibonacci? ");
    scanf("%i", &input);

    if (input <= 0){
        printf("Invalid input.\n");
        return 1;
    }
    fibonacci(input);
}

unsigned long a = 0;
unsigned long b = 1;
int count = 1;
void fibonacci(int i){
    printf("#%i: %ld\n", count++, a);
    if (i == 1){
        return;
    }
    
    unsigned long temp = b;
    b += a;
    a = temp;
    fibonacci(i - 1);
}