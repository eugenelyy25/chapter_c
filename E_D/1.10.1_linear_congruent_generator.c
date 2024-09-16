#include <stdio.h>

int main()
{
    // Parameters for the Linear Congruential Generator
    int seed = 0; // Initial seed value
    int M = 11; // Modulus parameter
    int A = 9; // Multiplier term
    int C = 5; // Increment term
    int i = 0;

    // Number of random numbers to be generated
    int Loops = 6;

    /*Linear Congruemtial Generator*/
    for (i = 0; i < Loops; i++) {
        seed = (A * seed + C) % M;
        /*Seed now contains your new random number */
        printf("%d\n", seed); // Print the generated seed number
    }
    return 0;
}
