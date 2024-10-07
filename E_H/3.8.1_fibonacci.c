#include <stdio.h>

#define MAX_SIZE 1000  // Define a maximum size for the array

int fibword_subs(int n);

int main(void) {
    int n = 21;
    printf("The %dth digit in the Fibonacci Words sequence is: %d\n", n, fibword_subs(n));
    return 0;
}

// Function to generate the nth digit of the Fibonacci Words sequence
int fibword_subs(int n) {
    // Initialize the sequence with the first digit
    int sequence[MAX_SIZE] = {0};
    int length = 1;
    // Generate the sequence until it is long enough to get the nth digit
    while (length < n) {
        int new_sequence[MAX_SIZE];
        int new_length = 0;

        for (int i = 0; i < length; i++) {
            if (sequence[i] == 0) {
                new_sequence[new_length++] = 1;
                new_sequence[new_length++] = 0;
            } else {
                new_sequence[new_length++] = 0;
            }
        }
        // Copy new_sequence to sequence
        for (int i = 0; i < new_length; i++) {
            sequence[i] = new_sequence[i];
        }
        length = new_length;
    }
    return sequence[n - 1];
}