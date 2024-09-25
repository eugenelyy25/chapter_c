#include <stdio.h>
#include <math.h>
#include <assert.h>

void test(int n, double term, double pi_approx);

int main(void)
{
    double pi = 0.0;
    double term;
    int n = 0;
    int precision = 7; // Decimal places precision
    double target_pi = 3.1415927;
    double pi_approx = 0.0;
    double tolerance = pow(10, -precision); // Tolerance for comparison

    // Leibniz series loop
    // Continue until pi approximation is close enough to target_pi
    while (round(pi_approx * pow(10, precision)) / pow(10, precision) < target_pi - tolerance || round(pi_approx * pow(10, precision)) / pow(10, precision) > target_pi + tolerance) {
        term = pow(-1, n) / (2 * n + 1);
        pi += term;
        pi_approx = 4 * pi;  // Calculate the approximate value of pi
        test(n, term, pi_approx); // Test assertions
        // printf("Iteration %d: Pi approximation = %.10f\n", n + 1, pi_approx);
        n++;
    }

    // Display of results
    printf("Approximated value of Pi: %.7f\n", pi_approx);
    printf("Number of iterations (terms): %d\n", n);
    return 0;
}

/*  The Condition:
//  while (round(pi_approx * pow(10, precision)) / pow(10, precision) < target_pi - tolerance || round(pi_approx * pow(10, precision)) / pow(10, precision) > target_pi + tolerance)
    pi_approx: Current approximation of 𝜋
    pow(10, precision): 10 raised to the power of precision 
                        [E.g. 10^7 ~ for 7 decimal place]
    round(pi_approx * pow(10, precision)):  Rounds current approximation of 𝜋
                                            to 7 decimal place
    / pow(10, precision):   Move decimal point back to original number,
                            but rounded to 7 decimal places
    < target_pi - tolerance || > target_pi + tolerance: Checks if the rounded value is within the tolerance range of the target value π (3.1415927).
    Summary:    Comparing current approx. of 𝜋 only up to 7 decimal place.
                if it match, loop stops.
                
    Inside the loop (Leibniz Series 1/1-1/3+1/5-1/7+...):
 // term = pow(-1, n) / (2 * n + 1);
    pow(-1, n): Alternates sign of n. When n even: 1, When n odd: -1
    (2 * n + 1): Generates odd numbers
    Summary: Even n (0,2,4) - Positive Term, Odd n (1,3,5) - Negative Term
*/
void test(int n, double term, double pi_approx)
{
    if (n % 2 == 0) {
        assert(term > 0); // For even n, term should be positive
    } else {
        assert(term < 0); // For odd n, term should be negative
    }

    assert(pi_approx > 0 && pi_approx < 5.0);
    // pi_approx should be between 0 and 5
}