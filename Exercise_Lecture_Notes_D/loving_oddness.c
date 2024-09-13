#include <stdio.h>

int main(void)
{
	int cnt = 0;
	float max = 0, x, found_odd = 0;
	
	//User Input Size
	printf("How many number do you wish to enter ? ");
	scanf("%d", &cnt);

	//User Input Numbers
	printf("Enter %d odd numbers: ", cnt);
	int i =0;
	while (i <cnt){
		scanf("%f", &x);
	
		if (x > max){
		max = x;}
	i++;
	}

	// Display the maximum odd number value
    	printf("Maximum Odd Number Value: %.2f\n", max);

    return 0;
}

/*
#include <stdio.h>

int main(void)
{
    int cnt = 0;
    int max = -1;  // Initialize to -1 or any value less than the possible odd numbers
    int x;
    int found_odd = 0; // Flag to check if at least one odd number is found
    
    // User Input Size
    printf("How many numbers do you wish to enter? ");
    scanf("%d", &cnt);

    // User Input Numbers
    printf("Enter %d numbers: ", cnt);
    for (int i = 0; i < cnt; i++) {
        scanf("%d", &x);
    
        if (x % 2 == 1) { // Check if the number is odd
            if (x > max) {
                max = x;
            }
            found_odd = 1; // Mark that an odd number has been found
        }
    }

    // Display the maximum odd number value
    if (found_odd) {
        printf("Maximum Odd Number Value: %d\n", max);
    } else {
        printf("No odd numbers were entered.\n");
    }

    return 0;
}
*/
