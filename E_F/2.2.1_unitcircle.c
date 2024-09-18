#include <stdio.h>
#include <math.h>

#define PI 3.141592653

int circle(int x);

int main(void)
{
    int x;
    
    printf("Input a radian: ");
    scanf("%f", &x);
    if (x >= 0 && x <= 2*PI){
        int circle(int x);
        printf("%d\n",x);
    }
    else
    {
        printf("Invalid Input");
    }
    return 0;
}

int circle(int x)
{
    return sin(x)*sin(x) + cos(x)*cos(x);
}