#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define INTERVAL 10000

int main(void)
{
   int circle_points = 0, square_points = 0;
   double rand_x, rand_y, d, pi;
   int interval, i;


   //x*x + y*y <= r*r
   //Initializing rand()
   srand(time(null));

   //Random numbers generated = possible x values * y values
   for (i = 0; i < (INTERVAL*INTERVAL); i++){
      
      rand_x = double(rand()%1000;
      rand_y = double(rand()%1000);

      d = x*x + y*y

      if (d <= 1){
         circle_points++;
         interval++;
      }
      if

     }

   
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

double monte_carlo_pi(int NO_OF_ITERATIONS);

int main(void) {
    int NO_OF_ITERATIONS = 10000;
    // Run Monte Carlo simulation and assert that the number of iterations is positive
    assert(NO_OF_ITERATIONS > 0);
    // Call the Monte Carlo simulation and get the approximation of Pi
    double pi = monte_carlo_pi(NO_OF_ITERATIONS);
    // Assert that the final approximation is within a reasonable range of Pi
    assert(pi > 3.0 && pi < 3.2);  // Loose bounds to allow for approximation variations
    // Display the final result
    printf("\nFinal approximation of Pi after %d iterations: %f\n", NO_OF_ITERATIONS, pi);

    return 0;
}

double monte_carlo_pi(int NO_OF_ITERATIONS) {
    int circle_points = 0;
    int square_points = 0;
    double x, y, d, pi_approx = 0.0;

    // Initialize the random number generator
    srand(time(NULL));

    for (int i = 0; i < NO_OF_ITERATIONS; i++) {
        // Generate random x and y coordinates between -1 and 1
        x = (double)rand() / RAND_MAX * 2 - 1;
        y = (double)rand() / RAND_MAX * 2 - 1;

        // Assert that x and y are within the expected range
        assert(x >= -1.0 && x <= 1.0);
        assert(y >= -1.0 && y <= 1.0);

        d = x * x + y * y; // Calculate distance from (0,0)

        // Assert that the distance is non-negative
        assert(d >= 0.0);

        // Check if the point is inside the unit circle
        if (d <= 1.0) {
            circle_points++;
        }

        // Increment total square points
        square_points++;

        // Approximate the value of pi
        pi_approx = 4.0 * circle_points / square_points;

        // Assert that pi approximation stays within a reasonable range
        // This is a loose range to allow for fluctuations in early iterations
        assert(pi_approx > 0.0 && pi_approx <= 4.0);

        // Display the current approximation of pi
        printf("Iteration %d: Pi approximation = %f\n", i + 1, pi_approx);
    }

    return pi_approx;
}*/