#include <stdio.h>

int main(void)
{
	int cnt = 0;
	float max = 0.0, x;
	
	//User Input Size
	printf("How many number do you wish to enter ? ");
	scanf("%d", &cnt);

	//User Input Numbers
	printf("Enter %d real numbers: ", cnt);
	int i =0;
	while (i <cnt){
		scanf("%f", &x);
	
		if (x > max){
		max = x;}
	i++;
	}

	// Display the maximum value
    	printf("Maximum Value: %.2f\n", max);

    return 0;
}




