#include <stdio.h>

int is_prime(int n);
int is_endthree(int n);

int main(void)
{
    int n = 30;
    int prime_count = 0; //Counter for prime numbers
    int endthree_count = 0; //Counter for prime numbers ending with 3

    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d \n", i);
            prime_count++; //Increment count, prime
            if (is_endthree(i)) {
                endthree_count++; //Increment count, primes ending in 3 
            }
        }
    }
    printf("Number of prime numbers: %d\n", prime_count);
    printf("Number of prime numbers ending with 3: %d\n", endthree_count);
    return 0;
}

int is_prime(int n)
{
    if (n <= 1) { //from number 0 & 1
        return 0; //Not prime
    }
    for (int i = 2; i * i <= n; i++) { //from number 2 to sqrt(n)
        if (n % i == 0) { //if divisible by i
            return 0; //Not prime
        }
    }
    return 1; //Prime
}

int is_endthree(int n)
{
    if (n % 10 == 3) {
        return 1;
    }
    else {
        return 0;
    } //Returns 1 if n ends with 3, otherwise returns 0
}