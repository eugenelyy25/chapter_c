#include <stdio.h>

int is_prime(int n);

int main(void){
    int num;

    do {
        printf("Enter a number: ");
        num = scanf ("%d", &num);
    }

    while (is_prime (1));//check input
        printf("%d\n", num);
        num = is_prime(num);

    if (is_prime (0)){
        printf("Number of prime number ending 3: %d", count3());
        printf("Number of prime number: %d", countprime());
        }
    return 0;
}

int is_prime(int n){
    int countprime = 0;
    int count3 = 0;
    for (int i = 1; i < n; i++){ //initialize input number
        if (n%i == 0){ //to check when number input divided has remainder
        countprime++;
        } //add the counter
        if (n%3 == 3){ //check if n ends with 3
            count3++; //add the counter
        }
        if (countprime == 2){
            return 1; //when counter returns 2 is prime
        }
        else{
            return 0; //when counter returns more than 2 is not prime
        }
    }
}

/*
#include <stdio.h>
#include <stdbool.h>

// Function prototypes
bool is_prime(int n);
int ends_in_three(int n);

int main(void) {
    int num;
    int numprime = 0;
    int num3 = 0;

    // Get user input
    printf("Enter a number: ");
    while (scanf("%d", &num) == 1) {
        // Check if number is prime
        if (is_prime(num)) {
            numprime++;
            // Check if prime number ends in 3
            if (ends_in_three(num)) {
                num3++;
            }
        }

        printf("Enter another number (or non-integer to stop): ");
    }

    // Print results
    printf("Number of prime numbers: %d\n", numprime);
    printf("Number of prime numbers ending in 3: %d\n", num3);

    return 0;
}

// Function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to check if a number ends in 3
int ends_in_three(int n) {
    return n % 10 == 3;
}
*/

/*
#include <stdio.h>

int is_prime(int n);
int ends_in_three (int n);

int main(void){
    int num;
    int numprime = 0;
    int num3 = 0;
    
    do { //user input
        printf("Enter a number: ");
        num = scanf ("%d", &num);
    }

    while(num == 1){
    if (is_prime(num));//check input is prime
        numprime++;
        printf("Number of prime numbers: %d\n", numprime);
    else if (ends_in_three(num))//check input ends in 3
        num3++;
        printf("Number of prime number ending 3: %d\n", num3);
    else (is_prime (0)){
        printf("%d is not a prime number.", num);
        }
    printf("Enter another number (terminate using non-integer): ")
    return 0;
}

int is_prime(int n){
    if (n <= 1){ //if number is 1 or less
        return 0;
    }
    if (n == 2){ //if number is 2, prime
        return 1;
    }
    if (n%2 == 0){ //if number is even
        return 0;
    }
    for (int i = 1; i < n;){ //initialize input number
        if (n%i == 0){
            return 0;
        } //add the counter
    if (n%3 == 3){ //check if n ends with 3
            count3++; //add the counter
        }
    if (countprime == 2){
            return 1; //when counter returns 2 is prime
        }
        else{
            return 0; //when counter returns more than 2 is not prime
        }
    }
}

int ends_in_three(int n);

*/
