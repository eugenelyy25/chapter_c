#include <stdio.h>

int min(int a, int b); //function prototype at top

int main(void) //execution begins in main()
{
    int j, k, m;

    printf("Input two integers: ");
    scanf("%i%i", &j, &k);
    m = min(j, k);
    printf("\nOf the two values %i and %i, the minimum is %i.\n\n", j, k, m);
    return 0;
}
int min(int a, int b) //min() takes 2 int & return 1 int
{
    if (a < b) //copies of j & k
        return a; //return a value to calling statement
    else
        return b;
}