#include <stdio.h>

//1st few powers of 2 are printed.
int main(void)
{
	int i = 0, power = 1;

	while (++i <= 10)
	{
		printf("%5i", power *= 2);
	}
	printf("\n");
	return 0;
}

/*
Execution :
2 4 8 16 32 64 128 256 512 1024
*/

// = operator low precedence (right-to-left)
// a = b = c = 0; same as a = (b = (c = 0));
// i = i + 3; same as i += 3;
// other operators -=, *=, /=

/* An example by Dr. Neil
while (i <= 10)
        {
                power=power*2;
                printf("%5i", power);
                i++;
        }
*/
