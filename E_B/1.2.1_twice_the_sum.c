#include <stdio.h>

int main(void)
{
	int a, b, c;
	printf("Input three integers: ");
	scanf("%d %d %d\n" ,&a, &b, &c);
	
	int d;
	d = 0;
	d = 2 * (a + b + c);

	printf("Twice the sum of integers plus 7 is %d !\n", d+7);
	return 0;
}
