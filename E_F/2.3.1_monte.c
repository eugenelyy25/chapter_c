#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

double monte_carlo_pi(int interval, int rand_max);


int main(void)
{
    int interval = 100;
    int rand_max = 100;
    //Run the Monte Carlo simulation and approximation of Pi
    double pi = monte_carlo_pi(interval, rand_max);

    printf("\nFinal approximation of Pi after %d iterations: %f\n", interval, pi);
    assert(interval > 0); //Ensure that INTERVAL is positive
    assert(pi > 3.0 && pi < 3.2);   //Final approximation of pi should be close to actual pi

    return 0;
}

double monte_carlo_pi(int interval, int rand_max)
{
    int circle_points = 0;
    int square_points = 0;
    double x, y, d, pi_approx = 0.0;

    srand(time(NULL)); //Initialize random number generator

    for (int j = 0; j < interval; j++) {
        //Generate random x and y coordinates between -1 and 1
        x = (2.0 * (rand()%(rand_max + 1)) /rand_max) - 1;
        y = (2.0 * (rand()%(rand_max + 1)) /rand_max) - 1; 

        // Assert that x and y are within the expected range
        assert(x >= -1.0 && x <= 1.0);
        assert(y >= -1.0 && y <= 1.0);

        //Calculate distance from (0,0)
        d = x * x + y * y;

        // Assert that the distance is non-negative
        assert(d >= 0.0);

        // Check if the point is inside the unit circle
        if (d <= 1.0) {
            circle_points++;
        }

        square_points++; // Increment total square points

        // Approximate the value of pi
        pi_approx = 4.0 * circle_points / square_points;

        // Assert that pi approximation stays within a reasonable range
        assert(pi_approx >= 0.0 || pi_approx <= 4.0);

        // Display the current approximation of pi
        printf("Iteration %d: Pi approximation = %f\n", j + 1, pi_approx);
    }

    return pi_approx;
}
