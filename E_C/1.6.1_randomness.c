#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Set upper bound for ran()
    int plus_cnt = 0;

    //Set lower bound for ran()
    int minus_cnt = 0;
    
    //Prompt user input rand_max value
    int rand_max;
    printf("Enter max value for random number generation: ");
    scanf("%d", &rand_max);
    
    //Median
    int median = rand_max/2;

    //Loop through 500 times
    for (int i = 0; i < 500; i++) {
        //generate random number within bound
        int value = rand()%(rand_max + 1);
        
        //if value  < median
        if (value < median) {
            minus_cnt++;
	}

        //Print difference
        printf("%d ", plus_cnt - minus_cnt);
    }
    return 0;
}

