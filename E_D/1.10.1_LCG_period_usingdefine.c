#include <stdio.h>

#define M 11   // Modulus parameter
#define A 7    // Multiplier term
#define C 5    // Increment term

int main(void)
{
    int seed = 0;  // Initial seed value
    int original_seed = seed; // To store the original seed value
    int count = 0; // To count the number of iterations

    // Generate numbers and detect the period
    do {
        seed = (A * seed + C) % M;
        count++;
    } while (seed != original_seed);

    // Print the period
    printf("Period of the LCG: %d\n", count);

    return 0;
}
