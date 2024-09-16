#include <stdio.h>

/* printf( fmt-str, arg1, arg2, ...);
%c characters
%i integers
%e floats/doubles (engineering notation)
%f floats/doubles
%s strings
*/

int main(void)
{	
	float f;

	f = 3.000183738483;

	/*printf( fmt-str, arg1, arg2, ...);*/
	printf("F:%7f\n", f); /*Fixed-width fields:*/
	printf("F:%.2f\n", f); /*Fixed Precision: */
	return 0;
}
