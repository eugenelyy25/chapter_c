#include <stdio.h>

int main(void)
{
    int cnt = 0;
    int max = 0, x, found_odd = 0;
    
    // User Input Size
    printf("How many numbers do you wish to enter? ");
    scanf("%d", &cnt);

    // User Input Numbers
    printf("Enter %d odd numbers: ", cnt);
    for (int i = 0; i < cnt; i++) {
        scanf("%d", &x);
    
        if (x % 2 == 1) { // Check if the number is odd
            if (x > max) {
                max = x;
            }
            found_odd = 1; // Mark odd number found
        }
    }

    //Display the maximum odd number value
    if (found_odd) {
        printf("Maximum Odd Number Value: %d", max);
    } else {
        printf("No odd numbers were entered.");
    }
    return 0;
}
