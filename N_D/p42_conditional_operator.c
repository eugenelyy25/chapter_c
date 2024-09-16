#include <stdio.h>

int main(void)
{
    int x, y, z;

    printf("Input three integers: ");
    if(scanf("%i%i%i", &x, &y, &z) != 3){
        printf("Didn't get 3 numbers?\n");
        return 1;
    }
    int min;
    min = (x < y) ? x : y; //if (x < y) is true then x is executed, else y is evaluated
    min = (z < min) ? z : min; //if (z < min) is true then y is executed, else min is evaluated
    printf("The minimum value is %i\n", min);
    return 0;
}