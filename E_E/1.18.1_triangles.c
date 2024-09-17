#include<stdio.h>

int main(void)
{
    int a, b, c;

    //User input
    printf("Input the three sides of a triangle:\n");

    //Input lengths for a, b, and c
    scanf("%d %d %d", &a, &b, &c);

    //Check if is triangle
    if ((a*a) + (b*b) == (c*c) || (a*a) + (c*c) == (b*b) || (b*b) + (c*c) == (a*a)) //a(sqr) + b(sqr) = c(sqr)
    {
        // If true, print Right Angle Triangle
        printf("It is a right angle triangle!\n");
    }
    else if ((a <= 0 || b <= 0 || c <= 0)) //negative length
    {
        //If true, Invalid triangle
        printf("Invalid triangle!\n");
    }
    else if ((a == b || b == c || a == c))
    {
        if (a == b && b == c){
        //If true, Equilateral triangle
        printf("It is an equilateral triangle!\n");
        }
        else{
        //If false, Isoceles triangle  
        printf("It is an isoceles triangle!\n");
        }
    }
    else if ((a + b > c && a + c > b && b + c > a)) //all possible triangles (triangle inequality theorem)
    {
        //If true, Valid triangle
        printf("Valid triangle!\n");
    }
    else
    {
        //If false, print not a Triangle
        printf("It is not a triangle!\n");
    }
    return 0; //End of program
}