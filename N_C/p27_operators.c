#include <stdio.h>

int main(void)
{
	int a, c = 0;
	a = ++c;
	
	int b = c++;
	printf("%i %i %i\n", a, b, ++c);
	return 0;

}

// 1 + 2 * 3 same as 1 + (2 * 3)
// 1 + 2 + 3 same as (1 + 2) + 3
// i++ same as i = i + 1 this means i will take current val then increment
// ++i this mean i will increment then take  val
// i-- this mean i will take current val then decrement
// --i this mean i will decrement then take val
