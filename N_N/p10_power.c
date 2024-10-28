/* Try to write power(a, b) to compute a^b
   without using any math functions other than
   multiplication:
   Try (1) iterative, then (2) recursive,
   (3) Trick that for n % 2 == 0, x^n = x^(n/2) * x^(n/2)
*/

#include <stdio.h>

int power(unsigned int a, unsigned int b);

int main(void)
{
    int x = 2;
    int y = 16;

    printf("%d^%d = %d\n", x, y, power(x, y));

    return 0;
}

/* Recursive implementation using the trick for even powers */
int power(unsigned int a, unsigned int b)
{
    if (b == 0) {
        return 1;  // Base case: a^0 = 1
    }
    if (b == 1) {
        return a;  // Base case: a^1 = a
    }
    if (b % 2 == 0) {
        int halfPower = power(a, b / 2);
        return halfPower * halfPower;  // For even b: a^b = (a^(b/2)) * (a^(b/2))
    } else {
        return a * power(a, b - 1);  // For odd b: a^b = a * a^(b-1)
    }
}
