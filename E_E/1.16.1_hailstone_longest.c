#include <stdio.h>

long long Hailstone(long long n); //use long long for type

int main(void) {
    long long start;

    printf("Input a number (less than 10,000,000): ");
    scanf("%lld", &start);

    if (start >= 10000000) { //Check input within allowed range
        printf("The number should be less than 10,000,000.\n");
        return 1;
    }

    printf("Hailstone sequence for %lld:\n", start); //Print initial number

    while (start != 1) { //loop terminates when start = 1
        printf("%lld\n", start);
        start = Hailstone(start);
    }
    printf("1\n"); //Print the final 1 number in sequence
    return 0;
}

long long Hailstone(long long n) { //long long stores more bits
    if (n % 2 == 0) {
        return n / 2;
    } else {
        return (3 * n) + 1;
    }
}