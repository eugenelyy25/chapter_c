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