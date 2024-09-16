#include <stdio.h>
#include <stdlib.h>

/*int simple_seed() {
    // Use a simple method to generate a pseudo-random seed
    int seed = 0; // Initial seed value
    seed = seed * 1103515245 + 0; // Linear congruential generator
    return seed;
}*/

int main(void) {
   /* int seed = simple_seed(); // Get a pseudo-random seed value
    srand(seed); // Seed the random number generator*/

    int n = rand() % 1000 + 1;
    int c = -1;

    while (n != c) {
        if (c == -1) {
            printf("Guess a number 1-1000\n");
        } else if (c > n) {
            printf("Too high!\n");
        } else if (c < n) {
            printf("Too low!\n");
        }

        printf("Enter your guess: ");
        scanf("%d", &c);
    }

    printf("Yes, the answer was %d \n", n);
    return 0;
}
