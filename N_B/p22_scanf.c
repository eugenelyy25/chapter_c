#include <stdio.h>

/*
scanf(fmt-str, &arg1, &arg2, ...);
%c characters
%i integers
%f floats
%lf doubles
% strings
*/

int main (void)
{
	int a, b;
	printf("Enter first number: ");
	scanf("%d", &a);

	printf("Enter second number: ");
	scanf("%d", &b);

	printf("A:%d \t B:%d", a, b);
	printf("\n");

	return 0;
}
