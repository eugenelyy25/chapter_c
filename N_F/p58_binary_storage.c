#include <stdio.h>

int main (void)
{
    float d = 0.1; //float operation doesn't need to be exact
    printf("%.12f\n", 3.0*d);
    return 0;
}

/*floats cannot store exactly so we won't compare it
Eg: if (d == 0.3)
Use flag to warn: -Wfloat-equal */