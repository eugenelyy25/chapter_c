#include <stdio.h>

int main(void) {
    int amount;
    int lower, higher;
    int valid = 0;

    while (!valid) {
        // Prompt user for input
        printf("How much money would you like?\n");
        scanf("%d", &amount);
        
        // Check if amount is divisible by £20
        if (amount % 20 == 0) {
            printf("OK, dispensing ...\n");
            valid = 1;
            break;
        } else {
            // Calculate lower & higher values of multiples of £20
            lower = (amount/20) * 20;
            higher = lower + 20;
            
            // Display closest options
            printf("I can give you %d or %d, try again.\n", lower, higher);
        }
    }
    return 0;
}