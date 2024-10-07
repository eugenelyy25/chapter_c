#include <stdio.h>
#include <math.h>

#define PHI 1.61803  // You can change this value to experiment with different approximations
#define MAX_ITERATIONS 10000  // Set a reasonable limit to avoid infinite loops
#define CORRECT 1
#define INCORRECT 0

int fibword_phi(int n);
int correct_fibword_phi(int n);

int main(void) {
    int n = 1;
    int incorrect_found = INCORRECT;  // Flag to indicate if an incorrect value is found

    for (n = 1; n <= MAX_ITERATIONS && !incorrect_found; n++) {
        int approx_value = fibword_phi(n);
        int correct_value = correct_fibword_phi(n);

        if (approx_value != correct_value) {
            printf("Incorrect value at n = %d\n", n);
            incorrect_found = CORRECT;
        }
    }

    if (!incorrect_found) {
        printf("No incorrect value found within %d iterations\n", MAX_ITERATIONS);
    }

    return 0;
}

// Function from Exercise 2.6.1
int fibword_phi(int n) {
    int nth_digit = 2 + floor(n * PHI) - floor((n + 1) * PHI);
    return (nth_digit == 1) ? CORRECT : INCORRECT;
}

// Correct function from Exercise 3.8.1 (assuming it returns the correct nth digit)
int correct_fibword_phi(int n) {
    // Placeholder for the correct implementation
    // Replace this with the actual implementation from Exercise 3.8.1
    int is_even = (n % 2 == 0);
    return is_even ? CORRECT : INCORRECT;  // Example implementation, replace with the actual one
}
