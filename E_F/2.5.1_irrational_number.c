#include <stdio.h>
#include <assert.h>

#define E 2.718281828459045 //Define number being searched (Euler's number)

void test(double approximation);

double my_abs(double value); 
//Custom absolute value function for double precision

int main(void)
{
    int best_a = 0, best_b = 1; //Initialize the best fraction
    double best_diff = my_abs(E - (double)best_a / best_b); 
    //Initialize the best difference

    for (int b = 1; b < 100000; b++) {
        int a = (int)(E * b + 0.5); 
        //Find the numerator a that gives the closest fraction to e
        double fraction = (double)a / b; //Calculate the fraction
        double diff = my_abs(E - fraction); //Calculate the difference

        if (diff < best_diff) { //If this is a better approximation, store it
            best_a = a;
            best_b = b;
            best_diff = diff;
        }
    }
    test((double)best_a / best_b);

    //Display best fraction
    printf("Best approximation of e: %d/%d = %.20f\n", best_a, best_b, (double)best_a / best_b);
    return 0;
}

double my_abs(double value) 
{
    return value < 0 ? -value : value; 
    //condition ? expression_if_true : expression_if_false;
}

/*  E: (Euler Number) 2.718281828459045
    for (): Investigate b between 1 ~ 100,000 [Loop for denominators]
//  Best Approximation to E:
    a = (int)(E * b + 0.5): Round E * b to nearest integer (int)(E * b + 0.5)
*/

void test(double approximation) 
{
    assert(my_abs(E - approximation) < 1e-9); 
    //Ensure approximation is close to e
}