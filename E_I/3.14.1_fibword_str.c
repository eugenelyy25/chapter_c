#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_SIZE 1000  // Maximum length for the Fibonacci word strings

int fibword_str(int n);
void test(void);

int main(void) {
    int n = 10; // Input
    int result = fibword_str(n);
    printf("The %dth digit of the Fibonacci word sequence is: %d\n", n, result);
    test();
    return 0;
}

// Function to generate the nth digit of the Fibonacci word sequence
int fibword_str(int n) {
    if (n < 1) {
        return 0; // Invalid input
    }

    // Initial strings S0 and S1
    char S0[MAX_SIZE] = "0";
    char S1[MAX_SIZE] = "1";
    char current[MAX_SIZE];

    strcpy(current, S1);

    // Generate the sequence until it is large enough
    while (strlen(current) < (size_t)n) {  // Compare against size_t to avoid warning
        char temp[MAX_SIZE];
        strcpy(temp, S1);
        strcat(temp, S0);

        // Update S0 and S1
        strcpy(S0, S1);
        strcpy(S1, temp);

        // Update the current sequence
        strcpy(current, temp);
    }

    // Get the nth digit
    char nth_digit = current[n - 1];

    // Return the nth digit as an integer (1 for '1', 0 for '0')
    return nth_digit == '1' ? 1 : 0;
}

void test(void) {
    assert(fibword_str(1) == 1);
    assert(fibword_str(2) == 0);
    assert(fibword_str(3) == 1);
    assert(fibword_str(4) == 1);
    assert(fibword_str(5) == 0);
}