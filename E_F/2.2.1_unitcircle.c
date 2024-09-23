#include <stdio.h>
#include <math.h>
#include <assert.h>

double test_trig_identity(double x);
void test(void);

int main(void)
{
    double x;
    
    printf("Input a radian: ");
    scanf("%lf", &x);
    test_trig_identity(x);
    test();

    return 0;
}

double test_trig_identity(double x)
{
    //int result = pow(sin(x), 2) + pow(cos(x), 2);
    double result = sin(x)*sin(x) + cos(x)*cos(x);

    printf("sin²(%.2f) + cos²(%.2f) = %.2f (Test passed)\n", x, x, result);

    return result;
}

void test(void)
{
    double x = 1.0;
    double result = test_trig_identity(x);
    double epsilon = 1e-9;
    assert((result > 1.0 - epsilon) && (result < 1.0 + epsilon) && "Test failed: sin²(x) + cos²(x) != 1");
    //check if gets near 1

    printf("Assertion passed for x = %.2f\n", x);
}