#include <stdio.h>
#include <stdint.h>  // for uint64_t

void fibonacci(int i);

int main(void) {
    int input = 0;
    printf("How many fibonacci? ");
    scanf("%i", &input);

    if (input <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    fibonacci(input);
}

uint64_t a = 0;
uint64_t b = 1;
int count = 1;

void fibonacci(int i) {
    printf("#%i: %llu\n", count++, a);  // %llu for uint64_t
    if (i == 1) {
        return;
    }

    uint64_t temp = b;
    b += a;
    a = temp;
    fibonacci(i - 1);
}
