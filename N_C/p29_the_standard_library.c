#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("Randomly distributed integers are printed.\n");
	printf("How many do you want to see? ");

	int n;
	if (scanf("%i", &n) == 1)
	{
		for (int i = 0; i < n; ++i)
		{
			if(i%4 == 0)
			{
				printf("\n");
			}
		printf("%12i", rand());
		}
	printf("\n");
	return 0;
	}
return 1;
}


// rand() use in stdlib.h -- definitions
/*
Execution :

Randomly ditributed integers are printed.
How many do you want to see? 11
1804289383 846930886 1681692777 1714636915
1957747793 424238335 719885386 1649760492
596516649 1189641421 1025202362
*/
//Exams will ask the for loop or while loop equivalent
