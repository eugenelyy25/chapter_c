#include <stdio.h>

#define MIN(A, B) ((A)<(B)?(A):(B)) //Using MACRO

int main(void)
{
    int j, k, m;

    printf("Input two integers: ");
    scanf("%i%i", &j, &k);
    m = MIN(j, k);
    printf("Minimum is %i \n", m);
    return 0;
}
//Replacing function with macro, #define MACRO
/*double evaluation
m = MIN(j++,k++);
expansion: ((j++)<(k++)?(j++):(k++))
*/