#include <stdio.h>

long long Hailstone(long long n);

int main(void) {
    long long start;
    long long max = 0; //initialize max to track maximum value in the sequence

    printf("Input a number (less than 10,000,000): ");
    scanf("%lld", &start);

    if (start >= 10000000) { //Check input within allowed range
        printf("The number should be less than 10,000,000.\n");
        return 1;
    }

    max = start; //Initialize max with starting number

    printf("Generating Hailstone sequence for %lld...\n", start); //Print user input

    while (start != 1) { //loop terminates when start = 1
        if (start > max) { //find maximum value
            max = start;
        }
        start = Hailstone(start); //Hailstone sequence
    }

    if (1 > max) { //Check the final value, which is 1
        max = 1;
    } //if max greater than 1, update max

    printf("The largest number in the sequence is: %lld\n", max);
    return 0; //Print maximum value found in the sequence
}

long long Hailstone(long long n) {
    if (n % 2 == 0) {
        return n / 2;
    } else {
        return (3 * n) + 1;
    }
}