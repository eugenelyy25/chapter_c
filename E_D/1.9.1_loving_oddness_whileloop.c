#include <stdio.h>

int main(void)
{
    int cnt = 0;
    int max = 0, x, found_odd;
    int i = 0; // Initialize a counter for the while loop
    
    // User Input Size
    printf("How many numbers do you wish to enter? ");
    scanf("%d", &cnt);

    // User Input Numbers
    printf("Enter %d odd numbers: ", cnt);
    while (i < cnt) {
        scanf("%d", &x);

        if (x % 2 == 1) { // Check if the number is odd
            if (x > max) {
                max = x;
            }
            found_odd = 1; // Mark odd number found
        }
        i++; // Increment counter
    }

    // Display the maximum odd number value
    if (found_odd) {
        printf("Maximum Odd Number Value: %d\n", max);
    } else {
        printf("No odd numbers were entered.\n");
    }
    return 0;
}
