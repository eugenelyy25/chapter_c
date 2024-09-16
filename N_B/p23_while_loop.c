#include <stdio.h>

//Sums are computed

int main(void)
{
	int cnt = 0;
	float sum = 0.0, x;
	printf("Input some numbers: ");
	while (scanf("%f", &x) == 1)
	{
		cnt = cnt + 1;
		sum = sum + x;
	}

	printf("\n%s%5i \n%s%5f \n\n", "Count:", cnt, "Sum: ", sum);
	return 0;
}

/*
Execution:
Input some numbers: 1 5 9 10

Count: 4
Sum: 25.000000
*/
