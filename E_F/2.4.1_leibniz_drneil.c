#include <stdio.h>
#include <math.h>

#define PI 3.1415927

int main(void)
{
    double denom = 3.0;
    double approx = 4.0;
    double sign = -1.0;

    do{
        approx = approx + sign*4.0/denom;
        denom += 2.0; // denom = denom + 2
        sign = sign * -1;
    }while(fabs(approx - PI) > 0.000001);{
        printf("approx = %.9lf pi = %.9lf\n", approx, PI);
    }
    return 0;
}

// The mathematical constant pi = 4 - 4/3 + 4/5 - 4/7 ... 