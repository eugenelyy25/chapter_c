#include <stdio.h>

int is_prime(int num);

int main(void) {
    int n, count = 0, num = 2;

    // Ask user for number of primes to print
    printf("Enter the number of primes to print: ");
    scanf("%d", &n);

    // Check input
    if (n <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }
    // Find & print the first n prime numbers
    printf("The first %d prime numbers are:\n", n);
    while (count < n) {
        if (is_prime(num)) {
            printf("%d\n", num);
            count++;
        }
        num++;
    }
    printf("\n");
    return 0;
}
// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 1; //evaluation results 1 (0 & 1)
    if (num <= 3) return 1; //evaluation result 3 or less than 3 (2 & 3)
    if (num % 2 == 0 || num % 3 == 0) return 0; //eliminates if divisible by (2 & 3)
    for (int i = 5; i * i <= num; i += 6) { //prime num in 6k±1 where k integer
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    } //eliminates if divisible by (i & i+2)
    return 1;
}